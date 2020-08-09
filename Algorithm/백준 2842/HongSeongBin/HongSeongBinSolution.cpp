#include<bits/stdc++.h>

using namespace std;

int n;
int dis[51][51];
char board[51][51];
int find_cnt;
int min_dis=2147000000;
int dx[8]={0,1,1,1,0,-1,-1,-1};
int dy[8]={1,1,0,-1,-1,-1,0,1};
int lt,rt;
vector<int> min_max;

struct Data
{
	int x,y;
	
	Data(int a,int b)
	{
		x=a,y=b;
	}
	
};

int bfs(Data start_pos)
{
	queue<Data> q;
	int cur_cnt=0;
	int check[51][51]={0,};
	
	if((dis[start_pos.x][start_pos.y]<min_max[lt] || dis[start_pos.x][start_pos.y]>min_max[rt]))
		return 0;
				
	q.push(start_pos);
	check[start_pos.x][start_pos.y]=1;
	
	while(!q.empty())
	{
		Data cur_pos = q.front();
		q.pop();
		
		
		
		if(board[cur_pos.x][cur_pos.y]=='K')
		{
			cur_cnt++;
		
			if(cur_cnt == find_cnt)
				return 1;	
		}

		for(int i=0 ; i<8 ; i++)
		{
			int next_x = cur_pos.x+dx[i];
			int next_y = cur_pos.y+dy[i];
			
			if(next_x>=n || next_x<0 || next_y>=n || next_y<0)
				continue;
			if(check[next_x][next_y]==1)
				continue;
				
			if((dis[next_x][next_y]<min_max[lt] || dis[next_x][next_y]>min_max[rt]))
				continue;
			
		
			q.push(Data(next_x,next_y));		
			check[next_x][next_y]=1;	
		}
	}
	
	return 0;
}

int main(){
	cin>>n;
	
	Data start_pos={0,0};
	
	for(int i=0 ; i<n ; i++)
		for(int j=0 ; j<n ; j++)
		{
			cin>>board[i][j];
			if(board[i][j]=='K')
			{
				find_cnt++;
			}
			else if(board[i][j]=='P')
				start_pos = Data(i,j);			
		}

	
	for(int i=0 ; i<n ; i++)
		for(int j=0 ; j<n ; j++)
		{
			cin>>dis[i][j];
			min_max.push_back(dis[i][j]);
		}

	sort(min_max.begin(),min_max.end());
	min_max.erase(unique(min_max.begin(),min_max.end()),min_max.end());

	while(lt<min_max.size() && rt<min_max.size())
	{
		int res = bfs(start_pos);
		
		if(res==1)
		{
			if(min_dis > min_max[rt]-min_max[lt])
				min_dis = min_max[rt]-min_max[lt];
			
			lt++;
		}
		else
		{
			rt++;
		}
	}

	cout<<min_dis;
}
