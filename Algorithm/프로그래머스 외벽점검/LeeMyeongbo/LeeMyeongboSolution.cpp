#include <iostream>
#include <vector>
using namespace std;

int answer = -1;
char wall[205];                 // 외벽의 상태 (0 이면 정상, 1이면 취약)
bool visited_dist[8];           // 친구 방문 체크

// visited_weak : 방문한 취약 지점 수, start_point : 취약 지점 중에서 탐색 시작 위치
void DFS(int n, int depth, vector<int>& weak, vector<int>& dist, int visited_weak, int start_point) {
    if (weak.size() <= visited_weak) {                      // 방문한 취약 지점 수가 실제 취약 지점 수 이상이 되면 최솟값 갱신
        if (answer == -1)
            answer = depth;
        answer = depth < answer ? depth : answer;           // 깊이 = 보낸 친구의 수
        return;
    }
    
    for (unsigned int i = 0; i < dist.size(); i++) {        // 순열 방식으로 dist 벡터에 저장된 수 만큼 외벽 탐색
        if (!visited_dist[i]) {
            visited_dist[i] = true;                         // 방문 체크

            int j = start_point, cover = 0;                 // cover : 취약 지점 발견 할 때마다 증가
            for (int d = 0; d <= dist[i]; d++) {            // 해당 친구의 이동 가능 거리만큼 이동
                if (wall[j] == 1)
                    cover++;
                j = (j + 1) % n;                            // 외벽이 원형 (끝에 도달 시 다시 처음으로 돌아와야 함)
            }
            while(!wall[j])                                 // 다음 취약 지점 발견할 때 까지 j 이동
                j = (j + 1) % n;

            DFS(n, depth + 1, weak, dist, visited_weak + cover, j);
            visited_dist[i] = false;
        }
    }
}

int solution(int n, vector<int> weak, vector<int> dist) {
    for (auto w : weak) 
        wall[w] = 1;                                // 취약한 지점마다 1로 설정
    
    for (unsigned int i = 0; i < weak.size(); i++)
        DFS(n, 0, weak, dist, 0, weak[i]);

    return answer;
}