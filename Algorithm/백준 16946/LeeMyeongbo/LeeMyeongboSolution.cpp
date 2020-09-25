#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<pair<int, int>> v;
queue<pair<int, int>> q;
char map[1000][1001];
bool visited[1000][1000];
int N, M, ans[1000][1000], dc[] = { 1, -1, 0, 0 }, dr[] = { 0, 0, 1, -1 };

void Solve() {
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < M; c++) {
			if (map[r][c] == '1')							// ÇöÀç À§Ä¡°¡ º®ÀÌ¶ó¸é +1
				ans[r][c] = (ans[r][c] + 1) % 10;
			else if (map[r][c] == '0' && !visited[r][c]) {	// ÇöÀç À§Ä¡°¡ Å½»öÇÑ Àû ¾ø´Â ºóÄ­ÀÌ¶ó¸é
				q.push(make_pair(r, c));
				visited[r][c] = true;
				int num = 0;								// ¿¬°áµÈ ºóÄ­ °¹¼ö Çì¾Æ¸²

				while (!q.empty()) {						// ºóÄ­À» BFS·Î Å½»ö
					int cur_r = q.front().first;
					int cur_c = q.front().second;
					q.pop();
					num++;

					for (int d = 0; d < 4; d++) {
						int R = cur_r + dr[d];
						int C = cur_c + dc[d];
						if (R >= 0 && R < N && C >= 0 && C < M && !visited[R][C]) {
							visited[R][C] = true;				// ¹æ¹® Ã¼Å©
							if (map[R][C] == '1')
								v.push_back(make_pair(R, C));	// ºóÄ­ ÁÖÀ§¿¡ º®Àº º¤ÅÍ¿¡ ÀúÀå
							else
								q.push(make_pair(R, C));		// ºóÄ­Àº Å¥¿¡ ÀúÀå
						}
					}
				}

				while (!v.empty()) {							// ÀúÀåµÈ º®À» ÇÏ³ªÇÏ³ª »©¸é¼­ Å½»öÇÑ ºóÄ­ °¹¼ö¸¦ ´õÇÔ
					int wall_r = v.back().first;
					int wall_c = v.back().second;
					visited[wall_r][wall_c] = false;
					ans[wall_r][wall_c] = (ans[wall_r][wall_c] + num) % 10;
					v.pop_back();
				}
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			printf("%d", ans[i][j]);
		printf("\n");
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		scanf("%s", map[i]);
	Solve();
	return 0;
}