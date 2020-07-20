import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.ResourceBundle;
import java.util.StringTokenizer;
class Point{
    int i;
    int j;
    int k;
    int cnt;
    public Point(int i, int j, int k, int cnt){
        this.i = i;
        this.j = j;
        this.k = k;
        this.cnt = cnt;
    }
}
public class Main {
    static int M, N, H;
    static int[] dI = {-1, 0, 0, 0, 0, 1};
    static int[] dJ = {0, -1, 0, 1, 0, 0};
    static int[] dK = {0, 0, 1, 0, -1, 0};
    static int result = 0;
    public static void main(String[] args) throws IOException {
	// write your code here
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        M = Integer.parseInt(st.nextToken());// 각각의 input data 입력
        N = Integer.parseInt(st.nextToken());
        H = Integer.parseInt(st.nextToken());
        Queue<Point> queue = new LinkedList<>();
        int[][][] map = new int[H][N][M];
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < N; j++) {
                st = new StringTokenizer(br.readLine());
                for (int k = 0; k < M; k++) {
                    map[i][j][k] = Integer.parseInt(st.nextToken());
                    if(map[i][j][k] == 1){
                        queue.add(new Point(i, j, k, 0));
                    }
                }
            }
        }
        while (!queue.isEmpty()){
            Point point = queue.poll();
            if(result < point.cnt)
                result = point.cnt;
            for (int i = 0; i < 6; i++) {
                int tmpI = point.i + dI[i];
                int tmpJ = point.j + dJ[i];
                int tmpK = point.k + dK[i];
                if(tmpI >= 0 && tmpI < H && tmpJ >= 0 && tmpJ < N && tmpK >= 0 && tmpK < M){
                    if(map[tmpI][tmpJ][tmpK] == 0){
                        queue.add(new Point(tmpI, tmpJ, tmpK, point.cnt + 1));
                        map[tmpI][tmpJ][tmpK] = 1;
                    }
                }
            }
        }
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < N; j++) {
                for (int k = 0; k < M; k++) {
                    if(map[i][j][k] == 0){
                        System.out.println(-1);
                        return;
                    }
                }
            }
        }
        System.out.println(result);

    }
}
