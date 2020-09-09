#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#define MAX 100001;
using namespace std;

struct Node {
	int r, c, cnt;		// 현재 행, 열, 열었는 문 개수
};
queue<Node> q[3];		// 맵 바깥에서 시작하는 상근이 + 죄수 2명 총 3가지 경우 각각에 대해서 BFS를 수행하기 위해 큐 배열 선언
int T, h, w, weight[3][102][102], dc[] = { 1, -1, 0, 0 }, dr[] = { 0, 0, 1, -1 }, ans = MAX;
char map[105][105];

void BFS() {
	for (int human = 0; human < 3; human++) {		// 상근이, 죄수 1, 죄수 2 순으로 각 지점에 이르기까지 열어야 하는 문의 최수 개수 weight에 저장
		while (!q[human].empty()) {
			Node node = q[human].front();
			q[human].pop();
			
			for (int d = 0; d < 4; d++) {
				int R = node.r + dr[d];
				int C = node.c + dc[d];
				if (R >= 0 && R < h + 2 && C >= 0 && C < w + 2 && map[R][C] != '*') {
					if (map[R][C] == '.' && weight[human][R][C] > node.cnt) {				// 빈 칸이면 문 여태까지 열었는 문 횟수 그대로
						q[human].push({ R, C, node.cnt });
						weight[human][R][C] = node.cnt;
					}
					else if (map[R][C] == '#' && weight[human][R][C] > node.cnt + 1) {		// 문을 만났다면 열었는 문 횟수 + 1
						q[human].push({ R, C, node.cnt + 1 });
						weight[human][R][C] = node.cnt + 1;
					}
				}
			}
		}
	}
	for (int i = 1; i < h + 1; i++) {
		for (int j = 1; j < w + 1; j++) {
			int temp = weight[0][i][j] + weight[1][i][j] + weight[2][i][j];
			if (map[i][j] == '#')				// 문이 있는 지점이라면 상근이, 죄수 1, 죄수 2 이렇게 횟수가 2번 더 중첩되므로 -2 해줘야 함
				temp -= 2;
			ans = ans > temp ? temp : ans;		// 최솟값 갱신
		}
	}
}

int main() {
	cin >> T;
	for (int t = 0; t < T; t++) {				// 맵 가장자리 부분을 '.'(빈칸)으로 둘러싸고 시작
		scanf("%d %d", &h, &w);
		for (int f = 0; f < 3; f++)
			for (int r = 0; r < h + 2; r++)
				for (int c = 0; c < w + 2; c++)
					weight[f][r][c] = MAX;

		q[0].push({ 0, 0, 0 });					// 맨 처음에 상근이가 맵 바깥 (0, 0)에서 시작하는 경우부터 큐에 넣음
		weight[0][0][0] = 0;
		int index = 1;
		for (int i = 0; i < w + 2; i++)			// 맵 제일 위쪽 변에 '.' 추가
			map[0][i] = '.';
		for (int i = 1; i < h + 1; i++) {		// 맵 제일 왼쪽과 오른쪽 변에 '.' 추가하고 동시에 죄수 2명 위치 큐에 삽입
			map[i][0] = '.';					// 왼쪽 변 '.' 추가
			scanf("%s", map[i] + 1);
			for (int j = 0; j < w + 1; j++) {
				if (map[i][j] == '$') {
					q[index].push({ i, j, 0 });
					weight[index++][i][j] = 0;
					map[i][j] = '.';
				}
			}
			map[i][w + 1] = '.';				// 오른쪽 변 '.' 추가
		}
		for (int i = 0; i < w + 2; i++)			// 제일 아래쪽 변 '.' 추가
			map[h + 1][i] = '.';

		BFS();
		printf("%d\n", ans);
		ans = MAX;
	}
	return 0;
}