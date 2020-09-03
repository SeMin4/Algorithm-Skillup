#include<bits/stdc++.h>

using namespace std;

int MOD = 20170805;
int board[501][501];

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
    int answer = 0;
    int i;
    
    for(i=0 ; i<n ; i++)
    {
        if(city_map[0][i]==0 || city_map[0][i] == 2)
        {
            board[0][i] = 1;
        }
        else 
            break;
    }
    if(city_map[0][n-1] == 2)
        board[0][n-1]=0;
    
    if(i!=n)
    {
        for(int j=i ; j<n ; j++)
            board[0][j] = 0;
    }
    
    i=0;
    for(i=0 ; i<m ; i++)
    {
        if(city_map[i][0]==0 || city_map[i][0] == 2)
        {
            board[i][0] = 1;
        }
        else 
            break;
    }
     if(city_map[m-1][0] == 2)
        board[m-1][0]=0;
    
    if(i!=m )
    {
        for(int j=i ; j<m ; j++)
            board[j][0] = 0;
    }
    for(int i=1 ; i<m ; i++)
    {
        for(int j=1 ; j<n ; j++)
        {
            int up = board[i-1][j];
            int left = board[i][j-1];
            
            if(city_map[i-1][j] == 2)
            {
                int k;
                
                for(k=i-2 ; k>=0 ; k--)
                {
                    if(city_map[k][j] != 2)
                    {
                        up = board[k][j];
                        break;
                    }
                }
                
                if(k<0)
                    up = 0;
            }
            
            if(city_map[i][j-1] == 2)
            {
                int k;
                
                for(k=j-2 ; k>=0 ; k--)
                {
                    if(city_map[i][k] != 2)
                    {
                        left = board[i][k];
                        break;
                    }
                }
                
                if(k<0)
                    left = 0;
            }
            
            if(city_map[i][j] == 1)
                board[i][j] = 0;
            else
            {
                if(board[i-1][j] == 0)
                {
                    board[i][j] = left;
                }
                else if(board[i][j-1] == 0)
                {
                    board[i][j] = up;
                }
                else
                    board[i][j] = (up+left)%MOD;
            }
        }
    }
    
    // for(int i=0 ; i<m ; i++)
    // {
    //     for(int j=0 ; j<n ; j++)
    //         cout<<board[i][j]<<" ";
    //     cout<<"\n";
    // }
    
    answer = board[m-1][n-1];
    return answer%MOD;
}
