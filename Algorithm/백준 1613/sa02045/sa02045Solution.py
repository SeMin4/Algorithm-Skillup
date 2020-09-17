import sys
from collections import defaultdict

n , k = map( int , sys.stdin.readline().split())
input_map = []
for _ in range(k):
    row = list(map(int,sys.stdin.readline().split()))
    input_map.append(row)

s = int(sys.stdin.readline())

ask=[]

for _ in range(s):
    row = list(map(int,sys.stdin.readline().split()))
    ask.append(row)

graph = defaultdict()

for start,end in input_map :
    if start not in graph:
        graph[start] = [end]
    else :
        graph[start].append(end)

answer = [0]*n

def dfs(start,end):
    cur_dict = graph[start]
    if end in cur_dict:
        answer[start]= 1
    
    for next_start in cur_dict :
        dfs(next_start , end)

def dfs_back(end,start):
    cur_dict = graph[end]
    if start in cur_dict:
        answer[start]=(-1)
    
    for next_start in cur_dict :
        dfs(next_start , start)

visited=set()

for start,end in ask:
    visited.add(start)
    dfs(start,end)
    dfs_back(start,end)
    if answer[start] == 0:
        answer[start] = 0
        
dfs(1,4)
dfs(2,3)

print(answer)
