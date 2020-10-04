import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    static int[] dI = {-1, 0, 1, 0};
    static int[] dJ = {0, 1, 0, -1};
    public static void main(String[] args) throws IOException {
	// write your code here
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[][] map = new int[10][10];
        for (int i = 0; i < 10; i++) {
            String tmp = br.readLine();
            for (int j = 0; j < 10; j++) {
                map[i][j] = tmp.charAt(j) == '#' ? 1 : 0;
            }
        }
        //불을 끄기 위해서는????? 자기 자신을 누르거나? 자신의 오른쪽을 누르거나? 자신의 위쪽을 누르거나? 자신의 왼쪽을 누르거나? 자신의 아래쪽이 눌려야 함..
        //5가지 경우의 수..
        //[0,0]을 끄기 위해서는 자기 자신이나 자신의 오른쪽 [0,1]이나, 자신의 아래쪽이 눌러야 한다...3가지의 경우의수..
        //0이면 불이 켜져 있다..
        //1이면 불이 꺼져 있다..
        int result = -1;
        for (int i = 0; i < 1024; i++) {
            int[][] newMap = new int[10][10];
            for (int j = 0; j < 10; j++) {//복사.
                for (int k = 0; k < 10; k++) {
                    newMap[j][k] = map[j][k];
                }
            }
            int cnt = 0;
            for (int j = 0; j < 10; j++) {
                int k = (1 << j) & i;
                if(k > 0){
                    statusChange(newMap, 0, j);
                    cnt += 1;
                }
            }
            for (int j = 1; j <= 9; j++) {//위에꺼 보고 끄자.
                for (int k = 0; k < 10; k++) {
                    if(newMap[j - 1][k] == 0){
                        statusChange(newMap, j, k);
                        cnt += 1;
                    }
                }
            }
            boolean flag = false;
            for (int j = 0; j < 10; j++) {
                if(newMap[9][j] == 0){
                    flag = true;
                    break;
                }
            }
            if(!flag){//불이 다꺼져 있다..
                result = result == -1 ? cnt : Math.min(result, cnt);
            }

        }
        System.out.println(result);
    }
    public static void statusChange(int[][] map, int i, int j){
        map[i][j] = map[i][j] == 1 ? 0 : 1;
        for (int k = 0; k < 4; k++) {
            int tmpI = i + dI[k];
            int tmpJ = j + dJ[k];
            if(tmpI >= 0 && tmpI < 10 && tmpJ >= 0 && tmpJ < 10){
                map[tmpI][tmpJ] = map[tmpI][tmpJ] == 1 ? 0 : 1;
            }
        }
    }
}
