#include<bits/stdc++.h> 

using namespace std;


int max_val=-2147000000;
int size;


struct Item
{
	int val;
	int sub;
	
	Item(int a, int b)
	{
		val=a;
		sub=b;
	}
};


void print_board(vector< vector<Item> > board)
{
	for(int i=0 ; i<size ; i++)
	{
		for(int j=0 ; j<size ; j++)
			cout<<board[i][j].val<<" ";
		cout<<"\n";			
	}
}

void DFS(int cnt,int dir,vector< vector<Item> > board)
{

//	print_board(board);
//	printf("\n");
//	printf("%d\n",p[cnt]);
//	p.push_back(dir);
	if(cnt>5)
	{
     //   print_board(board);
      //  printf("\n");
		for(int i=0 ; i<size ; i++)
		{
			for(int j=0 ; j<size ; j++)
			{
				if(board[i][j].val > max_val)
					max_val=board[i][j].val;
			}
		}
		return;
	}
	else
	{	

		switch(dir)
		{
			//right 
			case 1:
			//	printf("right\n");
				for(int i=0 ; i<size; i++)
				{
					for(int j=size-2 ; j>=0 ; j--)
					{
						int k=j;
						
						while(k<size-1 && (board[i][k+1].val == 0 || board[i][k+1].val==board[i][k].val))
						{
							if(board[i][k].val==0)
								{
									break;
								}
		
							if(board[i][k+1].val==board[i][k].val)
							{
								if(board[i][k+1].sub==1|| board[i][k].sub==1)
								{
									break;
								}
								
								board[i][k+1].val = board[i][k].val*2;
								board[i][k+1].sub=1;
							}
							else
								board[i][k+1] = board[i][k];
							board[i][k].val=0;
							board[i][k].sub=0;
							k++;							
						}
					}
				}
			//	printf("right end\n");
				break;
			
			//down	
			case 2:
			//	printf("down\n");
				for(int i=0 ; i<size; i++)
				{
					for(int j=size-2 ; j>=0 ; j--)
					{
						int k=j;
						
		
						while(k<size-1 && (board[k+1][i].val == 0 || board[k+1][i].val==board[k][i].val))
						{
			
								if(board[k][i].val==0)
								{
									break;
								}
							if(board[k+1][i].val==board[k][i].val)
							{
								if(board[k+1][i].sub==1|| board[k][i].sub==1)
								{
									break;
								}
						
								board[k+1][i].val = board[k][i].val*2;
								board[k+1][i].sub=1;
							}
							else
								board[k+1][i] = board[k][i];
							board[k][i].val=0;
							board[k][i].sub=0;
							k++;	
		
							if(k==size-1)
								break;				
						}

					}
				}

				break;
			
			//left
			case 3:
			//	printf("left\n");
				for(int i=0 ; i<size; i++)
				{
					for(int j=1 ; j<size ; j++)
					{
						int k=j;
						
						while(k>0 && (board[i][k-1].val == 0 || board[i][k-1].val==board[i][k].val))
						{
							if(board[i][k].val==0)
							{
								break;
							}
							if(board[i][k-1].val==board[i][k].val)
							{
								if(board[i][k-1].sub==1 || board[i][k].sub==1)
								{
									break;
								}
								
								board[i][k-1].val = board[i][k].val*2;
								board[i][k-1].sub=1;
							}
							else
								board[i][k-1] = board[i][k];
							board[i][k].val=0;
							board[i][k].sub=0;
							k--;							
						}
					}
				}
			//	printf("left end\n");
				break;
			
			//up	
			case 4:
			//	printf("up\n");
				for(int i=0 ; i<size; i++)
				{
					for(int j=1 ; j<size ; j++)
					{
						int k=j;
						
						while(k>0 && (board[k-1][i].val == 0 || board[k-1][i].val==board[k][i].val))
						{
							if(board[k][i].val==0)
							{
								break;
							}
							if(board[k-1][i].val==board[k][i].val)
							{
								if(board[k-1][i].sub==1|| board[k][i].sub==1)
								{
								
									break;
								}
								
								board[k-1][i].val = board[k][i].val*2;
								board[k-1][i].sub=1;
							}
							else
								board[k-1][i] = board[k][i];
							board[k][i].val=0;
							board[k][i].sub=0;
							k--;							
						}
					}
				}
			//	printf("up end\n");
				break;
		}
		
	}
	
	
	for(int i=0 ; i<size ; i++)
	{
		for(int j=0 ; j<size ; j++)
		{
			board[i][j].sub=0;
		}
	}

	
	for(int i=1; i<=4 ; i++)
	{
		DFS(cnt+1,i,board);
	}
	

}

int main(void)
{

	cin>>size;

	vector< vector<Item> > board(20);
	for(int i=0 ; i<size ; i++)
	{
		for(int j=0 ; j<size ; j++)
		{
			int temp;
		
			cin>>temp;
			board[i].push_back(Item(temp,0));

		}
	}

	DFS(0,0,board);
	cout<<max_val;
}
