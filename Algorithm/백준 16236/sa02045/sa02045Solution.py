from heapq import heappop, heappush

# 맵 크기 , 맵 입력
N = int(input())
arr = [list(map(int, input().split())) for _ in range(N)]
# 큐를 구현하는 리스트
queue = []


# 초기화 아기상어 정보를 큐에 집어넣는다.
def init():
    for y in range(N):
        for x in range(N):
            if arr[y][x] == 9:
                heappush(queue, (0, y, x))
                arr[y][x] = 0
                return


# bfs 아기상어의 위치에서 최단거리 계산
def bfs():
    global queue
    # 초기 아기상어 정보
    shark_body, shark_eat, distance = 2, 0, 0

    # 경로 초기화
    path = [[0] * N for _ in range(N)]

    while queue:
        # 큐에서 distance, y의 좌표, x의 좌표 순서로 minheap

        # 가장 가까운 distance pop
        d, y, x = heappop(queue)

        # 먹을 수 있으면 먹고, 크기를 키울수 있으면 키운다.
        if 0 < arr[y][x] < shark_body:
            shark_eat += 1
            arr[y][x] = 0
            if shark_eat == shark_body:
                shark_body += 1
                shark_eat = 0

            # 거리 증가
            distance += d

            d = 0
            queue = []
            path = [[0] * N for _ in range(N)]

        # x, y 좌표 움직이기
        for dx, dy in (0, -1), (-1, 0), (1, 0), (0, 1):
            nd, ny, nx = d + 1, y + dy, x + dx

            # 맵을 벗어나면 queue에 안집어 넣는다.
            if nx < 0 or nx >= N or ny < 0 or ny >= N:
                continue

            #
            if arr[ny][nx] > shark_body or path[ny][nx]:
                continue
            path[ny][nx] = 1
            heappush(queue, (nd, ny, nx))
    print(distance)


init()
bfs()