import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class Main {
    static int maximumArea = 0;
    public static void main(String[] args) throws IOException {
	// write your code here
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] str = br.readLine().split(" ");
        int N = Integer.parseInt(str[0]);//7
        int M = Integer.parseInt(str[1]);//7
        int[][] map =new int[N + 2][M + 2];// 사방을 벽으로 둘러 싸기 9 * 9
        for(int i = 0; i < map.length; ++i){//1로 채우
            for(int j = 0; j < map[i].length; ++j){
                map[i][j] = 1;
            }
        }

        for(int i = 1; i <= N; ++i){
            str = br.readLine().split(" ");
            for(int j = 1; j <= M; ++j){
                map[i][j] = Integer.parseInt(str[j - 1]);//맵 중앙에 입력값 집어 넣기
            }
        }
        boolean[][] visited = new boolean[N + 2][M + 2];//방문 배열
        for(int i = 0; i < N + 2; ++i){
            for(int j = 0; j < M + 2; ++j){
                if(map[i][j] != 0){//0이 아닌값은 어차피 벽을 세우지 못하기 때문에 방문햇다고 설정
                    visited[i][j] = true;
                }else{
                    visited[i][j] = false;
                }
            }
        }
        depthFirstSearch(map, visited, 0, 1 , 1);
        System.out.println(maximumArea);
    }

    public static void depthFirstSearch(int[][] map, boolean[][] visited, int depth, int startRow, int startCol){
        if(depth > 2){
            int area = virus(map);
            if(area > maximumArea){
                maximumArea = area;
            }
            return;
        }
        for(int i = startRow; i < map.length - 1; ++i){
            for (int j = startCol; j < map[i].length - 1; ++j){
                if(map[i][j] == 0 && !visited[i][j]){//0이고 visited[i][j] = false;
                    map[i][j] = 1;
                    visited[i][j] = true;
                    depthFirstSearch(map, visited, depth + 1, i, j + 1);
                    map[i][j] = 0;
                    visited[i][j] = false;
                }
            }
            startCol = 1;
        }
    }
    public static int virus(int [][] map){
        int[][] virusMap = new int[map.length][map[0].length];
        Queue<Integer> queueX = new LinkedList<Integer>();
        Queue<Integer> queueY = new LinkedList<Integer>();
        for(int i = 0; i < virusMap.length; ++i){
            for(int j = 0; j < virusMap[i].length; ++j){
                virusMap[i][j] = map[i][j];
                if(virusMap[i][j] == 2){
                    queueX.add(i);
                    queueY.add(j);
                }
            }
        }
        while(!queueX.isEmpty() && !queueY.isEmpty()){
            int x = queueX.poll();
            int y = queueY.poll();
            if(virusMap[x - 1][y] == 0){
                virusMap[x - 1][y] = 2;
                queueX.add(x - 1);
                queueY.add(y);
            }
            if(virusMap[x + 1][y] == 0){
                virusMap[x + 1][y] = 2;
                queueX.add(x + 1);
                queueY.add(y);
            }
            if(virusMap[x][y - 1] == 0){
                virusMap[x][y - 1] = 2;
                queueX.add(x);
                queueY.add(y - 1);
            }
            if(virusMap[x][y + 1] == 0){
                virusMap[x][y + 1] = 2;
                queueX.add(x);
                queueY.add(y + 1);
            }

        }
        int cnt = 0;
        for(int i = 0; i < virusMap.length; ++i){
            for (int j = 0; j < virusMap[i].length; ++j){
                if(virusMap[i][j] == 0){
                    cnt += 1;
                }
            }
        }
        return cnt;
    }
}
