#include <string>
#include <vector>

using namespace std;

vector<bool> selected;
int ret = 0;

vector<vector<int>> adj;
vector<int> matched;
vector<bool> visited;

bool dfs(int here)
{
    if (visited[here])
        return false;
    visited[here] = true;
    for (auto next : adj[here])
    {
        if (matched[next] == -1 || dfs(matched[next]))
        {
            matched[next] = here;
            return true;
        }
    }
    return false;
}

bool check(vector<string> &user_id, vector<string> &banned_id)
{
    matched.assign(user_id.size(), -1);
    int cnt = 0;
    for (int i = 0; i < user_id.size(); ++i)
    {
        if (selected[i])
        {
            visited.assign(user_id.size(), false);
            if (dfs(i))
            {
                ++cnt;
            }
        }
    }
    return cnt == banned_id.size();
}

void bf(int here, vector<string> &user_id, vector<string> &banned_id)
{
    if (here == user_id.size())
    {
        int cnt = 0;
        for (auto i : selected)
        {
            if (i)
                ++cnt;
        }
        if (cnt == banned_id.size())
        {
            if (check(user_id, banned_id))
                ++ret;
        }
        return;
    }
    selected[here] = true;
    bf(here + 1, user_id, banned_id);
    selected[here] = false;
    bf(here + 1, user_id, banned_id);
}

bool id_match(string &a, string &b)
{
    if (a.size() != b.size())
        return false;
    for (int i = 0; i < a.size(); ++i)
    {
        if (b[i] == '*')
            continue;
        if (a[i] != b[i])
            return false;
    }
    return true;
}

int solution(vector<string> user_id, vector<string> banned_id)
{
    int answer = 0;
    selected.assign(user_id.size(), false);
    adj.assign(user_id.size(), vector<int>());
    for (int i = 0; i < user_id.size(); ++i)
    {
        for (int j = 0; j < banned_id.size(); ++j)
        {
            if (id_match(user_id[i], banned_id[j]))
            {
                adj[i].push_back(j);
            }
        }
    }
    bf(0, user_id, banned_id);
    return ret;
}