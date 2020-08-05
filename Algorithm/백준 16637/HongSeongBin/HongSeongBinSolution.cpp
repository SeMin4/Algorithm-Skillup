#include<bits/stdc++.h> 

using namespace std;

vector<int> arr;


int find_cnt(int total)
{
	int cnt=1;
	int sum=0;
	
	for(int i=0; i<arr.size() ; i++)
	{
		sum+=arr[i];
		
		if(sum>total)
		{
			sum=0;
			cnt++;
			i--;	
		}	
	}
	
	return cnt;
	
}

int main(void)
{	
	int n,m;
	int lt=1;
	int rt=0;
	int min_val=2147000000;
	
	cin>>n>>m;
	
	for(int i=0 ; i<n ; i++)
	{
		int temp;
		
		cin>>temp;
		rt+=temp;
		arr.push_back(temp);	
	}
	
	
	while(lt<=rt)
	{
		int mid;
		int res;
		
		mid = (lt+rt)/2;
		
		res = find_cnt(mid);
		
		if(res<=m)
		{
			rt = mid-1;
			if(min_val>mid)
				min_val=mid;
		}
		else
		{
			lt = mid+1;
		}
	}
	
	cout<<min_val;
	
}
