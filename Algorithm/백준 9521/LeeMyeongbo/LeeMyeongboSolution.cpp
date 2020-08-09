#include <iostream>
using namespace std;

int N, f[1000001], visited[1000001], cycle_start, cycle_depth;
unsigned long long K, color[1000001], ans = 1;

void DFS(int index, int depth, int cycle_num) {
	if (!visited[index]) {								// 해당 정점을 방문한 적이 없다면
		visited[index] = cycle_num;						// 그 정점에 사이클 번호 일단 저장
		DFS(f[index], depth + 1, cycle_num);			// f[i]번 정점으로 다시 탐색
		if (cycle_start == index) {						// 사이클 시작 정점 발견 시
			int cycle_length = cycle_depth - depth;		// 시작 정점 재발견 했을 때 깊이에서 시작 정점 처음 발견 시 깊이를 빼서 사이클 길이 구함
			ans = ans * color[cycle_length] % 1000000007;
			cycle_start = cycle_depth = 0;				// 사이클 시작 정점과 깊이 다시 원래대로 돌림
		}
		else if (!cycle_start) {						// 사이클 시작 정점이 0이라면 현재 정점은 사이클이 아닌 것임
			ans = ans * (K - 1) % 1000000007;
		}
	}
	else if (visited[index] == cycle_num) {			// 방문한 정점에 이미 같은 사이클 번호가 저장되어 있을 경우
		cycle_start = index;						// 그 정점이 바로 사이클 시작 정점
		cycle_depth = depth;						// 사이클 길이 알기 위해 깊이도 같이 저장
	}
}

unsigned long long Solve() {
	int cycle_num = 1;					// 사이클 번호 (1부터 시작)
	for (int i = 1; i <= N; i++) {
		DFS(i, 0, cycle_num);
		cycle_num++;
	}
	return ans;
}

int main() {
	cin >> N >> K;
	for (int i = 1; i <= N; i++)
		scanf("%d", f + i);
	color[1] = K;
	color[2] = K * (K - 1) % 1000000007;
	color[3] = K * (K - 1) * (K - 2) % 1000000007;
	for (int i = 4; i <= 1000000; i++)
		color[i] = ((K - 1) * color[i - 2] + (K - 2) * color[i - 1]) % 1000000007;		// DP 테이블 채움
	cout << Solve();
	return 0;
}