#include <iostream>
#include <cstring>
using namespace std;

const int path[5][21] = {
	{0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40},	// 0번 경로
	{10, 13, 16, 19},		// 1번 경로
	{20, 22, 24},			// 2번 경로
	{30, 28, 27, 26},		// 3번 경로
	{25, 30, 35}			// 4번 경로
};
int order[10], horse[10], ans;

void DFS(int depth) {
	if (depth == 10) {
		int tmp = 0, info[4][2];				// tmp : 현재까지의 합, info[현재 말 번호][0] : 현재 위치한 경로의 번호, info[말 번호][1] : 위치한 지점
		memset(info, 0, sizeof(info));
		for (int i = 0; i < 10; i++) {
			if (info[horse[i]][1] == -1)		// 현재 말이 이미 도착했는데 이동하려고 하는 경우
				return;
			for (int move = 0; move < order[i]; move++) {   // 한 칸씩 움직임
				info[horse[i]][1] += 1;
				if (((info[horse[i]][0] == 1 || info[horse[i]][0] == 3) && info[horse[i]][1] > 3) || (info[horse[i]][0] == 2 && info[horse[i]][1] > 2)) {
					info[horse[i]][0] = 4;
					info[horse[i]][1] = 0;		// 경로 1, 2, 3에서 각각 19, 24, 26을 넘어서게 되면 경로 4로 전환
				}
				else if (info[horse[i]][0] == 4 && info[horse[i]][1] > 2) {
					info[horse[i]][0] = 0;
					info[horse[i]][1] = 20;		// 경로 4에서 35를 넘어가게 되면 경로 0의 40으로 전환
				}
			}
			if (!info[horse[i]][0] && info[horse[i]][1] == 5) {			// 파란색 10에 도착했을 경우 경로 1로 전환
				info[horse[i]][0] = 1;
				info[horse[i]][1] = 0;
			}
			else if (!info[horse[i]][0] && info[horse[i]][1] == 10) {		// 파란색 20에 도착했을 경우 2로 전환
				info[horse[i]][0] = 2;
				info[horse[i]][1] = 0;
			}
			else if (!info[horse[i]][0] && info[horse[i]][1] == 15) {		// 파란색 30에 도착했을 경우 3으로 전환
				info[horse[i]][0] = 3;
				info[horse[i]][1] = 0;
			}
			for (int h = 0; h < 4; h++) {
				if (h != horse[i] && info[horse[i]][0] == info[h][0] && info[horse[i]][1] == info[h][1])	// 현재 말이 다른 말이랑 겹치게 될 경우
					return;
			}
			if (info[horse[i]][1] <= 20)
				tmp += path[info[horse[i]][0]][info[horse[i]][1]];			// 현재 말이 40이하에 있을 경우 더함
			else
				info[horse[i]][1] = -1;										// 이미 도착 지점을 지났다면 -1로 도착 처리
		}
		ans = ans < tmp ? tmp : ans;
		return;
	}

	for (int i = 0; i < 4; i++) {
		horse[depth] = i;
		DFS(depth + 1);
	}
}

int main() {
	for (int i = 0; i < 10; i++)
		cin >> order[i];
	DFS(0);
	cout << ans;
	return 0;
}
