#include <iostream>
#include <vector>
#include <algorithm>

/*

 백준 1946
 
 첫번째 시도 : 모든 요소와 비교 O(n^2) -> 시간초과
 
 두번째 시도 : 서류등수로 정렬 후 면접등수로만 비교 O(n) -> 정답
 
 sol) 면접등수로 비교할때 높은 등수로 계속 bound변수를 업데이트해준다.
 
*/

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    
    int t;
    cin >> t;
    
    while(t--){
        vector<pair<int, int> > applicant;
        int n;
        cin >> n;
        
        for(int i=0; i<n; i++){
            pair<int, int> grade;
            cin >> grade.first >> grade.second;
            applicant.push_back(grade);
        }
        
        sort(applicant.begin(), applicant.end());
        
        int cnt = n;
        int bound = applicant[0].second;
        
        for(int i=1; i<n; i++){
            if(applicant[i].second > bound)
                cnt--;
            else
                bound = applicant[i].second;
        }
       
        cout << cnt << '\n';
        
    }
    
    return 0;
}
