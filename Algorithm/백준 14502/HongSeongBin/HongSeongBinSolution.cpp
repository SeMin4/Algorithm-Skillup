#include<bits/stdc++.h>

using namespace std;

int board[8][8];
int max_res=-1;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int res;
int n,m;

void DFS(int start, int cnt, vector< pair<int,int> > virus, vector< pair<int,int> > empty_space)
{
	if(cnt==3)
	{
		//BFS
		queue< pair<int,int> > q;	
		
		for(int i=0 ; i<virus.size() ; i++)
			q.push(virus[i]);
		
		int temp_board[8][8];
		int temp_cnt=0;
		
		for(int i=0 ; i<n ; i++)
		{

			for(int j=0 ; j<m ; j++)
				{
					temp_board[i][j]=board[i][j];
	//				cout<<board[i][j]<<" ";
				}
	//		cout<<"\n";
		}
	//	cout<<"\n";
		
		while(!q.empty())
		{
			int x_pos;
			int y_pos;
			
			x_pos = q.front().first;
			y_pos = q.front().second;
			
			q.pop();
			
			
			for(int i=0 ; i<4 ; i++)
			{
				if(x_pos+dx[i]<0 || x_pos+dx[i]>=n || y_pos+dy[i]<0 || y_pos+dy[i]>=m)
					continue;
				if(temp_board[x_pos+dx[i]][y_pos+dy[i]] != 0)
					continue;
					
				q.push(make_pair(x_pos+dx[i],y_pos+dy[i]));
				temp_board[x_pos+dx[i]][y_pos+dy[i]]=2;
			}
		}
		
		for(int i=0 ; i<n ; i++)
		{
			for(int j=0 ; j<m ; j++)
			{
				if(temp_board[i][j]==0)
					temp_cnt++;
			}
		}
		
		if(temp_cnt > max_res)
			max_res = temp_cnt;
			
		return;
		
	}
	else
	{
		for(int i=start ; i<empty_space.size() ; i++)
		{
			board[empty_space[i].first][empty_space[i].second]=1;
			DFS(i+1,cnt+1,virus,empty_space);
			board[empty_space[i].first][empty_space[i].second]=0;
		}
	}
}

int main(){
	cin>>n>>m;
	
	vector< pair<int,int> > virus;
	vector< pair<int,int> > empty_space;
	
	for(int i=0 ; i<n ; i++)
	{
		for(int j=0 ; j<m ; j++)
		{
			cin>>board[i][j];
			
			if(board[i][j]==2)
				virus.push_back(make_pair(i,j));
			else if(board[i][j] == 0)
				empty_space.push_back(make_pair(i,j));
		}
	}
	DFS(0,0,virus,empty_space);
	cout<<max_res;
	
}
