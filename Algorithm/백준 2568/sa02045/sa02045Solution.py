import sys

def lower_bound(answer:list, num:int)->int:
    low = 0 
    high = len(answer)-1
    while low < high :
        mid = (low + high)//2
        if answer[mid] >= num :
            high = mid
        else :
            low = mid + 1
    return high

if __name__ == "__main__":
    N = int(sys.stdin.readline())
    line_list = [0*N]
    for _ in range(N):
        A,B = map(int,sys.stdin.readline().split())
        line_list[A] = B
    

    answer = []

    visit = [_ for i in range(1 , N+1)]

    for index, line in enumerate(line_list):
        if len(answer) == 0:
            answer.append(line)
            continue
        if line > answer[-1] :
            answer.append(line)
        else :
            answer[lower_bound(answer,line)] = line

    print(answer)