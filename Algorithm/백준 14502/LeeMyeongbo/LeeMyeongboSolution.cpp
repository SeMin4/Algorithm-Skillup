#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

struct Node {
	int y, x;
};
int N, M, map[8][8], ans = -1, dx[] = { 1, -1, 0, 0 }, dy[] = { 0, 0, 1, -1 };

int BFS() {
	int temp = 0;
	queue<Node> q;
	bool visited[8][8];									// 바이러스 방문 체크
	memset(visited, false, sizeof(visited));
	for(int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 2) {						// 초기 바이러스 위치 큐에 삽입
				q.push({ i, j });
				visited[i][j] = true;
			}
		}
	while (!q.empty()) {
		Node node = q.front();
		q.pop();

		for (int d = 0; d < 4; d++) {
			int X = node.x + dx[d];
			int Y = node.y + dy[d];
			if (X >= 0 && X < M && Y >= 0 && Y < N && !visited[Y][X] && !map[Y][X]) {	// 바이러스 방문하지 않은 곳 + 빈칸 이면 바이러스 퍼짐
				visited[Y][X] = true;
				q.push({ Y, X });
			}
		}
	}
	for(int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (!map[i][j] && !visited[i][j])			// 빈칸이면서 바이러스 퍼지지 못한 곳 개수 헤아려서 리턴
				temp++;
	return temp;
}

void DFS(int depth, int start_row, int start_col) {		// 빈 칸 중에서 3개를 조합 방식으로 뽑아서 벽으로 만듦
	if (depth == 3) {									// 빈 칸 3개 모두 벽으로 만들었으면 바이러스 퍼뜨림
		int num = BFS();
		ans = ans < num ? num : ans;					// 최댓값 갱신
		return;
	}
	for (int i = start_row; i < N; i++) {
		if (i > start_row)
			start_col = 0;
		for (int j = start_col; j < M; j++) {
			if (!map[i][j]) {
				map[i][j] = 1;							// 빈칸을 벽으로
				DFS(depth + 1, i, j + 1);
				map[i][j] = 0;							// 벽으로 만든 빈칸 원상복귀
			}
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];
	DFS(0, 0, 0);
	cout << ans;
	return 0;
}