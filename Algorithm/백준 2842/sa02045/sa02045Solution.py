from collections import deque
import sys

dx=[-1,-1,-1,0,0,1,1,1]
dy=[-1,0,1,-1,1,-1,0,1]

def bfs(x, y, left, right):
    # 큐 생성과 visited배열
    q = deque()
    visited = [[0] * N for _ in range(N)]
    q.append([x,y])
    visited[x][y] =1

    while q:
        x,y = q.popleft()

        for i in range(8):
            nx = x +dx[i]
            ny = y +dy[i]
            if 0 <= nx < N and 0 <= ny < N:

                # nx,ny 고도보다 작고 방문하지 않았다면
                if left <= godo_map[nx][ny] <= right and not visited[nx][ny]:
                    visited[nx][ny] =1
                    q.append([nx,ny])

    # P와 K의 좌표값이 저장된 곳이 방문여부
    for i , j in P_K_map:
        if not visited[i][j]:
            return 0
    return 1


if __name__ == '__main__':
    #입력
    N = int(sys.stdin.readline())

    # P, K map 입력
    P_K_map =[]
    for i in range(N):
        row = list(sys.stdin.readline().strip())
        for j , char in enumerate(row):
            if char == 'P' or char == 'K':
                P_K_map.append([i,j])

    #고도 입력

    #고도의 최소값,최댓값의 set
    godo_set=set()

    #고도값을 담는 map
    godo_map =[]
    for i in range(N):
        row = list(map(int,sys.stdin.readline().split()))
        godo_map.append(row)
        for j in row :
            godo_set.add(j)

    #고도 set 정렬하고 리스트로
    godo_set = list(sorted(godo_set))

    #고도의 최소, 최댓값
    godo_min = godo_set[0]
    godo_max = godo_set[-1]



