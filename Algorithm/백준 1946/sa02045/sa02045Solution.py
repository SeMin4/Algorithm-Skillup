import sys

T = int( sys.stdin.readline() )

for _ in range(T):

    N = int( sys.stdin.readline() )
    recruit = [ ]

    for i in range( N ):
        paper , meeting = map( int , sys.stdin.readline().split())
        recruit.append([paper,meeting])

    recruit = sorted(recruit , key=lambda x : x[0])
    cur_person = recruit[0]
    cnt = 1

    for i in range( 1, len(recruit)) :
        if recruit[i][1] < cur_person[1] :
            cur_person = recruit[i]
            cnt += 1

    print(cnt)

