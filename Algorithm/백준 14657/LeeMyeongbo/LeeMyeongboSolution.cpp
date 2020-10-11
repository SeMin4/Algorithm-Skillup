#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node
{
	int cur, via;
	long long sum;						// 각각 현재 노드, 여태 거쳐온 노드 수, 가중치 합
};
int N, T, A, B, C, farthest;			// farthest : 1번 노드에서 출발하여 가장 많은 노드를 거쳤을 때 도착하는 노드
vector<pair<int, int>> tree[50001];		// (연결된 정점, 가중치) 꼴로 저장

long long BFS(int start_v)				// 트리의 지름 : (여기에서는) 한 노드에서 다른 노드까지 거쳐야 하는 노드 수의 최댓값
{
	int max = 0;							// start_v에서부터 출발하여 거친 노드 수의 최댓값
	long long weight_sum = 50000000000;		// 그 때의 가중치 합의 최소
	bool visited[50001] = { false, };
	queue<Node> q;
	
	q.push({ start_v, 0, 0 });
	visited[start_v] = true;

	while (!q.empty())
	{
		Node node = q.front();
		q.pop();

		if (max < node.via || (max == node.via && weight_sum > node.sum))		// 거친 노드 수가 더 많아지거나 거친 노드 수가 같으면서 가중치 합 최솟값이 갱신 시
		{
			max = node.via;
			weight_sum = node.sum;
			farthest = node.cur;
		}
		for (auto edge : tree[node.cur])
			if (!visited[edge.first])
			{
				q.push({ edge.first, node.via + 1, node.sum + edge.second });
				visited[edge.first] = true;
			}
	}
	return weight_sum;
}

int main()
{
	scanf("%d %d", &N, &T);
	for (int i = 0; i < N - 1; i++)
	{
		scanf("%d %d %d", &A, &B, &C);
		tree[A].push_back({ B, C });
		tree[B].push_back({ A, C });
	}
	BFS(1);									// 먼저 1번에서부터 BFS를 진행하여 farthest를 구함
	long long time = BFS(farthest);			// farthest에서 출발하여 가장 멀리 떨어진 노드까지의 시간의 최솟값 구함
	if (time % T == 0)
		printf("%lld", time / T);
	else
		printf("%lld", time / T + 1);
	return 0;
}