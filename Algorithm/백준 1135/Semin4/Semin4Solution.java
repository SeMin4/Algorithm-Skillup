import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class Main {
    static int N;
    public static void main(String[] args) throws IOException {
	// write your code here
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        int[] parent = new int[N];
        StringTokenizer st = new StringTokenizer(br.readLine());
        ArrayList<Integer>[] graph = new ArrayList[N];
        for (int i = 0; i < N; i++) {
            graph[i] = new ArrayList<>();
        }
        parent[0] = Integer.parseInt(st.nextToken());
        for (int i = 1; i < N; i++) {
            parent[i] = Integer.parseInt(st.nextToken());
            graph[parent[i]].add(i);
        }
        System.out.println(dfs(0, graph));
    }
    public static int dfs(int vertex, ArrayList<Integer>[] graph){
        int result = 0;
        if(graph[vertex].size() == 0)
            return 0;
        ArrayList<Integer> list = new ArrayList<>();
        for (int i = 0; i < graph[vertex].size(); i++) {
            int v = graph[vertex].get(i);
            list.add(dfs(v, graph));
        }
        Collections.sort(list, Collections.reverseOrder());
        int max = 0;
        for (int i = 0; i < list.size(); i++) {
            max = Math.max(max,list.get(i) + (i +1));
        }
        return max;
    }
}
