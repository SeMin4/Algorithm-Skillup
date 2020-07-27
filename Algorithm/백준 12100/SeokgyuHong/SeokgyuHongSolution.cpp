#include <iostream>
#include <algorithm>


using namespace std;
int** make_array(int** arr, int n);
int** init_array(int** arr, int n);
int** push(int** arr, int n, int dir);
int result = 0;
void dfs(int depth, int** arr, int n);
int main()
{
	int** arr = 0;

	int n;
	cin >> n;

	arr = make_array(arr, n);
	arr = init_array(arr, n);


	dfs(0, arr, n);

	cout << result << endl;

	return 0;

}
void dfs(int depth, int** arr, int n)
{

	if (depth == 5)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				if (arr[i][j] > result)
					result = arr[i][j];
		}
		return;
	}
	for (int i = 1; i <= 4; i++)
	{
		int** temp = 0;
		temp = make_array(arr, n);
		temp = push(arr, n, i);
		dfs(depth + 1, temp, n);
	}
}
int** push(int** arr, int n, int dir)
{

	int** return_map = 0;
	return_map = make_array(return_map, n); // 리턴할 배열 
	switch (dir) {
	case 1: //위
		for (int i = 0; i < n; i++) //0인공간 다 비워줌
		{
			for (int j = 0, cnt = 0; j < n; j++, cnt++)
			{
				if (arr[j][i] == 0) //0일경우
				{
					while (arr[j][i] == 0 && j < n - 1)
					{
						j++;
					}
					return_map[cnt][i] = arr[j][i];
					//arr[j][i] = 0;
				}
				else
				{
					return_map[cnt][i] = arr[j][i];
					//arr[j][i] = 0;
				}
			}
		} //0인공간 없애버린것 
		for (int i = 0; i < n; i++)
		{
			for (int j = 0, cnt = 0; j < n; j++, cnt++)
			{
				if (return_map[cnt][i] == 0)
				{
					int temp = cnt;
					for (j = cnt + 1; j < n; j++)
					{
						if (return_map[j][i] != 0)
						{
							return_map[temp++][i] = return_map[j][i];
							return_map[j][i] = 0;
						}
					}
					return_map[n - 1][i] = 0;
					j = cnt;

				}
				if (cnt != n - 1 && (return_map[cnt][i] == return_map[cnt + 1][i]))
				{

					return_map[cnt][i] *= 2;
					return_map[cnt + 1][i] = 0;


				}

			}
		}
		break;
	case 2: //오른쪽
		for (int i = 0; i < n; i++) //0인공간 다 비워줌
		{
			for (int j = n - 1, cnt = n - 1; j >= 0; j--, cnt--)
			{
				if (arr[i][j] == 0) //0일경우
				{
					while (arr[i][j] == 0 && j > 0)
					{
						j--;
					}
					return_map[i][cnt] = arr[i][j];
					//arr[j][i] = 0;
				}
				else
				{
					return_map[i][cnt] = arr[i][j];
					//arr[j][i] = 0;
				}
			}
		} //0인공간 없애버린것 

		for (int i = 0; i < n; i++)
		{
			for (int j = n - 1, cnt = n - 1; j >= 0; j--, cnt--)
			{
				if (return_map[i][cnt] == 0)
				{
					int temp = cnt;
					for (j = cnt - 1; j >= 0; j--)
					{
						if (return_map[i][j] != 0)
						{
							return_map[i][temp--] = return_map[i][j];
							return_map[i][j] = 0;
						}
					}
					return_map[i][0] = 0;
					j = cnt;

				}
				if (cnt > 0)
				{
					if (return_map[i][cnt] == return_map[i][cnt - 1])
					{
						return_map[i][cnt] *= 2;
						return_map[i][cnt - 1] = 0;
					}

				}

			}
		}
		break;
	case 3: //아래쪽
		for (int i = 0; i < n; i++) //0인공간 다 비워줌
		{
			for (int j = n - 1, cnt = n - 1; j >= 0; j--, cnt--)
			{
				if (arr[j][i] == 0) //0일경우
				{
					while (arr[j][i] == 0 && j > 0)
					{
						j--;
					}
					return_map[cnt][i] = arr[j][i];
					//arr[j][i] = 0;
				}
				else
				{
					return_map[cnt][i] = arr[j][i];
					//arr[j][i] = 0;
				}
			}
		} //0인공간 없애버린것 

		for (int i = 0; i < n; i++)
		{
			for (int j = n - 1, cnt = n - 1; j >= 0; j--, cnt--)
			{
				if (return_map[cnt][i] == 0)
				{
					int temp = cnt;
					for (j = cnt - 1; j >= 0; j--)
					{
						if (return_map[j][i] != 0)
						{
							return_map[temp--][i] = return_map[j][i];
							return_map[j][i] = 0;
						}
					}
					return_map[0][i] = 0;
					j = cnt;

				}
				if (cnt > 0)
				{
					if (return_map[cnt][i] == return_map[cnt - 1][i])
					{
						return_map[cnt][i] *= 2;
						return_map[cnt - 1][i] = 0;
					}

				}

			}
		}
		break;


	case 4: //왼쪽
		for (int i = 0; i < n; i++) //0인공간 다 비워줌
		{
			for (int j = 0, cnt = 0; j < n; j++, cnt++)
			{
				if (arr[i][j] == 0) //0일경우
				{
					while (arr[i][j] == 0 && j < n - 1)
					{
						j++;
					}
					return_map[i][cnt] = arr[i][j];
					//arr[j][i] = 0;
				}
				else
				{
					return_map[i][cnt] = arr[i][j];
					//arr[j][i] = 0;
				}
			}
		} //0인공간 없애버린것 
		for (int i = 0; i < n; i++)
		{
			for (int j = 0, cnt = 0; j < n; j++, cnt++)
			{
				if (return_map[i][cnt] == 0)
				{
					int temp = cnt;
					for (j = cnt + 1; j < n; j++)
					{
						if (return_map[i][j] != 0)
						{
							return_map[i][temp++] = return_map[i][j];
							return_map[i][j] = 0;
						}

					}
					return_map[i][n - 1] = 0;
					j = cnt;

				}
				if ((return_map[i][cnt] == return_map[i][cnt + 1]) && cnt != n - 1)
				{
					return_map[i][cnt] *= 2;
					return_map[i][cnt + 1] = 0;

				}

			}
		}
		break;


	}
	return return_map;

}
int** make_array(int** arr, int n)
{
	arr = (int**)malloc(sizeof(int*) * n);

	for (int i = 0; i < n; i++)
	{
		arr[i] = (int*)malloc(sizeof(int) * n);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = 0;
		}
	}
	return arr;
}


int** init_array(int** arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}
	return arr;
}