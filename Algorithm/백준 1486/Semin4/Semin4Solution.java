import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;
class Point implements Comparable<Point>{
    int i;
    int j;
    int value;
    public Point(int i, int j, int value){
        this.i = i;
        this.j = j;
        this.value = value;
    }

    @Override
    public int compareTo(Point o) {
        if(this.value < o.value){
            return -1;
        }
        else if(this.value == o.value){
            return 0;
        }
        else{
            return 1;
        }
    }
}
public class Main {
    static int N, M, T, D;//N 세로 M 가로 T 높이 제한 D 시간제한
    static int[] dI = {-1, 0, 1, 0};
    static int[] dJ = {0, 1, 0, -1};
    static int result = 0;
    public static void main(String[] args) throws IOException {
	// write your code here
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        T = Integer.parseInt(st.nextToken());
        D = Integer.parseInt(st.nextToken());
        int[][] map = new int[N][M];
        for (int i = 0; i < N; i++) {
            String tmp = br.readLine();
            for (int j = 0; j < M; j++) {
                map[i][j] = tmp.charAt(j) >= 'a' && tmp.charAt(j) <= 'z' ? tmp.charAt(j) - 'G' : tmp.charAt(j) - 'A';
            }
        }
        int[][] cost = new int[N][M];
        int[][] backCost = new int[N][M];
        for (int i = 0; i < N; i++) {
            Arrays.fill(cost[i], 1000001);
            Arrays.fill(backCost[i], 1000001);
        }
        cost[0][0] = 0;
        backCost[0][0] = 0;
        dijkstra(cost, map, 0);
        dijkstra(backCost, map, 1);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if(cost[i][j] + backCost[i][j] <= D){
                    result = Math.max(result, map[i][j]);
                }
            }
        }
        System.out.println(result);

    }
    public static void dijkstra(int[][] cost, int[][] map, int type){
        PriorityQueue<Point> costQueue = new PriorityQueue<>();
        costQueue.offer(new Point(0, 0, map[0][0]));
        while (!costQueue.isEmpty()){
            Point point = costQueue.poll();
            for (int i = 0; i < 4; i++) {
                int tmpI = point.i + dI[i];
                int tmpJ = point.j + dJ[i];
                if(tmpI >= 0 && tmpI < N && tmpJ >= 0 && tmpJ < M){//아직 방문하지 못한곳
                    int diff = map[tmpI][tmpJ] - point.value;
                    if(Math.abs(diff) > T)
                        continue;
                    int value = getCost(diff, type);
                    if(cost[point.i][point.j] + value < cost[tmpI][tmpJ]){
                        cost[tmpI][tmpJ] = cost[point.i][point.j] + value;
                        costQueue.offer(new Point(tmpI, tmpJ, map[tmpI][tmpJ]));
                    }
                }
            }
        }
    }

    public static int getCost(int diff, int type){
        if(diff == 0)
            return 1;
        else if(diff < 0){
            return type == 0 ? 1 : diff * diff;
        }
        else{
            return type == 1 ? 1 : diff * diff;
        }
    }
}

