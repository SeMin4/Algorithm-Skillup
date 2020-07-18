#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int> > loc;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int mapp[1000][1000]={0,};
int m,n;
int cnt=0;
int zero;
int day;

void BFS()
{
	int i,j;
	int pos_x,pos_y;
	int cnt=0;
	
	queue<pair<int,int> > q;
	
	for(i=0 ; i<loc.size() ; i++)
		q.push(loc[i]);
	
	while(!q.empty())
	{
		pos_x=q.front().first;
		pos_y=q.front().second;
		
		q.pop();
		
		for(i=0 ; i<4 ; i++)
		{
			if(pos_x+dx[i]<0 || pos_x+dx[i]>=m || pos_y+dy[i]<0 || pos_y+dy[i]>=n)
				continue;
			
			if(mapp[pos_x+dx[i]][pos_y+dy[i]]==0)
			{
				cnt++;
				q.push(make_pair(pos_x+dx[i],pos_y+dy[i]));
				mapp[pos_x+dx[i]][pos_y+dy[i]] = mapp[pos_x][pos_y]+1;
				if(day<mapp[pos_x+dx[i]][pos_y+dy[i]])
					day=mapp[pos_x+dx[i]][pos_y+dy[i]];
			}
		}
	}
	if(cnt != zero)
		day=0;
}

int main()
{	
	cin>>n>>m;
	
	for(int i=0 ; i<m ; i++)
	{
		for(int j=0 ; j<n ; j++)
		{
			cin>>mapp[i][j];
			
			if(mapp[i][j]==1)
			{
				loc.push_back(make_pair(i,j));
			}
			else if(mapp[i][j]==0)
				zero++;
		}
	}
	
	if(zero==0)
		cout<<0;
	else
	{
		BFS();
		
		cout<<day-1;
	}
	
}	
