#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, k;
vector<vector<char>> board;
vector<vector<int>> height;
//vector<pair<int,int>> start;

pair<int,int> p;

const int dir[8][2] = {{1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,-1},{1,-1},{-1,1}};

bool isInRange(int a, int b, int chk)
{
    return a <= chk && chk <= b;
}

bool isValid(int a, int b)
{
    return a>=0&&b>=0&&a<n&&b<n;
}
bool visited[51][51];
int tcnt;
bool check(int a, int b)
{
    for(int i=0;i<n;++i) for(int j=0;j<n;++j) visited[i][j] = false;
    queue<pair<int,int>> q;
    q.push(p);
    visited[p.first][p.second] = true;
    if(!isInRange(a,b,height[p.first][p.second])) return false;
    int cnt = 0;

    while(!q.empty())
    {
        auto here = q.front();
        q.pop();
        for(int i=0;i<8;++i)
        {
            int ny = dir[i][0] + here.first;
            int nx = dir[i][1] + here.second;
            if(isValid(ny,nx) && !visited[ny][nx] && isInRange(a,b,height[ny][nx]))
            {
                if(board[ny][nx] == 'K') ++cnt;
                visited[ny][nx] = true;
                q.push({ny,nx});
            }
        }
    }
    return cnt == tcnt;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>n;
    board.assign(n,vector<char>(n));
    for(auto& i : board) for(auto& j : i) cin>>j;
    height.assign(n,vector<int>(n));
    for(auto& i : height) for(auto& j : i) cin>>j;
    int ret = 1e9;
    vector<int> iter;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            if(board[i][j] == 'P') p = {i,j};
            if(board[i][j] == 'K') tcnt++;
            iter.push_back(height[i][j]);
        }
    }
    sort(iter.begin(),iter.end());
    iter.erase(unique(iter.begin(),iter.end()),iter.end());
    int cnt = 0;
    int low = 0, high = 0;
    while(low <= high && high < iter.size())
    {
        if(check(iter[low],iter[high]))
        {
            ret = min(ret, iter[high]-iter[low]);
            if(low == high) break;
            ++low;
        }
        else
        {
            ++high;
        }
    }
    cout<<ret;
}