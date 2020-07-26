import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    static int N, M;
    public static void main(String[] args) throws IOException {
	// write your code here
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        int[] memory = new int[N];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            memory[i] = Integer.parseInt(st.nextToken());
        }
        st = new StringTokenizer(br.readLine());
        int[] cost = new int[N];
        for (int i = 0; i < N; i++) {
            cost[i] = Integer.parseInt(st.nextToken());
        }
        int[][] dp = new int[N][100001];

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < 100001; j++) {
                if(i == 0){
                    if(j >= cost[i])
                        dp[i][j] = memory[i];
                }
                else{
                    if(j >= cost[i])
                        dp[i][j] = Math.max(dp[i - 1][j - cost[i]] + memory[i] , dp[i - 1][j]);
                    else
                        dp[i][j] = dp[i - 1][j];
                }
            }
        }
        for (int i = 0; i < 100001; i++) {
            for (int j = 0; j < N; j++) {
                if(dp[j][i] >= M){
                    System.out.println(i);
                    return;
                }
            }
        }
    }
}
