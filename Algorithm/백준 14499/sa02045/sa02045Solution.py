import sys

"""
주사위를 굴려서 좌표를 움직이고 윗면에 표시된 수를 출력
d[1] = 윗면 d[6] = 밑면
"""

def rolling_dice(order,x,y):

    if order == 1:
        dice[1],dice[3],dice[4],dice[6] = dice[4],dice[1],dice[6],dice[3]
    elif order ==2 :
        dice[1],dice[3],dice[4],dice[6] = dice[3],dice[6],dice[1],dice[4]
    elif order == 3:
        dice[1],dice[2],dice[5],dice[6] = dice[5],dice[1],dice[6],dice[2]
    elif order == 4:
        dice[1], dice[2], dice[5], dice[6] = dice[2],dice[6],dice[1],dice[5]

    if input_map[x][y] != 0:
        dice[6] = input_map[x][y]
        input_map[x][y] = 0
    else:
        input_map[x][y] = dice[6]

    print(dice[1])

    """
    입력 후에 명령에 따라서 동작
    """

if __name__ == '__main__':

    N , M , x , y , K = map(int,sys.stdin.readline().split())

    input_map = []
    for i in range(N):
        row = list(map(int,sys.stdin.readline().split()))
        input_map.append(row)

    order_list = list(map(int,sys.stdin.readline().split()))

    dice = [ 0 for _ in range(6+1)]

    """
    맵 밖으로 나가는지 검사후 이동
    주사위 던지기
    """
    for order in order_list:
        if order == 1 and y+1 < M :
            y= y+1
            rolling_dice(order, x, y)
        elif order == 2 and y-1>=0:
            y= y-1
            rolling_dice(order, x, y)
        elif order == 3 and x-1 >=0:
            x= x-1
            rolling_dice(order, x, y)
        elif order ==4 and x+1 < N:
            x +=1
            rolling_dice(order, x, y)

    """
    틀렸던 코드  : contiune 잘못된 사용
    for order in order_list:
        if order == 1 :
            if y+1 > M :
                continue
            else :
                y = y+1
        elif order == 2 :
             if y-1 < 0 :
                continue
            else :
                y = y-1
        elif order == 3 a:
             if x+1 > N :
                continue
            else :
                x = x+1

        elif order ==4 :
             if x-1 > N :
                continue
            else :
                x = x+1
        rolling_dice(order, x, y)
    """

