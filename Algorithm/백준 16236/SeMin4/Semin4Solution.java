import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

class Shark{
    int i;
    int j;
    int age;
    int count;
    public Shark(int i, int j, int age){
        this.i = i;
        this.j = j;
        this.age = age;
        this.count = 0;
    }
}
class Position implements Comparable<Position>{
    int i;
    int j;
    int length;
    int value;
    public Position(int i, int j, int length, int value){
        this.i = i;
        this.j = j;
        this.length = length;
        this.value = value;
    }
    @Override
    public int compareTo(Position o) {
        if(this.length < o.length){
            return -1;
        }else if(this.length == o.length){
            if(this.i < o.i){
                return -1;
            }else if(this.i == o.i){
                if(this.j < o.j){
                    return -1;
                }else if(this.j == o.j){
                    return 0;
                }else{
                    return 1;
                }
            }else{
                return 1;
            }
        }else{
            return  1;
        }
    }
}
public class Main {
    static int[] dI = {-1, 0, 1, 0};
    static int[] dJ = {0, 1, 0, -1};
    static int N;
    static Shark shark;
    static int time = 0;
    public static void main(String[] args) throws IOException {
	// write your code here
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());

        int[][] map = new int[N][N];
        StringTokenizer st;
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
                if(map[i][j] == 9) {
                    map[i][j] = 0;
                    shark = new Shark(i, j, 2);
                }
            }
        }
        boolean[][] visit = new boolean[N][N];
        bfs(map, visit);
        System.out.println(time);

    }
    public static void bfs(int[][] map, boolean[][] visit){
        PriorityQueue<Position> priorityQueue = new PriorityQueue<>();
        priorityQueue.add(new Position(shark.i, shark.j, 0, 0));
        while (!priorityQueue.isEmpty()){
            Position position = priorityQueue.poll();
            if(position.value != 0 && position.value < shark.age){
                shark.count += 1;
                shark.i = position.i;
                shark.j = position.j;
                map[position.i][position.j] = 0;
                if(shark.count == shark.age){
                    shark.age += 1;
                    shark.count = 0;
                }
                time += position.length;
                priorityQueue.clear();
                for (int i = 0; i < N; i++) {
                    Arrays.fill(visit[i], false);
                }
                priorityQueue.add(new Position(shark.i, shark.j, 0, 0));
                continue;
            }
            for (int i = 0; i < 4; i++) {
                int tmpI = position.i + dI[i];
                int tmpJ = position.j + dJ[i];
                if(tmpI >= 0 && tmpI < N && tmpJ >= 0 && tmpJ < N){
                    if(map[tmpI][tmpJ] <= shark.age && !visit[tmpI][tmpJ]){
                        priorityQueue.add(new Position(tmpI, tmpJ, position.length + 1, map[tmpI][tmpJ]));
                        visit[tmpI][tmpJ] = true;
                    }
                }
            }
        }
    }
}
