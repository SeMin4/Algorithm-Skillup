#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
using namespace std;

// 순수 BFS를 이용한 풀이
struct Node {
	int y, x;
};
int N, M, island_num[2000][2000], tot = 1;
const int dx[] = { 1, -1, 0, 0, 1, -1, -1, 1 }, dy[] = { 0, 0, 1, -1, 1, 1, -1, -1 };	// 동 서 남 북 동남 서남 서북 동북 순
char map[2000][2001];
bool visited[2000][2000], searched_island[4000001];			// 바다를 따라 너비 탐색하며 찾은 섬을 searched_island에 체크

void indexing() {							// 섬들마다 번호 부여
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (island_num[i][j] > 0 || map[i][j] == '.')		// 이미 번호를 매겼거나 바다라면 skip
				continue;
			queue<Node> q;
			q.push({ i, j });
			island_num[i][j] = tot;

			while (!q.empty()) {
				Node node = q.front();
				q.pop();

				for (int d = 0; d < 4; d++) {
					int X = node.x + dx[d];
					int Y = node.y + dy[d];
					if (X >= 0 && X < M && Y >= 0 && Y < N && !island_num[Y][X] && map[Y][X] == '#') {
						q.push({ Y, X });
						island_num[Y][X] = tot;
					}
				}
			}
			tot++;
		}
	}
}

void search() {
	queue<Node> q;
	q.push({ 0, 0 });
	visited[0][0] = true;

	while (!q.empty()) {
		Node node = q.front();
		q.pop();

		for (int d = 0; d < 8; d++) {					// 8방향으로 살펴봄
			int X = node.x + dx[d];
			int Y = node.y + dy[d];
			if (X >= 0 && X < M && Y >= 0 && Y < N && !visited[Y][X]) {
				if (map[Y][X] == '.') {
					if (d < 4)							// 처음 동 서 남 북 이렇게 살필 때는 근처 바다 있으면 큐에 삽입
						q.push({ Y, X });
					else if (d >= 4 && map[Y][node.x] == '#' && map[node.y][X] == '#') {	// 대각선 방향 탐색 시 주위에 섬이 있는 경우 고려
						if (island_num[Y][node.x] != island_num[node.y][X]) {				// 주위 섬이 같은 섬이 아니면 내부 바다로
							q.push({ Y, X });
							searched_island[island_num[Y][node.x]] = searched_island[island_num[node.y][X]] = true;
						}
					}
					else								// 주위에 섬이 1개 이하이면 그대로 진행
						q.push({ Y, X });
				}
				else
					searched_island[island_num[Y][X]] = true;
				visited[Y][X] = true;
			}
		}
	}
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
		scanf("%s", map[i]);
	indexing();
	search();

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == '.')
				printf(".");
			else {
				if (searched_island[island_num[i][j]])
					printf("O");
				else
					printf("X");
			}
		}
		printf("\n");
	}
	return 0;
}