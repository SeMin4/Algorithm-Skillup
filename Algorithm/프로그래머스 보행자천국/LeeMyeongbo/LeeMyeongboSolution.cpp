#include <vector>
using namespace std;
                                                       // tmp[0][r][c] : 오른쪽으로 (r,c)에 도달할 때의 경로 수
int MOD = 20170805, dp[500][500], tmp[2][500][500];    // tmp[1][r][c] : 아래쪽으로 (r,c)에 도달할 때의 경로 수
                                                       // dp[r][c] : (r,c)로 올 때의 총 경로 수 저장
int solution(int m, int n, vector<vector<int>> city_map) {
    dp[0][0] = 1;
    tmp[0][0][0] = tmp[1][0][0] = 0;

    bool is_blocked = false;
    for (int i = 1; i < n; i++) {                           // city_map에서 맨 윗줄 처리
        if (city_map[0][i] != 1 && !is_blocked) {
            dp[0][i] = tmp[0][0][i] = 1;
            tmp[1][0][i] = 0;
        }
        else {                                              // 통행금지 위치를 만나면 그 뒤에 칸 모두 0으로 처리
            is_blocked = true;
            dp[0][i] = tmp[0][0][i] = tmp[1][0][i] = 0;
        }
    }
    is_blocked = false;
    for (int i = 1; i < m; i++) {                           // city_map에서 맨 왼쪽 줄 처리
        if (city_map[i][0] != 1 && !is_blocked) {
            dp[i][0] = tmp[1][i][0] = 1;
            tmp[0][i][0] = 0;
        }
        else {                                              // 통행금지 위치를 만나면 그 밑에 칸 모두 0으로 처리
            is_blocked = true;
            dp[i][0] = tmp[0][i][0] = tmp[1][i][0] = 0;
        }
    }

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (city_map[i][j] == 1)                                        // 현재 위치가 통행금지 위치면 dp와 tmp 모두 0으로 함
                dp[i][j] = tmp[0][i][j] = tmp[1][i][j] = 0;
            else if (city_map[i - 1][j] != 2 && city_map[i][j - 1] != 2) {  // 현재 위치의 바로 위쪽 위치와 왼쪽 위치가 모두 교차로 금지가 아닐 때
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;             // 위쪽 칸에 이르기까지 경로의 합과 왼쪽 칸에 이르기까지 경로의 합 더함
                tmp[0][i][j] = dp[i][j - 1];
                tmp[1][i][j] = dp[i - 1][j];
            }
            else if (city_map[i - 1][j] != 2 && city_map[i][j - 1] == 2) {  // 현재 위치의 왼쪽 위치만이 교차로 금지일 때
                dp[i][j] = (dp[i - 1][j] + tmp[0][i][j - 1]) % MOD;         // 오른쪽으로 왼쪽 칸에 도달할 때의 경로 수 + 위쪽 칸의 경로 수
                tmp[0][i][j] = tmp[0][i][j - 1];
                tmp[1][i][j] = dp[i - 1][j];
            }
            else if (city_map[i - 1][j] == 2 && city_map[i][j - 1] != 2) {  // 현재 위치의 위쪽 위치만이 교차로 금지일 때
                dp[i][j] = (tmp[1][i - 1][j] + dp[i][j - 1]) % MOD;         // 아래쪽으로 위쪽 칸에 도달할 때의 경로 수 + 왼쪽 칸의 경로 수
                tmp[0][i][j] = dp[i][j - 1];
                tmp[1][i][j] = tmp[1][i - 1][j];
            }
            else {                                                          // 현재 위치에서 왼쪽과 위쪽 모두 교차로 금지일 경우
                dp[i][j] = (tmp[1][i - 1][j] + tmp[0][i][j - 1]) % MOD;     // 오른쪽으로 왼쪽 칸에 도달할 때의 경로 수 + 아래쪽으로 위쪽 칸에 도달할 때의 경로 수
                tmp[0][i][j] = tmp[0][i][j - 1];
                tmp[1][i][j] = tmp[1][i - 1][j];
            }
        }
    }
    return dp[m - 1][n - 1];
}