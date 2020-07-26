#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;
/*dfs 이용해서 매순간 4방향 탐색으로 진행했는데 dfs 함수가 리턴될경우 제값으로 안돌아오는게 문제인지, 이동과정에서 실수가있는건지 모르겠음.*/

vector<vector <int>> init(vector<vector<int>> &arr, int n);
vector<vector <int>> input(vector<vector<int>>& arr, int n);
void dfs(vector<vector <int>> arr, int n);
vector<vector <int>> up_push(vector<vector<int>>& arr, int n);
vector<vector <int>> left_push(vector<vector <int>>& arr, int n);
vector<vector <int>> right_push(vector<vector <int>>& arr, int n);
vector<vector <int>> down_push(vector<vector <int>>& arr, int n);
void search(vector<vector <int>> arr, int n, int dir);
int row, col;
int result = 0;
int up = 1;
int ri = 3;
int down = 5;
int le = 7;
int check_cnt = 0;
stack <int> a;
pair<int**, int> check;
vector <int> test;
vector<vector<int>> tmp;
int main()
{

	int n;

	
	vector<vector <int>> board;
	cin >> n;

	board = init(board, n);
	board = input(board, n);
	a.push(up);
	a.push(ri);
	a.push(down);
	a.push(le);
	dfs(board, n);




	cout << result << endl;
	


	return 0;
}
void search(vector<vector <int>> arr, int n)
{
	int dir;
	dir = a.top();
	a.pop();
	check_cnt++;
	if (check_cnt > 5)
		return;
	if (check_cnt == 5)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (arr[i][j] > result)
					result = arr[i][j];
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			vector<int> row(n);
			tmp.push_back(row);
		}
	}
	int k;
	int flag = false;
	int cnt = 0;
	int check = 0;

	switch (dir) 
	{
	case 1:
	
		for (int i = 0; i < n; i++)
		{
			cnt = 0;
			for (int j = 0; j < n; j++)
			{
				if (arr[j][i] != 0)
					cnt++;
			}
			check = 0;
			for (int j = 0; j < n - 1; j++)
			{
				if (check == cnt)
					break;
				if (arr[j][i] == 0)
				{
					k = j + 1;
					while (k < n)
					{
						if (arr[k][i] != 0)
						{
							arr[j][i] = arr[k][i];
							arr[k][i] = 0;
							check++;
							break;
						}
						k++;
					}
				}
			}
			for (int j = 0; j < n - 1; j++)
			{
				k = j + 1;
				if (arr[j][i] == arr[k][i])
				{
					arr[j][i] *= 2;
					arr[k][i] = 0;
					if (arr[j][i] != 0)
						flag = true;
				}
				if (arr[j][i] == 0)
				{
					arr[j][i] = arr[k][i];
					arr[k][i] = 0;
				}
			}
		}
		break;
	case 3:

		for (int i = 0; i < n; i++)
		{
			cnt = 0;
			for (int j = 0; j < n; j++)
			{
				if (arr[i][j] != 0)
					cnt++;
			}
			check = 0;
			for (int j = n - 1; j > 0; j--)
			{
				if (check == cnt)
					break;
				if (arr[i][j] == 0)
				{
					k = j - 1;
					while (k >= 0)
					{
						if (arr[i][k] != 0)
						{
							arr[i][j] = arr[i][k];
							arr[i][k] = 0;
							check++;
							break;
						}
						k--;
					}
				}

			}
			for (int j = n - 1; j > 0; j--)
			{
				k = j - 1;
				if (arr[i][j] == arr[i][k])
				{
					arr[i][j] *= 2;
					arr[i][k] = 0;
					if (arr[i][j] != 0)
						flag = true;
				}
				if (arr[i][j] == 0)
				{
					arr[i][j] = arr[i][k];
					arr[i][k] = 0;
				}
			}
		}
		break;
	case 5:

		for (int i = 0; i < n; i++)
		{
			cnt = 0;
			for (int j = 0; j < n; j++)
			{
				if (arr[j][i] != 0)
					cnt++;
			}
			check = 0;
			for (int j = n - 1; j > 0; j--)
			{
				if (check == cnt)
					break;
				if (arr[j][i] == 0)
				{
					k = j - 1;
					while (k >= 0)
					{
						if (arr[k][i] != 0)
						{
							arr[j][i] = arr[k][i];
							arr[k][i] = 0;
							check++;
							break;
						}
						k--;
					}
				}
			}
			for (int j = n - 1; j > 0; j--)
			{
				k = j - 1;
				if (arr[j][i] == arr[k][i])
				{
					arr[j][i] *= 2;
					arr[k][i] = 0;
					if (arr[j][i] != 0)
						flag = true;
				}
				if (arr[j][i] == 0)
				{
					arr[j][i] = arr[k][i];
					arr[k][i] = 0;
				}
			}
		}

		break;
	case 7:

		for (int i = 0; i < n; i++)
		{
			cnt = 0;
			for (int j = 0; j < n; j++)
			{
				if (arr[i][j] != 0)
					cnt++;
			}
			check = 0;
			for (int j = 0; j < n - 1; j++)
			{
				if (check == cnt)
					break;
				if (arr[i][j] == 0)
				{
					k = j + 1;
					while (k < n)
					{
						if (arr[i][k] != 0)
						{
							arr[i][j] = arr[i][k];
							arr[i][k] = 0;
							check++;
							break;
						}
						k++;
					}

				}
			} //일단 옆으로 다 당긴상태 
			for (int j = 0; j < n - 1; j++)
			{
				k = j + 1;
				if (arr[i][j] == arr[i][k])
				{
					arr[i][j] *= 2;
					arr[i][k] = 0;
					if (arr[i][j] != 0)
						flag = true;
				}
				if (arr[i][j] == 0)
				{
					arr[i][j] = arr[i][k];
					arr[i][k] = 0;
				}
			}
		}

		break;


	}
	if (check_cnt == 5)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (arr[i][j] > result)
					result = arr[i][j];
			}
		}
	}
	a.push(up);
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			tmp[i][j] = arr[i][j];
		}
	}

	search(arr, n);
	check_cnt--;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = tmp[i][j];
		}
	}
	a.push(ri);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			tmp[i][j] = arr[i][j];
		}
	}

	search(arr, n);
	check_cnt--;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = tmp[i][j];
		}
	}
	a.push(down);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			tmp[i][j] = arr[i][j];
		}
	}

	search(arr, n);
	check_cnt--;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = tmp[i][j];
		}
	}
	a.push(le);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			tmp[i][j] = arr[i][j];
		}
	}

	search(arr, n);
	check_cnt--;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = tmp[i][j];
		}
	}

}
void dfs(vector<vector <int>> arr, int n)
{
		search(arr, n);


}

