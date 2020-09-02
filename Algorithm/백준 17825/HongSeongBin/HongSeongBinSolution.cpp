#include<bits/stdc++.h>

using namespace std;

int red_board[43];
int blue_board[43];
int player[4];
int blue_player[4];
int dice[10];
int max_res=0;

void init_board()
{
	for(int i=0 ; i<=40 ; i++)
	{
		red_board[i]=i+2;	
	}	
	red_board[42]=42;
	
	blue_board[10] = 13; blue_board[13] = 16; blue_board[16] = 19; blue_board[19] = 25;
	blue_board[20] = 22; blue_board[22] = 24; blue_board[24] = 25;
	blue_board[30] = 28; blue_board[28] = 27; blue_board[27] = 26; blue_board[26] = 25;
	blue_board[25] = 30; blue_board[30] = 35; blue_board[35] = 40; blue_board[40] = 42;
	blue_board[42] = 42;
}

void move_player(int player_num, int dis, int is_blue)
{
	if(is_blue)
	{
		for(int i=0 ; i<dis ; i++)
		{
			player[player_num] = blue_board[player[player_num]];
		}
	}
	else
	{
		for(int i=0 ; i<dis ; i++)
		{
			player[player_num] = red_board[player[player_num]];
		}
		
		if(player[player_num]%10 == 0)
			blue_player[player_num]=1;
	}
}

int find_already(int cur)
{
	for(int i=0 ; i<4 ; i++)
	{
		if(i == cur)
			continue;
		if(player[i] == player[cur])
			return 1;
	}
	return -1;
}
void play_game(int cnt, int sum)
{
//	for(int i=0 ; i<4 ; i++)
//		cout<<player[i]<<" ";
//	cout<<"\n";
//	
	if(cnt>=10)
	{
		if(max_res < sum)
			max_res = sum;
			
		return;
	}
	else
	{
		for(int i=0 ; i<4 ; i++)
		{
			if(player[i] == 42)
				continue;
			
			int pre_player_info = player[i];
			int pre_blue_info = blue_player[i];
			
			if(blue_player[i])
				move_player(i,dice[cnt],1);
			else
				move_player(i,dice[cnt],0);
			
			if(player[i] != 42)
			{
				if(find_already(i) == 1)
				{
					player[i] = pre_player_info;
					blue_player[i] = pre_blue_info;
					continue;
				}
			}
			
			if(player[i] == 42)
				play_game(cnt+1, sum);
			else
				play_game(cnt+1,sum+player[i]);
			
			player[i] = pre_player_info;
			blue_player[i] = pre_blue_info;
		}
	}
	
}

int main(void)
{
	for(int i=0 ; i<10 ; i++)
		cin>>dice[i];
	
	init_board();
	play_game(0,0);
	
	cout<<max_res;
	
}
