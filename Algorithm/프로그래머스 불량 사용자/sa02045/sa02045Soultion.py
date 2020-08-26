"""from itertools import permutations

def is_matched(case,banned_ids):
    for i in range(len(banned_ids)):
        if banned_ids 
        

def check(banned_ids,case):
    for i in range(len(banned_ids)):
        if len(banned_ids[i])!= len(case[i]):
            return False
        return is_matched(case,banned_ids) 

def solution(user_ids, banned_ids):
    ans = []
    #모든 순열을 만들어서 하나하나씩 비교 
    all_list = permutations(user_ids,len(banned_ids))

    for case in all_list:
        if check(banned_ids,case) is True:
            case =set(case)
            print(case)
            if case not in ans :
                ans.append(case)
    print(len(ans))

user_id=["frodo", "fradi", "crodo", "abc123", "frodoc"]
banned_id=["fr*d*", "abc1**"]
solution(user_id,banned_id)"""


from itertools import permutations


def is_matched(soonyeol, banned_id):
    for i in range(len(soonyeol)):
        if len(soonyeol[i]) != len(banned_id[i]):
            return False
        for j in range(len(soonyeol[i])):
            if banned_id[i][j] == "*":
                continue
            if soonyeol[i][j] != banned_id[i][j]:
                return False
    return True

    
def solution(user_id, banned_id):
    answer =[]
    for soonyeol in permutations(user_id,len(banned_id)):
        if is_matched(soonyeol,banned_id):
            soonyeol = set(soonyeol)
            if soonyeol not in answer:
                answer.append(soonyeol)
        
        return len(answer)