#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> gems) {
    set<string> jew;
    map<string, int> tmp;               // key : 보석 이름(string), value : 갯수(int)
    vector<pair<int, int>> possible;    // 답이 될 수 있는 (시작 번호, 끝 번호) 목록
    vector<int> answer;
    int left = 0, right = 0;

    for (string g : gems)
        jew.insert(g);
    int size = jew.size();              // 전체 보석이 몇 종류 있는지 헤아림

    while (left <= right && right < (int)gems.size()) {
        if (tmp.size() < size) {                                // map에 모든 종류의 보석을 넣지 못했을 경우
            if (tmp.count(gems[right]))                         // right 자리의 보석은 넣은 상태일 경우 개수만 증가
                tmp[gems[right]]++;
            else
                tmp.insert(make_pair(gems[right], 1));          // 반대로 넣지 않은 상태일 경우 map에 해당 보석을 넣음
            right++;                                            // right 오른쪽으로 한 칸 이동
        }
        else {                                                  // 반대로 모두 넣은 상태일 경우
            possible.push_back(make_pair(left, right - 1));     // 시작 번호(left)와 끝 번호(right - 1)을 짝지어서 저장
            tmp[gems[left]]--;                                  // left 자리의 보석 개수 1 감소
            if (!tmp[gems[left]])
                tmp.erase(gems[left]);                          // 개수가 0이 되면 map에서 없앰
            left++;                                             // left 오른쪽으로 한 칸 이동
        }
    }
    while (left < right && tmp.size() == size) {                // right가 마지막 index를 넘어서도 아직 완료가 되지 않았을 수도 있음 -> left 옮겨가며 마저 처리
        possible.push_back(make_pair(left, right - 1));
        tmp[gems[left]]--;
        if (!tmp[gems[left]])
            tmp.erase(gems[left]);
        left++;
    }

    sort(possible.begin(), possible.end());                     // 시작 번호 기준으로 정렬
    left = possible[0].first, right = possible[0].second;
    for (auto i : possible) {
        if (i.second - i.first < right - left)
            right = i.second, left = i.first;                   // 구간이 제일 짧은 시작 번호, 끝 번호로 갱신
    }

    answer.push_back(left + 1);
    answer.push_back(right + 1);
    return answer;
}