vector<vector <int>> down_push(vector<vector<int>>& arr, int n)
{
	int k;
	int flag = false;
	int cnt = 0;
	int check = 0;

	for (int i = 0; i < n; i++)
	{
		cnt = 0;
		for (int j = 0; j < n; j++)
		{
			if (arr[j][i] != 0)
				cnt++;
		}
		check = 0;
		for (int j = n - 1; j > 0; j--)
		{
			if (check == cnt)
				break;
			if (arr[j][i] == 0)
			{
				k = j - 1;
				while (k >= 0)
				{
					if (arr[k][i] != 0)
					{
						arr[j][i] = arr[k][i];
						arr[k][i] = 0;
						check++;
						break;
					}
					k--;
				}
			}
		}
		for (int j = n - 1; j > 0; j--)
		{
			k = j - 1;
			if (arr[j][i] == arr[k][i])
			{
				arr[j][i] *= 2;
				arr[k][i] = 0;
				if (arr[j][i] != 0)
					flag = true;
			}
			if (arr[j][i] == 0)
			{
				arr[j][i] = arr[k][i];
				arr[k][i] = 0;
			}
		}
	}
	return arr;

}
vector<vector <int>> up_push(vector<vector <int>> &arr, int n)
{
	int k;
	int flag = false;
	
	int cnt = 0;
	int check = 0;
	for (int i = 0; i < n; i++)
	{
		cnt = 0;
		for (int j = 0; j < n; j++)
		{
			if (arr[j][i] != 0)
				cnt++;
		}
		check = 0;
		for (int j = 0; j < n - 1; j++)
		{
			if (check == cnt)
				break;
			if (arr[j][i] == 0)
			{
				k = j + 1;
				while (k < n)
				{
					if (arr[k][i] != 0)
					{
						arr[j][i] = arr[k][i];
						arr[k][i] = 0;
						check++;
						break;
					}
					k++;
				}
			}
		}
		for (int j = 0; j < n - 1; j++)
		{
			k = j + 1;
			if (arr[j][i] == arr[k][i])
			{
				arr[j][i] *= 2;
				arr[k][i] = 0;
				if (arr[j][i] != 0)
					flag = true;
			}
			if (arr[j][i] == 0)
			{
				arr[j][i] = arr[k][i];
				arr[k][i] = 0;
			}
		}
	}
	return arr;

}
vector<vector <int>> right_push(vector<vector <int>> &arr, int n)
{
	int k;
	int flag = false;
	int cnt = 0;
	int check = 0;
	for (int i = 0; i < n; i++)
	{
		cnt = 0;
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] != 0)
				cnt++;
		}
		check = 0;
		for (int j = n - 1; j > 0; j--)
		{
			if (check == cnt)
				break;
			if (arr[i][j] == 0)
			{
				k = j - 1;
				while (k >= 0)
				{
					if (arr[i][k] != 0)
					{
						arr[i][j] = arr[i][k];
						arr[i][k] = 0;
						check++;
						break;
					}
					k--;
				}
			}

		}
		for (int j = n - 1; j > 0; j--)
		{
			k = j - 1;
			if (arr[i][j] == arr[i][k])
			{
				arr[i][j] *= 2;
				arr[i][k] = 0;
				if (arr[i][j] != 0)
					flag = true;
			}
			if (arr[i][j] == 0)
			{
				arr[i][j] = arr[i][k];
				arr[i][k] = 0;
			}
		}
	}
	return arr;

}
vector<vector <int>>left_push(vector<vector <int>> &arr, int n)
{
	int k;
	int flag = false;
	int cnt = 0;
	int check = 0;
	
	for (int i = 0; i < n; i++)
	{
		cnt = 0;
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] != 0)
				cnt++;
		}
		check = 0;
		for (int j = 0; j < n - 1; j++)
		{
			if (check == cnt)
				break;
			if (arr[i][j] == 0)
			{
				k = j + 1;
				while (k < n)
				{
					if (arr[i][k] != 0)
					{
						arr[i][j] = arr[i][k];
						arr[i][k] = 0;
						check++;
						break;
					}
					k++;
				}

			}
		} //일단 옆으로 다 당긴상태 
		for (int j = 0; j < n - 1; j++)
		{
			k = j + 1;
			if (arr[i][j] == arr[i][k])
			{
				arr[i][j] *= 2;
				arr[i][k] = 0;
				if (arr[i][j] != 0)
					flag = true;
			}
			if (arr[i][j] == 0)
			{
				arr[i][j] = arr[i][k];
				arr[i][k] = 0;
			}
		}
	}
	return arr;

}
vector<vector<int>> init(vector<vector<int>> &arr, int n)
{
	
	for (int i = 0; i < n; i++)
	{
		vector<int> temp(n);
		arr.push_back(temp);
	}
	return arr;
} //배열 초기화

vector<vector<int>> input(vector<vector<int>> &arr, int n)
{

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
	}
	return arr;
} //배열 입력