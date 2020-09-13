import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    static int N;
    public static void main(String[] args) throws IOException {
	// write your code here
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        ArrayList<Integer>[] list = new ArrayList[N + 1];
        for (int i = 1; i <= N; i++) {
            list[i] = new ArrayList<Integer>();
        }
        for (int i = 0; i < N - 1; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int V1 = Integer.parseInt(st.nextToken());
            int V2 = Integer.parseInt(st.nextToken());
            list[V1].add(V2);
            list[V2].add(V1);
        }
        int[] earlyAdapter = new int[N + 1];
        boolean[] visit = new boolean[N + 1];
        for (int i = 1; i <= N; i++) {
            if(!visit[i]){
                visit[i] = true;
                dfs(i, visit, earlyAdapter, list);
            }
        }
        int sum = 0;
//        for (int i = 1; i < earlyAdapter.length; i++) {
//            System.out.print(earlyAdapter[i] + " ");
//        }
        for (int i = 1; i < earlyAdapter.length; i++) {
            sum += earlyAdapter[i];
        }
        System.out.println(sum);

    }
    public static int dfs(int V, boolean[] visit, int[] earlyAdapter, ArrayList<Integer>[] list){
        for (int i = 0; i < list[V].size(); i++) {
            int v = list[V].get(i);
            if(!visit[v]){
                visit[v] = true;//방문하였음..
                int valid = dfs(v, visit, earlyAdapter, list);
                if(earlyAdapter[V] == 0)
                    earlyAdapter[V] = valid == 0 ? 1 : 0;
            }
        }
        return earlyAdapter[V];
    }
}
