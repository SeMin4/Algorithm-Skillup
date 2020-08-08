import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {
    static long N, K;//그림의 갯수 색깔의 개수
    static long MOD = 1000000007;
    static int[] graph = new int[1000001];//규칙을 저장
    static long[] dp = new long[1000001];//색깔을 칠할 수 있는 경우의 수
    static int[] visit = new int[1000001];
    static int cycle = Integer.MIN_VALUE;
    static int startIdx;
    static int[] firstVisit = new int[1000001];
    public static void main(String[] args) throws IOException {
//         write your code here
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//        FileReader fr = new FileReader("C:\\Users\\SeMin\\Desktop\\contest2_testdata\\paleta\\paleta.in.10a");
//        BufferedReader br = new BufferedReader(fr);
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Long.parseLong(st.nextToken());
        K = Long.parseLong(st.nextToken());
        graph[0] = 0;
        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= N; i++) {
            graph[i] = Integer.parseInt(st.nextToken());
        }
        dp[0] = 1;
        dp[1] = K;
        dp[2] = (K * (K - 1)) % MOD;//............int로 해줘서 너무 고생...
        dp[3] = (dp[2] * (K - 2)) % MOD;
        for (int i = 4; i <= N; i++) {
            dp[i] = ((dp[i - 2] * (K - 1)) + (dp[i - 1] * (K - 2))) % MOD ;//지금 색칠할려고 하는 바로 전것이 첫번째 것과 색깔이 같은 경우 | 지금 색칠할려고 하는 바로 전것이 색깔이 다른 경우
        }

        long ans = 1;
        long vertex = N;
        for (int i = 1; i <= N ; i++) {//사이클의 크기를 구해보자!
            if(visit[i] == 0){
                startIdx = i;//어느점에서 dfs가 시작하는가....
                Stack<Integer> stack = new Stack<>();
                stack.push(i);
                int cnt = 1;
                while (!stack.empty()){
                    int currentIDx = stack.pop();
                    if(visit[currentIDx] != 0){
                        if(firstVisit[currentIDx] == startIdx){//같은 경로에서 왔었으면 사이클이란 소리..
                            cycle = cnt - visit[currentIDx];
                            break;
                        }else{//같은 경로에서 온게 아님...
                            cycle = 0;
                            break;
                        }
                    }
                    visit[currentIDx] = cnt;
                    firstVisit[currentIDx] = startIdx;
                    cnt += 1;
                    stack.push(graph[currentIDx]);
                }
                ans *= dp[cycle];//사이클 개수만큼 곱하기
                ans %= MOD;
                vertex -= cycle;
            }
        }
        //남은 애들 다 곱해서 답 구하기...
        for (int i = 0; i < vertex; i++) {
            ans *= (K - 1);
            ans %= MOD;
        }
        System.out.println(ans);
    }

}
