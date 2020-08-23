#첫번째 풀이 - 효율성 통과X
"""def solution(words, queries):
    check_list =[]
    words = sorted(words)
    for query in queries:
        check=0
        for word in words:
            if len(query)!=len(word):
                pass

            query_point=0
            word_point=0
            while query_point<len(query) and word_point<len(word):
                if query[query_point]=="?" or word[word_point] == query[query_point]:
                    word_point+=1
                    query_point+=1
                else:
                    break

            if query_point == len(query) and word_point== len(word):
                check+=1
    
        check_list.append(check)
    return check_list
"""

from collections import defaultdict

def add(trie, word):
    cur = trie
    for char in word:
        if char not in cur:
            cur[char]=[0,{}]
        cur[char][0]+=1
        cur = cur[char][1]

def search(trie, query):
    cur = trie
    check = 0
    if len(trie) == 0:
        return 0
    
    for char in query:
        if char == "?":
            return check
        else:
            if char not in cur:
                return 0
            check = cur[char][0]
            cur = cur[char][1]
    return check

def solution(words, queries):
    answer = []
    trie = defaultdict(dict)
    reverse_trie=defaultdict(dict)
    len_word = defaultdict(int)

    for word in words:
        word_length = len(word)
        len_word[word_length]+=1
        add(trie[word_length],word)
        add(reverse_trie[word_length],word[::-1])

    for query in queries:
        query_length = len(query)

        #case1 query = "?????" 전부 "?"
        if query[0] == "?" and query[-1]=="?":
            answer.append(len_word[query_length])

        #case2 query = "abc??" 접미사 "?"
        elif query[-1] == "?":
            answer.append(search(trie[query_length],query))

        #case3 query = "???abc" 접미사 "?"
        elif query[0] == "?":
            answer.append(search(reverse_trie[query_length],query[::-1]))

    return answer