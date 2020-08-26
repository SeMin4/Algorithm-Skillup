#include<bits/stdc++.h>

#define left 6
#define right 2

using namespace std;

vector<string> already_res;
int check_arr[8];
int res;

int check_banned(string source, string des)
{
	if(source.length() != des.length())
		return -1;
		
	for(int i=0 ; i<source.length() ; i++)
	{
		if(des[i] == '*')
			continue;
		else
		{
			if(source[i] != des[i])
				return -1;	
		}	
	}	
	return 1;
}

void DFS(vector<string> user_id, vector<string> banned_id, int cur, string res_temp)
{
	if(cur >= banned_id.size())
	{
		sort(res_temp.begin(),res_temp.end());
		
		if(find(already_res.begin(),already_res.end(),res_temp) == already_res.end())
		{
			already_res.push_back(res_temp);
			res++;
		}
		return;	
	}
	
	for(int i=0 ; i<user_id.size() ; i++)
	{
		if(check_arr[i])
			continue;
		
		int check = check_banned(user_id[i],banned_id[cur]);
		
		if(check==1)
		{
			check_arr[i]=1;
			res_temp+=(i+'0');
			DFS(user_id,banned_id,cur+1,res_temp);
			check_arr[i]=0;
			res_temp.erase(res_temp.end()-1);
		}
	}
}


int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    return answer;
}


int main(){
	vector<string> user_id = {"frodo", "fradi", "crodo", "abc123", "frodoc"};
	vector<string> banned_id = {"fr*d*", "*rodo", "******", "******"};
	
	DFS(user_id,banned_id,0,"");
	
	cout<<res;
}
