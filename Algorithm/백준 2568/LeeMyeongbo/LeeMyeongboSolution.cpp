#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, a, b, B[100001], chk[100001];		// chk : LIS에서의 B[i]의 index + 1 저장
bool is_connected[100001];
vector<pair<int, int>> wire;
vector<int> LIS;

void Solve() {
	LIS.push_back(B[0]);
	chk[0] = 1;
	for (int i = 1; i < N; i++) {
		int left = 0;							// left : 맨 처음 index
		int right = LIS.size() - 1;				// right : 맨 마지막 index
		while (left <= right) {					// 이분 탐색으로 B[i]가 들어갈 적당한 위치 탐색
			int middle = (left + right) / 2;
			if (LIS[middle] > B[i])
				right = middle - 1;
			else
				left = middle + 1;
		}
		if (left == LIS.size())
			LIS.push_back(B[i]);				// LIS의 마지막 원소보다 B[i]가 크다면 추가 (결과적으로 LIS는 오름차순으로 정렬)
		else
			LIS[left] = B[i];					// 그게 아니면 해당 자리를 B[i]로 바꿈
		chk[i] = left + 1;
	}

	int size = LIS.size();						// LIS의 길이 = 최장 증가 부분 수열의 길이
	printf("%d\n", N - size);
	for (int i = N - 1; i >= 0; i--) {			// 맨 오른쪽에서부터 차례로 LIS에 해당하는 index를 true로 처리
		if (chk[i] == size) {
			size--;
			is_connected[i] = true;
		}
	}
	for (int i = 0; i < N; i++) {
		if (!is_connected[i])
			printf("%d\n", wire[i].first);		// LIS에 해당하지 않는 index의 A 위치 오름차순 출력
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &a, &b);
		wire.push_back(make_pair(a, b));
	}
	sort(wire.begin(), wire.end());			// 먼저 전봇대 A 기준 오름차순으로 전깃줄 정렬
	for (int i = 0; i < N; i++)
		B[i] = wire[i].second;				// 정렬된 전깃줄의 전봇대 B 위치 복사
	Solve();
	return 0;
}