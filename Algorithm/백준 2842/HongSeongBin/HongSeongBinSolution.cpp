#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1e9+7;


int main(){
	int n;
	int num[1000001];
	int check[1000001];
	long long k;
	long long dp[1000001];
	long long res=1;
	long long cycle_vertex=0;
	
	vector<int> cycle;
	
	cin>>n>>k;
	
	for(int i=1 ; i<=n ; i++)
		cin>>num[i];
		
	dp[1] = k;
	dp[2] = k*(k-1)%MOD;
	dp[3] = dp[2]*(k-2)%MOD;
	
	for(int i=4 ; i<=n ; i++)
		dp[i] = (dp[i-2]*(k-1) + dp[i-1]*(k-2))%MOD;

	check[1]=1;
	
	for(int i=1 ; i<=n ; i++)
	{
		if(check[num[i]]==1)
			cycle.push_back(i-num[i]+1);
			
		check[num[i]]=1;	
	}
	
	for(int i=0 ; i<cycle.size() ;i++)
	{
		res = (res*cycle[i])%MOD;
		cycle_vertex += cycle[i];
	}
	
	if(n-cycle_vertex>0)
		res = res*pow(n-cycle_vertex,k-1);
	
	cout<<res;
	
}
