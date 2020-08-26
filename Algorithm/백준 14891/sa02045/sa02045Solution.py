"""from collections import deque
import sys

gear_list=[]
checked = [0 for _ in range(5)]

def rotate(gear_number,dir):
    if dir == 1:
        gear_list[gear_number].appendleft(gear_list[gear_number].pop())
    elif dir == -1:
        gear_list[gear_number].append(gear_list[gear_number].popleft())

def check_left(gear_number,dir):
    if 1< gear_number <=4:
        if gear_list[gear_number][2] != gear_list[gear_number+1][6]:
            check_left(gear_number-1,-1*dir)
            rotate(gear_number,dir)

def check_right(gear_number,dir):
    if 1<=gear_number<4:
        if gear_list[gear_number][6] != gear_list[gear_number-1][2]:
            check_right(gear_number+1,-1*dir)
            rotate(gear_number,dir)
    
if __name__ == "__main__":
    #input
    for _ in range(4):
        row = deque(map(int,sys.stdin.readline().strip()))
        gear_list.append(row)
    K = int(sys.stdin.readline())
    sum=0
    for _ in range(K):
        checked = [0 for _ in range(5)]
        gear_number , dir = map(int,sys.stdin.readline().split())
        check_left(gear_number-1,-1*dir)
        check_right(gear_number+1,-1*dir)

    print(gear_list)"""

import sys
from collections import deque

def check_left(gear_number , dir):
    if gear_number < 1:
        return
    if gear_list[gear_number][2] != gear_list[gear_number+1][6]:
        check_left(gear_number-1,-dir)
        rotate(gear_number,dir)
    

def check_right(gear_number , dir):
    if gear_number > 4:
        return
    if gear_list[gear_number][6] !=gear_list[gear_number-1][2]:
        check_right(gear_number+1, -dir)
        rotate(gear_number,dir)

def rotate(gear_number,dir):
    if dir == 1:
        gear_list[gear_number].appendleft(gear_list[gear_number].pop())
    elif dir == -1:
        gear_list[gear_number].append(gear_list[gear_number].popleft())

gear_list=[]

gear_list.append([])

for _ in range(4):
    row = deque(map(int,sys.stdin.readline().strip()))
    gear_list.append(row)

K = int(sys.stdin.readline())

for _ in range(K):
    gear_number , dir = map(int,sys.stdin.readline().split())
    check_left(gear_number-1,-1*dir)
    check_right(gear_number+1,-1*dir)
    rotate(gear_number,dir)

ans = 0
for index in range(1,5):
    score = gear_list[index][0]
    if score ==1:
        ans += 2**(index-1)
print(ans)