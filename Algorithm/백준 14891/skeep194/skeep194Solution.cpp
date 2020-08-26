#include <bits/stdc++.h>

using namespace std;

vector<deque<int>> arr;

int main()
{
    arr.resize(4);
    for (auto &i : arr)
    {
        i.resize(8);
        for (int j = 0; j < 8; ++j)
        {
            scanf(" %1d", &i[j]);
        }
    }
    int q;
    cin >> q;
    bool check[4];
    while (q--)
    {
        memset(check, 0, sizeof(check));
        int a, b;
        cin >> a >> b;
        a--;
        check[a] = true;
        for (int i = a - 1; i >= 0; --i)
        {
            if (arr[i][2] == arr[i + 1][6])
                break;
            check[i] = true;
        }
        for (int i = a + 1; i < 4; ++i)
        {
            if (arr[i][6] == arr[i - 1][2])
                break;
            check[i] = true;
        }
        bool clockwise = b == 1;
        for (int i = a; i >= 0; --i, clockwise = !clockwise)
        {
            if (!check[i])
                continue;
            if (clockwise)
            {
                int k = arr[i].back();
                arr[i].pop_back();
                arr[i].push_front(k);
            }
            else
            {
                int k = arr[i].front();
                arr[i].pop_front();
                arr[i].push_back(k);
            }
        }
        clockwise = b == 1;
        for (int i = a; i < 4; ++i, clockwise = !clockwise)
        {
            if (!check[i])
                continue;
            if (i == a)
                continue;
            if (clockwise)
            {
                int k = arr[i].back();
                arr[i].pop_back();
                arr[i].push_front(k);
            }
            else
            {
                int k = arr[i].front();
                arr[i].pop_front();
                arr[i].push_back(k);
            }
        }
    }
    int ret = 0;
    for (int i = 0; i < 4; ++i)
    {
        if (arr[i][0] == 1)
        {
            ret += 1 << i;
        }
    }
    cout << ret;
}