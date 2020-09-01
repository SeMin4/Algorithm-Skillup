import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

class Token{
    int i;
    int j;
    int depth;
    public Token(int i, int j){
        this.i = i;
        this.j = j;
    }
}
public class Main {
    public static int[] dice = new int[10];
    static int maxScore = Integer.MIN_VALUE;
    public static void main(String[] args) throws IOException {
	// write your code here
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i = 0; i < 10; ++i){
            dice[i] = Integer.parseInt(st.nextToken());
        }

        int[][] map = {
                {0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 0},
                {10, 13, 16, 19},
                {20, 22, 24, 25, 30, 35},
                {30, 28, 27, 26}

        };

        Token[] tokens = new Token[4];
        int[] score = new int[4];
        for (int i = 0; i < 4; i++) {
            tokens[i] = new Token(0, 0);
            score[i] = 0;
        }
        DFS(tokens, map, score, 0);
        System.out.println(maxScore);
    }

    public static void DFS(Token[] tokens, int[][] map, int[] score, int depth){
        if(depth == 10){
            int sum = 0;
            for (int i = 0; i < 4; ++i){
                sum += score[i];
            }
            if(maxScore < sum){
                maxScore = sum;
            }
            return;
        }

        int tmpI, tmpJ, prevI, prevJ;
        for(int idx = 0; idx < 4; ++idx){
            Token token = tokens[idx];// 한개씩 말을 선택...........
            tmpI = prevI = token.i;
            tmpJ = prevJ = token.j;
            if(tmpI == 0 && tmpJ == 21)//이미 도착지점에 있는거는 거르자......
                continue;
            tmpJ += dice[depth];
            while(tmpJ >= map[tmpI].length){
                int diff= tmpJ - (map[tmpI].length);
                if(tmpI == 0){
                    tmpJ = 21;
                    break;
                }
                else if(tmpI == 1){
                    tmpI = 2;
                    tmpJ = 3;
                    tmpJ += diff;
                }
                else if(tmpI == 2){
                    tmpI = 0;
                    tmpJ = 20;
                    tmpJ += diff;
                }else if(tmpI == 3){
                    tmpI = 2;
                    tmpJ = 3;
                    tmpJ += diff;
                }
            }
            if(tmpI == 0 && tmpJ == 5){
                tmpI = 1;
                tmpJ = 0;
            }else if(tmpI == 0 && tmpJ == 10){
                tmpI = 2;
                tmpJ = 0;
            }else if(tmpI == 0 && tmpJ == 15){
                tmpI = 3;
                tmpJ = 0;
            }
            boolean flag = false;
            for(int check_idx = 0; check_idx < 4; ++check_idx){
                if(check_idx != idx){
                    if(tmpI == tokens[check_idx].i && tmpJ == tokens[check_idx].j){
                        if(tmpI == 0 && tmpJ == 21){
                            continue;
                        }else{
                            flag = true;
                            break;
                        }

                    }
                }

            }
            if(flag){
                continue;
            }
            token.i = tmpI;
            token.j = tmpJ;
            score[idx] += map[token.i][token.j];
            DFS(tokens, map, score, depth + 1);
            score[idx] -= map[token.i][token.j];
            token.i = prevI;
            token.j = prevJ;
        }


    }
}
