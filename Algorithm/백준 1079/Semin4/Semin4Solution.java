import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int N;
    static int playerNum;
    static int result = Integer.MIN_VALUE;
    public static void main(String[] args) throws IOException {
	// write your code here
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        int[] score = new int[N];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            score[i] = Integer.parseInt(st.nextToken());
        }
        int[][] R = new int[N][N];
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                R[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        playerNum = Integer.parseInt(br.readLine());
        boolean[] kill = new boolean[N];
        playGame(0, N, score, R, kill);
        System.out.println(result);
    }
    public static void playGame(int nightCnt, int player, int[] score, int[][] R, boolean[] kill){
        if(player % 2 == 0){
            for (int i = 0; i < N; i++) {
                if(i != playerNum && !kill[i]){
                    kill[i] = true;
                    for (int j = 0; j < N; j++) {
                        score[j] += R[i][j];
                    }
                    playGame(nightCnt + 1, player - 1, score, R, kill);
                    for (int j = 0; j < N; j++) {//원래대로 되돌리기..
                        score[j] -= R[i][j];
                    }
                    kill[i] = false;
                }
            }
        }
        else{
            int max_score = Integer.MIN_VALUE, max_idx = 0;
            for (int i = 0; i < N; i++) {
                if(!kill[i] && max_score < score[i]){
                    max_score = score[i];
                    max_idx = i;
                }
            }
            if(max_idx == playerNum){
                result = Math.max(result, nightCnt);
                return;
            }
            kill[max_idx] = true;
            playGame(nightCnt, player - 1, score, R, kill);
            kill[max_idx] = false;
        }
    }
}
