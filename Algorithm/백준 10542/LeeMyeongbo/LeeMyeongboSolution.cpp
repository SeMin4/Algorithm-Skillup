#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>
#define MAX 500001
using namespace std;

int visited[MAX], edges[MAX], N, num, ans, cnt, cycle_start = -1, cycle_end = -1;
bool is_maphia[MAX], visited_sub[MAX];
queue<int> q;
vector<int> graph[MAX];

void DFS(int parent, int cur, vector<int>& sub_graph, vector<int>& cycle) {
	visited[cur] = ++cnt;
	sub_graph.push_back(cur);
	int freq = 0;

	for (int n : graph[cur]) {
		if (!visited[n])
			DFS(cur, n, sub_graph, cycle);
		else if (parent != n && visited[n] && visited[n] < visited[cur]) {		// 길이가 3 이상인 사이클을 발견했을 경우
			cycle_start = visited[n];
			cycle_end = visited[cur];					// 사이클 시작 정점의 방문 번호와 끝나는 정점의 방문 번호 저장
		}
		else if (parent == n) {
			freq++;
			if (freq == 2) {							// 길이가 2인 사이클을 발견했을 경우
				cycle_start = visited[n];
				cycle_end = visited[cur];
			}
		}
	}
	// 사이클 시작하는 정점의 방문 번호와 사이클이 끝나는 정점의 방문 번호 사이에 있는 정점들 모두 cycle 벡터에 저장
	if (cycle_start != -1 && visited[cur] >= cycle_start && visited[cur] <= cycle_end) {
		cycle.push_back(cur);
		if (cycle_start == visited[cur])
			cycle_start = cycle_end = -1;
	}
}

int Solve() {
	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {						// 방문하지 않은 정점이 있을 경우 DFS로 연결된 정점 모두 탐색
			vector<int> sub_graph, cycle;
			bool is_cycle = false;

			DFS(0, i, sub_graph, cycle);
			for(int n : sub_graph)
				if (graph[n].size() == 1) {		// 연결된 간선 수가 1인 말단 정점들 먼저 큐에 삽입
					q.push(n);
					is_maphia[n] = true;
				}
			while (!q.empty()) {				// BFS를 이용한 위상정렬 이용해 마피아 판별 (사이클 제외한 정점들 탐색)
				int v = q.front();
				visited_sub[v] = true;
				q.pop();

				for (int vertex : graph[v]) {
					edges[v]--;
					edges[vertex]--;			// 말단 정점과 연결된 간선 제거
					if (edges[vertex] == 1) {	// 간선 제거 후 새로운 말단 정점이 생기면 또 큐에 삽입
						q.push(vertex);
						bool found = true;
						for (int n : graph[vertex]) {
							if (is_maphia[n]) {
								found = false;
								break;
							}
						}
						if (found)
							is_maphia[vertex] = true;
					}
				}
			}
			for (int v : cycle) {					// 이후 사이클인 정점들 탐색
				for(int n : graph[v])				// 각 정점마다 살펴서 주위에 마피아인 정점이 존재한다면 큐에 삽입
					if (is_maphia[n]) {
						q.push(v);
						visited_sub[v] = true;
						break;
					}
			}
			if (q.empty()) {						// 사이클과 인접한 정점들 중 마피아가 하나도 없다면 사이클 아무 정점이나 큐에 삽입
				q.push(cycle[0]);
				visited_sub[cycle[0]] = true;
			}
			while (!q.empty()) {
				is_cycle = true;
				int v = q.front();
				q.pop();

				bool find = true;
				for (int vertex : graph[v]) {
					if (!visited_sub[vertex]) {
						q.push(vertex);
						visited_sub[vertex] = true;
					}
					if (is_maphia[vertex])
						find = false;
				}
				if (find)
					is_maphia[v] = true;
			}
		}
	}
	for (int i = 1; i <= N; i++)
		if (is_maphia[i])
			ans++;
	return ans;
}

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {				// 정점 갯수 = 간선 갯수
		scanf("%d", &num);
		graph[i].push_back(num);
		edges[i]++;
		graph[num].push_back(i);
		edges[num]++;
	}
	cout << Solve();
	return 0;
}