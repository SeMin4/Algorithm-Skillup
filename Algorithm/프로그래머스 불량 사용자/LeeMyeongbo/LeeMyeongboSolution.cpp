#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool visited[8];
int user_size, banned_size, answer;
vector<int> visited_strings;            // 찾은 문자열들의 index를 비트 연산(왼쪽 시프트)을 통해 계산하여 저장

void DFS(int depth, vector<string>& user_id, vector<string>& banned_id) {
    if (depth == banned_size) {         // 불량 사용자들의 id와 매치되는 사용자들의 id를 모두 찾았을 경우
        int n = 0;
        for (int i = 0; i < 8; i++)
            if (visited[i])
                n += 1 << i;
        for (int num : visited_strings)
            if (num == n)               // 이미 해당 사용자들을 찾아낸 적이 있을 경우 바로 종료
                return;
        answer++;
        visited_strings.push_back(n);   // 그렇지 않다면 answer 1 증가시키고 계산한 비트 연산값을 저장
        return;
    }

    for (int i = 0; i < user_size; i++) {
        bool matched = true;
        if (!visited[i] && user_id[i].length() == banned_id[depth].length()) {
            int length = user_id[i].length();
            for (int j = 0; j < length; j++) {          // 한 문자씩 비교해 가며 일치한 지 확인
                if (banned_id[depth][j] == '*')
                    continue;
                if (banned_id[depth][j] != user_id[i][j]) {
                    matched = false;
                    break;
                }
            }
            if (matched) {                              // 일치하다면 그 다음 불량 사용자 id 가지고 또 체크
                visited[i] = true;
                DFS(depth + 1, user_id, banned_id);
                visited[i] = false;
            }
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    user_size = user_id.size();
    banned_size = banned_id.size();
    DFS(0, user_id, banned_id);
    return answer;
}