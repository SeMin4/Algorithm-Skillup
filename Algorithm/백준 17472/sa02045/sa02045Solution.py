import sys
from collections import deque 
from collections import defaultdict

min_dist = [ [11] * 6 ] * 6
MAP = []
island = []
visited = set()
label_island = [ [0] * 6 ] *6 
connected_area = defaultdict()

def Input():
    N , M = map( int, sys.stdin.readline().split())
    
    for _ in range( N ):
        row = list( map ( int, sys.stdin.readline().split()))
        MAP.append( row )
    for i in range( N ):
        for j in range( M ):
            if MAP[i][j] == 1:
                island.append((i,j))

def bfs( i_j , num_island):
    q = deque()
    i = i_j[0]
    j = i_j[1]
    q.append((i,j))
    visited.add( (i,j) )
    label_island[i][j] = num_island
    connected_area[num_island].append((i,j))

    while q :
        q.popleft()



def numbering_isalnd():
    num_island = 1
    for (i , j) in island:
        if (i,j) not in visited:
            bfs( (i,j) , num_island + 1)
        
if __name__ == "__main__":
    Input()