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
            list[i] = new ArrayList<>();
        }
        for (int i = 0; i < N - 1; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int V1 = Integer.parseInt(st.nextToken());
            int V2 = Integer.parseInt(st.nextToken());
            list[V1].add(V2);
            list[V2].add(V1);
        }
        boolean[] visit = new boolean[N + 1];
        int[][] dp = new int[N + 1][2];//각각의 정점과 스테이트들을 표현.
        for (int i = 0; i < N + 1; i++) {
            Arrays.fill(dp[i], -1);
        }
        visit[1] = true;
        DFS(list, visit, dp, 1);
        System.out.println(Math.min(dp[1][0], dp[1][1]));

    }
    public static void DFS(ArrayList<Integer>[] list, boolean[] visit,int[][] dp, int V){
        dp[V][0] = 0;
        dp[V][1] = 1;//자기 자신의 값을 선정.
        for (int i = 0; i < list[V].size(); i++) {
            int v = list[V].get(i);
            if(!visit[v]){
                visit[v] = true;
                DFS(list, visit, dp, v);
                dp[V][0] += dp[v][1];//자기자신이 얼리어답터가 아니기 때문에...! 자식은 무조건 얼리어답터 여야 한다. 그래서 그값을 바로 더함.
                dp[V][1] += Math.min(dp[v][0], dp[v][1]);// 자기자신이 얼리어답터라면?? 자식의 얼리어답터가 아닌경우와 맞는 경우 둘중에 작은값을 대입.
            }
        }
    }
}
