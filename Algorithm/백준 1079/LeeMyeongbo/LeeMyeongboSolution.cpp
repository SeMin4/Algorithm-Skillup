#include <iostream>
using namespace std;

int N, n, maphia, guilty[16], R[16][16], ans;
bool dead[16];		// 죽은 사람 체크

void DFS(int tmp) {
	if (dead[maphia]) {							// 마피아가 죽었다면 밤이 지난 횟수 최댓값 갱신하고 종료
		ans = ans < tmp ? tmp : ans;
		return;
	}
	/*
	bool all_kill = true;
	for (int i = 0; i < N; i++) {
		if (!dead[i] && i != maphia) {			// 죽지 않은 시민이 남아있다면
			all_kill = false;
			break;
		}
	}
	if (all_kill) {								// 시민이 모두 죽었다면 역시 밤 지난 횟수 최댓값 갱신하고 종료
		ans = ans < tmp ? tmp : ans;
		return;
	}
	*/
	if (n % 2 == 0) {							// 밤일 때 마피아가 죽일 사람 한 명 지목
		for (int i = 0; i < N; i++) {
			if (!dead[i] && i != maphia) {
				dead[i] = true;
				for (int j = 0; j < N; j++)
					guilty[j] += R[i][j];
				n--;
				DFS(tmp + 1);					// 밤에서 낮이 될 땐 밤 지난 횟수 +1
				for (int j = 0; j < N; j++)
					guilty[j] -= R[i][j];
				n++;
				dead[i] = false;
			}
		}
	}
	else {										// 낮일 때 유죄 지수 가장 높은 시민 죽임
		int guilt = -1;
		int kill;
		for (int i = 0; i < N; i++) {
			if (!dead[i] && guilt < guilty[i]) {	// 살아 있으면서 유죄 지수가 가장 높은 사람 찾음
				kill = i;
				guilt = guilty[i];
			}
		}
		dead[kill] = true;
		n--;
		DFS(tmp);								// 낮에서 밤 될 땐 밤 지난 횟수 +1 안함
		n++;
		dead[kill] = false;
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> guilty[i];
	for (int i = 0; i < N * N; i++)
		cin >> R[i / N][i % N];
	cin >> maphia;

	n = N;
	DFS(0);
	cout << ans;
	return 0;
}