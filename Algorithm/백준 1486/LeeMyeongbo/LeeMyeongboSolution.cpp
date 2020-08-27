#include <iostream>
#include <cmath>
#include <queue>
#define MAX 1000000000								// 다익스트라 초기 최댓값
using namespace std;

struct Node {
	int y, x, time;
};
queue<Node> q;
int N, M, T, D, height[25][25], visited[25][25], r_visited[25][25];		// visited : (0, 0)에서 각 지점까지 걸리는 시간의 최솟값 저장
const int dx[] = { 1, -1, 0, 0 }, dy[] = { 0, 0, 1, -1 };				// r_visited : 각 지점에서 (0, 0)으로 돌아올 때 걸리는 시간의 최솟값 저장
char map[25][26];

void Start() {							// (0, 0)에서 출발하여 각 지점까지 가는 데 걸리는 시간의 최솟값 저장
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			visited[i][j] = MAX;
	q.push({ 0, 0, 0 });
	visited[0][0] = 0;
	
	while (!q.empty()) {
		Node node = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int X = node.x + dx[i];
			int Y = node.y + dy[i];
			if (X >= 0 && X < M && Y >= 0 && Y < N && abs(height[node.y][node.x] - height[Y][X]) <= T) {
				int time_spent = node.time;
				if (height[Y][X] > height[node.y][node.x])		// 가려는 곳의 높이가 현재 위치한 높이보다 높을 경우
					time_spent += (height[Y][X] - height[node.y][node.x]) * (height[Y][X] - height[node.y][node.x]);
				else
					time_spent += 1;
				if (time_spent < visited[Y][X]) {
					q.push({ Y, X, time_spent });
					visited[Y][X] = time_spent;
				}
			}
		}
	}
}

int go_Back() {						// 다시 (0, 0)에서부터 시작하여 역으로 계산해 나감
	int h = -1;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			r_visited[i][j] = MAX;
	q.push({ 0, 0, 0 });
	r_visited[0][0] = 0;

	while (!q.empty()) {
		Node node = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int X = node.x + dx[i];
			int Y = node.y + dy[i];
			if (X >= 0 && X < M && Y >= 0 && Y < N && abs(height[node.y][node.x] - height[Y][X]) <= T) {
				int time_spent = node.time;
				if (height[Y][X] < height[node.y][node.x])		// 가려는 곳의 높이가 현재 위치보다 낮을 경우 (돌아올 때는 역으로 계산해야 함)
					time_spent += (height[Y][X] - height[node.y][node.x]) * (height[Y][X] - height[node.y][node.x]);
				else
					time_spent += 1;
				if (time_spent < r_visited[Y][X]) {
					q.push({ Y, X, time_spent });
					r_visited[Y][X] = time_spent;
				}
			}
		}
	}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (visited[i][j] + r_visited[i][j] <= D)
				h = h < height[i][j] ? height[i][j] : h;
	return h;
}

int main() {
	cin >> N >> M >> T >> D;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] <= 'Z')
				height[i][j] = map[i][j] - 'A';
			else if (map[i][j] <= 'z')
				height[i][j] = map[i][j] - 'a' + 26;
		}
	}
	Start();
	cout << go_Back();
	return 0;
}