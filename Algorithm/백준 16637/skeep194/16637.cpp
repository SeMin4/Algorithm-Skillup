#include <bits/stdc++.h>

using namespace std;
int n;
string s;
vector<bool> galho(25,false);

int subcal(const string& str)
{
    if(str[1] == '+')
    {
        return str[0] + str[2] - '0' - '0';
    }
    else if(str[1] == '-')
    {
        return (str[0]-'0') - (str[2]-'0');
    }
    else if(str[1] == '*')
    {
        return (str[0]-'0')*(str[2]-'0');
    }
}

int cal()
{
    vector<char> oper;
    vector<int> num;
    for(int i=1;i<s.size();i+=2)
    {
        if(galho[i])
        {
            num.push_back(subcal(s.substr(i-1,3)));
            if(i+2 < s.size())
            {
                oper.push_back(s[i+2]);
                i+=2;
            }
        }
        else
        {
            num.push_back(s[i-1]-'0');
            oper.push_back(s[i]);
        }
    }
    num.push_back(s.back()-'0');
    int ret = num[0];
    for(int i=0;i<oper.size();++i)
    {
        if(oper[i] == '+')
        {
            ret += num[i+1];
        }
        else if(oper[i] == '-')
        {
            ret -= num[i+1];
        }
        else
        {
            ret *= num[i+1];
        }
    }
    return ret;
}

int solve(int here)
{
    if(here >= s.size()) return cal();
    int ret;
    ret = solve(here + 2);
    galho[here] = true;
    ret = max(ret,solve(here + 4));
    galho[here] = false;
    return ret;
}

int main()
{
    cin>>n>>s;
    cout<<solve(1);
}