#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node {
    int r, c, cnt;              // 가로 방향일 땐 왼쪽의, 세로 방향일 땐 위쪽의 좌표
    bool garo;                  // 가로면 true, 세로면 false
};
queue<Node> q;
bool visited[2][100][100];      // 가로 방향일 때는 [0][r][c]에, 세로 방향일 땐 [1][r][c]에 방문 체크

int solution(vector<vector<int>> board) {
    int N = board.size();
    int dir[2] = { 1, -1 };
    q.push({ 0, 0, 0, true });
    visited[0][0][0] = true;

    while (!q.empty()) {
        Node node = q.front();
        q.pop();
        if ((node.r + 1 == N - 1 && node.c == N - 1) || (node.r == N - 1 && node.c + 1 == N - 1))
            return node.cnt;
        if (node.garo) {                                                                                // 가로 모양일 경우
            if (node.c + 2 < N && !visited[0][node.r][node.c + 1] && !board[node.r][node.c + 2]) {      // 동쪽으로 이동 시
                visited[0][node.r][node.c + 1] = true;
                q.push({ node.r, node.c + 1, node.cnt + 1, true });
            }
            if (node.c - 1 >= 0 && !visited[0][node.r][node.c - 1] && !board[node.r][node.c - 1]) {     // 서쪽으로 이동 시
                visited[0][node.r][node.c - 1] = true;
                q.push({ node.r, node.c - 1, node.cnt + 1, true });
            }
            for (int d = 0; d < 2; d++) {
                int R = node.r + dir[d];
                if (R >= 0 && R < N && !visited[0][R][node.c] && !board[R][node.c] && !board[R][node.c + 1]) {    // 남쪽, 북쪽으로 이동 시
                    visited[0][R][node.c] = true;
                    q.push({ R, node.c, node.cnt + 1, true });
                }
            }
            if (node.r + 1 < N && !board[node.r + 1][node.c] && !board[node.r + 1][node.c + 1]) {       // 맨 밑이 아니면서 로봇 아래 2칸이 빈 칸일 경우
                if (!visited[1][node.r][node.c]) {                                                      // 왼쪽 축 기준으로 시계 방향 회전 시
                    visited[1][node.r][node.c] = true;
                    q.push({ node.r, node.c, node.cnt + 1, false });
                }
                if (!visited[1][node.r][node.c + 1]) {                                                  // 오른쪽 축 기준으로 반시계 방향 회전 시
                    visited[1][node.r][node.c + 1] = true;
                    q.push({ node.r, node.c + 1, node.cnt + 1, false });
                }
            }
            if (node.r - 1 >= 0 && !board[node.r - 1][node.c] && !board[node.r - 1][node.c + 1]) {      // 맨 위가 아니면서 로봇 위 2칸이 빈 칸일 경우
                if (!visited[1][node.r - 1][node.c]) {                                                  // 왼쪽 축 기준으로 반시계 방향 회전 시
                    visited[1][node.r - 1][node.c] = true;
                    q.push({ node.r - 1, node.c, node.cnt + 1, false });
                }
                if (!visited[1][node.r - 1][node.c + 1]) {                                              // 오른쪽 축 기준으로 시계 방향 회전 시
                    visited[1][node.r - 1][node.c + 1] = true;
                    q.push({ node.r - 1, node.c + 1, node.cnt + 1, false });
                }
            }
        }
        else {                                                                                          // 세로 모양일 경우
            for (int d = 0; d < 2; d++) {
                int C = node.c + dir[d];
                if (C >= 0 && C < N && !board[node.r][C] && !board[node.r + 1][C] && !visited[1][node.r][C]) {      // 동쪽, 서쪽으로 이동 시
                    visited[1][node.r][C] = true;
                    q.push({ node.r, C, node.cnt + 1, false });
                }
            }
            if (node.r + 2 < N && !board[node.r + 2][node.c] && !visited[1][node.r + 1][node.c]) {      // 남쪽으로 이동할 경우
                visited[1][node.r + 1][node.c] = true;
                q.push({ node.r + 1, node.c, node.cnt + 1, false });
            }
            if (node.r - 1 >= 0 && !board[node.r - 1][node.c] && !visited[1][node.r - 1][node.c]) {     // 북쪽으로 이동할 경우
                visited[1][node.r - 1][node.c] = true;
                q.push({ node.r - 1, node.c, node.cnt + 1, false });
            }
            if (node.c - 1 >= 0 && !board[node.r][node.c - 1] && !board[node.r + 1][node.c - 1]) {      // 맨 왼쪽이 아니면서 로봇 왼쪽 2칸이 빈 칸일 경우
                if (!visited[0][node.r][node.c - 1]) {                                                  // 위쪽 축 기준으로 시계 방향 회전 시
                    visited[0][node.r][node.c - 1] = true;
                    q.push({ node.r, node.c - 1, node.cnt + 1, true });
                }
                if (!visited[0][node.r + 1][node.c - 1]) {                                              // 아래쪽 축 기준으로 반시계 방향 회전 시
                    visited[0][node.r + 1][node.c - 1] = true;
                    q.push({ node.r + 1, node.c - 1, node.cnt + 1, true });
                }
            }
            if (node.c + 1 < N && !board[node.r][node.c + 1] && !board[node.r + 1][node.c + 1]) {       // 맨 오른쪽이 아니면서 로봇 오른쪽 2칸이 빈 칸일 경우
                if (!visited[0][node.r][node.c]) {                                                      // 위쪽 축 기준으로 반시계 방향 회전 시
                    visited[0][node.r][node.c] = true;
                    q.push({ node.r, node.c, node.cnt + 1, true });
                }
                if (!visited[0][node.r + 1][node.c]) {                                                  // 아래쪽 축 기준으로 시계 방향 회전 시
                    visited[0][node.r + 1][node.c];
                    q.push({ node.r + 1, node.c, node.cnt + 1, true });
                }
            }
        }
    }
    return 0;
}