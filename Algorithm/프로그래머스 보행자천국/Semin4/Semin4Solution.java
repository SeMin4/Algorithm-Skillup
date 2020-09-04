public class Main{
    static int MOD = 20170805;
    public static void main(String[] args) {
	// write your code here
        int m = 3;
        int n = 6;
        int[][] cityMap = {{0, 2, 0, 0, 0, 2}, {0, 0, 2, 0, 1, 0}, {1, 0, 0, 2, 2, 0}};
//        int m = 3;
//        int n = 3;
//        int[][] cityMap = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
        int result = solution(m, n, cityMap);
        System.out.println(result);
    }

    public static int solution(int m, int n, int[][] cityMap) {
        int[][] leftMap = new int[m][n];//왼쪽에서 온 경우
        int[][] upMap = new int[m][n];//위쪽에서 온 경우
        for (int i = 0; i < n; i++) {
            if(cityMap[0][i] == 1)
                break;
            else{
                leftMap[0][i] = 1;
            }
        }
        for(int i = 0; i < m; ++i){
            if(cityMap[i][0] == 1)
                break;
            else
                upMap[i][0] = 1;
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if(cityMap[i][j] == 1){
                    leftMap[i][j] = 0;
                    upMap[i][j] = 0;
                }
                else{
                    if(cityMap[i - 1][j] == 2){//위쪽에서 온 경우를 처리
                        upMap[i][j] = upMap[i - 1][j];
                    }
                    else{
                        upMap[i][j] = (upMap[i - 1][j] % MOD + leftMap[i - 1][j] % MOD) % MOD;
                    }
                    if(cityMap[i][j - 1] == 2){
                        leftMap[i][j] = leftMap[i][j - 1];
                    }
                    else{
                        leftMap[i][j] = (upMap[i][j - 1] % MOD + leftMap[i][j - 1] % MOD) % MOD;
                    }
                }
            }
        }
//        for (int i = 0; i < m; i++) {
//            for (int j = 0; j < n; j++) {
//                System.out.print(upMap[i][j] + " ");
//            }
//            System.out.println();
//        }
//        System.out.println();
//        for (int i = 0; i < m; i++) {
//            for (int j = 0; j < n; j++) {
//                System.out.print(leftMap[i][j] + " ");
//            }
//            System.out.println();
//        }
        return (leftMap[m - 1][n - 1] + upMap[m - 1][n - 1]) % MOD;
    }
}
