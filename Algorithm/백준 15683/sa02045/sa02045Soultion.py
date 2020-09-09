"""import sys

def check_left( input_map,visited , cctv_location=(0,0)):
    zero_cnt = 0

    for left in range(cctv_location[1], -1 ,-1):

        if input_map[cctv_location[0]][left] == 6:
            break
        elif visited[cctv_location[0]][left] == 0:
            zero_cnt +=1
        else :
            continue

    return [zero_cnt,"left"]

def check_right( input_map , visited , cctv_location=(0,0)):
    zero_cnt = 0
    for right in range(cctv_location[1] , len(visited[0])):
        if input_map[cctv_location[0]][right] == 6:
            break
        elif visited[cctv_location[0]][right] == 0:
            zero_cnt +=1
        else :
            continue
    return [zero_cnt,"right"]

def check_up( input_map, visited , cctv_location=(0,0)):
    zero_cnt = 0
    for up in range(cctv_location[0] , -1, -1):
        if input_map[up][cctv_location[1]] == 6:
            break
        elif visited[up][cctv_location[1]] == 0:
            zero_cnt +=1
        else :
            continue
    return [zero_cnt,"up"]

def check_down( input_map, visited , cctv_location=(0,0)):
    zero_cnt = 0
    for down in range(cctv_location[0] , len(visited)):
        if input_map[down][cctv_location[0]] == 6:
            break
        elif visited[down][cctv_location[0]] == 0:
            zero_cnt +=1
        else :
            continue
    return [zero_cnt,"down"]

def save_visited( dir, input_map, visited , cctv_location):
    visited[cctv_location[0]][cctv_location[1]] =1
    if dir == "up":
        for up in range(cctv_location[0] , -1, -1):
            if input_map[up][cctv_location[1]] == 6:
                break
            elif visited[up][cctv_location[1]] != 0:
                visited[up][cctv_location[1]] = 1

    elif dir == "down":
        for down in range(cctv_location[0] , len(visited)):
            if input_map[down][cctv_location[0]] == 6:
                break
            elif visited[down][cctv_location[0]] != 1:
                visited[down][cctv_location[0]] = 1

    elif dir == "left":
        for left in range(cctv_location[1]-1, -1 ,-1):
            if input_map[cctv_location[0]][left] == 6:
                break
            elif visited[cctv_location[0]][left] != 1:
                visited[cctv_location[0]][left] = 1
    
    elif dir == "right":
        for right in range(cctv_location[1] , len(visited[0])):
            if input_map[cctv_location[0]][right] == 6:
                break
            elif visited[cctv_location[0]][right] != 1:
                visited[cctv_location[0]][right] = 1

if __name__ == "__main__":
    #입력
    input_map = []
    N , M = map( int , sys.stdin.readline().split() )
    for i in range(N):
        row = list( map( int , sys.stdin.readline().split()))
        input_map.append(row)
    #visited배열
    visited=[[0 for _ in range(M)] for _ in range(N)]

    for i in range(N):
        for j in range(M):
            if input_map[i][j] == 1 :
                max_dir = check_left(input_map,visited,(i,j))
                if max_dir[0] < check_right(input_map,visited,(i,j))[0]:
                    max_dir = check_right(input_map,visited,(i,j))
                if max_dir[0] < check_down(input_map,visited,(i,j))[0]:
                    max_dir = check_down(input_map,visited,(i,j))
                if max_dir[0] < check_up(input_map,visited,(i,j))[0]:
                    max_dir = check_up(input_map,visited,(i,j))
                save_visited( max_dir[1], input_map, visited , (i,j))

            elif input_map[i][j] == 2:
                max_dir = [check_left(input_map,visited,(i,j)) , check_right(input_map,visited,(i,j))]
                if max_dir[0][0]+max_dir[1][0] < check_up(input_map,visited,(i,j))[0]+check_down(input_map,visited,(i,j))[0]:
                    max_dir = [check_up(input_map,visited,(i,j)) , check_down(input_map,visited,(i,j))]
    
                save_visited( max_dir[0][1], input_map, visited , (i,j))
                save_visited( max_dir[1][1], input_map, visited , (i,j))

            elif input_map[i][j] == 3:
                max_dir = [check_up(input_map,visited,(i,j)) , check_right(input_map,visited,(i,j))]
                if max_dir[0][0]+max_dir[1][0] < check_right(input_map,visited,(i,j))[0] + check_down(input_map,visited,(i,j))[0]:
                    max_dir = [check_right(input_map,visited,(i,j)) , check_down(input_map,visited,(i,j))]
                if max_dir[0][0]+max_dir[1][0] < check_down(input_map,visited,(i,j))[0]+ check_left(input_map,visited,(i,j))[0]:
                    max_dir = [check_down(input_map,visited,(i,j)) , check_left(input_map,visited,(i,j))]
                if max_dir[0][0]+max_dir[1][0] < check_left(input_map,visited,(i,j))[0]+ check_up(input_map,visited,(i,j))[0]:
                    max_dir = [check_left(input_map,visited,(i,j)) , check_up(input_map,visited,(i,j))]

                save_visited( max_dir[0][1], input_map, visited , (i,j))
                save_visited( max_dir[1][1], input_map, visited , (i,j))

            elif input_map[i][j] == 4:
                max_dir = [check_left(input_map,visited,(i,j)) , check_up(input_map,visited,(i,j)) , check_right(input_map,visited,(i,j))]

                if max_dir[0][0]+max_dir[1][0] + max_dir[2][0] < check_up(input_map,visited,(i,j))[0]+ check_right(input_map,visited,(i,j))[0]+check_down(input_map,visited,(i,j))[0]:
                    max_dir = [check_up(input_map,visited,(i,j)), check_right(input_map,visited,(i,j)),check_down(input_map,visited,(i,j))]

                if max_dir[0][0]+max_dir[1][0] + max_dir[2][0] < check_right(input_map,visited,(i,j))[0]+ check_down(input_map,visited,(i,j))[0] + check_left(input_map,visited,(i,j))[0]:
                    max_dir = [check_right(input_map,visited,(i,j)) , check_down(input_map,visited,(i,j)) , check_left(input_map,visited,(i,j))]

                if max_dir[0][0]+max_dir[1][0] < check_down(input_map,visited,(i,j))[0]+ check_left(input_map,visited,(i,j))[0] + check_up(input_map,visited,(i,j) )[0]:
                    max_dir = [check_down(input_map,visited,(i,j)), check_left(input_map,visited,(i,j)) , check_up(input_map,visited,(i,j))]

                save_visited( max_dir[0][1], input_map, visited , (i,j))
                save_visited( max_dir[1][1], input_map, visited , (i,j))
                save_visited( max_dir[2][1], input_map, visited , (i,j))
            
            elif input_map[i][j] == 5:
                for dir in ["left", "right", "up" , "down"]:
                    save_visited( dir, input_map, visited , (i,j))

            elif input_map[i][j] == 6:
                visited[i][j] = 1
            
            elif input_map[i][j] == 0:
                pass

 
    answer = 0
    for i in range(N):
        for j in range(M):
            if visited[i][j] == 0:
                answer+=1

    print(answer)

"""



