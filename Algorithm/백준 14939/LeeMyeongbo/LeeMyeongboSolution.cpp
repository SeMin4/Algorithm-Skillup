#include <iostream>
#include <cstring>
using namespace std;

char c;
int chk[10][10], ans = -1;
const int dc[] = { 1, -1, 0, 0 }, dr[] = { 0, 0, 1, -1 };

void DFS(int num, int cur_num, int start) {			// 맨 윗줄에서 num개의 스위치 변경한 다음 2번째 ~ 10번째 줄 차례로 살핌
	if (num == cur_num) {
		int tmp_ans = num;							// 맨 윗줄에서 버튼 누른 횟수 기본적으로 포함해야 함!
		int tmp_chk[10][10];
		memcpy(tmp_chk, chk, sizeof(tmp_chk));		// 임시 배열에다 현 상태 복사해 놓고 살핌 (원본 배열 변경 금지)

		for (int i = 1; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				if (!tmp_chk[i - 1][j])
					continue;
				tmp_chk[i][j] = (tmp_chk[i][j] + 1) % 2;
				tmp_ans++;
				for (int d = 0; d < 4; d++) {
					int R = i + dr[d];
					int C = j + dc[d];
					if (R >= 0 && R < 10 && C >= 0 && C < 10)
						tmp_chk[R][C] = (tmp_chk[R][C] + 1) % 2;
				}
			}
		}
		for (int i = 0; i < 100; i++)
			if (tmp_chk[i / 10][i % 10])			// 도중에 하나라도 켜진 게 있다면 실패!
				return;
		if (ans == -1)
			ans = tmp_ans;
		ans = ans > tmp_ans ? tmp_ans : ans;		// 건드린 스위치 갯수 최솟값 갱신
		return;
	}
	for (int c = start; c < 10; c++) {
		chk[0][c] = (chk[0][c] + 1) % 2;					// 맨 윗줄에 해당 스위치 켬
		for (int d = 0; d < 4; d++) {						// 켠 스위치 주변 스위치 켬
			int R = dr[d];
			int C = c + dc[d];
			if (R >= 0 && R < 10 && C >= 0 && C < 10)
				chk[R][C] = (chk[R][C] + 1) % 2;
		}
		DFS(num, cur_num + 1, c + 1);
		chk[0][c] = (chk[0][c] + 1) % 2;					// 켠 스위치 도로 끔
		for (int d = 0; d < 4; d++) {						// 주변도 다시 원상복귀
			int R = dr[d];
			int C = c + dc[d];
			if (R >= 0 && R < 10 && C >= 0 && C < 10)
				chk[R][C] = (chk[R][C] + 1) % 2;
		}
	}
}

int Solve() {
	for (int i = 0; i <= 10; i++) {
		DFS(i, 0, 0);
	}
	return ans;
}

int main() {
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++) {
			cin >> c;
			if (c == '#')
				chk[i][j] = 0;
			else
				chk[i][j] = 1;
		}
	
	cout << Solve();
	return 0;
}