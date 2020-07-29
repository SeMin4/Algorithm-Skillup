import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;
class Snake{
    int i;
    int j;
    int dir;//0 오른쪽 1 아래쪽 2 왼쪽 3 위쪽
    ArrayList<Position> positionArrayList;
    public Snake(){
        this.i = 0;
        this.j = 0;
        this.dir = 0;
        positionArrayList = new ArrayList<>();
        positionArrayList.add(new Position(0 ,0));
    }
}
class Position{
    int i;
    int j;
    public Position(int i, int j){
        this.i = i;
        this.j = j;
    }
}
class Move{
    int sec;
    char command;
    public Move(int sec, char command){
        this.sec = sec;
        this.command = command;
    }
}
public class Main {
    static int N, K, L;
    static int result = 0;
    static int[] dI = {0, 1, 0, -1};
    static int[] dJ = {1, 0, -1, 0};
    public static void main(String[] args) throws IOException {
	// write your code here
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        K = Integer.parseInt(br.readLine());
        int[][] map = new int[N][N];
        int row, col;
        StringTokenizer st;
        for (int i = 0; i < K; i++) {
             st = new StringTokenizer(br.readLine());
            row = Integer.parseInt(st.nextToken());
            col = Integer.parseInt(st.nextToken());
            map[row - 1][col - 1] = 1;
        }
        L = Integer.parseInt(br.readLine());
        int sec;
        char command;
        Queue<Move> moves = new LinkedList<>();
         for (int i = 0; i < L; i++) {
            st = new StringTokenizer(br.readLine());
            sec = Integer.parseInt(st.nextToken());
            command = st.nextToken().charAt(0);
            moves.add(new Move(sec, command));
        }
         Snake snake = new Snake();
        while (true){
            result += 1;
            int tmpI = snake.i + dI[snake.dir];
            int tmpJ = snake.j + dJ[snake.dir];
            if(tmpI >= 0 && tmpI < N && tmpJ >=0 && tmpJ < N){
                for (int i = 0; i < snake.positionArrayList.size(); i++) {//자기 몸뚱아리랑 부딪히는지 체크...
                    Position position = snake.positionArrayList.get(i);
                    if(position.i == tmpI && position.j == tmpJ){
                        System.out.println(result);
                        return;
                    }
                }
                if(map[tmpI][tmpJ] == 1){//사과가 있으면
                    map[tmpI][tmpJ] = 0;
                    snake.i = tmpI;
                    snake.j = tmpJ;
                    snake.positionArrayList.add(new Position(tmpI, tmpJ));
                }else{
                    snake.i = tmpI;
                    snake.j = tmpJ;
                    snake.positionArrayList.remove(0);
                    snake.positionArrayList.add(new Position(tmpI, tmpJ));
                }
                if(!moves.isEmpty()){
                    Move move = moves.peek();
                    if(move.sec == result){
                        moves.poll();
                        if(move.command == 'D'){
                            snake.dir  = (snake.dir + 1) % 4;
                        }
                        else if(move.command == 'L'){
                            if(snake.dir == 0)
                                snake.dir = 3;
                            else
                                snake.dir -= 1;
                        }
                    }
                }

            }else{
                System.out.println(result);
                return;
            }

        }
    }
}