import sys
import math
import copy

dx=[0,0,-1,1]
dy=[-1,1,0,0]
dirs=[0,[[0],[1],[2],[3]],[[0,1],[2,3]],[[1,2],[1,3],[0,2],[0,3]],[[0,1,2],[0,1,3],[0,2,3],[1,2,3]],[[0,1,2,3]]]
MIN= sys.maxsize

def dfs(start, MAP , cctv):
    global MIN

    if start == len(cctv):
        cnt = 0
        for y in range(0,N):
            for x in range(0,M):
                if MAP[y][x]==0:
                    cnt += 1
        MIN=min(MIN,cnt)

        return

    num,y,x = cctv[start]

    for dir in dirs[num]:
        tmp = copy.deepcopy(MAP)

        for i in dir:
            ny , nx = y + dy[i] , x + dx[i]
            while N > ny >=0 and M > nx >=0:

                if tmp[ny][nx] == 6:
                    break

                elif tmp[ny][nx] == 0:
                    tmp[ny][nx]='#'
                ny += dy[i]
                nx += dx[i]

        dfs(start+1,tmp,cctv)

if __name__ == "__main__":
    N,M= map(int , sys.stdin.readline().split())
    MAP=[list(map(int,input().split())) for _ in range(N)]

    cctv = [] #cctv_number , y,x 좌표

    for y in range(0,N):
        for x in range(0,M):
            if MAP[y][x] !=0 and MAP[y][x] !=6:
                cctv.append([MAP[y][x],y,x])

    dfs(0,MAP,cctv)
    print(MIN)