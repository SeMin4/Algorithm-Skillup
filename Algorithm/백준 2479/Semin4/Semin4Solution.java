import java.io.*;
import java.util.*;

public class Main {
    static int N, K;
    static int S, E;
    public static void main(String[] args) throws IOException {
	// write your code here
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        int[] arr = new int[N + 1];
        for (int i = 1; i <= N; i++) {
            arr[i] = Integer.parseInt(br.readLine(), 2);
        }
        st = new StringTokenizer(br.readLine());
        S = Integer.parseInt(st.nextToken());
        E = Integer.parseInt(st.nextToken());
        int[] minDepth = new int[N + 1];
        Arrays.fill(minDepth, N + 1);
        minDepth[S] = 0;
        int[] parent = new int[N + 1];
        Arrays.fill(parent, - 1);
        bfs(arr, minDepth, S, parent);
//        dfs(arr, 0, minDepth, S, parent);
        if(parent[E] == -1){
            System.out.println(-1);
            return;
        }
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        printPath(bw, E, parent);
        bw.write("\n");
        bw.close();
    }
    public static void printPath(BufferedWriter bw, int v, int[] parent) throws IOException{
        if(v == S){
            bw.write(v + " ");
            return;
        }
        printPath(bw, parent[v], parent);
        bw.write(v+ " ");
    }
    public static void dfs(int[] arr, int depth, int[] minDepth, int vertex, int[] parent){
        if(vertex == E){
            return;
        }
        boolean res = false;
        for (int i = 1; i < arr.length; i++) {
            if(i != vertex){
                int value = arr[i]^arr[vertex];
                int cnt = Integer.bitCount(value);
                if(cnt == 1 && minDepth[i] > depth){
                    minDepth[i] = depth + 1;
                    parent[i] = vertex;
                    dfs(arr, depth + 1, minDepth, i, parent);
                }
            }
        }
    }
    public static void bfs(int[] arr, int[] minDepth, int vertex, int[] parent){
        Queue<int[]> queue = new LinkedList<>();
        queue.offer(new int[]{vertex, 0});
        while (!queue.isEmpty()){
            int[] v = queue.poll();
            for (int i = 1; i < arr.length; i++) {
                if(i != v[0]){
                    int value = arr[i]^arr[v[0]];
                    int cnt = Integer.bitCount(value);
                    if(cnt == 1 && (minDepth[i] > (v[1] + 1))){
                        minDepth[i] = v[1] + 1;
                        parent[i] = v[0];
                        queue.offer(new int[]{i, v[1] + 1});
                    }
                }
            }
        }
    }
}
