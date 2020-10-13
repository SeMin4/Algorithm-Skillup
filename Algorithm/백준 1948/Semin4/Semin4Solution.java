import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

class Edge{
    int vertex;
    int cost;
    public Edge(int vertex, int cost){
        this.vertex = vertex;
        this.cost = cost;
    }
}
public class Main {
    static int N, M, S, E;
    static int MAX_COST = Integer.MIN_VALUE;
    static int VERTEX_CNT = 0;
    public static void main(String[] args) throws IOException {
	// write your code here
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        M = Integer.parseInt(br.readLine());
        ArrayList<Edge>[] graph = new ArrayList[N + 1];
        ArrayList<Edge>[] reverseGraph = new ArrayList[N + 1];
        for (int i = 1; i <= N; i++) {
            graph[i] = new ArrayList<>();
            reverseGraph[i] = new ArrayList<>();
        }
        for (int i = 0; i < M; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int V1 = Integer.parseInt(st.nextToken());
            int V2 = Integer.parseInt(st.nextToken());
            int cost = Integer.parseInt(st.nextToken());
            graph[V1].add(new Edge(V2, cost));
            reverseGraph[V2].add(new Edge(V1, cost));
        }
        StringTokenizer st = new StringTokenizer(br.readLine());
        S = Integer.parseInt(st.nextToken());
        E = Integer.parseInt(st.nextToken());
        Queue<Edge> queue = new LinkedList<>();
        int[] maxTime = new int[N + 1];
        maxTime[S] = 0;
        queue.offer(new Edge(S, 0 ));
        while (!queue.isEmpty()){
            Edge edge = queue.poll();
            for (int j = 0; j < graph[edge.vertex].size(); j++) {
                Edge e = graph[edge.vertex].get(j);
                if(maxTime[e.vertex] < edge.cost + e.cost){
                    maxTime[e.vertex] = edge.cost + e.cost;
                    queue.offer(new Edge(e.vertex, edge.cost + e.cost));
                }

            }
        }
        System.out.println(maxTime[E]);
        queue.offer(new Edge(E, maxTime[E]));
        boolean[] visit = new boolean[N + 1];
        visit[E] = true;
        while (!queue.isEmpty()){
            Edge edge = queue.poll();
            for(int j = 0; j < reverseGraph[edge.vertex].size(); j++){
                Edge e = reverseGraph[edge.vertex].get(j);
                if(maxTime[e.vertex] == edge.cost - e.cost){
                    VERTEX_CNT += 1;
                    if(!visit[e.vertex]){
                        visit[e.vertex] = true;
                        queue.offer(new Edge(e.vertex, edge.cost - e.cost));
                    }
                }
            }
        }
        System.out.println(VERTEX_CNT);
    }
}
