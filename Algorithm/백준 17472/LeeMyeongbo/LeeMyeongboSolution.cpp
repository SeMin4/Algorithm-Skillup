#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

queue<pair<int, int>> q;
int N, M, map[100][100], visited[100][100], island_num, bridge[7][7], parent[7], ans;
const int dc[] = { 1, -1, 0, 0 }, dr[] = { 0, 0, 1, -1 };
vector<pair<int, pair<int, int>>> bridges;		// 두 섬 사이 다리 길이와 그 두 섬의 번호 저장

void count_island() {							// 섬 개수 + 섬 구별
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!map[i][j] || visited[i][j])	// 바다거나 방문한 섬은 skip
				continue;
			island_num++;
			q.push(make_pair(i, j));
			visited[i][j] = island_num;

			while (!q.empty()) {
				pair<int, int> p = q.front();
				q.pop();

				for (int d = 0; d < 4; d++) {	// 동 서 남 북 순으로 살핌
					int R = p.first + dr[d];
					int C = p.second + dc[d];
					if (R >= 0 && R < N && C >= 0 && C < M && map[R][C] && !visited[R][C]) {
						q.push(make_pair(R, C));
						visited[R][C] = island_num;
					}
				}
			}
		}
	}
}

void count_bridge() {
	for (int i = 1; i < 7; i++)
		for (int j = 1; j < 7; j++)
			bridge[i][j] = 100;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!visited[i][j])					// 바다인 지점은 skip
				continue;
			for (int d = 0; d < 4; d++) {		// 해당 섬 지점에서 동, 서, 남, 북 각 방향으로 쭉 가면서 다른 섬까지의 최소 다리 길이 갱신	
				int R = i + dr[d];
				int C = j + dc[d];
				int length = 0;
				while (R >= 0 && R < N && C >= 0 && C < M) {
					if (visited[R][C] == visited[i][j])		// 같은 섬인 지점을 만났을 경우 바로 break
						break;
					else if (visited[R][C]) {				// 다른 섬 지점을 만났을 경우 다리 길이 최솟값 갱신 + break
						if (length >= 2)
							bridge[visited[i][j]][visited[R][C]] = min(bridge[visited[i][j]][visited[R][C]], length);
						break;
					}
					length++;
					R += dr[d];
					C += dc[d];
				}
			}
		}
	}
}

int Find(int n) {				// 가장 최상위 부모 정점 탐색
	if (parent[n] == n)
		return n;
	return parent[n] = Find(parent[n]);
}

void Union(int v1, int v2, int weight) {	// 크루스칼 활용
	v1 = Find(v1);
	v2 = Find(v2);
	if (v1 == v2)
		return;
	if (v1 > v2)
		parent[v1] = v2;
	else
		parent[v2] = v1;
	ans += weight;
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];
	
	count_island();
	count_bridge();

	for (int i = 0; i < 7; i++)
		parent[i] = i;

	for (int i = 1; i <= island_num; i++)
		for (int j = i + 1; j <= island_num; j++)
			if (bridge[i][j] < 100)					// 두 섬 사이에 다리가 놓일 수 있는 경우 (다리 길이, (낮은 번호의 섬, 높은 번호의 섬)) 형태로 저장
				bridges.push_back(make_pair(bridge[i][j], make_pair(i, j)));
	sort(bridges.begin(), bridges.end());			// 다리 길이 오름차순으로 정렬

	for (auto v : bridges)
		Union(v.second.first, v.second.second, v.first);	// MST (유니온 파인드)

	for (int i = 1; i <= island_num; i++)			// 최종적으로 연결된 섬들 갱신
		Find(i);

	for (int i = 1; i <= island_num; i++) {			// 만약 다리로 연결되지 못한 섬이 존재한다면 바로 -1
		if (parent[i] != 1) {
			cout << -1;
			return 0;
		}
	}
	cout << ans;
	return 0;
}