#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n, k, s, before, after, n1, n2;
vector<int> outdegree[401];				// 해당 정점(index)으로부터 진출 간선과 연결된 정점들 저장
bool complete, visited[401];

void DFS(int n1, int n2) {
	if (n1 == n2) {						// 진출 간선을 타고 목표로 하는 n2를 만나게 되었다면 n1이 n2보다 먼저 일어났다는 것이 성립
		complete = true;
		return;
	}
	
	for (int v : outdegree[n1]) {
		if (!visited[v] && !complete) {
			visited[v] = true;
			DFS(v, n2);					// 재귀 빠져나올 땐 방문 체크 안 풀고 나와야 중복방문을 막을 수 있음!
		}
	}
}

int main() {
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		scanf("%d %d", &before, &after);
		outdegree[before].push_back(after);				// 이전 사건 index에 이후 사건 추가
	}
	cin >> s;
	for (int i = 0; i < s; i++) {
		scanf("%d %d", &n1, &n2);
		DFS(n1, n2);									// n1이 n2보다 먼저 일어난 것인지 살핌
		if (complete) {
			printf("-1\n");
			memset(visited, false, sizeof(visited));	// 항상 탐색이 끝나면 방문 체크 원래대로 돌리기
			complete = false;
			continue;
		}
		memset(visited, false, sizeof(visited));
		DFS(n2, n1);
		if (complete) {
			printf("1\n");
			memset(visited, false, sizeof(visited));
			complete = false;
			continue;
		}
		memset(visited, false, sizeof(visited));
		printf("0\n");
	}
	return 0;
}