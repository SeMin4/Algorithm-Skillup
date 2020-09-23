#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> v;
int T, N, first, second;

int Solve() {
	int s = v[0].second, ans = 1;
	for (int i = 1; i < N; i++) {
		if (v[i].second < s) {			// 면접 시험 순위가 더 작은 사람이 있다면 갱신하고 ans + 1
			s = v[i].second;
			ans++;
		}
	}
	return ans;
}

int main() {
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> N;
		for (int n = 0; n < N; n++) {
			cin >> first >> second;
			v.push_back(make_pair(first, second));
		}
		sort(v.begin(), v.end());		// 1차 서류 심사 기준으로 오름차순 정렬
		cout << Solve() << "\n";
		v.clear();
	}
	return 0;
}