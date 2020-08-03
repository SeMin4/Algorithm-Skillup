#include<bits/stdc++.h> 

using namespace std;

int max_val=-2147000000;
int cal_size;

void DFS(int start,int pre,vector<int> cal,vector<int> num, vector<char> calculate)
{
	if(start>=cal_size)
	{
		int temp_max;
		int erase_cnt=0;
		
		for(int i=0 ; i<cal.size() ; i++)
		{
			int idx = cal[i]-i;
			
			switch(calculate[idx])
			{
				case '+':
					num[idx] = num[idx]+num[idx+1];
					break;
				case '-':
					num[idx] = num[idx]-num[idx+1];
					break;
					
				case '*':
					num[idx] = num[idx]*num[idx+1];
					break;
			}
			num.erase(num.begin()+idx+1);
			calculate.erase(calculate.begin()+idx);
		
		}
		
		temp_max = num[0];
		
		for(int i=0 ; i<calculate.size() ; i++)
		{
			switch(calculate[i])
			{
				case '+':
					temp_max += num[i+1];
					break;
				case '-':
					temp_max -= num[i+1];
					break;
					
				case '*':
					temp_max *= num[i+1];
					break;
			}
		}
		
		if(temp_max>max_val)
			max_val=temp_max;
		return;
	}
	
	if(pre == 1)
	{
		DFS(start+1,0,cal,num,calculate);
	}
	else
	{
		cal.push_back(start);
		DFS(start+1,1,cal,num,calculate);
		cal.pop_back();
		DFS(start+1,0,cal,num,calculate);	
	}

}

int main(void)
{	
	int n;
	vector<int> cal;
	vector<int> num;
	vector<char> calculate;
	
	cin>>n;
	
	cal_size = n/2;
	
	for(int i=0 ; i<n ; i++)
	{
		char temp;
		
		cin>>temp;
		
		if(temp>='0'&&temp<='9')
		{
			num.push_back(temp-'0');
		}
		else
			calculate.push_back(temp);
	}
	
	DFS(0,0,cal,num,calculate);
	
	cout<<max_val;
}
