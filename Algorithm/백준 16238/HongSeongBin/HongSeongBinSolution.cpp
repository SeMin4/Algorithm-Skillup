#include <bits/stdc++.h>

using namespace std;

int res;
int zero_num;

void operator-(vector<int> &arr,int n)
{
	for(int i=0 ; i<arr.size() ; i++)
	{
		if(arr[i] == 0)
		{
			zero_num++;
			continue;
		}
		arr[i] = arr[i] - n;
		if(arr[i] == 0)
			zero_num++;
	}
	return;
}

int main(void)
{
	vector<int> arr;
	int n;
	
	cin>>n;
	
	for(int i=0 ; i<n ; i++)
	{
		int temp;
		
		cin>>temp;
		arr.push_back(temp);
	}
	
	while(zero_num < n)
	{
		int idx = max_element(arr.begin(),arr.end()) - arr.begin();	
		res += arr[idx]; arr[idx]=0; zero_num=0;
		arr-1;
	}
	
	cout<<res;
}
