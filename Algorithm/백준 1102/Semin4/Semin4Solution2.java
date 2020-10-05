import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    static int N, P;
    static int result = Integer.MAX_VALUE;
    public static void main(String[] args) throws IOException {
	// write your code here
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        int[][] graph = new int[N][N];
        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                graph[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        String status = br.readLine();
        int currentStatus = 0;
        for (int i = 0; i < status.length(); i++) {
            currentStatus = status.charAt(i) == 'Y' ? currentStatus | (1 << i) : currentStatus;
        }
        P = Integer.parseInt(br.readLine());
        int[] dp = new int[1 << N];
        Arrays.fill(dp, -1);
        if(Integer.bitCount(currentStatus) >= P){
            result = 0;
        }else if(Integer.bitCount(currentStatus) != 0){
            result = dfs(currentStatus, dp, graph);
        }
        if(result != Integer.MAX_VALUE)
            System.out.println(result);
        else
            System.out.println(-1);
    }
    public static int dfs(int currentStatus, int[] dp, int[][] graph){
        if(dp[currentStatus] != -1) return dp[currentStatus];
        if(Integer.bitCount(currentStatus) == P){//원하는 만큼 다켰으면.
            return dp[currentStatus] = 0;//= //??
        }
        int value = Integer.MAX_VALUE;
        for (int i = 0; i < N; i++) {//i의 켜져 있는거
            if((currentStatus & (1 << i)) == 0) continue;//현재 그자리수가 꺼져 있다면?..
            for (int j = 0; j < N; j++) {//꺼져 있는거.
                if((currentStatus & (1 << j)) > 0) continue;
                value = Math.min(value, dfs((currentStatus|(1 << j)), dp, graph) + graph[i][j]);
            }
        }
        return dp[currentStatus] = value;
    }

}
