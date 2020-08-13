#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int N, K, words[50], ans;			// words : 단어들 마다 포함되어 있는 알파벳 가중치 총합
bool used[26], total[26];			// used : 입력받은 단어에 포함되어 있는 알파벳 체크, total : 전체 단어에 포함된 알파벳 체크
string word;

void DFS(int depth, int start, int weight) {
	if (depth == K) {
		int temp = 0;
		for (int i = 0; i < N; i++) {
			if ((words[i] & weight) == words[i])
				temp++;
		}
		ans = temp > ans ? temp : ans;
		return;
	}
	for (int i = start; i < 26; i++) {
		if (total[i])
			DFS(depth + 1, i + 1, weight + (1 << i));		// 해당 단어가 사용되었을 시 DFS 진행
	}
}

int main() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> word;
		for (unsigned int j = 0; j < word.size(); j++) {
			used[word[j] - 'a'] = true;			// 'a'이면 [0]에, 'b'면 [1]에, 'c'면 [2]에 true 체크 하는 식
			total[word[j] - 'a'] = true;
		}
		for (int j = 0; j < 26; j++)
			if (used[j])
				words[i] += 1 << j;				// 해당 단어에 'a'가 있었다면 1, 'b'가 있었다면 2 'c'가 있었다면 4... 이렇게 더해감
		memset(used, false, sizeof(used));		// used 초기화
	}
	int cnt = 0;
	for (int i = 0; i < 26; i++)
		if (total[i])
			cnt++;								// 전체 단어에 쓰인 알파벳 개수 체크
	if (K >= cnt)
		printf("%d", N);						// K가 그 이상이라면 더 볼 필요 없이 모든 단어를 읽을 수 있는 것
	else {
		DFS(0, 0, 0);							// 그게 아니면 조합 방식으로 K개 만큼 뽑아서 읽을 수 있는 최대 단어 수 갱신
		cout << ans;
	}
	return 0;
}