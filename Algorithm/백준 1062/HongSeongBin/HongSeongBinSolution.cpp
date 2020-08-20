#include<bits/stdc++.h>

using namespace std;

int n,m;
int max_res=-1;
int check[26]={0,};
vector<string> str;

void deleteLong()
{
	string start_str = "antic";
	
	
	for(int i=0 ; i<str.size() ; i++)
	{
		int cnt=0;
		vector<int> res;
		int checkArr[26]={0,};
		int res_cnt=0;
		
		for(int j=4 ; j<str[i].size()-4 ; j++)
		{
			if(start_str.find(str[i][j]) != std::string::npos)
				continue;
			else
			{
				if(checkArr[str[i][j]-97]==0)
				{
					res_cnt++;
					checkArr[str[i][j]-97]++;
				}	
			} 
			//	res.push_back((str[i][j]));
		}
		//sort(res.begin(),res.end());
		//res.erase(unique(res.begin(),res.end()),res.end());
		
		if(res_cnt > m-5)
		{
			str.erase(str.begin()+i);
			i--;
		}
	}
}

void DFS2(int start, int put_cnt)
{
	if(put_cnt >= m-5)
	{
		int cnt=0;
		for(int i=0 ; i<str.size() ; i++)
		{
			int j;
			int check_val=0;
			for(j=4; j<str[i].length()-4 ; j++)
			{
	//			if(str[i][j] == 'a' || str[i][j] == 'n' ||str[i][j] == 't' || str[i][j] == 'i' || str[i][j] == 'c')
	//				continue;
				
				if(check[str[i][j]-97]==0)
				{
					check_val=1;
					break;
				}
			}	
			
			if(check_val==0)
				cnt++;
		}
		
		if(max_res < cnt)
			max_res=cnt;
		return;	
	}
	else
	{
		for(int i=start ; i<26 ; i++)
		{
			if(i == 'a'-97 || i == 'n'-97 || i == 't'-97 || i == 'i'-97 || i == 'c'-97)
				continue;
			check[i]=1;
			DFS2(i+1,put_cnt+1);
			check[i]=0;
			
		}
		
	}
}
void DFS(int check[],int put_cnt, int cnt,int total_cnt)
{
	if(cnt==str.size())
	{
		int total=0;
		int i;
		
		for(i=0 ; i<26 ; i++)
		{
		//	cout<<check[i]<<" ";
			if(i == 'a'-97 || i == 'n'-97 || i == 't'-97 || i == 'i'-97 || i == 'c'-97)
				continue;
			else
			{
				if(check[i]>0)
					total++;
			}
			
			if(total > m-5)
				break;
		}
		if(i==26)
		{
			if(max_res < put_cnt)
				max_res = put_cnt;
		}
		//cout<<"\n";
		return;	
	}
	else
	{
		int copy_check[26];
		int check_cnt,temp_cnt;
		
		copy(check,check+26,copy_check);
		
		for(int i=4 ; i<str[cnt].length()-4 ; i++)
			check[str[cnt][i]-97]++;
		
		check_cnt=temp_cnt=0;
		
		for(int i=0 ; i<26 ; i++)
		{
			if(i == 'a'-97 || i == 'n'-97 || i == 't'-97 || i == 'i'-97 || i == 'c'-97)
				continue;
			
			if(check[i]>0)
				check_cnt++;
			if(copy_check[i]>0)
				temp_cnt++;
		}
		
		if(check_cnt <= m-5)
			DFS(check,put_cnt+1,cnt+1,check_cnt);
		if(temp_cnt <= m-5)
			DFS(copy_check,put_cnt,cnt+1,temp_cnt);

	}	
}

int main(){
	

	cin>>n>>m;
	
	for(int i=0 ; i<n ; i++)
	{
		string temp;
		
		cin>>temp;
		str.push_back(temp);
	}
	
	deleteLong();
	check['a'-97]=1;
	check['n'-97]=1;
	check['t'-97]=1;
	check['i'-97]=1;
	check['c'-97]=1;
	//DFS(check,0,0,0);
	DFS2(0,0);
	
	cout<<max_res;
}
