#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<int> heights;
int N, height[50][50], K_num, py, px, dx[] = { 1, 1, 1, 0, -1, -1, -1, 0 }, dy[] = { -1, 0, 1, 1, 1, 0, -1, -1 }, h_num;
char map[50][50];
bool existing_heights[1000001], complete;

bool DFS(int cur_row, int cur_col, int right, int left, bool visited[][50]) {
	if (h_num == K_num) {
		complete = true;
		return complete;
	}
	for (int i = 0; i < 8; i++) {
		int X = cur_col + dx[i];
		int Y = cur_row + dy[i];
		if (X >= 0 && X < N && Y >= 0 && Y < N && !visited[Y][X] && height[Y][X] >= heights[left] && height[Y][X] <= heights[right]) {
			visited[Y][X] = true;
			if (map[Y][X] == 'K')
				h_num++;			// K 만났을 시 실제로 방문한 K 갯수 증가
			DFS(Y, X, right, left, visited);
		}
	}
	return complete;
}

int Solve() {
	int ans = 5000000, left = 0, right = 0;
	bool visited[50][50];
	while (right < heights.size()) {
		if (height[py][px] >= heights[left] && height[py][px] <= heights[right]) {		// P의 고도가 left - right 구간에 있을 경우
			memset(visited, false, sizeof(visited));
			visited[py][px] = true;
			if (DFS(py, px, right, left, visited)) {	// DFS 로 left - right 구간 내 갈 수 있는 모든 고도 탐색하고 모든 K 방문 시
				ans = heights[right] - heights[left] < ans ? heights[right] - heights[left] : ans;
				complete = false;
				left++;			// left 오른쪽으로 한 칸 움직여 구간 줄임
			}
			else				// 모든 K 방문하지는 못했을 시
				right++;		// right 오른쪽으로 한 칸 움직여 구간 늘임
			h_num = 0;			// 방문한 K 개수 초기화
		}
		else if (height[py][px] > heights[right])		// P의 고도가 left - right 구간을 아직 만나지 못했을 경우
			right++;
		else if (height[py][px] < heights[left])		// P의 고도가 이미 left - right 구간을 지나갔을 경우
			break;
	}
	return ans;
}

int main() {
	cin >> N;
	for(int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'P')
				py = i, px = j;				// P의 행, 열 위치를 각각 py, px에 저장
			else if (map[i][j] == 'K')	
				K_num++;					// K_num에 총 K 갯수 저장
		}
	for(int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			cin >> height[i][j];
			existing_heights[height[i][j]] = true;
		}
	for (int i = 0; i <= 1000000; i++)
		if (existing_heights[i])
			heights.push_back(i);			// heights 벡터에 입력받은 고도(같은 수 중복x) 오름차순으로 저장

	cout << Solve();
	return 0;
}