#include <bits/stdc++.h>

using namespace std;

//dir 1:위 2:아래 3:오른쪽 4:왼쪽 
struct Shark{
	int x;
	int y;
	int speed;
	int dir;
	int size;
	int is_die;
	
	Shark(int r,int c,int s,int d,int z,int die)
	{
		x=r;
		y=c;
		speed=s;
		dir=d;
		size=z;
		is_die = die;
	}
	
	void died()
	{
		is_die=1;
		speed=0;
		size=0;
		dir=0;
		x=0,y=0;
	}
	
	bool operator<(Shark &b)
	{
		return size>b.size;
	}
};

struct Fisher{
	int catch_count;
	
	Fisher(int a)
	{
		catch_count=a;
	}
};

int R,C,M;
int board[100][100];


void move_shark(vector<Shark> &shark)
{
	for(int i=0 ; i<shark.size() ; i++)
	{
		if(shark[i].is_die)
			continue;
		board[shark[i].x][shark[i].y]=-1;
		switch(shark[i].dir)
		{
			
			case 0:
				if(shark[i].x - shark[i].speed<0)
				{
					int new_speed = shark[i].speed - shark[i].x;
					
					if((new_speed/(R-1))%2==0)
					{
						shark[i].dir=1;
						shark[i].x = (new_speed)%(R-1);
					}
					else
					{
						shark[i].x = (R-1)-(new_speed%(R-1));
					}
				}
				else
				{
					shark[i].x -= shark[i].speed;
				}
				break;
			case 1:
				if(shark[i].x + shark[i].speed >= R)
				{
					int new_speed = shark[i].speed - (R-1-shark[i].x);
					
					if((new_speed/(R-1))%2==0)
					{
						shark[i].dir=0;
						shark[i].x = (R-1)-(new_speed%(R-1));
					}
					else
					{
						shark[i].x = (new_speed)%(R-1);
					}
				}
				else
				{
					shark[i].x += shark[i].speed;
				}
				break;	
			case 2:
				if(shark[i].y + shark[i].speed >= C)
				{
					int new_speed = shark[i].speed - (C-1-shark[i].y);
					
					if((new_speed/(C-1))%2==0)
					{
						shark[i].dir=3;
						shark[i].y = (C-1)-(new_speed%(C-1));
					}
					else
					{
						shark[i].y = (new_speed)%(C-1);
					}
				}
				else
				{
					shark[i].y += shark[i].speed;
				}
				break;
			case 3:
				if(shark[i].y - shark[i].speed<0)
				{
					int new_speed = shark[i].speed - shark[i].y;
					
					if((new_speed/(C-1))%2==0)
					{
						shark[i].dir=2;
						shark[i].y = (new_speed)%(C-1);
					}
					else
					{
						shark[i].y = (C-1)-(new_speed%(C-1));
					}
				}
				else
				{
					shark[i].y -= shark[i].speed;
				}
				break;
						
		}

	}
	
	sort(shark.begin(),shark.end());
	
	for(int i=0 ; i<shark.size() ; i++)
	{
		if(shark[i].is_die)
		{
			board[shark[i].x][shark[i].y]=-1;
			continue;
		}
		if(board[shark[i].x][shark[i].y]==-1)
			board[shark[i].x][shark[i].y]=i;		
		else
		{
			shark[i].died();
			continue;
		}

	}	

}

int main(void)
{
	cin>>R>>C>>M;
	
	vector<Shark> shark;
	Fisher fisher = Fisher(0);
	
	for(int i=0 ; i<R ; i++)
	{
		for(int j=0 ; j<C ; j++)
			board[i][j]=-1;
	}

	for(int i=0 ; i<M ; i++)
	{
		int r,c,s,d,z;
		
		cin>>r>>c>>s>>d>>z;
		board[r-1][c-1]=i;
		shark.push_back(Shark(r-1,c-1,s,d-1,z,0));
	}

	for(int i=0 ; i<C ; i++)
	{
		//상어 잡기
		for(int j=0 ; j<R ; j++)
		{
			if(board[j][i]>=0)
			{
				if(shark[board[j][i]].is_die)
					continue;
				fisher.catch_count += shark[board[j][i]].size;
				shark[board[j][i]].died();
				board[j][i]=-1;
				break;
			}
		} 
		
		//상어 이동
		move_shark(shark);
		 
	}
	
	cout<<fisher.catch_count;
}


