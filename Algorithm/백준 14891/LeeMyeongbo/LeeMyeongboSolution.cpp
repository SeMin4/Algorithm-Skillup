#include <iostream>
using namespace std;

int K, order[100][2];
char saw[4][9];

void rotate(int rotating_saw, int dir) {
	if (dir == 1) {											// 시계 방향 회전
		int temp = saw[rotating_saw][7];
		for (int i = 6; i >= 0; i--)
			saw[rotating_saw][i + 1] = saw[rotating_saw][i];
		saw[rotating_saw][0] = temp;
	}
	else if (dir == -1) {									// 반시계 방향 회전
		int temp = saw[rotating_saw][0];
		for (int i = 0; i < 7; i++)
			saw[rotating_saw][i] = saw[rotating_saw][i + 1];
		saw[rotating_saw][7] = temp;
	}
}

int Solve() {
	int ans = 0;
	for (int i = 0; i < K; i++) {
		int rotating_saw = order[i][0] - 1;				// 돌리는 톱니
		int saw_list[4] = { 0, };						// 돌리는 톱니바퀴들의 방향 저장용 배열
		int dir = order[i][1];
		saw_list[rotating_saw] = dir;

		for (int j = rotating_saw - 1; j >= 0; j--) {	// 현재 돌리는 톱니의 왼쪽들 먼저 살펴봄
			if (saw[j][2] != saw[j + 1][6]) {			// 다른 극이라면 방향 * -1 해서 저장
				dir *= -1;
				saw_list[j] = dir;
			}
			else break;
		}
		dir = order[i][1];
		for (int j = rotating_saw + 1; j < 4; j++) {	// 오른쪽 살펴봄
			if (saw[j][6] != saw[j - 1][2]) {
				dir *= -1;
				saw_list[j] = dir;
			}
			else break;
		}
		for (int i = 0; i < 4; i++)						// 4개 톱니 차례로 저장된 방향대로 돌림
			rotate(i, saw_list[i]);
	}
	for (int i = 0; i < 4; i++)
		if (saw[i][0] == '1')
			ans += 1 << i;
	return ans;
}

int main() {
	for (int i = 0; i < 4; i++)
		cin >> saw[i];
	cin >> K;
	for (int i = 0; i < K; i++)
		cin >> order[i][0] >> order[i][1];
	cout << Solve();
	return 0;
}