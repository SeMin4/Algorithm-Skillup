#include <bits/stdc++.h>
using namespace std;
#define int ll
typedef long long ll;
const ll MOD = 1e9+7;

int n, k;
vector<int> adj;
vector<int> visited;
ll cache[1000001];

ll modpow(ll a, ll b)
{
    if(b == 0) return 1;
    if(b % 2 == 1) return a * modpow(a,b-1) % MOD;
    ll half = modpow(a,b/2);
    return half*half%MOD;
}

int visitcnt;
vector<int> visitnum;
int cyclecnt;
ll ret = 1;
void dfs(int here, int num)
{
    for(int i=here;i!=-1;i=adj[i])
    {
        visited[i] = num;
        visitnum[i] = visitcnt++;
        int next = adj[i];
        if(visited[next] != -1)
        {
            if(visited[next] == num)
            {
                cyclecnt += visitnum[i]-visitnum[next]+1;
                ret *= cache[visitnum[i]-visitnum[next]+1];
                ret %= MOD;
                return;
            }
            else return;
        }
    }
}

int32_t main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>n>>k;
    adj.assign(n,-1);
    visited.assign(n,-1);
    visitnum.assign(n,-1);
    for(int i=0;i<n;++i)
    {
        int x;
        cin>>x;
        x--;
        adj[i] = x;
    }
    int cnt = 0;
    cache[1] = k;
    cache[2] = k*(k-1)%MOD;
    cache[3] = k*(k-1)%MOD*(k-2)%MOD;
    for(int i=4;i<=n;++i)
    {
        cache[i] = (k*modpow((k-1),i-1)%MOD+MOD-cache[i-1])%MOD;
    }
    for(int i=0;i<n;++i)
    {
        if(visited[i] == -1) dfs(i,cnt++);
    }
    int remain = n-cyclecnt;
    ret *= modpow(k-1,remain);
    ret %= MOD;
    cout<<ret;
}