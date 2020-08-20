#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<string> arr;
vector<int> p;
int ret = 0;

void bf(int here, int kk)
{
    if (kk > k)
        return;
    if (here + 'a' == 'a' || here + 'a' == 'n' || here + 'a' == 't' || here + 'a' == 'i' || here + 'a' == 'c')
    {
        bf(here + 1, kk);
        return;
    }
    if (here == 26)
    {
        if (kk == k)
        {
            int hret = 0;
            for (int i = 0; i < n; ++i)
            {
                bool pp = true;
                for (int j = 0; j < arr[i].size(); ++j)
                {
                    if (p[arr[i][j] - 'a'] == 0)
                    {
                        pp = false;
                        break;
                    }
                }
                if (pp)
                    ++hret;
            }
            ret = max(ret, hret);
        }
        return;
    }
    bf(here + 1, kk);
    p[here] = 1;
    bf(here + 1, kk + 1);
    p[here] = 0;
}

int main()
{
    cin >> n >> k;
    arr.resize(n);
    for (auto &i : arr)
        cin >> i;
    p.assign(26, 0);
    if (k < 5)
    {
        cout << 0;
        return 0;
    }
    p[0] = 1;
    p['n' - 'a'] = 1;
    p['t' - 'a'] = 1;
    p['i' - 'a'] = 1;
    p['c' - 'a'] = 1;
    bf(0, 5);
    cout << ret;
}