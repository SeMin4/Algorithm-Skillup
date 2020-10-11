import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
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
    static int N, T;
    static int maximumProblem = Integer.MIN_VALUE;
    static int minimumTime = Integer.MAX_VALUE;
    static int idx = 0;
    public static void main(String[] args) throws IOException {
        // write your code here
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        T = Integer.parseInt(st.nextToken());
        ArrayList<Edge>[] list = new ArrayList[N + 1];
        for (int i = 1; i <= N; i++) {
            list[i] = new ArrayList<>();
        }
        for (int i = 0; i < N - 1; i++) {
            st = new StringTokenizer(br.readLine());
            int V1 = Integer.parseInt(st.nextToken());
            int V2 = Integer.parseInt(st.nextToken());
            int cost = Integer.parseInt(st.nextToken());
            list[V1].add(new Edge(V2, cost));
            list[V2].add(new Edge(V1, cost));
        }
        boolean[] visit = new boolean[N + 1];
        visit[1] = true;
        dfs(1, visit, list, 1,0);
        visit = new boolean[N + 1];
        visit[idx] = true;
        dfs(1, visit, list, idx, 0);
        System.out.println(minimumTime % T == 0 ? minimumTime / T : minimumTime / T + 1);
    }
    public static void dfs(int depth, boolean[] visit, ArrayList<Edge>[] graph, int V, int cost){
        if(maximumProblem < depth){
            maximumProblem = depth;
            minimumTime = cost;
            idx = V;
        }
        else if(maximumProblem == depth){
            if(minimumTime > cost){
                minimumTime = cost;
                idx = V;
            }
        }
        for (int i = 0; i < graph[V].size(); i++) {
            int vertex = graph[V].get(i).vertex;
            if(!visit[vertex]){
                visit[vertex] = true;
                dfs(depth + 1, visit, graph, vertex, cost + graph[V].get(i).cost);
            }
        }
    }
}
