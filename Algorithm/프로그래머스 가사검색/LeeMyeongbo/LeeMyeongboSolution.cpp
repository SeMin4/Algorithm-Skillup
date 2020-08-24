#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

vector<string> words, queries;
string str;

struct Trie {
    Trie* nextNode[26];             // 자식 노드 가리키는 포인터들의 배열
    vector<pair<int, int>> list;    // 단어 길이에 따라서 현재 갯수 저장 (현 단어의 길이, 갯수)
    int depth;                      // 트라이에서의 현 노드의 깊이

    Trie(int depth) {
        fill(nextNode, nextNode + 26, nullptr);
        this->depth = depth;
    }

    ~Trie() {
        for (int i = 0; i < 26; i++)
            if (nextNode[i]) {
                delete nextNode[i];
                nextNode[i] = nullptr;
            }
    }

    void insert(string word) {
        int index = 0;
        Trie* node = this;

        while (index < word.size()) {
            bool isadded = false;
            int nextkey = word[index++] - 'a';                  // 'a'라면 0번 index, 'b'라면 1번 index... 이런식으로 설정
            if (!node->nextNode[nextkey])
                node->nextNode[nextkey] = new Trie(index);      // 현 노드의 해당 index에 자식 노드가 없다면 생성
            for (int i = 0; i < node->list.size(); i++) {
                if (node->list[i].first == word.size()) {       // 이미 같은 길이의 단어가 list 벡터에 저장되어 있다면
                    node->list[i].second++;                     // 2번째 값인 갯수만 증가
                    isadded = true;
                    break;
                }
            }
            if (!isadded)                                       // 같은 길이의 단어가 없을 경우 list 벡터에 순서쌍 만들어서 저장
                node->list.push_back(make_pair(word.size(), 1));
            node = node->nextNode[nextkey];
        }
    }
};

int search(Trie* t, string query) {
    while (query[t->depth] != '?' && t)                // 현 Trie의 root로부터 ?를 만나거나 nullptr를 만날 때까지 알맞는 자식 노드를 찾아 내려감
        t = t->nextNode[query[t->depth] - 'a'];
    if (t) {
        for (int i = 0; i < t->list.size(); i++)
            if (t->list[i].first == query.size())      // ?를 만난 시점에 list 벡터 내의 순서쌍 차례로 살펴서 first가 query 길이와 같으면 갯수 리턴 
                return t->list[i].second;
    }
    return 0;
}

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    Trie* trie = new Trie(0);                           // 단어 저장용 Trie
    Trie* rtrie = new Trie(0);                          // 거꾸로 뒤집은 단어 저장용 Trie

    for (auto w : words) {
        trie->insert(w);
        reverse(w.begin(), w.end());
        rtrie->insert(w);
    }

    for (auto query : queries) {
        int ans;
        if (query[query.size() - 1] == '?')                      // 접미어가 ?일 경우 trie에서 단어 검색
            ans = search(trie, query);
        else {                                                   // 접두어가 ?일 경우 rtrie에서 단어 검색
            reverse(query.begin(), query.end());
            ans = search(rtrie, query);
        }
        answer.push_back(ans);
    }

    delete trie;
    delete rtrie;
    return answer;
}