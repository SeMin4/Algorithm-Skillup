#include<bits/stdc++.h>

#define left 6
#define right 2

using namespace std;

char tire[4][8];

void right_rotate(int cur)
{
	char final_temp = tire[cur][7];
	
	for(int i=7 ; i>0 ; i--)
		tire[cur][i] = tire[cur][i-1];
	tire[cur][0] = final_temp;
}

void left_rotate(int cur)
{
	char final_temp = tire[cur][0];
	
	for(int i=0 ; i<7 ; i++)
		tire[cur][i] = tire[cur][i+1];
	tire[cur][7] = final_temp;
}

void rotate_tire(int m,int dir)
{
	int check_rotate[4]={0,};
	int cur = m-1;

	check_rotate[cur]=dir;

	//right
	for(int i=cur+1 ; i<4 ; i++)
	{
		if(tire[cur][right] != tire[i][left])
		{
			if(check_rotate[cur] == -1)
				check_rotate[i] = 1;
			else
				check_rotate[i] = -1;
			cur = i;
		}
		else
			break;
	}
	
	cur = m-1;
	//left
	for(int i=cur-1 ; i>=0 ; i--)
	{
		if(tire[cur][left] != tire[i][right])
		{
			if(check_rotate[cur] == -1)
				check_rotate[i] = 1;
			else
				check_rotate[i] = -1;
			cur = i;
		}
		else
			break;
	}
	

	for(int i=0 ; i<4 ; i++)
	{
		if(check_rotate[i]==1)
			right_rotate(i);
		else if(check_rotate[i]==-1)
			left_rotate(i);
	}
	
}


int main(){
	int n;
	int m,dir;
	int res=0;
	

	for(int i=0 ; i<4 ; i++)
		for(int j=0 ; j<8 ; j++)
			cin>>tire[i][j];
	
	cin>>n;

	for(int i=0 ; i<n ; i++)
	{
		cin>>m>>dir;
		
		rotate_tire(m,dir);
	}


	for(int i=0 ; i<4 ; i++)
		if(tire[i][0]=='1')
			res+=pow(2,i);
	
	cout<<res;
	
}
