import java.io.*;
import java.util.*;

class Point{
    int i;
    int j;
    public Point(int i, int j){
        this.i = i;
        this.j = j;
    }
}
public class Main {
    static int N, M;
    static int[] dI = {-1, 0, 1, 0};
    static int[] dJ = {0, 1, 0, -1};
    public static void main(String[] args) throws IOException {
	// write your code here
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        int[][] map = new int[N][M];
        for (int i = 0; i < N; i++) {
            String tmp = br.readLine();
            for (int j = 0; j < M; j++) {
                map[i][j] = tmp.charAt(j) - '0';
            }
        }
        ArrayList<Integer> list = new ArrayList<>();
        list.add(0);
        list.add(0);
        boolean[][] visit = new boolean[N][M];
        int group = 2;
        for(int i = 0; i < N; ++i){
            for (int j = 0; j < M; j++) {
                if(map[i][j] == 0 && !visit[i][j]){//한개씩 그룹
                    int cnt = 1;
                    map[i][j] = group;
                    Queue<Point> queue = new LinkedList<>();
                    queue.offer(new Point(i, j));
                    visit[i][j] = true;
                    while (!queue.isEmpty()){
                        Point point = queue.poll();
                        for (int k = 0; k < 4; k++) {
                            int tmpI = point.i + dI[k];
                            int tmpJ = point.j + dJ[k];
                            if(tmpI >= 0 && tmpI < N && tmpJ >= 0 && tmpJ < M){
                                if(map[tmpI][tmpJ] == 0 && !visit[tmpI][tmpJ]){
                                    queue.offer(new Point(tmpI, tmpJ));
                                    visit[tmpI][tmpJ] = true;
                                    map[tmpI][tmpJ] = group;
                                    cnt += 1;
                                }
                            }
                        }
                    }
                    list.add(cnt);
                    group+= 1;
                }
            }
        }
        int[][] output = new int[N][M];
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if(map[i][j] >= 2){
                    bw.write('0');
                }
                else{
                    Set<Integer> set = new HashSet<>();
                    for (int k = 0; k < 4; k++) {
                        int tmpI = i + dI[k];
                        int tmpJ = j + dJ[k];
                        if(tmpI >= 0 && tmpI < N && tmpJ >= 0 && tmpJ < M){
                            if(map[tmpI][tmpJ] >= 2){
                                set.add(map[tmpI][tmpJ]);
                            }
                        }
                    }
                    int cnt = 1;
                    for (int groupNum : set) {
                        cnt += list.get(groupNum);
                    }
                    bw.write("" +cnt % 10);

                }
            }
            bw.write("\n");
        }
        bw.close();
    }


}
