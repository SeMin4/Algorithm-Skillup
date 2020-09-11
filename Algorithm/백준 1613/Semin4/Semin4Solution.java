import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    static int N, K, S;
    public static void main(String[] args) throws IOException {
	// write your code here
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        int[][] graph = new int[N][N];
//        for (int i = 0; i < N; i++) {
//            Arrays.fill(graph[i], 100000);
//        }
        for (int i = 0; i < K; i++) {
            st = new StringTokenizer(br.readLine());
            graph[Integer.parseInt(st.nextToken()) - 1][Integer.parseInt(st.nextToken()) - 1] = 1;//앞이 먼저 일어났으므로 갈수 있다.
        }
        S = Integer.parseInt(br.readLine());

        for (int i = 0; i < N; i++) {//거쳐가는 노드.
            for (int j = 0; j < N; j++) {//출발노드
                for (int k = 0; k < N; k++) {//도착노드
                    if(j == k) continue;
                    if(graph[j][i] + graph[i][k] > graph[j][k] + 1){
                        graph[j][k] = 1;
                    }
                }
            }
        }
        for (int i = 0; i < S; i++) {
            st = new StringTokenizer(br.readLine());
            int accident = Integer.parseInt(st.nextToken()) - 1;
            int accident2 = Integer.parseInt(st.nextToken()) - 1;
            boolean first = graph[accident][accident2] > 0;
            boolean second = graph[accident2][accident] > 0;
            if(first == second)
                System.out.println(0);
            else if(first)
                System.out.println(-1);
            else
                System.out.println(1);

        }
    }
}

