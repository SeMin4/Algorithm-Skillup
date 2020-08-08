#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> board;

struct pos
{
    int y, x;
    bool operator<(const pos& p) const
    {
        return make_pair(y,x) < make_pair(p.y,p.x);
    }
    bool isValid()
    {
        return y>=0&&x>=0&&y<n&&x<n;
    }
};

const int dir[4][2] = {{0,1},{1,0},{-1,0},{0,-1}};

int search_fish(int sz, pos& start)
{
    queue<pos> q;
    q.push(start);
    vector<vector<bool>> visited(n,vector<bool>(n,false));
    visited[start.y][start.x] = true;
    pos ret = {999,999};
    int depth = 0;
    bool e = false;
    while(!q.empty())
    {
        ++depth;
        int qsize = q.size();
        ret = {999,999};
        while(qsize--)
        {
            pos here = q.front();
            q.pop();
            for(int i=0;i<4;++i)
            {
                pos next = {dir[i][0]+here.y,dir[i][1]+here.x};
                if(next.isValid() && !visited[next.y][next.x] && board[next.y][next.x] <= sz)
                {
                    if(board[next.y][next.x] != 0 && board[next.y][next.x] < sz)
                    {
                        e = true;
                        ret = min(ret, next);
                    }
                    q.push(next);
                    visited[next.y][next.x] = true;
                }
            }
        }
        if(e) break;
    }
    if(!e) return -1;
    board[ret.y][ret.x] = 0;
    start = ret;
    return depth;
}

int main()
{
    cin>>n;
    board.assign(n,vector<int>(n));
    for(auto& i : board) for(auto& j : i) cin>>j;
    int sz = 2, exp = 2;
    pos p;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            if(board[i][j] == 9)
            {
                p = {i,j};
                board[i][j] = 0;
            }
        }
    }
    int ret = 0;
    while(true)
    {
        int hret = search_fish(sz,p);
        if(hret == -1) break;
        ret += hret;
        if(--exp == 0)
        {
            sz++;
            exp = sz;
        }
    }
    cout<<ret;
}