"""import sys
from collections import deque

dx = [ -1, 0, 1, 0]
dy = [ 0, 1, 0, -1]

N , L , R = map( int , sys.stdin.readline().split() )
input_map = []
visited = [[False for in range(N)] for in range(N)]

for i in range( N ):
    row = list( map( int , sys.stdin.readline().split() ))
    input_map.append( row )

bfs_q = deque()
union_q =deque()
cnt = 0
is_open = True

while is_open :
 
    is_open = False
    cnt += 1
    for i in range(N):
        for j in range(N):
            if visited[i][j] == True:
                continue
            bfs_q.append([i,j])
            union_q.append([i,j])
            sum = input_map[i][j]
            visited[i][j] = True
            
            while bfs_q :
                x_y = bfs_q.popleft()
                cur_y = x_y[0]
                cur_x = x_y[1]
                for k in range(4):
                    next_y = cur_y + dy[k]
                    next_x = cur_x + dx[k]
                    if 0 <= next_y < N and 0 <= next_x < N :
                        if L <= abs(input_map[i][j] - input_map[next_y][next_x]) <=R and visited[next_y][next_x] == False:
                            is_open= True
                            bfs_q.append([next_y,next_x])
                            union_q.append([next_y,next_x])
                            sum += input_map[next_y][next_x]
                            visited[next_y][next_x] = True

            average = sum //len(union_q)

            while union_q :
                x_y = union_q.popleft()
                cur_y = x_y[0]
                cur_x = x_y[1]
                input_map[cur_y][cur_x] = average

print(input_map)
print(cnt)"""

import sys
from collections import deque

dx = [ -1, 0, 1, 0]
dy = [ 0, 1, 0, -1]

N , L , R = map( int , sys.stdin.readline().split() )
input_map = []
for _ in range(N):
    row = list ( map( int, sys.stdin.readline().split() ))
    input_map.append(row)

bfs_q = deque()
union_q = deque() #하나의 연합의 x,y좌표를 보관 -> 꺼내서 x,y좌표에 인구이동
is_open = True
cnt = 0 # 인구이동수

while is_open:
    visited = set()
    cnt+=1
    is_open = False
    for i in range(N):
        for j in range(N):
            if (i,j) in visited :
                continue

            bfs_q.append([i,j])
            sum = input_map[i][j]
            union_q.append([i,j])
            visited.add((i,j))

            while bfs_q:
                y_x= bfs_q.popleft()
                cur_y = y_x[0]
                cur_x = y_x[1]

                for k in range(4):
                    next_y = cur_y+dy[k]
                    next_x = cur_x+dx[k]

                    if 0 <= next_x < N and 0 <= next_y < N and (next_y,next_x) not in visited:
                        if L <= abs ( input_map[next_y][next_x] - input_map[cur_y][cur_x] ) <= R:
                            bfs_q.append([next_y,next_x])
                            union_q.append([next_y,next_x])
                            visited.add((next_y,next_x))
                            sum += input_map[next_y][next_x]
                            is_open = True
            
            avr = sum // len(union_q)
            while union_q :
                y_x = union_q.popleft()
                input_map[y_x[0]][y_x[1]] = avr

print(cnt)
print(input_map)