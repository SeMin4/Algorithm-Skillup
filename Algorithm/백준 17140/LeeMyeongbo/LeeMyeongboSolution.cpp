#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int A[100][100], r, c, k;

int Solve() {
	int cur_row = 3, cur_col = 3;
	vector<pair<int, int>> v;

	for (int a = 0; a <= 100; a++) {
		if (A[r][c] == k)										// 원하는 자리에 k가 있다면 반복 횟수 리턴
			return a;
		if (cur_row >= cur_col) {								// 현재 행 크기가 열 크기보다 크거나 같을 경우 R 연산
			for (int row = 0; row < cur_row; row++) {
				int freq[101] = { 0, };							// 각 숫자가 나타난 빈도 수 저장 (3이 2번 나타났으면 freq[3] = 2가 저장되는 식)
				for (int col = 0; col < cur_col; col++) {
					freq[A[row][col]]++;
					A[row][col] = 0;
				}
				for (int i = 1; i <= 100; i++)
					if (freq[i])
						v.push_back(make_pair(freq[i], i));		// 한 번 이상 나타난 자연수를 (빈도, 해당 자연수)의 순서쌍으로 묶어서 저장
				sort(v.begin(), v.end());
				int index = 0;
				for (auto p : v) {								// 맨 왼쪽부터 반복하며 값을 채워나감
					A[row][index++] = p.second;
					if (index == 100)
						break;
					A[row][index++] = p.first;
					if (index == 100)
						break;
				}
				cur_col = max(cur_col, index);					// 현재 열 크기 최댓값 갱신
				v.clear();
			}
		}
		else {													// 행 크기가 열 크기보다 작을 경우 C 연산
			for (int col = 0; col < cur_col; col++) {
				int freq[101] = { 0, };
				for (int row = 0; row < cur_row; row++) {
					freq[A[row][col]]++;
					A[row][col] = 0;
				}
				for (int i = 1; i <= 100; i++)
					if (freq[i])
						v.push_back(make_pair(freq[i], i));
				sort(v.begin(), v.end());
				int index = 0;
				for (auto p : v) {								// 맨 위쪽부터 반복하며 값을 채워나감
					A[index++][col] = p.second;
					if (index == 100)
						break;
					A[index++][col] = p.first;
					if (index == 100)
						break;
				}
				cur_row = max(cur_row, index);					// 현재 행 크기 최댓값 갱신
				v.clear();
			}
		}
	}
	return -1;
}

int main() {
	cin >> r >> c >> k;
	r--, c--;
	for (int i = 0; i < 9; i++)
		cin >> A[i / 3][i % 3];

	cout << Solve();
	return 0;
}