#include <iostream>


using namespace std;
int find_max(int a, int b);
int main()
{
	int n=0, m=0;
	cin >> n >> m;

	int** dp = (int**)malloc(sizeof(int*)*(n));
	int* memory = (int*)malloc(sizeof(int) * (n));
	int* cost = (int*)malloc(sizeof(int) * (n));
	for (int i = 0; i < n; i++)
		dp[i] = (int*)malloc(sizeof(int) * 10001);

	for (int i = 0; i < n; i++)
		cin >> memory[i];

	for (int i = 0; i < n; i++)
		cin >> cost[i];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= 10000; j++)
		{
			if (i == 0)
			{
				if (j >= cost[i])
					dp[i][j] = memory[i];
				else
					dp[i][j] = 0;
			}
			else
			{
				if (j >= cost[i])
				{
					dp[i][j] = find_max(dp[i - 1][j - cost[i]] + memory[i], dp[i - 1][j]);
				}
				else
					dp[i][j] = dp[i - 1][j];
			}
		}
	}
	for (int i = 0; i <= 10000; i++)
	{
		for(int j=0; j<n; j++)
			if (dp[j][i] >= m)
			{
				cout << i<< endl;
				return 0;
			}
	}

			return 0;
}

int find_max(int a, int b)
{
	if (a >= b)
		return a;
	else
		return b;
}