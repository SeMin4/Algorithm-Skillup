#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m, v1, v2, weight, Start, End, Max[10001], into_edge[10001];
vector<pair<int, int>> edges[10001], reversed_edges[10001];				// 각각 (도착 정점, 가중치) & (출발 정점, 가중치)로 저장

int BFS()
{
	queue<pair<int, int>> q;				// (도착 정점, 가중치 합)
	q.push({ Start, 0 });

	while (!q.empty())
	{
		int cur = q.front().first;
		int sum = q.front().second;
		q.pop();

		for (auto e : edges[cur])
		{
			into_edge[e.first]--;
			Max[e.first] = Max[e.first] < sum + e.second ? sum + e.second : Max[e.first];
			if (!into_edge[e.first])
				q.push({ e.first, Max[e.first] });			// 해당 정점의 진입 간선 수가 0이 되면 해당 정점을 큐에 삽입
		}
	}
	return Max[End];
}

int Find_way()
{
	int ans = 0;
	queue<int> q;
	bool visited[10001] = { false, };
	q.push(End);

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		if (visited[cur])									// 이미 방문한 정점은 skip
			continue;

		visited[cur] = true;
		for (auto v : reversed_edges[cur])
			if (Max[cur] - v.second == Max[v.first])
			{
				q.push(v.first);
				ans++;
			}
	}
	return ans;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d %d", &v1, &v2, &weight);
		edges[v1].push_back({ v2, weight });
		reversed_edges[v2].push_back({ v1, weight });
		into_edge[v2]++;
	}
	scanf("%d %d", &Start, &End);

	int time = BFS();
	int num = Find_way();
	
	printf("%d\n%d\n", time, num);
	return 0;
}