#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdlib>
using namespace std;


int*** list;
int*** visit;
int cnt;
void make_array(int m, int n, int h);
void in_array(int m, int n, int h);
void basic_func(int i, int j, int k);
void store_func(int i, int j, int k);
bool last_check(int m, int n, int h);
pair <int, pair<int, int>> temp;
queue<pair<int, pair<int, int>>> a;
int m, n, h;
int main()
{


	int init_flag = true; // 입력 모든 토마토가 다 익어있을경우
	int flag = true; //모든 토마토가 익지 못할경우 
	int i, j, k;
	int check = 0;
	int day_check = 0;
	cin >> m >> n >> h;

	make_array(m, n, h);
	in_array(m, n, h);

	for (int i = 0; i < h; i++) //초기 설정
	{
		for (int j = 1; j <=n; j++)
		{
			for (int k = 1; k <=m; k++)
			{
				if (list[i][j][k] == 1)
				{
					visit[i][j][k] = 1;
					temp.first = i;
					temp.second.first = j;
					temp.second.second = k;
					a.push(temp);
				}
				if (list[i][j][k] == 0)
					init_flag = false;
			}
		}
	}

	if (init_flag) // 초기에 모든 토마토가 다 익어있을경우 
	{
		cout << 0 << endl;
		return 0;
	}
	day_check = a.size();
	check = 0;
	while (1) //돌면서 체크
	{
		if (a.empty()) //큐가 비었다면
		{
			break;
		}
		temp = a.front();
		a.pop(); 
		check++;
		i = temp.first;  //h
		j = temp.second.first; //n
		k = temp.second.second; //m
		store_func(i, j, k);
		
		if (day_check == check)
		{
			cnt++;
			day_check = a.size();
			check = 0;
		}
		
		
	}
	cnt--;
	flag = last_check(m, n, h);
	if (flag)
	{
		cout << cnt << endl;
	}
	else
	{
		cout << -1 << endl;
	}

	return 0;
}
bool last_check(int m, int n, int h)
{
	bool flag = true;
	for (int i = 0; i < h; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int k = 1; k <= m; k++)
			{
				if (list[i][j][k] == 0)
				{
					flag = false;
					
				}
			}
		}
	}
	return flag;
}
void basic_func(int i, int j, int k)
{
	if (list[i][j - 1][k] == 0)
	{
		list[i][j - 1][k] = 1;
		if (visit[i][j - 1][k] == 0)
		{
			temp.first = i; temp.second.first = j - 1; temp.second.second = k;
			a.push(temp);
			visit[i][j - 1][k] = 1;
		}

	}
	if (list[i][j + 1][k] == 0)
	{
		list[i][j + 1][k] = 1;
		if (visit[i][j + 1][k] == 0)
		{
			temp.first = i; temp.second.first = j + 1; temp.second.second = k;
			a.push(temp);
			visit[i][j + 1][k] = 1;
		}

	}
	if (list[i][j][k - 1] == 0)
	{
		list[i][j][k - 1] = 1;
		if (visit[i][j][k - 1] == 0)
		{
			temp.first = i; temp.second.first = j; temp.second.second = k - 1;
			a.push(temp);
			visit[i][j][k-1] = 1;
		}

	}
	if (list[i][j][k + 1] == 0)
	{
		list[i][j][k + 1] = 1;
		if (visit[i][j][k + 1] == 0)
		{
			temp.first = i; temp.second.first = j; temp.second.second = k + 1;
			a.push(temp);
			visit[i][j][k + 1] = 1;
		}

	}
}
void store_func(int i, int j, int k)
{
	if (h == 1) // 단층일경우
	{
		basic_func(i, j, k);
	}
	else
	{
		if (i == 0)
		{
			basic_func(i, j, k);

			if (list[i + 1][j][k] == 0)
			{
				list[i + 1][j][k] = 1;
				if (visit[i + 1][j][k] == 0)
				{
					temp.first = i + 1; temp.second.first = j; temp.second.second = k;
					a.push(temp);
					visit[i+1][j][k] = 1;
				}
			}
		}
		else if (i == h - 1)
		{
			basic_func(i, j, k);
			if (list[i-1][j][k] == 0)
			{
				list[i-1][j][k] = 1;
				if (visit[i-1][j][k] == 0)
				{
					temp.first = i-1; temp.second.first = j; temp.second.second = k;
					a.push(temp);
					visit[i-1][j][k] = 1;
				}
			}
		}
		else if ( i>=1 && i<=h-2)
		{
			basic_func(i, j, k);
			if (list[i + 1][j][k] == 0)
			{
				list[i + 1][j][k] = 1;
				if (visit[i + 1][j][k] == 0)
				{
					temp.first = i + 1; temp.second.first = j; temp.second.second = k;
					a.push(temp);
				}
			}
			if (list[i - 1][j][k] == 0)
			{
				list[i - 1][j][k] = 1;
				if (visit[i - 1][j][k] == 0)
				{
					temp.first = i - 1; temp.second.first = j; temp.second.second = k;
					a.push(temp);
				}
			}
		}
	}
}
void in_array(int m, int n, int h)
{
	int temp;
	for (int i = 0; i < h; i++)
	{
		for (int j = 1; j <=n; j++)
		{
			for (int k = 1; k <=m; k++)
			{
				cin >> temp;
				list[i][j][k] = temp;
				visit[i][j][k] = 0;
			}
		}
	}
}
void make_array(int m, int n, int h)
{
	
	list = (int***)malloc(sizeof(int**) * h);
	visit = (int***)malloc(sizeof(int**) * h);
	for (int i = 0; i < h; i++)
	{
		list[i] = (int**)malloc(sizeof(int*) * (n+2));
		visit[i] = (int**)malloc(sizeof(int*) * (n+2));
	}
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < n+2; j++)
		{
			list[i][j] = (int*)malloc(sizeof(int) * (m+2));
			visit[i][j] = (int*)malloc(sizeof(int) * (m+2));
		}
	}
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < n + 2; j++)
		{
			for (int k = 0; k < m + 2; k++)
			{

				list[i][j][k] = 9;
				visit[i][j][k] = 9;
			}
		}
	}

}