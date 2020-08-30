#include<bits/stdc++.h>

//a:97 A:65
using namespace std;

int N,M,T,D;
char board[27][27];
int up[26][26];
int down[26][26];

void BFS1(int start_x,int start_y)
{
	int dx[4]={-1,0,0,1};
	int dy[4]={0,-1,1,0};
	queue< pair<int,int> > q;
	
	for(int i=0 ; i<N ; i++)
	{
		for(int j=0 ; j<M ; j++)
		{
			up[i][j]=1000000000;
			//down[i][j]=8000;
		}
	}
	
	up[0][0]=0;
//	down[0][0]=0;
	q.push({start_x,start_y});
	
	while(!q.empty())
	{
		int cur_x = q.front().first;
		int cur_y = q.front().second;
		
		q.pop();
		
		for(int i=0 ; i<4 ; i++)
		{
			if(cur_x+dx[i]<0 || cur_x+dx[i]>=N || cur_y+dy[i]<0 || cur_y+dy[i]>=M)
				continue;
				
			int cur_height;
			int next_height;
			
			if(board[cur_x][cur_y] < 'a')
				cur_height = board[cur_x][cur_y]-'A';
			else
				cur_height = board[cur_x][cur_y]-'a'+26;
				
			if(board[cur_x+dx[i]][cur_y+dy[i]] < 'a')
				next_height = board[cur_x+dx[i]][cur_y+dy[i]]-'A';
			else
				next_height = board[cur_x+dx[i]][cur_y+dy[i]]-'a'+26;
			
			if(abs(cur_height-next_height)>T)
				continue;
				

			
			if(cur_height>=next_height)
			{		
				if(up[cur_x+dx[i]][cur_y+dy[i]] > up[cur_x][cur_y]+1)
				{
					up[cur_x+dx[i]][cur_y+dy[i]] = up[cur_x][cur_y]+1;
					q.push({cur_x+dx[i],cur_y+dy[i]});

				}
	
			}
			else
			{	

				if(	up[cur_x+dx[i]][cur_y+dy[i]] > up[cur_x][cur_y]+pow(abs(cur_height-next_height),2))
				{
					up[cur_x+dx[i]][cur_y+dy[i]] = up[cur_x][cur_y]+pow(abs(cur_height-next_height),2);		
					check=1;
					q.push({cur_x+dx[i],cur_y+dy[i]});
				}

			}
			
			
		}
	}
	
}

void BFS2(int start_x,int start_y)
{
	int dx[4]={-1,0,0,1};
	int dy[4]={0,-1,1,0};
	queue< pair<int,int> > q;
	
	for(int i=0 ; i<N ; i++)
	{
		for(int j=0 ; j<M ; j++)
		{
			down[i][j]=1000000000;
		}
	}
	
	down[0][0]=0;
	q.push({start_x,start_y});
	
	while(!q.empty())
	{
		int cur_x = q.front().first;
		int cur_y = q.front().second;
		
		q.pop();
		
		for(int i=0 ; i<4 ; i++)
		{
			if(cur_x+dx[i]<0 || cur_x+dx[i]>=N || cur_y+dy[i]<0 || cur_y+dy[i]>=M)
				continue;
				
			int cur_height;
			int next_height;
			
			if(board[cur_x][cur_y] < 'a')
				cur_height = board[cur_x][cur_y]-'A';
			else
				cur_height = board[cur_x][cur_y]-'a'+26;
				
			if(board[cur_x+dx[i]][cur_y+dy[i]] < 'a')
				next_height = board[cur_x+dx[i]][cur_y+dy[i]]-'A';
			else
				next_height = board[cur_x+dx[i]][cur_y+dy[i]]-'a'+26;
			
			if(abs(cur_height-next_height)>T)
				continue;
				

			
			if(cur_height<=next_height)
			{
				int check=0;
				if(down[cur_x+dx[i]][cur_y+dy[i]] > down[cur_x][cur_y]+1)
				{
					down[cur_x+dx[i]][cur_y+dy[i]] = down[cur_x][cur_y]+1;
					q.push({cur_x+dx[i],cur_y+dy[i]});
				}
			}
			else
			{	

				if(down[cur_x+dx[i]][cur_y+dy[i]] > down[cur_x][cur_y]+pow(abs(cur_height-next_height),2))
				{

					down[cur_x+dx[i]][cur_y+dy[i]] = down[cur_x][cur_y]+pow(abs(cur_height-next_height),2);
					q.push({cur_x+dx[i],cur_y+dy[i]});
	
				}

			}
			
			
		}
	}
	
}

int main(){
	int max_height = 0;
	
	cin>>N>>M>>T>>D;
	
	for(int i=0 ; i<N ; i++)
		for(int j=0 ; j<M ; j++)
			cin>>board[i][j];
		
	BFS1(0,0);
	BFS2(0,0);
	
	for(int i=0 ; i<N ; i++)
	{
		for(int j=0 ; j<M ; j++)
		{
			//cout<<down[i][j]<<" ";
			up[i][j] += down[i][j];
		//	cout<<up[i][j]<<" ";
			if(up[i][j] <= D)
			{
				int temp_height;
				if(board[i][j] < 'a')
					temp_height = board[i][j]-'A';
				else
					temp_height = board[i][j]-'a'+26;
					
				if(temp_height > max_height)
					max_height = temp_height;
			}
		}
		//cout<<"\n";
	}
	
	cout<<max_height;
}
