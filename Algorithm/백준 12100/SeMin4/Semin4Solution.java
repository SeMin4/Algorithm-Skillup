import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int N;
    static int MAX = Integer.MIN_VALUE;
    public static void main(String[] args) throws IOException {
	// write your code here
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        int[][] map = new int[N][N];
        StringTokenizer st;
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        dfs(map, 0);
        System.out.println(MAX);

    }
    public static void dfs(int[][] map, int depth){
        if(depth == 5){
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                   if(map[i][j] > MAX) 
                       MAX = map[i][j];
                }
            }
            return;
        }
        for (int i = 0; i < 4; i++) {
            int[][] map2 = swipe(map, i);
            map2 = move(map2, i);
            dfs(map2, depth + 1);
        }
    }
    public static int[][] swipe(int[][] map, int direction){
        int[][] returnMap = new int[N][N];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                returnMap[i][j] = 0;
            }
        }
        switch (direction){
            case 0://왼쪽
                for (int i = 0; i < N; i++) {
                    for (int j = 0, cnt = 0; j < N; j++, cnt++) {
                        if(map[i][j] == 0){
                            while (j < N && map[i][j] == 0){
                                ++j;
                            }
                            if(j < N)
                                returnMap[i][cnt] = map[i][j];
                        }
                        else{
                            returnMap[i][cnt] = map[i][j];
                        }
                    }
                }
                break;
            case 1://위쪽
                for (int i = 0; i < N; i++) {
                    for (int j = 0, cnt = 0; j < N; j++,cnt++) {
                        if(map[j][i] == 0){
                            while (j < N  && map[j][i] == 0){
                                ++j;
                            }
                            if(j < N)
                                returnMap[cnt][i] = map[j][i];
                        }
                        else{
                            returnMap[cnt][i] = map[j][i];
                        }
                    }
                }
                break;
            case 2://오른쪽
                for (int i = 0; i < N; i++) {
                    for (int j = N - 1, cnt = N - 1; j >= 0; j--, cnt--) {
                        if(map[i][j] == 0){
                            while (j >= 0 && map[i][j] == 0){
                                j -= 1;
                            }
                            if(j >= 0)
                                returnMap[i][cnt] = map[i][j];
                        }
                        else
                            returnMap[i][cnt] = map[i][j];
                    }
                }
                break;
            case 3://아래쪽
                for (int i = 0; i < N; i++) {
                    for (int j = N - 1, cnt = N - 1; j >= 0; j--, cnt--) {
                        if(map[j][i] == 0){
                            while (j >= 0 && map[j][i] == 0){
                                j--;
                            }
                            if(j >= 0)
                                returnMap[cnt][i] = map[j][i];
                        }
                        else
                            returnMap[cnt][i] = map[j][i];
                    }
                }
                break;
        }
        return returnMap;
    }
    public static int[][] move(int[][] map, int direction){
        int[][] returnMap = new int[N][N];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                returnMap[i][j] = 0;
            }
        }
        switch (direction){
            case 0://왼쪽
                for (int i = 0; i < N; i++) {
                    for (int j = 0, cnt = 0; j < N; j++, cnt++) {
                        if(j == N - 1){
                            returnMap[i][cnt] = map[i][j];
                            break;
                        }
                        if(map[i][j] == map[i][j + 1]){
                            returnMap[i][cnt] = map[i][j] * 2;
                            j += 1;
                        }
                        else{
                            returnMap[i][cnt] = map[i][j];
                        }
                    }
                }
                break;
            case 1://위쪽
                for (int i = 0; i < N; i++) {
                    for (int j = 0, cnt = 0; j < N; j++, cnt++) {
                        if(j == N - 1){
                            returnMap[cnt][i] = map[j][i];
                            break;
                        }
                        if(map[j][i] == map[j + 1][i]){
                            returnMap[cnt][i] = map[j][i] * 2;
                            j += 1;
                        }
                        else{
                            returnMap[cnt][i] = map[j][i];
                        }
                    }
                }
                break;
            case 2://오른쪽
                for (int i = 0; i < N; i++) {
                    for (int j = N - 1, cnt = N - 1; j >= 0; j--, cnt--) {
                        if(j == 0){
                            returnMap[i][cnt] = map[i][j];
                            break;
                        }
                        if(map[i][j] == map[i][j - 1]){
                            returnMap[i][cnt] = map[i][j] * 2;
                            j -= 1;
                        }
                        else{
                            returnMap[i][cnt] = map[i][j];
                        }
                    }
                }
                break;
            case 3://아래쪽
                for (int i = 0; i < N; i++) {
                    for (int j = N - 1, cnt = N - 1; j >= 0; j--, cnt--) {
                        if(j == 0){
                            returnMap[cnt][i] = map[j][i];
                            break;
                        }
                        if(map[j][i] == map[j - 1][i]){
                            returnMap[cnt][i] = map[j][i] * 2;
                            j -= 1;
                        }
                        else{
                            returnMap[cnt][i] = map[j][i];
                        }
                    }
                }
                break;
        }
        return returnMap;
    }
}
