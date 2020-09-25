#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int N, sheep[1000], ans;

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", sheep + i);
	sort(sheep, sheep + N);

	int night = 0;
	for (int i = N - 1; i >= 0; i--) {		// 오름차순으로 정렬하고 맨 오른쪽에서부터 1씩 빼며 더해가면 됨
		if (sheep[i] - night <= 0)
			break;
		ans += sheep[i] - night++;
	}
	printf("%d", ans);
	return 0;
}