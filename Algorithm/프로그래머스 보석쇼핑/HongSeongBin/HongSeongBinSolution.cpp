#include <bits/stdc++.h>

using namespace std;
#include<bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    map<string,int> m;
    vector<int> dp(gems.size()+1,0);
    
	int start=0,end=0;
	int res = 2147000000;
	int res_start,res_end;
	int check=0;
	
	for(int i=0 ; i<gems.size() ; i++)
	{
		if(!m.count(gems[i]))
		{
			m[gems[i]]=1;
            dp[i+1] = dp[i]+1;
		}
		else
		{
			m[gems[i]]++;
            dp[i+1] = dp[i];
		}
	}
	int size = m.size();
    
    for(int i=1 ; i<=gems.size() ; i++)
    {
        if(dp[i] == size)
        {
            end = i-1;
            break;
        }
    }
    
    for(int i=end+1 ; i<gems.size() ; i++)
        m[gems[i]]--;
    
    
	while(end<gems.size() && start <= end)
	{
		if(m.size() == size)
		{
			int temp_res = end-start;
			
			if(temp_res < res)
			{
				res_start = start;
				res_end = end;
				res=temp_res;
			}
			m[gems[start]]--;
			if(m[gems[start]]==0)
				m.erase(gems[start]);
			start++;
		}
		else
        {
			end++;
            if(end >= gems.size())
                break;
            if(!m.count(gems[end]))
                m[gems[end]]=1;
            else
                m[gems[end]]++;
        }
	}
    answer.push_back(res_start+1);
    answer.push_back(res_end+1);
    return answer;
}
int main(void)
{	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<string> arr = {"DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA"};
	vector<int> res = solution(arr);
	cout<<res[0]<<" "<<res[1];
	

}
