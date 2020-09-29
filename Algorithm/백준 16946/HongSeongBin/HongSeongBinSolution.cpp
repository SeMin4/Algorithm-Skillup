#include <bits/stdc++.h>

using namespace std;

int n,m;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};
int res=1;
int area_num=2;

void DFS(vector< vector<int> > &board, vector< vector<int> > &visited, int start_x, int start_y)
{
	
	for(int i=0 ; i<4 ; i++)
	{
		if(start_x+dx[i]<0 || start_x+dx[i]>=n || start_y+dy[i]<0 || start_y+dy[i]>=m)
			continue;
		
		if(visited[start_x+dx[i]][start_y+dy[i]]>0)
			continue;
			
		if(board[start_x+dx[i]][start_y+dy[i]]==0)
		{
			visited[start_x+dx[i]][start_y+dy[i]] = area_num;
			res++;
			DFS(board,visited,start_x+dx[i],start_y+dy[i]);
		}
	}
	
}

int main(void)
{	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>n>>m;
	
	vector< vector<int> > board(n);
	vector< vector<int> > visited(n);
	vector<int> res_set;
	
	res_set.push_back(-2147000000); res_set.push_back(-2147000000);
	 
	for(int i=0 ; i<n ; i++)
	{
		for(int j=0 ; j<m ; j++)
		{
			char temp;
			
			cin>>temp;
			board[i].push_back(temp-'0');
			visited[i].push_back(0);
		}
	}

	for(int i=0 ; i<n ; i++)
	{
		for(int j=0 ; j<m ; j++)
		{
			if(board[i][j] == 1)
				one_set.push_back({i,j});
			if(board[i][j]==0 && visited[i][j]==0)
			{

				visited[i][j] = area_num;
		
				DFS(board,visited,i,j);
				res = (res)%10;
				area_num++;
				res_set.push_back(res);
				res=1;
			}
		}
	}

	for(int i=0 ; i<one_set.size() ; i++)
	{
		int x=one_set[i].first;
		int y=one_set[i].second;
		
		set<int> check;
		
		for(int j=0 ; j<4 ; j++)
		{
			if(x+dx[j]<0 || x+dx[j]>=n ||y+dy[j]<0 || y+dy[j]>=m)
				continue;
			
			if(visited[x+dx[j]][y+dy[j]]==0)
				continue;	
				
			if(check.find(visited[x+dx[j]][y+dy[j]]) != check.end())
				continue;
			
			board[x][y] = (board[x][y]+res_set[visited[x+dx[j]][y+dy[j]]])%10;
			check.insert(visited[x+dx[j]][y+dy[j]]);
		}
	}
	
	for(int i=0 ; i<n ; i++)
	{
		for(int j=0 ; j<m ; j++)
			cout<<board[i][j];
		cout<<"\n";
	}
}
