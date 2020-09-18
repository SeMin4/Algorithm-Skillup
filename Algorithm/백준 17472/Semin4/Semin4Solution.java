import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Island{
    int i;
    int j;
    public Island(int i, int j){
        this.i = i;
        this.j = j;
    }
}
class Edge implements Comparable<Edge>{
    int v1;
    int v2;
    int weight;
    public Edge(int v1, int v2, int weight){
        this.v1 = v1;
        this.v2 = v2;
        this.weight = weight;
    }

    @Override
    public int compareTo(Edge o) {
        if(this.weight < o.weight)
            return -1;
        else if(this.weight == o.weight)
                return 0;
        else
            return 1;
    }
}
public class Main {
    static int N, M;
    static int[] dI = {-1, 0, 1, 0};
    static int[] dJ = {0, 1, 0, -1};
    public static void main(String[] args) throws IOException {
	// write your code here
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        int[][] map = new int[N][M];
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < M; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        int[][] graph = new int[N][M];
        ArrayList<Island>[] island = new ArrayList[7];
        for (int i = 0; i < 7; i++) {
            island[i] = new ArrayList<>();
        }

        int cnt = bfs(map, graph, island);
//        int[][] relation = new int[cnt + 1][cnt + 1];
        int[] parent = new int[cnt + 1];
        for (int i = 1; i <= cnt; i++) {
//            Arrays.fill(relation[i], Integer.MAX_VALUE);
//            relation[i][i] = 0;
            parent[i] = i;
        }
        PriorityQueue<Edge> queue = new PriorityQueue<>();
        getLength(queue,graph, island);
//        for (int i = 1; i <= cnt; i++) {
//            for (int j = 1; j <= cnt; j++) {
//                System.out.print(relation[i][j] + " ");
//            }
//            System.out.println();
//        }
        int length = 0;
        int bridge = 0;
        while (!queue.isEmpty()){
            Edge edge = queue.poll();
            boolean chk = union(edge.v1, edge.v2, parent);
            if(chk){
                length += edge.weight;
                bridge += 1;
            }
        }
        if(bridge == cnt - 1)
            System.out.println(length);
        else
            System.out.println(-1);
    }
    public static int bfs(int[][] map, int[][] graph, ArrayList<Island>[] island){
        int cnt = 0;
        boolean[][] visit = new boolean[N][M];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if(map[i][j] == 1 && !visit[i][j]){
                    cnt += 1;
                    Queue<int[]> queue = new LinkedList<>();

                    queue.offer(new int[]{i,j});
                    island[cnt].add(new Island(i, j));
                    visit[i][j] = true;
                    graph[i][j] = cnt;
                    while (!queue.isEmpty()){
                        int[] point = queue.poll();
                        for (int k = 0; k < 4; k++) {
                            int tmpI = point[0] + dI[k];
                            int tmpJ = point[1] + dJ[k];
                            if(tmpI >= 0 && tmpI < N && tmpJ >= 0 && tmpJ < M){
                                if(map[tmpI][tmpJ] == 1 && !visit[tmpI][tmpJ]){
                                    visit[tmpI][tmpJ] = true;
                                    graph[tmpI][tmpJ] = cnt;
                                    queue.offer(new int[]{tmpI, tmpJ});
                                    island[cnt].add(new Island(tmpI, tmpJ));
                                }
                            }
                        }
                    }
                }
            }
        }
        return cnt;
    }
    public static void getLength(PriorityQueue<Edge> queue, int[][] graph, ArrayList<Island>[] island){
        for (int i = 1; i < island.length; i++) {
            ArrayList<Island> posList = island[i];
            for (int j = 0; j < posList.size(); j++) {
                int posI = posList.get(j).i;
                int posJ = posList.get(j).j;
                checkVertical(0, 1, posJ, posI, queue, graph, i);
                checkHorizontal(1, 1, posJ, posI, queue, graph, i);
                checkVertical(2, 1, posJ, posI, queue, graph, i);
                checkHorizontal(3, 1, posJ, posI, queue, graph, i);
            }
        }
    }
    public static void checkHorizontal(int type, int k, int posJ, int posI, PriorityQueue<Edge> queue, int[][] graph, int i){
        while (true){//왼쪽 방향 오른쪽.
            int tmpJ = posJ + dJ[type] * k;
            if(tmpJ >= 0 && tmpJ < M){
                if(graph[posI][tmpJ] != 0){
                    if(k > 2){
                        queue.offer(new Edge(i, graph[posI][tmpJ], k - 1));
//                        relation[i][graph[posI][tmpJ]] = Math.min(relation[i][graph[posI][tmpJ]], k - 1);
                    }
                    break;
                }
            }
            else
                break;
            k += 1;
        }
    }
    public static void checkVertical(int type, int k, int posJ, int posI, PriorityQueue<Edge> queue, int[][] graph, int i){
        while (true){//위쪽 방향.
            int tmpI = posI + dI[type] * k;
            if(tmpI >= 0 && tmpI < N){
                if(graph[tmpI][posJ] != 0){
                    if(k > 2){
                        queue.offer(new Edge(i, graph[tmpI][posJ], k - 1));
//                        relation[i][graph[tmpI][posJ]] = Math.min(relation[i][graph[tmpI][posJ]], k);
                    }
                    break;
                }
            }
            else
                break;
            k += 1;
        }
    }
    public static boolean union(int v1, int v2, int[] parent){
        int parentV1 = find(v1, parent);
        int parentV2 = find(v2, parent);
        if(parentV1 == parentV2)
            return false;
        parent[parentV2] = parentV1;
        return true;
    }
    public static int find(int v1, int[] parent){
        if(parent[v1] == v1){
            return v1;
        }
        return find(parent[v1], parent);
    }
}
