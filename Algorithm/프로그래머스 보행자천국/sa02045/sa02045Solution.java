class Solution {
    int MOD = 20170805;
    int[][] right = new int[501][501];
    int[][] bottom = new int[501][501];

    public int solution(int m, int n, int[][] cityMap) {
        right[1][1] = 1;
        bottom[1][1] = 1;

        for(int i = 1; i <= m ; i++){
            for(int j = 1; j<= n ; j++){
                if(cityMap[i-1][j-1]==0){
                    right[i][j] = (right[i][j]+bottom[i-1][j] + right[i][j-1])%MOD;
                    bottom[i][j] = (bottom[i][j]+bottom[i-1][j] + right[i][j-1])%MOD;
                }

                else if(cityMap[i-1][j-1]==1){
                    right[i][j] = 0;
                    bottom[i][j] = 0;
                }

                else{
                    right[i][j] = right[i][j-1];
                    bottom[i][j] = bottom[i-1][j];
                }
            }
        }

        return (right[m][n-1]+bottom[m-1][n])%MOD;
    }
}