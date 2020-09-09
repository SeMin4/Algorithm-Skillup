"""
def solve(K,N,T):
    while True:
        brother_location = count_brother_location(K,T)
        subin_location = count_subin_location(brother_location,N,T)
        if brother_location >= 500000 or subin_location >= 500000:
            return -1
        if brother_location == subin_location:
            break

        T+=1
    return T

def count_brother_location(K,T):
    sum=0
    for i in range(1,T+1):
        sum += i
    return K+sum

def count_subin_location(K,N,T):
    while T>0:
        if N <= K:
            if 2*N <= K:
                N = 2*N
            else :
                if K-N >= 2*N-K:
                    N= 2*N
                else:
                    N=N+1
        else :
            N= N-1
        T-=1

    return N

if __name__ == "__main__":
    N,K = map(int,input().split())
    print(solve(K,N,0))
"""


"""
0. visited[0][500001] 홀수시간, 짝수시간에 방문한 지점에 최초로 방문한 time을 저장
1. BFS로 수빈이 방문가능한 모든 지점 방문
2. time을 증가시키면서 동생이 방문하는 지점을 체크
3. 동생이 방문한 지점 == 수빈이 방문한 지점 and 수빈이 동생보다 빨리 방문했다면 
"""

from collections import deque

visited = [[-1 for _ in range(500000 + 1)] for _ in range(2)]

def bfs(q:deque):

    while len(q)!=0:

        N , time = q.popleft()
        n_list = [N-1 , N+1 , 2*N]

        for n in n_list:
            if 0<= n <= 500000 and visited[(time+1)%2][n] == -1:
                visited[(time+1)%2][n] = time + 1
                q.append((n , time+1))

if __name__ == "__main__":

    N , K = map(int, input().split())
    q = deque()
    q.append((N,0))
    visited[0][N] = 0

    #초기 시간 = 0, 답 = -1
    time = 0
    answer = -1
    #bfs로 수빈(N)이 갈수 있는 모든 지점체크하고 최초방문시간을 저장
    bfs(q)
    #시간을 늘려가면서 수빈이 방문한 지점을 동생이 방문하는지 체크

    while True:
        if K > 500000:
            break

        # 수빈이 방문했었던 자리이고 && 수빈이 홀수/짝수시간에 방문한 시간 <= 동생이 홀수시간에 방문한 시간이면 동생이 방문한시간 저장(+-1)
        if visited[time%2][K] != -1 and visited[time%2][K] <= time: #time이 3이면 visited[1][K] = (6 <= 3):
            answer = time
            break

        # 수빈이 방문안했던 자리를 방문했다면 다음 time 동생이 방문하는 자리 계산
        time +=1 # 1, 2, 3, 4, 5
        K += time # 1 + 2 + 3 + 4 + 5

    print(answer)