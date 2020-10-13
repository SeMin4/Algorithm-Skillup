#include <iostream>
#include <queue>
using namespace std;

int N, K, Start, End;
bool visited[1001];
string code[1001];

bool BFS()
{
	queue<vector<int>> q;		// (현재 코드 번호, 길이)
	vector<int> v;
	v.push_back(Start);
	q.push(v);
	visited[Start] = true;

	while (!q.empty())
	{
		vector<int> v = q.front();
		int cur = v.back();
		q.pop();

		if (cur == End)
		{
			for (int i : v)
				cout << i << " ";
			return true;
		}
		for (int i = 1; i <= N; i++)
		{
			int diff = 0;
			for (int c = 0; c < K; c++)
				if (code[i][c] != code[cur][c])
					diff++;
			if (diff == 1 && !visited[i])
			{
				vector<int> new_v = v;
				new_v.push_back(i);
				visited[i] = true;
				q.push(new_v);
			}
		}
	}
	return false;
}

int main()
{
	cin >> N >> K;
	for (int i = 1; i <= N; i++)
		cin >> code[i];
	cin >> Start >> End;
	if (!BFS())
		cout << -1;
	return 0;
}