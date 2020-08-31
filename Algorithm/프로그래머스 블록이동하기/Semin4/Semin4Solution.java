import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;

class Robot{
    int i1;
    int j1;
    int i2;
    int j2;
    int dir;
    int cnt = 0;
    public Robot(int i1, int j1, int i2, int j2, int dir, int cnt){
        this.i1 = i1;
        this.j1 = j1;
        this.i2 = i2;
        this.j2 = j2;
        this.dir = dir;
        this.cnt = cnt;
    }
}
public class Main{
    static int N;
    static final int[] dI = {-1, 0, 1, 0};
    static final int[] dJ = {0, 1, 0 ,-1};
    static final int[] hRotatedI1 = {-1, 1};//왼쪽 점이 기준
    static final int[] hRotatedJ1 = {-1, -1};
    static final int[] hRotatedI2 = {-1, 1};//오른쪽 점이 기준
    static final int[] hRotatedJ2 = {1, 1};
    static final int[] vRotatedI1 = {-1, -1};//위쪽 점이 기준
    static final int[] vRotatedJ1 = {-1, 1};
    static final int[] vRotatedI2 = {1, 1};//아래쪽 점이 기준
    static final int[] vRotatedJ2 = {-1, 1};

    public static void main(String[] args) {
        int[][] board = {{0, 0, 0, 1, 1},{0, 0, 0, 1, 0},{0, 1, 0, 1, 1},{1, 1, 0, 0, 1},{0, 0, 0, 0, 0}};
        int result = solution(board);
        System.out.println(result);
    }
    public static int solution(int[][] board) {
        int answer = 0;
        N = board.length;
        int[][] new_board = new int[N + 2][N + 2];
        for (int i = 0; i < N + 2; i++) {
            Arrays.fill(new_board[i], 1);
        }
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                new_board[i][j] = board[i - 1][j - 1];
            }
        }
        //왼쪽 i1 오른쪽 i2
        //위쪽이 i1 아래쪽이 i2
        boolean[][][] visit = new boolean[2][N + 2][N + 2];//0은 가로 1은 세로
        Queue<Robot> queue = new LinkedList<>();
        queue.offer(new Robot(1, 1, 1, 2,0, 0));
        visit[0][1][1] = true;
        visit[0][1][2] = true;
        while (!queue.isEmpty()){
            Robot robot = queue.poll();
            if(robot.i1 == N && robot.j1 == N || robot.i2 == N && robot.j2 == N)
                return robot.cnt;
            for (int i = 0; i < 4; i++) {
                int tmpI1 = robot.i1 + dI[i];
                int tmpJ1 = robot.j1 + dJ[i];
                int tmpI2 = robot.i2 + dI[i];
                int tmpJ2 = robot.j2 + dJ[i];
                if(validPos(new_board, tmpI1, tmpJ1, tmpI2, tmpJ2)){
                    //방문여부....
                    if(!visit[robot.dir][tmpI1][tmpJ1] || !visit[robot.dir][tmpI2][tmpJ2]){
                        visit[robot.dir][tmpI1][tmpJ1] = true;
                        visit[robot.dir][tmpI2][tmpJ2] = true;
                        queue.offer(new Robot(tmpI1, tmpJ1, tmpI2, tmpJ2, robot.dir, robot.cnt + 1));
                    }
                }
            }
            if(robot.dir == 0){//현재 가로며 세로가 될 예정 왼쪽 오른쪽 축을 기준으로 다 회전 시켜봐야 댐...
                for (int i = 0; i < 2; i++) {//왼쪽 점이 기준...
                    int tmpI1 = robot.i1;
                    int tmpJ1 = robot.j1;
                    int tmpI2 = robot.i2 + hRotatedI1[i];
                    int tmpJ2 = robot.j2 + hRotatedJ1[i];
                    if(validPos(new_board, tmpI1, tmpJ1, tmpI2, tmpJ2)){
                        if(validRotate(new_board, tmpI2, tmpJ2 + 1)){
                            //방문여부....
                            if(!visit[1][tmpI1][tmpJ1] || !visit[1][tmpI2][tmpJ2]){
                                visit[1][tmpI1][tmpJ1] = true;
                                visit[1][tmpI2][tmpJ2] = true;
                                queue.offer(new Robot(Math.min(tmpI1, tmpI2), tmpJ1, Math.max(tmpI1, tmpI2), tmpJ2, 1, robot.cnt + 1));
                            }
                        }
                    }
                }
                for (int i = 0; i < 2; i++) {//오른쪽 점이 기준...
                    int tmpI1 = robot.i1 + hRotatedI2[i];
                    int tmpJ1 = robot.j1 + hRotatedJ2[i];
                    int tmpI2 = robot.i2;
                    int tmpJ2 = robot.j2;
                    if(validPos(new_board, tmpI1, tmpJ1, tmpI2, tmpJ2)){
                        if(validRotate(new_board, tmpI1, tmpJ1 - 1)){
                            //방문여부....
                            if(!visit[1][tmpI1][tmpJ1] || !visit[1][tmpI2][tmpJ2]){
                                visit[1][tmpI1][tmpJ1] = true;
                                visit[1][tmpI2][tmpJ2] = true;
                                queue.offer(new Robot(Math.min(tmpI1, tmpI2), tmpJ1, Math.max(tmpI1, tmpI2), tmpJ2, 1, robot.cnt + 1));
                            }
                        }
                    }
                }
            }else{//현재 세로이며 가로가 될 예정 위쪽 아래쪽 축을 기준으로 다 회전..
                for (int i = 0; i < 2; i++) {//위쪽 점이 기준...
                    int tmpI1 = robot.i1;
                    int tmpJ1 = robot.j1;
                    int tmpI2 = robot.i2 + vRotatedI1[i];
                    int tmpJ2 = robot.j2 + vRotatedJ1[i];
                    if(validPos(new_board, tmpI1, tmpJ1, tmpI2, tmpJ2)){
                        if(validRotate(new_board, tmpI2 + 1, tmpJ2)){
                            if(!visit[0][tmpI1][tmpJ1] || !visit[0][tmpI2][tmpJ2]){
                                visit[0][tmpI1][tmpJ1] = true;
                                visit[0][tmpI2][tmpJ2] = true;
                                queue.offer(new Robot(tmpI1, Math.min(tmpJ1, tmpJ2), tmpI2, Math.max(tmpJ1, tmpJ2), 0, robot.cnt + 1));
                            }
                        }
                    }
                }
                for (int i = 0; i < 2; i++) {//아래쪽 점이 기준...
                    int tmpI1 = robot.i1 + vRotatedI2[i];
                    int tmpJ1 = robot.j1 + vRotatedJ2[i];
                    int tmpI2 = robot.i2;
                    int tmpJ2 = robot.j2;
                    if(validPos(new_board, tmpI1, tmpJ1, tmpI2, tmpJ2)){
                        if(validRotate(new_board, tmpI1 - 1, tmpJ1)){
                            if(!visit[0][tmpI1][tmpJ1] || !visit[0][tmpI2][tmpJ2]){
                                visit[0][tmpI1][tmpJ1] = true;
                                visit[0][tmpI2][tmpJ2] = true;
                                queue.offer(new Robot(tmpI1, Math.min(tmpJ1, tmpJ2), tmpI2, Math.max(tmpJ1, tmpJ2), 0, robot.cnt + 1));
                            }
                        }
                    }
                }
            }
        }
        return answer;
    }
    public static boolean validPos(int[][] board, int tmpI1, int tmpJ1, int tmpI2, int tmpJ2){
        return board[tmpI1][tmpJ1] == 0 && board[tmpI2][tmpJ2] == 0;
    }
    public static boolean validRotate(int[][] board, int tmpI2, int tmpJ2){
        return board[tmpI2][tmpJ2] == 0;
    }

}