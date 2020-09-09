import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Position implements Comparable<Position>{
    int i;
    int j;
    int cnt;
    int type;
    int isDoor;
    public Position(int i, int j, int cnt, int type, int isDoor){
        this.i = i;
        this.j = j;
        this.cnt = cnt;
        this.type = type;
        this.isDoor = isDoor;
    }
    @Override
    public int compareTo(Position o) {
        if(this.isDoor < o.isDoor)
            return -1;
        else if(this.isDoor == o.isDoor){
            if(this.cnt < o.cnt)
                return -1;
            else if(this.cnt == o.cnt)
                return 0;
            else
                return 1;
        }
        else return 1;
    }
}
public class Main {
    static int T, W, H;
    static final int[] dI = {-1, 0, 1, 0};
    static final int[] dJ = {0, 1, 0, -1};
    public static void main(String[] args) throws IOException {
        // write your code here
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        T = Integer.parseInt(br.readLine());
        for (int i = 0; i < T; i++) {
            StringTokenizer st  = new StringTokenizer(br.readLine());
            H = Integer.parseInt(st.nextToken());
            W = Integer.parseInt(st.nextToken());
            char[][] map = new char[H + 2][W + 2];
            Arrays.fill(map[0], '.');
            Arrays.fill(map[H + 1], '.');
            for (int j = 1; j <= H; j++) {
                map[j][0] = map[j][W + 1] = '.';
            }
            Queue<Position> queue = new LinkedList<>();
            int type = 0;
            for (int j = 1; j <= H; j++) {
                String tmp = br.readLine();
                for (int k = 1; k <= W; k++) {
                    map[j][k] = tmp.charAt(k - 1);
                    if(map[j][k] == '$'){
                        queue.offer(new Position(j, k, 0, ++type, 0));
                    }
                }
            }
            int result = bfs(map, queue);
            System.out.println(result);
        }
    }
    public static int bfs(char[][] map, Queue<Position> people){
        int[][][] visit = new int[3][H + 2][W + 2];
        for (int i = 0; i < H + 2; i++) {
            Arrays.fill(visit[0][i], -1);
            Arrays.fill(visit[1][i], -1);
            Arrays.fill(visit[2][i], -1);
        }
        PriorityQueue<Position> queue = new PriorityQueue<>();
        people.offer(new Position(0, 0, 0, 0, 0));
        while (!people.isEmpty()){
            Position nextPeople = people.poll();
            visit[nextPeople.type][nextPeople.i][nextPeople.j] = nextPeople.cnt;
            queue.offer(nextPeople);
            while (!queue.isEmpty()){
                Position position = queue.poll();
                for (int i = 0; i < 4; i++) {
                    int tmpI = position.i + dI[i];
                    int tmpJ = position.j + dJ[i];
                    if(tmpI >= 0 && tmpI < H + 2 && tmpJ >= 0 && tmpJ < W + 2){
                        if(visit[position.type][tmpI][tmpJ] == -1 && map[tmpI][tmpJ] != '*'){
                            if(map[tmpI][tmpJ] == '#'){
                                visit[position.type][tmpI][tmpJ] = position.cnt + 1;
                                queue.offer(new Position(tmpI, tmpJ, position.cnt + 1, position.type, 1));
                            }
                            else{
                                visit[position.type][tmpI][tmpJ] = position.cnt;
                                queue.offer(new Position(tmpI, tmpJ, position.cnt, position.type, 0));
                            }
                        }
                    }
                }
            }
        }
        int[][] result = new int[H + 2][W + 2];
        int res = Integer.MAX_VALUE;
        for (int i = 0; i < H + 2; i++) {
            for (int j = 0; j < W + 2; j++) {
                if(map[i][j] != '*'){
                    if(map[i][j] == '#'){
                        result[i][j] = visit[0][i][j] + visit[1][i][j] + visit[2][i][j] - 2;
                    }
                    else{
                        result[i][j] = visit[0][i][j] + visit[1][i][j] + visit[2][i][j];
                    }
                    res = Math.min(result[i][j] , res);
                }


            }
        }



        return res;
    }
}
