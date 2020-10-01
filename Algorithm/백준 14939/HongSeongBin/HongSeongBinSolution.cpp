#include <bits/stdc++.h>

using namespace std;

char board[10][10];
int check_push[11];
int dx[4]={1,0,0,0};
int dy[4]={0,-1,1,0};
int res=2147000000;

void copy_board(char source[10][10],char des[10][10])
{
	for(int i=0; i<10 ; i++)
		for(int j=0; j<10 ; j++)
			des[i][j] = source[i][j];
}

void DFS(int start_pos)
{
	if(start_pos>10)
	{
		char temp_board[10][10];
		int push_cnt=0;
		copy_board(board,temp_board);
		for(int i=0; i<10 ; i++)
		{
			if(check_push[i])
			{
				push_cnt++;
				for(int j=0 ; j<4 ; j++)
				{
					if(i+dy[j]<0 || i+dy[j]>=10)
						continue;
					if(board[0+dx[j]][i+dy[j]]=='#')
						board[0+dx[j]][i+dy[j]]='O';
					else
						board[0+dx[j]][i+dy[j]]='#';	
				}
			}
		}
		
		for(int i=1 ; i<10 ; i++)
		{
			for(int j=0 ; j<10 ; j++)
			{
				if(board[i-1][j]=='O')
				{
					push_cnt++;
					board[i-1][j]='#';
					for(int k=0 ; k<4 ; k++)
					{
						if(i+dx[k]<0 || i+dx[k]>=10 || j+dy[k]<0 || j+dy[k]>=10)
							continue;
						if(board[i+dx[k]][j+dy[k]]=='#')
							board[i+dx[k]][j+dy[k]]='O';
						else
							board[i+dx[k]][j+dy[k]]='#';	
					}
				}
			}
		}
		
		for(int i=0 ; i<10 ; i++)
		{
			if(board[9][i]=='O')
			{
				copy_board(temp_board,board);
				return;
			}
		}
		copy_board(temp_board,board);
		if(res>push_cnt)
			res=push_cnt;
		return;
			
	}

	for(int i=start_pos ; i<=10 ; i++)
	{
		check_push[i]=1;
		DFS(i+1);
		check_push[i]=0;
	}
	
}



int main(void)
{	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for(int i=0 ; i<10 ; i++)
	{
		for(int j=0 ; j<10 ; j++)
			cin>>board[i][j];
	}

	DFS(0);
	cout<<res;
}
