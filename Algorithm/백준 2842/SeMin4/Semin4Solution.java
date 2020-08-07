import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Home{
    int i;
    int j;
    char value;
    public Home(int i, int j, char value){
        this.i = i;
        this.j = j;
        this.value = value;
    }
}
public class Main {
    static int N;
    static int minHeight = 0;
    static int maxHeight = 0;
    static int[] dI = {-1, -1, 0, 1, 1, 1, 0, -1};
    static int[] dJ = {0, 1, 1, 1, 0, -1, -1, -1};
    static int result = Integer.MAX_VALUE;
    static int K = 0;
    static int SIZE = 0;
    //3c
    public static void main(String[] args) throws IOException {
	// write your code here
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        char[][] map = new char[N][N];
        int[][] heightMap = new int[N][N];

        Home postOffice = new Home(0, 0, 'P');
        for (int i = 0; i < N; i++) {
            String tmp = br.readLine();
            for (int j = 0; j < N; j++) {
                map[i][j] = tmp.charAt(j);
                if(map[i][j] == 'P'){
                    postOffice.i = i;
                    postOffice.j = j;
                }else if(map[i][j] == 'K'){
                    K += 1;
                }
            }
        }
        Set<Integer> set = new TreeSet<>();
        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                heightMap[i][j] = Integer.parseInt(st.nextToken());
                set.add(heightMap[i][j]);
            }
        }
        SIZE = set.size();
        Integer[] heighArray = new Integer[SIZE];
        set.toArray(heighArray);
        boolean[][] visit = new boolean[N][N];
        minHeight = 0;
        maxHeight = 0;
        for (int i = 0; i < SIZE; i++) {
            if(heighArray[i] == heightMap[postOffice.i][postOffice.j]){
                maxHeight = i;
                break;
            }
        }
        bfs(heightMap, map, postOffice, visit, heighArray);
        System.out.println(result);
    }
    public static void bfs(int[][] heightMap, char[][] map, Home postOffice, boolean[][] visit, Integer[] heightArray){
        while (minHeight < SIZE){
            if(heightMap[postOffice.i][postOffice.j] < heightArray[minHeight]){
                break;
            }
            Queue<Home> queue = new LinkedList<>();
            queue.add(postOffice);

            int homeCnt = 0;
            boolean flag = false;
            for (int i = 0; i < N; i++) {
                Arrays.fill(visit[i], false);
            }

            visit[postOffice.i][postOffice.j] = true;
            while (!queue.isEmpty()){
                Home home = queue.poll();
                if(home.value == 'K'){
                    homeCnt += 1;
                }
                if(homeCnt == K){//갈 수 있다..
                    result = Math.min(result, heightArray[maxHeight] - heightArray[minHeight]);
                    minHeight += 1;
                    flag = true;
                    break;
                }
                for (int i = 0; i < 8; i++) {
                    int tmpI = home.i + dI[i];
                    int tmpJ = home.j + dJ[i];
                    if(tmpI >= 0 && tmpI < N && tmpJ >= 0 && tmpJ < N){
                        if(heightMap[tmpI][tmpJ] >= heightArray[minHeight] && heightMap[tmpI][tmpJ] <= heightArray[maxHeight] && !visit[tmpI][tmpJ]){
                            queue.add(new Home(tmpI, tmpJ, map[tmpI][tmpJ]));
                            visit[tmpI][tmpJ] = true;
                        }
                    }
                }
            }
            if(!flag){
                maxHeight += 1;
                if(maxHeight >= SIZE){
                    break;
                }
            }
        }
    }
}
