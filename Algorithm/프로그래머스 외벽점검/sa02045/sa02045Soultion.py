from collections import deque
import itertools

def solution(n,weak,dist):
    dist.sort(reverse= True)
    weak = deque(weak)
    if weak[-1]-weak[1] <=dist[0]:
        return 1

    for friend_number in range(2,len(dist)+1):
        dist_set = list(itertools.permutations(dist[:friend_number]))
        for number_person in range(2,len(weak)+1):
            for friend in dist:

#풀이공부하고 완벽히 이해후 이번주까지 올리겠습니다.
