#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
const int INF = 987654321;
int cache[15][31][1 << 8];

int dp(int start, int here, int used, vector<int> &dist, vector<int> &weak)
{
    if (here >= start + weak.size() / 2)
        return 0;
    int &ret = cache[start][here][used];
    if (ret != -1)
        return ret;
    ret = INF;
    for (int i = 0; i < dist.size(); ++i)
    {
        if (!(used & (1 << i)))
        {
            int next = upper_bound(weak.begin(), weak.end(), weak[here] + dist[i]) - weak.begin();
            ret = min(ret, dp(start, next, used | (1 << i), dist, weak) + 1);
        }
    }
    return ret;
}

int solution(int n, vector<int> weak, vector<int> dist)
{
    int answer = 0;
    memset(cache, -1, sizeof(cache));
    int ret = INF;
    int sz = weak.size();
    for (int i = 0; i < sz; ++i)
    {
        weak.push_back(weak[i] + n);
    }
    for (int i = 0; i < weak.size() / 2; ++i)
    {
        ret = min(ret, dp(i, i, 0, dist, weak));
    }
    return ret >= INF ? -1 : ret;
}