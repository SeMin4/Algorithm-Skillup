import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

class Cctv{
    int row;
    int col;
    int type;
    int rotate;// 0 오른쪽 1 아래쪽 2 왼쪽 3 위쪽
    public Cctv(int row, int col, int type){
        this.row = row;
        this.col = col;
        this.type = type;
        rotate = 0;
    }
    public void nextRotate(){
        this.rotate += 1;
    }
}
public class Main {
    static int N, M, minValue;
    public static void main(String[] args) throws IOException {
	// write your code here
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] str = br.readLine().split(" ");
        N = Integer.parseInt(str[0]);
        M = Integer.parseInt(str[1]);
        int[][] map = new int[N][M];
        ArrayList<Cctv> cctvList = new ArrayList<>();
        for(int i = 0; i < N; ++i){
            str = br.readLine().split(" ");
            for(int j= 0; j < M; ++j){
                int tmp = Integer.parseInt(str[j]);
                if(tmp != 0 && tmp != 6){//벽이 아니고 빈곳이 cctv
                    cctvList.add(new Cctv(i, j , tmp));
                }
                map[i][j] = tmp;
            }
        }
        minValue = N * M;
        for(int i = 0; i < cctvList.size(); ++i){
            Cctv cctv = cctvList.get(i);
            if(cctv.type == 5){//5는 회전할 필요가 없으므로 이미 다찍어주고 삭제시켜 버리기
                map = rightCalculate(map, cctv);
                map = leftCalculate(map, cctv);
                map = upCalculate(map, cctv);
                map = downCalculate(map, cctv);
                cctvList.remove(i);
                i--;
            }
        }
        int cnt = 0;
        if(cctvList.isEmpty()){
            for(int i = 0; i < N; ++i){
                for(int j = 0; j < M; ++j){
                    if(map[i][j] == 0){
                        cnt += 1;    
                    }
                }
            }
            System.out.println(cnt);
        }
        else{
            dfs(map, cctvList, 0);
            System.out.println(minValue);
        }


    }
    public static int[][] rightCalculate(int[][] map, Cctv cctv){
        int[][] newMap = new int[N][M];
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < M; ++j){
                newMap[i][j] = map[i][j];
            }
        }
        for(int j = cctv.col + 1; j < M; ++j){//오른쪽
            if(newMap[cctv.row][j] == 0 || newMap[cctv.row][j] == 7){//빈곳이거나 이미 감시하고 있는 곳이라면
                newMap[cctv.row][j] = 7;
            }
            else if(newMap[cctv.row][j] == 6){
                break;
            }
        }
        return newMap;
    }
    public static int[][] leftCalculate(int[][] map, Cctv cctv){
        int[][] newMap = new int[N][M];
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < M; ++j){
                newMap[i][j] = map[i][j];
            }
        }
        for(int j = cctv.col - 1; j >= 0; --j){//왼쪽
            if(newMap[cctv.row][j] == 0 || newMap[cctv.row][j] == 7){//빈곳이거나 이미 감시하고 있는 곳이라면
                newMap[cctv.row][j] = 7;
            }
            else if(newMap[cctv.row][j] == 6){
                break;
            }
        }
        return newMap;
    }
    public static int[][] upCalculate(int[][] map, Cctv cctv){
        int[][] newMap = new int[N][M];
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < M; ++j){
                newMap[i][j] = map[i][j];
            }
        }
        for(int j = cctv.row - 1; j >= 0; --j){//위쪽
            if(newMap[j][cctv.col] == 0 || newMap[j][cctv.col] == 7){//빈곳이거나 이미 감시하고 있는 곳이라면
                newMap[j][cctv.col] = 7;
            }
            else if(newMap[j][cctv.col] == 6){
                break;
            }
        }
        return newMap;
    }
    public static int[][] downCalculate(int[][] map, Cctv cctv){
        int[][] newMap = new int[N][M];
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < M; ++j){
                newMap[i][j] = map[i][j];
            }
        }
        for(int j = cctv.row + 1; j < N; ++j){//아래쪽
            if(newMap[j][cctv.col] == 0 || newMap[j][cctv.col] == 7){//빈곳이거나 이미 감시하고 있는 곳이라면
                newMap[j][cctv.col] = 7;
            }
            else if(newMap[j][cctv.col] == 6){
                break;
            }
        }
        return newMap;
    }
    public static void dfs(int[][] map, ArrayList<Cctv> cctvList, int current_idx){
        if(current_idx == cctvList.size()){
            int cnt = 0;
            for(int i = 0; i < N; ++i){
                for(int j = 0; j < M; ++j){
                    if(map[i][j] == 0){
                        cnt += 1;
                    }
                }
            }
            if(minValue > cnt){
                minValue = cnt;
            }
            return;
        }
        int[][] rotateMap = new int[N][M];
        int[][] newMap = new int[N][M];
        for(int i = 0; i < N; ++i){
            for (int j = 0; j < M; ++j){
                newMap[i][j] = map[i][j];
            }
        }
        Cctv cctv = cctvList.get(current_idx);
        for(int j = 0; j < 4; ++j){
            if(cctv.type == 1){
                if(cctv.rotate == 0){// 0 오른쪽 1 아래쪽 2 왼쪽 3 위쪽
                    rotateMap = rightCalculate(newMap, cctv);
                }else if(cctv.rotate == 1){
                    rotateMap = downCalculate(newMap, cctv);
                }else if(cctv.rotate == 2){
                    rotateMap = leftCalculate(newMap, cctv);
                }else if(cctv.rotate == 3){
                    rotateMap = upCalculate(newMap, cctv);
                }
            }else if(cctv.type == 2){
                if(cctv.rotate == 0){
                    rotateMap = rightCalculate(newMap, cctv);
                    rotateMap = leftCalculate(rotateMap , cctv);
                }else if(cctv.rotate == 1){
                    rotateMap = upCalculate(newMap, cctv);
                    rotateMap = downCalculate(rotateMap, cctv);
                }else if(cctv.rotate == 2){
                    rotateMap = rightCalculate(newMap, cctv);
                    rotateMap = leftCalculate(rotateMap , cctv);
                }else if(cctv.rotate == 3){
                    rotateMap = upCalculate(newMap, cctv);
                    rotateMap = downCalculate(rotateMap, cctv);
                }
            }else if(cctv.type == 3){
                if(cctv.rotate == 0){
                    rotateMap = rightCalculate(newMap, cctv);
                    rotateMap = upCalculate(rotateMap, cctv);
                }else if(cctv.rotate == 1){
                    rotateMap = rightCalculate(newMap, cctv);
                    rotateMap = downCalculate(rotateMap, cctv);
                }else if(cctv.rotate == 2){
                    rotateMap = leftCalculate(newMap, cctv);
                    rotateMap = downCalculate(rotateMap, cctv);
                }else if(cctv.rotate == 3){
                    rotateMap = leftCalculate(newMap, cctv);
                    rotateMap = upCalculate(rotateMap, cctv);
                }
            }else if(cctv.type == 4) {
                if(cctv.rotate == 0){
                    rotateMap = leftCalculate(newMap, cctv);
                    rotateMap = upCalculate(rotateMap, cctv);
                    rotateMap = rightCalculate(rotateMap, cctv);
                }else if(cctv.rotate == 1){
                    rotateMap = upCalculate(newMap, cctv);
                    rotateMap = rightCalculate(rotateMap, cctv);
                    rotateMap = downCalculate(rotateMap, cctv);
                }else if(cctv.rotate == 2){
                    rotateMap = leftCalculate(newMap, cctv);
                    rotateMap = rightCalculate(rotateMap, cctv);
                    rotateMap = downCalculate(rotateMap, cctv);
                }else if(cctv.rotate == 3){
                    rotateMap = leftCalculate(newMap, cctv);
                    rotateMap = upCalculate(rotateMap, cctv);
                    rotateMap = downCalculate(rotateMap, cctv);
                }
            }
            dfs(rotateMap, cctvList, current_idx + 1);
            cctv.nextRotate();
        }
        cctv.rotate = 0;



    }
}