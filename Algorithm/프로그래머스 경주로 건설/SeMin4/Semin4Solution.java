import javafx.geometry.Pos;

import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;

class Position implements Comparable<Position>{
    int i;
    int j;
    int value;
    int direction;// 1이면 가로 0이면 세로
    public Position(int i, int j, int value, int direction){
        this.i = i;
        this.j = j;
        this.value = value;
        this.direction = direction;
    }

    @Override
    public int compareTo(Position o) {
        if(this.value < o.value)
            return -1;
        else if (this.value == o.value)
            return 0;
        else
            return 1;
    }
}
public class Main {

    public static void main(String[] args) {
	// write your code here
//        int[][] board = {{0,0,0},{0,0,0},{0,0,0}};
//        int[][] board = {{0,0,0,0,0,0,0,1},{0,0,0,0,0,0,0,0},{0,0,0,0,0,1,0,0},{0,0,0,0,1,0,0,0},{0,0,0,1,0,0,0,1},{0,0,1,0,0,0,1,0},{0,1,0,0,0,1,0,0},{1,0,0,0,0,0,0,0}};
//        int[][] board = {{0,0,1,0},{0,0,0,0},{0,1,0,1},{1,0,0,0}};
//        int[][] board = {{0,0,0,0,0,0},{0,1,1,1,1,0},{0,0,1,0,0,0},{1,0,0,1,0,1},{0,1,0,0,0,1},{0,0,0,0,0,0}};
//        int[][] board = {
//                {0, 0, 0, 0, 0},
//                {0, 1, 1, 1, 0},
//                {0, 0, 1, 0, 0},
//                {1, 0, 0, 0, 1},
//                {0, 1, 1, 0, 0}
//        };
        int[][] board = {{0,0,0},{1,1,1},{0,0,0}};
        int answer = solution(board);
        System.out.println(answer);
    }

    public static int solution(int[][] board) {
        int N = board.length;
        int[] dI = {-1, 0, 1, 0};
        int[] dJ = {0, 1, 0, -1};
        int answer = 0;
        int[][] cost = new int[N][N];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cost[i][j] = Integer.MAX_VALUE;
            }
        }
        cost[0][0] = 0;
        // PriorityQueue<Position> queue = new PriorityQueue<>();
        Queue<Position> queue = new LinkedList<>();
        queue.add(new Position(0, 0, 0, -1));//세로에서 출발
        while (!queue.isEmpty()){
            Position position = queue.poll();
            // if(position.i == N - 1 && position.j == N - 1){//위치 찾으면 리턴
            //     return cost[N - 1][N - 1];
            // }
            for (int i = 0; i < 4; i++) {
                int tmpI = position.i + dI[i];
                int tmpJ = position.j + dJ[i];
                if(tmpI >= 0 && tmpI < N && tmpJ >= 0 && tmpJ < N){//배열 벗어나는지 검사
                    if(board[tmpI][tmpJ] == 0){//갈수 있는 길이면
                        if(position.direction == -1){//맨처음!!
                            cost[tmpI][tmpJ] = 100;
                            queue.add(new Position(tmpI, tmpJ, 100, i % 2));
                        }
                        else if((position.direction % 2) == (i % 2)){// 같은방향에서 같은방향으로 옴
                            if(position.value + 100 <= cost[tmpI][tmpJ]){
                                cost[tmpI][tmpJ] = position.value + 100;
                                queue.add(new Position(tmpI, tmpJ, position.value + 100, position.direction));
                            }
                        }else{//다른방향에서 옴...
                            if(position.value + 600 <= cost[tmpI][tmpJ]){
                                cost[tmpI][tmpJ] = position.value + 600;
                                queue.add(new Position(tmpI, tmpJ, position.value + 600, i % 2));
                            }
                        }
                    }
                }
            }

        }

        return cost[N - 1][N - 1];
    }
}
