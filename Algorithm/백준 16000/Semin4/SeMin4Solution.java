import java.io.*;
import java.util.*;
class Position{
    int i;
    int j;
    public Position(int i, int j){
        this.i = i;
        this.j = j;
    }
}
public class Main {
    static int N, M;
    static int[] dI = {-1, 0, 1, 0, -1, 1, 1, -1};
    static int[] dJ = {0, 1, 0, -1, 1, 1, -1, -1};
    public static void main(String[] args) throws IOException {
        long start = System.currentTimeMillis();
        // FileReader fr = new FileReader("C:\\Users\\SeMin\\Desktop\\JavaAlgorithm\\make_test\\output.txt");
        // BufferedReader br = new BufferedReader(fr);
       BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        char[][] map = new char[N][M];
        for (int i = 0; i < N; i++) {
            String tmp = br.readLine();
            for (int j = 0; j < M; j++) {
                map[i][j] = tmp.charAt(j);
            }
        }
        int[][] visitCnt = new int[N][M];
        int vertexNum = 1;
        vertexNum = makeGRAPH(visitCnt, map);
        boolean[] danger = new boolean[vertexNum + 1];

        findDangerPoint(visitCnt, danger);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if(map[i][j] == '.'){
                    bw.write('.');
                }
                else{
                    if(danger[visitCnt[i][j]]){
                        bw.write('O');
                    }
                    else{
                        bw.write('X');
                    }
                }
            }
            bw.write('\n');
        }
        bw.close();
    }
    public static int makeGRAPH(int[][] visit, char[][] graph){
        int vertexNum = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if(visit[i][j] == 0 && graph[i][j] == '#'){
                    Queue<Position> queue = new LinkedList<>();
                    queue.offer(new Position(i, j));
                    vertexNum += 1;
                    visit[i][j] = vertexNum;
                    while (!queue.isEmpty()){
                        Position position = queue.poll();
                        for (int k = 0; k < 4; k++) {
                            int tmpI = position.i + dI[k];
                            int tmpJ = position.j + dJ[k];
                            if(tmpI >= 0 && tmpI < N && tmpJ >=0 && tmpJ < M){
                                if(visit[tmpI][tmpJ] == 0 && graph[tmpI][tmpJ] == '#'){
                                    visit[tmpI][tmpJ] = vertexNum;
                                    queue.offer(new Position(tmpI, tmpJ));
                                }
                            }
                        }
                    }
                }
            }
        }
        return vertexNum;
    }
    public static void findDangerPoint(int[][] visit, boolean[] danger){
        Queue<Position> queue = new LinkedList<>();
        queue.offer(new Position(0, 0));
        visit[0][0] = -1;
        while (!queue.isEmpty()){
            Position position = queue.poll();
            for (int i = 0; i < 8; i++) {
                int tmpI = position.i + dI[i];
                int tmpJ = position.j + dJ[i];
                if(tmpI >= 0 && tmpI < N && tmpJ >= 0  && tmpJ < M){
                    if(i > 3 && visit[tmpI][tmpJ] == 0){
                        if(visit[position.i][tmpJ] != visit[tmpI][position.j]){
                            visit[tmpI][tmpJ] = -1;
                            queue.offer(new Position(tmpI, tmpJ));
                        }
                    }
                    else if(visit[tmpI][tmpJ] == 0){
                        visit[tmpI][tmpJ] = -1;
                        queue.offer(new Position(tmpI, tmpJ));
                    }
                    else if(visit[tmpI][tmpJ] > 0){
                        if(!danger[visit[tmpI][tmpJ]]){
                            danger[visit[tmpI][tmpJ]] = true;
                        }
                    }
                }
            }
        }
    }

}

