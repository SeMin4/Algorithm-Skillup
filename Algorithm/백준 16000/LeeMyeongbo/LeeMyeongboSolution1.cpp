#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

// BFS와 단절점을 이용한 풀이
struct Node {
	int y, x;
};
int N, M, island_num[2000][2000], dx[] = { 1, -1, 0, 0 }, dy[] = { 0, 0, 1, -1 }, cnt, discovered[4000000];
char map[2000][2001];
bool visited[2000][2000], is_X[4000000], is_sea[4000000];
vector<vector<int>> graph;
vector<int> passed_v;

void numbering() {										// 섬, 바다 번호 매김
	memset(island_num, -1, sizeof(island_num));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (island_num[i][j] != -1)
				continue;
			queue<Node> q;
			q.push({ i, j });
			island_num[i][j] = cnt;
			while (!q.empty()) {
				Node node = q.front();
				q.pop();

				for (int d = 0; d < 4; d++) {
					int X = node.x + dx[d];
					int Y = node.y + dy[d];
					if (X >= 0 && X < M && Y >= 0 && Y < N && island_num[Y][X] == -1 && map[Y][X] == map[i][j]) {
						q.push({ Y, X });
						island_num[Y][X] = cnt;
					}
				}
			}
			cnt++;
		}
	}
}

void building_graph() {							// 해당 번호를 토대로 그래프 형성
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visited[i][j])
				continue;
			queue<Node> q;
			q.push({ i, j });
			visited[i][j] = true;
			if (map[i][j] == '.')
				is_sea[island_num[i][j]] = true;
			vector<int> v;
			graph.push_back(v);
			while (!q.empty()) {
				Node node = q.front();
				q.pop();

				for (int d = 0; d < 4; d++) {
					int X = node.x + dx[d];
					int Y = node.y + dy[d];
					if (X >= 0 && X < M && Y >= 0 && Y < N) {
						if (!visited[Y][X] && island_num[Y][X] == island_num[node.y][node.x]) {
							q.push({ Y, X });
							visited[Y][X] = true;
						}
						else if (island_num[Y][X] != island_num[i][j] && discovered[island_num[Y][X]] < island_num[i][j] + 1) {
							graph[island_num[i][j]].push_back(island_num[Y][X]);
							discovered[island_num[Y][X]] = island_num[i][j] + 1;
						}
					}
				}
			}
		}
	}
}

void find_Arti_point(int V) {				// 형성한 그래프를 토대로 단절점인 정점 탐색 + 단절점 찾았을 시 역추적
	discovered[V] = ++cnt;
	int num = discovered[V];
	passed_v.push_back(V);

	for (auto next : graph[V]) {
		if (!discovered[next]) {
			find_Arti_point(next);
			if (!is_sea[V] && discovered[next] == discovered[V]) {		// 육지인 단절점 발견 시
				while (!passed_v.empty() && passed_v.back() != V) {		// 해당 단절점 만날 때까지 거친 정점(subtree)들 역추적
					is_X[passed_v.back()] = true;
					passed_v.pop_back();
				}
			}
			passed_v.push_back(V);
		}
		num = num > discovered[next] ? discovered[next] : num;
	}
	discovered[V] = num;
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
		scanf("%s", map[i]);

	numbering();
	building_graph();

	cnt = 0;
	passed_v.reserve(4000001);
	memset(discovered, 0, sizeof(discovered));
	find_Arti_point(0);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == '.')
				printf(".");
			else {
				if (is_X[island_num[i][j]] && discovered[island_num[i][j]] != 1)	// X로 표시되는 섬들 중 최외곽은 제외
					printf("X");
				else
					printf("O");
			}
		}
		printf("\n");
	}
	return 0;
}