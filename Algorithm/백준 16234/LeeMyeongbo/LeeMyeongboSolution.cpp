#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;

struct Node {
	int r, c;
};
int N, Min, Max, map[50][50], ans;
const int dc[] = { 1, -1, 0, 0 }, dr[] = { 0, 0, 1, -1 };
bool visited[50][50];

int BFS() {
	while (true) {
		bool move = false;					// 인구 이동이 일어났는지 여부
		for (int r = 0; r < N; r++) {
			for (int c = 0; c < N; c++) {
				if (visited[r][c])
					continue;
				vector<Node> v;				// BFS를 통해 살핀 칸 저장용 벡터
				queue<Node> q;				// BFS용 큐
				int tot = 0;
				q.push({ r, c });
				visited[r][c] = true;

				while (!q.empty()) {
					Node node = q.front();
					v.push_back(node);
					tot += map[node.r][node.c];
					q.pop();

					for (int d = 0; d < 4; d++) {
						int C = node.c + dc[d];
						int R = node.r + dr[d];
						if (R >= 0 && R < N && C >= 0 && C < N && !visited[R][C]) {
							int gap = abs(map[R][C] - map[node.r][node.c]);
							if (gap >= Min && gap <= Max) {
								visited[R][C] = true;
								move = true;			// 인구 이동 발생
								q.push({ R, C });
							}
						}
					}
				}
				for (Node n : v)
					map[n.r][n.c] = tot / v.size();
			}
		}
		if (!move)
			return ans;									// 모든 칸을 살펴도 인구 이동이 일어나지 않았으면 여태 움직인 횟수 리턴
		ans++;
		memset(visited, false, sizeof(visited));		// 방문 초기화
	}
}

int main() {
	scanf("%d %d %d", &N, &Min, &Max);
	for (int i = 0; i < N * N; i++)
		scanf("%d", &map[i / N][i % N]);
	printf("%d", BFS());
	return 0;
}