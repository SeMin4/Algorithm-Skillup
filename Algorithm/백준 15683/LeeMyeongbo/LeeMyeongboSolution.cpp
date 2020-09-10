#include <iostream>
using namespace std;

int N, M, map[8][8], check[8][8], cctv, Min = 100;
const int dc[] = { 1, -1, 0, 0 }, dr[] = { 0, 0, 1, -1 };

void Search(int r, int c, int depth, int dir) {			// 입력받은 dir에 따라 살피고 해당 depth로 방문 체크
	int R = r, C = c;
	while (C >= 0 && C < M && R >= 0 && R < N && map[R][C] != 6) {
		if (!check[R][C])
			check[R][C] = depth + 1;
		R += dr[dir], C += dc[dir];
	}
}

void Rewind(int r, int c, int depth, int dir) {			// 입력받은 dir로 살핀 지점 중 해당 depth에서 살핀 지점을 다시 원상복귀
	int R = r, C = c;
	while (C >= 0 && C < M && R >= 0 && R < N && map[R][C] != 6) {
		if (check[R][C] == depth + 1) 
			check[R][C] = 0;
		R += dr[dir], C += dc[dir];
	}
}

void DFS(int depth, int start_r, int start_c) {
	if (depth == cctv) {								// 모든 cctv에서 방향 정하고 체크했으면 사각지대 개수 최솟값 갱신
		int sagak = 0;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				if (!check[i][j] && map[i][j] != 6)
					sagak++;
		Min = sagak < Min ? sagak : Min;
		return;
	}
	for (int i = start_r; i < N; i++) {
		if (i > start_r)
			start_c = 0;
		for (int j = start_c; j < M; j++) {
			if (map[i][j] == 1) {						// 1번 cctv
				for (int d = 0; d < 4; d++) {
					Search(i, j, depth, d);				// 각 방향으로 살피고 DFS
					DFS(depth + 1, i, j + 1);
					Rewind(i, j, depth, d);
				}
			}
			else if (map[i][j] == 2) {					// 2번 cctv
				for (int d = 0; d < 2; d++)				// 동서 방향 먼저 살피고 DFS
					Search(i, j, depth, d);
				DFS(depth + 1, i, j + 1);
				for (int d = 0; d < 2; d++)
					Rewind(i, j, depth, d);
				for (int d = 2; d < 4; d++)				// 그 다음 남북 방향 살피고 DFS
					Search(i, j, depth, d);
				DFS(depth + 1, i, j + 1);
				for (int d = 2; d < 4; d++)
					Rewind(i, j, depth, d);
			}
			else if (map[i][j] == 3) {					// 3번 cctv
				for (int d1 = 0; d1 < 2; d1++) {		// 동 서 각 방향에 대해서
					Search(i, j, depth, d1);
					for (int d2 = 2; d2 < 4; d2++) {	// 남 북 방향으로 살피고 DFS
						Search(i, j, depth, d2);
						DFS(depth + 1, i, j + 1);
						Rewind(i, j, depth, d2);
					}
					Rewind(i, j, depth, d1);
				}
			}
			else if (map[i][j] == 4) {					// 4번 cctv
				for (int d1 = 0; d1 < 4; d1++) {
					for (int d2 = 0; d2 < 4; d2++) {	// 서남북, 동남북, 동서북, 동서남 순으로 살피고 DFS
						if (d1 == d2)
							continue;
						Search(i, j, depth, d2);
					}
					DFS(depth + 1, i, j + 1);
					for (int d2 = 0; d2 < 4; d2++) {
						if (d1 == d2)
							continue;
						Rewind(i, j, depth, d2);
					}
				}
			}
			else if (map[i][j] == 5) {					// 5번 cctv
				for (int d = 0; d < 4; d++)
					Search(i, j, depth, d);				// 모든 방향으로 살피고 DFS
				DFS(depth + 1, i, j + 1);
				for (int d = 0; d < 4; d++)
					Rewind(i, j, depth, d);
			}
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] > 0 && map[i][j] < 6)
				cctv++;
		}
	DFS(0, 0, 0);
	cout << Min << endl;
	return 0;
}