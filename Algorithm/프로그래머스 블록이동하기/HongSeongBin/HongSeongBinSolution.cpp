#include<bits/stdc++.h>

//a:97 A:65
using namespace std;

int board[5][5] = {{0, 0, 0, 1, 1},{0, 0, 0, 1, 0},{0, 1, 0, 1, 1},{1, 1, 0, 0, 1},{0, 0, 0, 0, 0}};
int check_1[5][5];
int check_2[5][5];
int min_res = 2147000000;
int N;

struct Pos{
	int x;
	int y;
};

struct Muzi{
	Pos first;
	Pos second;
	bool is_stand;
};

Muzi muzi;

void init_muzi()
{
	muzi.first.x=0;
	muzi.first.y=0;
	
	muzi.second.x=0;
	muzi.second.y=1;
	
	muzi.is_stand=false;
	
	check_1[0][0]=1;
	check_1[0][1]=1;
	
	
}

void shift_right()
{
	muzi.first.y++;
	muzi.second.y++;
}

void shift_left()
{
	muzi.first.y--;
	muzi.second.y--;
}

void shift_up()
{
	muzi.first.x--;
	muzi.second.x--;
}

void shift_down()
{
	muzi.first.x++;
	muzi.second.x++;
}

int is_rotatable()
{
	if(muzi.is_stand == true)  // 세로 
	{
		if(muzi.second.y+1 < N && board[muzi.second.x][muzi.second.y+1] != 1 && board[muzi.second.x-1][muzi.second.y+1]!=1)
		{
			return 1;
		}
		
		if(muzi.second.y-1 >=0 && board[muzi.second.x][muzi.second.y-1]!=1 && board[muzi.second.x-1][muzi.second.y-1]!=1)
		{
			return 2;
		}
	}
	else//가로  
	{
		//위로올리기
		if(muzi.first.x-1>=0 && board[muzi.first.x-1][muzi.first.y]!=1 && board[muzi.first.x-1][muzi.first.y+1]!=1 )
		{
			return 1;
		}
		
		if(muzi.first.x+1<N && board[muzi.first.x+1][muzi.first.y]!=1 && board[muzi.first.x+1][muzi.first.y+1]!=1)
		{
			return 2;
		}
	}
	
	return -1; 
}
void DFS(int cnt)
{
	cout<<muzi.first.x<<" "<<muzi.first.y<<" "<<muzi.second.x<<" "<<muzi.second.y<<" "<<cnt<<"\n";
	if(muzi.second.x == N-1 && muzi.second.y == N-1)
	{
		if(cnt < min_res)
			min_res = cnt;
		return;
	}
	
	if(is_rotatable() > 0)
	{
		if(muzi.is_stand == true)//세로 
		{
			if(is_rotatable()==1)
			{
				Muzi temp = muzi;
				
				muzi.second.x = muzi.first.x;
				muzi.second.y = muzi.first.y+1;
				muzi.is_stand = false;
				if(check_1[muzi.first.x][muzi.first.y] != 0 && check_1[muzi.second.x][muzi.second.y]!= 0 && check_1[muzi.second.x][muzi.second.y]<=cnt)
			 	{
			 		muzi=temp;
				}
				else
				{	
					check_1[muzi.first.x][muzi.first.y]=cnt;
				 	check_1[muzi.second.x][muzi.second.y]=cnt;
					DFS(cnt+1);
					
					muzi = temp;
				}
				
				muzi.first = muzi.second;
				muzi.second.y++;
				muzi.is_stand = false;
				if(check_1[muzi.first.x][muzi.first.y]!= 0 && check_1[muzi.second.x][muzi.second.y]!= 0  && check_1[muzi.second.x][muzi.second.y]<=cnt)
			 	{
			 		muzi=temp;
				}
				else
				{	
					check_1[muzi.first.x][muzi.first.y]=cnt;
				 	check_1[muzi.second.x][muzi.second.y]=cnt;
					DFS(cnt+1);
					muzi = temp;
				}
			}
			else
			{
				Muzi temp = muzi;
				
				muzi.first.y--;
				muzi.second.x--;
				muzi.is_stand = false;
				if(check_1[muzi.first.x][muzi.first.y] != 0 && check_1[muzi.second.x][muzi.second.y]!= 0  && check_1[muzi.second.x][muzi.second.y]<=cnt)
			 	{
			 		muzi=temp;
				}
				else
				{
					check_1[muzi.first.x][muzi.first.y]=cnt;
				 	check_1[muzi.second.x][muzi.second.y]=cnt;
					DFS(cnt+1);
					
					muzi = temp;
				}
				muzi.first.x++;
				muzi.first.y--;
				muzi.is_stand = false;
				if(check_1[muzi.first.x][muzi.first.y]!= 0 && check_1[muzi.second.x][muzi.second.y]!= 0  && check_1[muzi.second.x][muzi.second.y]<=cnt)
			 	{
			 		muzi=temp;
				}
				else
				{
					check_1[muzi.first.x][muzi.first.y]=cnt;
				 	check_1[muzi.second.x][muzi.second.y]=cnt;
					DFS(cnt+1);
					muzi = temp;
				}
			}
			 
			 
		}	
		else //가로  
		{	
			if(is_rotatable()==1)
			{
				Muzi temp = muzi;
				
				muzi.first.x--;
				muzi.second.y--;
				muzi.is_stand = true;
				if(check_2[muzi.first.x][muzi.first.y] != 0 && check_2[muzi.second.x][muzi.second.y]!= 0  && check_2[muzi.second.x][muzi.second.y]<=cnt) 
			 	{
			 		muzi=temp;
				}
				else
				{	
					check_2[muzi.first.x][muzi.first.y]=cnt;
				 	check_2[muzi.second.x][muzi.second.y]=cnt;
					DFS(cnt+1);
					
					muzi = temp;
				}
				
				muzi.first.y = muzi.second.y;
				muzi.first.x = muzi.second.x-1;
				muzi.is_stand = true;
				if(check_2[muzi.first.x][muzi.first.y] != 0 && check_2[muzi.second.x][muzi.second.y]!= 0  && check_2[muzi.second.x][muzi.second.y]<=cnt)
			 	{
			 		muzi=temp;
				}
				else
				{	
					check_2[muzi.first.x][muzi.first.y]=cnt;
				 	check_2[muzi.second.x][muzi.second.y]=cnt;
					DFS(cnt+1);
					muzi = temp;
				}
			}
			else
			{
				Muzi temp = muzi;
				
				muzi.second.y = muzi.first.y;
				muzi.second.x = muzi.first.x+1;
				muzi.is_stand = true;
				if(check_2[muzi.first.x][muzi.first.y] != 0 && check_2[muzi.second.x][muzi.second.y]!= 0  && check_2[muzi.second.x][muzi.second.y]<=cnt)
			 	{
			 		muzi=temp;
				}
				else
				{	
					check_2[muzi.first.x][muzi.first.y]=cnt;
				 	check_2[muzi.second.x][muzi.second.y]=cnt;
					DFS(cnt+1);
					
					muzi = temp;
				}
				
				muzi.first=muzi.second;
				muzi.second.x++;
				muzi.is_stand = true;
				if(check_2[muzi.first.x][muzi.first.y]!= 0 && check_2[muzi.second.x][muzi.second.y]!=0   && check_2[muzi.second.x][muzi.second.y]<=cnt)
			 	{
			 		muzi=temp;
				}
				else
				{	
					check_2[muzi.first.x][muzi.first.y]=cnt;
				 	check_2[muzi.second.x][muzi.second.y]=cnt;
					DFS(cnt+1);
					muzi = temp;
				}
				
			}
			
		}
	}
	
	if(muzi.is_stand == true)  // 세로 
	{
		if(muzi.second.x+1 < N)
		{
			
		 if(board[muzi.second.x+1][muzi.second.y]==0)
		 {
		 	Muzi temp = muzi;
		 	shift_down();
		 	
		 	if(check_2[muzi.first.x][muzi.first.y] != 0 && check_2[muzi.second.x][muzi.second.y]!= 0  && check_2[muzi.second.x][muzi.second.y]<=cnt)
		 	{
		 		muzi=temp;
			}
			else
			{	
			 //	board[muzi.second.x+1][muzi.second.y]=-1;
			 	check_2[muzi.first.x][muzi.first.y]=cnt;
			 	check_2[muzi.second.x][muzi.second.y]=cnt;
			 	DFS(cnt+1);
			 //	board[muzi.second.x+1][muzi.second.y]=0;
			 	muzi=temp;
		 	}
		 }
	}
		 if(muzi.first.x-1 >=0 )
		{
		
		 	
		 if(board[muzi.first.x-1][muzi.first.y]==0)
		 {
		 	Muzi temp = muzi;
		 	shift_up();
		 	if(check_2[muzi.first.x][muzi.first.y]!= 0 && check_2[muzi.second.x][muzi.second.y]!= 0  && check_2[muzi.second.x][muzi.second.y]<=cnt)
		 	{
		 		muzi=temp;
			}
			else
			{
			 	check_2[muzi.first.x][muzi.first.y]=cnt;
			 	check_2[muzi.second.x][muzi.second.y]=cnt;
			 //	board[muzi.second.x-1][muzi.second.y]=-1;
			 	DFS(cnt+1);
			 //	board[muzi.second.x-1][muzi.second.y]=0;
			 	muzi=temp;
			 }
		 }
		}
	}
	else //가로 
	{
		if(muzi.second.y+1 < N)
		{
		
		
		 if(board[muzi.second.x][muzi.second.y+1]==0)
		 {
		 	Muzi temp = muzi;
		 	shift_right();
		 	if(check_1[muzi.first.x][muzi.first.y] != 0 && check_1[muzi.second.x][muzi.second.y]!= 0  && check_1[muzi.second.x][muzi.second.y]<=cnt)
		 	{
		 		muzi=temp;
			}
			else
			{
			 	check_1[muzi.first.x][muzi.first.y]=cnt;
			 	check_1[muzi.second.x][muzi.second.y]=cnt;
		//	 	board[muzi.second.x][muzi.second.y+1]=-1;
			 	DFS(cnt+1);
		//	 	board[muzi.second.x][muzi.second.y+1]=0;
			 	muzi=temp;
			 }
		 }
		 
		}
		
		 if(muzi.first.y-1 >=0 )
		 {
		 	
		 if(board[muzi.first.x][muzi.first.y-1]==0)
		 {
		 	Muzi temp = muzi;
		 	shift_left();
		 	if(check_1[muzi.first.x][muzi.first.y] != 0 && check_1[muzi.second.x][muzi.second.y]!= 0  && check_1[muzi.second.x][muzi.second.y]<=cnt)
		 	{
		 		muzi=temp;
			}
			else
			{
			 	check_1[muzi.first.x][muzi.first.y]=cnt;
			 	check_1[muzi.second.x][muzi.second.y]=cnt;
		//	 	board[muzi.second.x][muzi.second.y-1]=-1;
			 	DFS(cnt+1);
		//	 	board[muzi.second.x][muzi.second.y-1]=0;
			 	muzi=temp;
			 }
		 }
		}
		 
	}
	
}
int main(){
	N=5;
	init_muzi();
	DFS(1);
	
	cout<<min_res;
}
