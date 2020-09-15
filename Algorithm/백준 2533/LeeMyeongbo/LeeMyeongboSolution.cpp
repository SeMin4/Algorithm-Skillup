#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#define MAX 1000001
using namespace std;

int N, v1, v2, ans;
bool is_early[MAX], visited[MAX];
vector<int> adj[MAX];

bool DFS(int cur_v) {
	bool early_adapter = false;
	for (int child_v : adj[cur_v]) {	// 현재 노드(cur_v)와 연결된 자식 노드들 중에서
		if (!visited[child_v]) {
			visited[child_v] = true;
			if (!DFS(child_v))			// 얼리 아답터가 아닌 자식 노드가 있다면 현재 노드를 얼리 아답터로 설정
				early_adapter = true;
		}
	}
	if (early_adapter)
		is_early[cur_v] = true;			// 현재 노드를 얼리 아답터로 체크
	return early_adapter;				// 말단 노드(자식 노드가 없는 노드)들은 얼리 아답터로 설정되지 않음!
}

int main() {
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		scanf("%d %d", &v1, &v2);
		adj[v1].push_back(v2);
		adj[v2].push_back(v1);
	}
	visited[1] = true;
	DFS(1);								// 1번 노드를 root로 보고 진행
	for (int i = 1; i <= N; i++)
		if (is_early[i])				// 얼리 아답터인 노드 개수 헤아림
			ans++;
	cout << ans;
	return 0;
}