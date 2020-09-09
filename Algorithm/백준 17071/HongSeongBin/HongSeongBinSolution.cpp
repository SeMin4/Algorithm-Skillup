#include<bits/stdc++.h>

#define max_dis 500000
#define min_dis 0
using namespace std;

int older,younger;
int visited[2][max_dis+1];
int younger_visited[max_dis+1];

void BFS_older()
{
	queue< pair<int,int> > q;
	
	q.push({older,1});
	visited[0][older] = 0;
	
	while(!q.empty())
	{
		int start = q.front().first;
		int time = q.front().second;
		q.pop();
		
		if(start+1<=max_dis)
		{
			if(time%2 == 0)
			{
				if(visited[0][start+1] == -1 || time<visited[0][start+1])
				{
					visited[0][start+1] = time;
					q.push({start+1,time+1});
				}
			}
			else
			{
				if(visited[1][start+1] == -1 || time<visited[1][start+1])
				{
					visited[1][start+1] = time;
					q.push({start+1,time+1});
				}
			}
		}
		
		if(start-1 >= 0)
		{
			if(time%2 == 0)
			{
				if(visited[0][start-1]==-1 || time<visited[0][start-1])
				{
					visited[0][start-1] = time;
					q.push({start-1,time+1});
				}
			}
			else
			{
				if(visited[1][start-1]==-1 || time<visited[1][start-1])
				{
					visited[1][start-1] = time;
					q.push({start-1,time+1});
				}
			}
		}
		
		if(start*2<=max_dis)
		{
			if(time%2 == 0)
			{
				if(visited[0][start*2]==-1 || time<visited[0][start*2])
				{
					visited[0][start*2] = time;
					q.push({start*2,time+1});
				}	
			}
			else
			{
				if(visited[1][start*2]==-1 || time<visited[1][start*2])
				{
					visited[1][start*2] = time;
					q.push({start*2,time+1});
				}	
			}
		}
		
	}
}

int BFS_younger()
{
	queue< pair<int,int> > q;

	q.push({younger,0});
	
	while(!q.empty())
	{
		int start = q.front().first;
		int time = q.front().second;
		
		if(start > max_dis)
			return -1;
			
		q.pop();
		
		if(time%2 == 0)
		{
			//cout<<start<<" "<<visited[0][start]<<"\n";
			if(visited[0][start]>=0 && time>=visited[0][start])
			{
				return time;
			}
		}
		else
		{
			//cout<<start<<" "<<visited[1][start]<<"\n";
			if(visited[1][start]>=0 && time>=visited[1][start])
			{
				return time;
			}
		
		}

		
		
		time++;
		q.push({start+time,time});
		//q.push({start-time,time});
	}
}

void init_visited()
{
	for(int j=0 ; j<2 ; j++)
		for(int i=0 ; i<=max_dis ; i++)
			visited[j][i]=-1;
}

int main(void)
{
	cin>>older>>younger;

	init_visited();
	BFS_older();
	int res = BFS_younger();
	
	cout<<res;
}
