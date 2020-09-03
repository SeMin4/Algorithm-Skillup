#include <iostream>
#include <queue>
#define MAX 500001
using namespace std;

struct Node {
	int cur, time;
};
queue<Node> q;
int n, k, visited[2][MAX], ans = MAX;					// visited[0][n] : 짝수 초 최소 시간, visited[1][n] : 홀수 초 최소 시간
														// 만약 어느 지점에 최소 N초만에 도달했다고 하면 (N + 2)초, (N + 4)초, ... 에도 재방문 가능!
void BFS() {
	for (int i = 0; i < MAX; i++) {
		visited[0][i] = visited[1][i] = MAX;
	}
	q.push({ n, 0 });
	visited[0][n] = 0;
	int cur_time = 0, weight = 1;

	while (!q.empty()) {
		Node node = q.front();
		q.pop();
		if (node.time != cur_time) {					// 현재 시간 내에 수빈이가 할 수 있는 모든 이동을 완료했을 경우 동생 이동 및 현재 시간 증가
			k += weight++;
			cur_time++;
		}
		if (k < MAX) {
			if (visited[0][k] <= cur_time && cur_time % 2 == 0) {		// 현재 시간이 짝수이고 해당 지점까지 가는데 걸리는 최소 짝수 시간이 현재 시간 이하일 경우
				ans = cur_time;
				return;
			}
			else if (visited[1][k] <= cur_time && cur_time % 2 != 0) {	// 현재 시간이 홀수이고 해당 지점까지 가는데 걸리는 최소 홀수 시간이 현재 시간 이하일 경우
				ans = cur_time;
				return;
			}
		}
		else if (k >= MAX)												// 동생 위치가 500000을 넘어서게 되면 바로 종료
			return;
		if (node.cur - 1 >= 0) {										// -1 이동 가능할 때
			if ((node.time + 1) % 2 == 0 && visited[0][node.cur - 1] > node.time + 1) {			// 최소 짝수 시간 갱신 및 큐 삽입, 방문 체크
				q.push({ node.cur - 1, node.time + 1 });
				visited[0][node.cur - 1] = node.time + 1;
			}
			else if ((node.time + 1) % 2 != 0 && visited[1][node.cur - 1] > node.time + 1) {	// 최소 홀수 시간 갱신 및 큐 삽입, 방문 체크
				q.push({ node.cur - 1, node.time + 1 });
				visited[1][node.cur - 1] = node.time + 1;
			}
		}
		if (node.cur + 1 < MAX) {										// +1 이동 가능할 때
			if ((node.time + 1) % 2 == 0 && visited[0][node.cur + 1] > node.time + 1) {
				q.push({ node.cur + 1, node.time + 1 });
				visited[0][node.cur + 1] = node.time + 1;
			}
			else if ((node.time + 1) % 2 != 0 && visited[1][node.cur + 1] > node.time + 1) {
				q.push({ node.cur + 1, node.time + 1 });
				visited[1][node.cur + 1] = node.time + 1;
			}
		}
		if (node.cur * 2 < MAX) {										// *2 이동 가능할 때
			if ((node.time + 1) % 2 == 0 && visited[0][node.cur * 2] > node.time + 1) {
				q.push({ node.cur * 2, node.time + 1 });
				visited[0][node.cur * 2] = node.time + 1;
			}
			else if ((node.time + 1) % 2 != 0 && visited[1][node.cur * 2] > node.time + 1) {
				q.push({ node.cur * 2, node.time + 1 });
				visited[1][node.cur * 2] = node.time + 1;
			}
		}
	}
}

int main() {
	cin >> n >> k;
	BFS();
	if (ans == MAX)
		cout << -1;
	else
		cout << ans;
	return 0;
}