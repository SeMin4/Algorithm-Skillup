#include <string>
#include <vector>

using namespace std;

int size;
int res_cnt;
int result=2147000000;
int max_size;

void is_possible(vector<int> arr,vector<int> weak, vector<int> dis, int cur, int find_cnt)
{
	if(cur >= max_size)
		return;
	
    int x=0;
    
	for(int i=0 ; i<weak.size() ; i++)
	{
		int j;
		int temp_find_cnt=0;
		vector<int> temp_weak;
		vector<int> b;
        
		//temp_find_cnt = find_cnt;
		temp_weak.assign(arr.begin(),arr.end());
		b.assign(weak.begin(),weak.end());
		for(j=weak[i] ; j<=weak[i]+dis[dis.size()-cur] ; j++)
		{
			if(j == temp_weak.size())
				break;
				
			if(temp_weak[j]>0)
			{
				temp_weak[j]=0;
				temp_find_cnt++;
			}
		}
		
		if(j==temp_weak.size() && weak[i]+dis[dis.size()-cur] >=size )
		{
			int old_find = temp_find_cnt;
            int new_find =0;
            int limit = dis[dis.size()-cur]-(size-weak[i]);
			
			for(int k=0 ; k<=limit ; k++)
			{
				if(temp_weak[k]>0)
				{
					temp_weak[k]=0;
					temp_find_cnt++;
                    new_find++;
				}
			}
            b.erase(b.begin()+i,b.end());
            b.erase(b.begin(),b.begin()+new_find);
		}
        else
            b.erase(b.begin()+i,b.begin()+i+temp_find_cnt);
        
		temp_find_cnt += find_cnt;
		if(temp_find_cnt == res_cnt)
		{
			if(result>cur)
            {
                max_size=cur;
				result=cur;
            }
			return;	
		}
//		cout<<temp_find_cnt<<" "<<dis[dis.size()-cur]<<"\n";
        if(temp_find_cnt<x)
            continue;
        x=temp_find_cnt;
		is_possible(temp_weak,b,dis,cur+1,temp_find_cnt);
	}
}

int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = 0;
    vector<int> arr(n,0);
    
    size = n;
    for(int i=0 ; i<weak.size() ; i++)
        arr[weak[i]]=1;
    
    res_cnt=weak.size();
    max_size = dist.size()+1;
    is_possible(arr,weak,dist,1,0);
    
    if(result == 2147000000)
        return -1;
    else
        return result;
}
