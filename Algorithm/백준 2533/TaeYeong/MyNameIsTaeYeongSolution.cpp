#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;


vector<int> friends_tree[1000001];
int cache[1000001][2];


int solve(int root, int is_EA){
    int &ret = cache[root][is_EA];
    if(ret != -1)
        return ret;
    
    if(friends_tree[root].empty()){
        if(is_EA == 1)
            return 1;
        else
            return 0;
    }
    
    
    
    // EA일때
    if( is_EA == 1 ){
        ret = 1;
        for( int next : friends_tree[root] ){
            ret += min(solve(next, 0), solve(next, 1));
        }
    }
    
    // EA가 아닐때
    else{
        ret = 0;
        for( int next : friends_tree[root] ){
            ret += solve(next, 1);
        }
    }
    
    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
 
    int n;
    cin >> n;
    
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        friends_tree[u].push_back(v);
    }
    
    memset(cache, -1, sizeof(cache));
    
    cout << min(solve(1, 0), solve(1, 1)) <<'\n';
    
    return 0;
}

