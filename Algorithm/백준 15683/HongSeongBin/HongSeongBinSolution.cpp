#include<bits/stdc++.h>

using namespace std;

int board[8][8];
int n,m;
int min_res = 2147000000;

void check_cctv(int x,int y,int up,int right,int down, int left)
{
	if(up)
	{
		for(int i=x-1 ; i>=0 ; i--)
		{
			if(board[i][y] == 0)
				board[i][y] = -1;
			else if(board[i][y] == 6)
				break;
		}
	}
	if(right)
	{
		for(int i=y+1 ; i<m ; i++)
		{
			if(board[x][i] == 0)
				board[x][i] = -1;
			else if(board[x][i] == 6)
				break;
		}
	}
	if(down)
	{
		for(int i=x+1 ; i<n ; i++)
		{
			if(board[i][y] == 0)
				board[i][y] = -1;
			else if(board[i][y] == 6)
				break;
		}
	}
	if(left)
	{
		for(int i=y-1 ; i>=0 ; i--)
		{
			if(board[x][i] == 0)
				board[x][i] = -1;
			else if(board[x][i] == 6)
				break;
		}
	}
}

void copy_board(int temp[8][8])
{
	for(int i=0 ; i<n ; i++)
		for(int j=0 ; j<m ; j++)
			temp[i][j] = board[i][j];
}

void reset_board(int temp[8][8])
{
	for(int i=0 ; i<n ; i++)
		for(int j=0 ; j<m ; j++)
			board[i][j] = temp[i][j];
}

void print_board()
{
	for(int i=0 ; i<n ; i++)
	{
		for(int j=0; j<m ; j++)
			cout<<board[i][j]<<" ";
		cout<<"\n";
	}
}

void check_min()
{
	int sum=0;
		
	for(int i=0 ; i<n ; i++)
		for(int j=0 ; j<m ; j++)
			if(board[i][j] == 0)
				sum++;
		
	if(sum<min_res)
		min_res = sum;
}

void DFS(int start_x,int start_y)
{
	if(start_x >= n-1 && start_y > m-1)
	{
		check_min();		
		
//		print_board();
//		cout<<"\n";
	}
	else
	{
		for(int i=start_x ; i<n ; i++)
		{
			for(int j=start_y ; j<m ; j++)
			{
				if(board[i][j]>0 && board[i][j] <=4)
				{
					int temp[8][8];
					
					copy_board(temp);
					
					switch(board[i][j])
					{
						case 1:
							check_cctv(i,j,1,0,0,0);
							DFS(i,j+1);
							reset_board(temp);
							
							check_cctv(i,j,0,1,0,0);
							DFS(i,j+1);
							reset_board(temp);
							
							check_cctv(i,j,0,0,1,0);
							DFS(i,j+1);
							reset_board(temp);
							
							check_cctv(i,j,0,0,0,1);
							DFS(i,j+1);
							reset_board(temp);
							
							break;
						case 2:
							check_cctv(i,j,1,0,1,0);
							DFS(i,j+1);
							reset_board(temp);
							
							check_cctv(i,j,0,1,0,1);
							DFS(i,j+1);
							reset_board(temp);
							
							break;
						case 3:
							check_cctv(i,j,1,1,0,0);
							DFS(i,j+1);
							reset_board(temp);
							
							check_cctv(i,j,0,1,1,0);
							DFS(i,j+1);
							reset_board(temp);
							
							check_cctv(i,j,0,0,1,1);
							DFS(i,j+1);
							reset_board(temp);
							
							check_cctv(i,j,1,0,0,1);
							DFS(i,j+1);
							reset_board(temp);
							
							break;
						case 4:
							check_cctv(i,j,1,1,1,0);
							DFS(i,j+1);
							reset_board(temp);
							
							check_cctv(i,j,0,1,1,1);
							DFS(i,j+1);
							reset_board(temp);
							
							check_cctv(i,j,1,0,1,1);
							DFS(i,j+1);
							reset_board(temp);
							
							check_cctv(i,j,1,1,0,1);
							DFS(i,j+1);
							reset_board(temp);
							
							break;
					}
					
					return;
				}
			}
			start_y=0;
		}
		
		check_min();
//		print_board();
//		cout<<"\n";
	}
}

int main(void)
{
	queue< pair<int,int> > q;
	
	cin>>n>>m;
	
	for(int i=0 ; i<n ; i++)
	{
		for(int j=0 ; j<m ; j++)
		{
			cin>>board[i][j];
			
			if(board[i][j] == 5)
				q.push({i,j});
		}
	}

	while(!q.empty())
	{
		check_cctv(q.front().first,q.front().second,1,1,1,1);
		q.pop();
	}
	DFS(0,0);
	cout<<min_res;
	//print_board();
}
