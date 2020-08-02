#include <iostream>
#include <algorithm>
using namespace std;

int N, M, mem[101], cost[101], dp[101][10001], ans = 1000000;

int Knapsack() {
	for (int app = 1; app <= N; app++) {		// 1번째 앱부터 i번째 앱까지 고를 수 있을 때
		for (int c = 0; c <= 10000; c++) {		// 감당할 수 있는 비용 0부터 시작
			if (c < cost[app])					// 만약 app번째의 앱의 비용이 현재 감당할 수 있는 비용(c)보다 작을 경우
				dp[app][c] = dp[app - 1][c];	// app - 1번째까지 골랐을 때 최대 메모리를 저장
			else {
				dp[app][c] = max(dp[app - 1][c - cost[app]] + mem[app], dp[app - 1][c]);	// app번째 앱 골랐을 때랑 고르지 않았을 때 중 더 큰 메모리 저장
				if (dp[app][c] >= M)			// 만약 저장된 메모리 값이 M 이상이라면
					ans = min(ans, c);			// 비용 최솟값 갱신
			}
		}
	}
	return ans;
}

int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		cin >> mem[i];
	for (int i = 1; i <= N; i++)
		cin >> cost[i];
	cout << Knapsack();
	return 0;
}