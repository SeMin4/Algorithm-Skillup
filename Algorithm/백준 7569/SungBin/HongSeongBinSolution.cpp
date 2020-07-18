#include <bits/stdc++.h>

using namespace std;

struct Location
{
	int x;
	int y;
	int z;
	
	Location(int a,int b,int c)
	{
		x=a;
		y=b;
		z=c;		
	}
};

vector<Location> loc;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int dz[]={1,-1};
int mapp[100][100][100]={0,};
int m,n,h;
int cnt=0;
int zero;
int day;

void BFS()
{
	int i,j;
	int pos_x,pos_y,pos_z;
	int cnt=0;
	
	queue<Location> q;
	
	for(i=0 ; i<loc.size() ; i++)
		q.push(loc[i]);
	
	while(!q.empty())
	{
		pos_x=q.front().x;
		pos_y=q.front().y;
		pos_z=q.front().z;
		
		q.pop();
		
		for(i=0 ; i<4 ; i++)
		{
			if(pos_x+dx[i]<0 || pos_x+dx[i]>=m || pos_y+dy[i]<0 || pos_y+dy[i]>=n)
				continue;
			
			if(mapp[pos_x+dx[i]][pos_y+dy[i]][pos_z]==0)
			{
				cnt++;
				q.push(Location(pos_x+dx[i],pos_y+dy[i],pos_z));
				mapp[pos_x+dx[i]][pos_y+dy[i]][pos_z] = mapp[pos_x][pos_y][pos_z]+1;
				if(day<mapp[pos_x+dx[i]][pos_y+dy[i]][pos_z])
					day=mapp[pos_x+dx[i]][pos_y+dy[i]][pos_z];
			}
		}
		for(i=0 ; i<2 ; i++)
		{
			if(pos_z+dz[i]<0 || pos_z+dz[i]>=h)
				continue;
			if(mapp[pos_x][pos_y][pos_z+dz[i]]==0)
			{
				cnt++;
				q.push(Location(pos_x,pos_y,pos_z+dz[i]));
				mapp[pos_x][pos_y][pos_z+dz[i]] = mapp[pos_x][pos_y][pos_z]+1;
				if(day<mapp[pos_x][pos_y][pos_z+dz[i]])
					day=mapp[pos_x][pos_y][pos_z+dz[i]];
			}
		}
	}
	if(cnt != zero)
		day=0;
}

int main()
{	
	cin>>n>>m>>h;
	
	for(int z=0 ; z<h ; z++)
	{
		for(int i=0 ; i<m ; i++)
		{
			for(int j=0 ; j<n ; j++)
			{
				cin>>mapp[i][j][z];
				
				if(mapp[i][j][z]==1)
				{
					loc.push_back(Location(i,j,z));
				}
				else if(mapp[i][j][z]==0)
					zero++;
			}
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











