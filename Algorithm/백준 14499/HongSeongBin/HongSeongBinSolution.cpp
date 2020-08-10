#include<bits/stdc++.h>

#define down_x 3
#define down_y 1
#define up_x 1
#define up_y 1

using namespace std;

int dice[4][3];
int board[21][21];
int n,m;
int cur_x,cur_y;

void left()
{
	int down = dice[1][0];
	
	dice[1][0] = dice[1][1];
	dice[1][1] = dice[1][2];
	dice[1][2] = dice[down_x][down_y];
	dice[down_x][down_y] = down;
}

void right()
{
	int down = dice[1][2];
	
	dice[1][2] = dice[1][1];
	dice[1][1] = dice[1][0];
	dice[1][0] = dice[down_x][down_y];
	dice[down_x][down_y] = down;
}

void up()
{
	int down = dice[0][1];
	
	dice[0][1] = dice[1][1];
	dice[1][1] = dice[2][1];
	dice[2][1] = dice[down_x][down_y];
	dice[down_x][down_y] = down;
}

void down()
{
	int down = dice[down_x][down_y];
	
	dice[down_x][down_y] = dice[2][1];
	dice[2][1] = dice[1][1];
	dice[1][1] = dice[0][1];
	dice[0][1] = down;
}

int main(){
	int size;
	int move_info[1000];
	
	cin>>n>>m>>cur_x>>cur_y>>size;
	
	for(int i=0 ; i<n ; i++)
		for(int j=0 ; j<m ; j++)
			cin>>board[i][j];
		
	for(int i=0 ; i<size ; i++)
		cin>>move_info[i];
		
	for(int i=0 ; i<size ; i++)
	{
		switch(move_info[i])
		{
			case 1:
				if(cur_y+1>=m)
					continue;
				cur_y++;
				right();
				break;
			case 2:
				if(cur_y-1<0)
					continue;
				cur_y--;
				left();
				break;
			case 3:
				if(cur_x-1<0)
					continue;
				cur_x--;
				up();
				break;
			case 4:
				if(cur_x+1>=n)
					continue;
				cur_x++;
				down();
				break;
		}
		if(board[cur_x][cur_y]==0)
			board[cur_x][cur_y]=dice[down_x][down_y];
		else
		{
			dice[down_x][down_y]=board[cur_x][cur_y];
			board[cur_x][cur_y]=0;
		}

		cout<<dice[up_x][up_y]<<"\n";
	}

}
