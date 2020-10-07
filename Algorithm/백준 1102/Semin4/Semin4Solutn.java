import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    static int N;
    static int P;
    static int MORE = 0;
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
        String statusStr = br.readLine();
        int cnt = 0;//이미 켜져 있는 발전소의 개수
        ArrayList<Integer> off_list = new ArrayList<>();
        ArrayList<Integer> on_list = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            if (statusStr.charAt(i) == 'Y') {
                cnt += 1;
                on_list.add(i);
            } else off_list.add(i);

        }
        P = Integer.parseInt(br.readLine());
        if(P != 0 && cnt == 0){//기저
            System.out.println(-1);
            return;
        }
        if(P <= cnt){
            System.out.println(0);
            return;
        }

        int[] dp = new int[(int) Math.pow(2, N)];
        Arrays.fill(dp, 100000);
        int currentStatus = 0;
        for (int i = 0; i < on_list.size(); i++) {
            currentStatus |= (1 << on_list.get(i));
        }
        dp[currentStatus] = 0;
        MORE = P - cnt;
        for (int i = 0; i < off_list.size(); i++) {
            dfs(0, dp, currentStatus, on_list, off_list.get(i), graph);
        }
        System.out.println(result);

    }
    public static void dfs(int need, int[] dp, int currentStatus, ArrayList<Integer> onList, int onPower, int[][] graph){
        int tmpStatus = currentStatus | (1 << onPower);
        for (int i = 0; i < onList.size(); i++) {
            if(dp[tmpStatus] > dp[currentStatus] + graph[onList.get(i)][onPower]){
                dp[tmpStatus] = dp[currentStatus] + graph[onList.get(i)][onPower];
                if(need == MORE - 1){
                    continue;
                }
                onList.add(onPower);
                for (int j = 0; j < N; j++) {
                    int bitMask = tmpStatus & (1 << j);
                    if(bitMask == 0){
                        dfs(need + 1, dp, tmpStatus, onList, j, graph);
                    }
                }
                onList.remove((Integer) onPower);
            }
        }
        if(need == MORE - 1){
            result = Math.min(result, dp[tmpStatus]);
        }

    }
}



