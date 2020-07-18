#include <bits/stdc++.h>

using namespace std;

<<<<<<< HEAD
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
=======
vector<pair<int,int> > loc;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int mapp[1000][1000]={0,};
int m,n;
>>>>>>> be2b64205378958c3c9e6971f6b9f9e0c3778dd0
int cnt=0;
int zero;
int day;

void BFS()
{
	int i,j;
<<<<<<< HEAD
	int pos_x,pos_y,pos_z;
	int cnt=0;
	
	queue<Location> q;
=======
	int pos_x,pos_y;
	int cnt=0;
	
	queue<pair<int,int> > q;
>>>>>>> be2b64205378958c3c9e6971f6b9f9e0c3778dd0
	
	for(i=0 ; i<loc.size() ; i++)
		q.push(loc[i]);
	
	while(!q.empty())
	{
<<<<<<< HEAD
		pos_x=q.front().x;
		pos_y=q.front().y;
		pos_z=q.front().z;
=======
		pos_x=q.front().first;
		pos_y=q.front().second;
>>>>>>> be2b64205378958c3c9e6971f6b9f9e0c3778dd0
		
		q.pop();
		
		for(i=0 ; i<4 ; i++)
		{
			if(pos_x+dx[i]<0 || pos_x+dx[i]>=m || pos_y+dy[i]<0 || pos_y+dy[i]>=n)
				continue;
			
<<<<<<< HEAD
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
=======
			if(mapp[pos_x+dx[i]][pos_y+dy[i]]==0)
			{
				cnt++;
				q.push(make_pair(pos_x+dx[i],pos_y+dy[i]));
				mapp[pos_x+dx[i]][pos_y+dy[i]] = mapp[pos_x][pos_y]+1;
				if(day<mapp[pos_x+dx[i]][pos_y+dy[i]])
					day=mapp[pos_x+dx[i]][pos_y+dy[i]];
>>>>>>> be2b64205378958c3c9e6971f6b9f9e0c3778dd0
			}
		}
	}
	if(cnt != zero)
		day=0;
}

int main()
{	
<<<<<<< HEAD
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
=======
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
	
>>>>>>> be2b64205378958c3c9e6971f6b9f9e0c3778dd0
	if(zero==0)
		cout<<0;
	else
	{
		BFS();
		
		cout<<day-1;
	}
	
<<<<<<< HEAD
	
}	











=======
}	
>>>>>>> be2b64205378958c3c9e6971f6b9f9e0c3778dd0
