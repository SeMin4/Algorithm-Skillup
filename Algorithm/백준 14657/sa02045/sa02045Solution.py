import sys
from collections import defaultdict

sys.setrecursionlimit(10**9)
visited = []

fartestNode = 0
minCost = 0
diameter = 0

# dfs 두번 돌리기
def dfs(nodeNumber, length, cost):
    global diameter
    global minCost
    global fartestNode

    if diameter < length :
        fartestNode = nodeNumber
        diameter = length
        minCost = cost
    elif diameter == length and minCost > cost:
        fartestNode = nodeNumber
        minCost = cost

    visited.append(nodeNumber)

    for dest , next_cost in graph[nodeNumber]:
        if dest not in visited:
            dfs(dest ,  length + 1 , cost + next_cost)
    #2 N개의 문제들 중 링크를 통해 도달할 수 없는 문제는 없다. --> 모든 문제들은 연결되어있음
    #1 N개의 문제들과 두 문제를 연결하는 링크가 N-1개 존재한다. --> 

if __name__ == "__main__":
    N , T = map( int , sys.stdin.readline().split() )
    graph = defaultdict(list)

    for _ in range(N - 1):
        A, B ,C = map(int , sys.stdin.readline().split())
        graph[A].append([B,C])
        graph[B].append([A,C])

    diameter = 1
    dfs(1,1,0)

    diameter = 1
    minCost = 0
    dfs(fartestNode,1,0)

    residue = 0 if minCost % T == 0 else 1
    print((minCost / T + residue))