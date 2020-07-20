#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;  
    int start=0;
    
    while(true)
    {
        for(int i=0 ; i<progresses.size() ; i++)
            progresses[i] += speeds[i];

           if(progresses[start]>=100)
            {
            	int cnt=1;
            	
            	progresses.erase(find(progresses.begin(),progresses.end(),progresses[0]));
                speeds.erase(find(speeds.begin(),speeds.end(),speeds[0]));
                
                if(progresses.size() == 0)
                {
					answer.push_back(cnt);
                	printf("%d\n",cnt);
                	break;
            	}
            	
            	int len = progresses.size();
                for(int j=0 ; j<len ; j++)
                {

                	if(progresses[start] < 100)
                	{
                		answer.push_back(cnt);
                		printf("%d\n",cnt);
                		break;
                	}
                	else
                	{
                		progresses.erase(find(progresses.begin(),progresses.end(),progresses[0]));
                		speeds.erase(find(speeds.begin(),speeds.end(),speeds[0]));
                		cnt++;
					}
					
					if(progresses.size()==0)
					{
						answer.push_back(cnt);
                		printf("%d\n",cnt);
                		break;	
					}
				}
				
            }
            
        if(progresses.size() == 0)
            break;
    }
    return answer;
}

int main(void)
{
	vector<int> p{40, 93, 30, 55, 60, 65};
	vector<int> s{60, 1, 30, 5 , 10, 7};
	vector<int> ans;
	

	ans = solution(p,s);
}
