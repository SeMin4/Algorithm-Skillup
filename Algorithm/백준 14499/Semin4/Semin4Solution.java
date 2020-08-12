import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
class Dice{
    int row;
    int col;
    int down;
    int top;
    int back;
    int front;
    int left;
    int right;
    public Dice(){
        this.col = 0;
        this.row = 0;
        this.down = 0;
        this.top = 0;
        this.back = 0;
        this.front = 0;
        this.left = 0;
        this.right = 0;
    }
    public void diceRoll(int dir){
        //dir 1 east 2 west 3 north 4 south
        int tmp;
        switch (dir){
            case 1://east
                tmp = this.left;
                this.left = this.down;
                this.down = this.right;
                this.right = this.top;
                this.top = tmp;
                break;
            case 2:
                tmp = this.right;
                this.right = this.down;
                this.down = this.left;
                this.left = this.top;
                this.top = tmp;
                break;
            case 3:
                tmp = this.top;
                this.top = this.front;
                this.front = this.down;
                this.down = this.back;
                this.back = tmp;
                break;
            case 4:
                tmp = this.top;
                this.top = this.back;
                this.back = this.down;
                this.down = this.front;
                this.front = tmp;
                break;
        }
    }
    public boolean diceRollXY(int dir, int N, int M){
        switch (dir){//1 east 2 west 3 north 4 south
            case 1:
                if(this.col + 1 >= M){
                    return false;
                }
                else{
                    this.col += 1;
                    return true;
                }
            case 2:
                if(this.col - 1 < 0){
                    return false;
                }else{
                    this.col -= 1;
                    return true;
                }
            case 3:
                if(this.row - 1 < 0){
                    return false;
                }else{
                    this.row -= 1;
                    return true;
                }
            case 4:
                if(this.row + 1 >= N){
                    return false;
                }else{
                    this.row += 1;
                    return true;
                }
        }
        return false;
    }
}
public class Main {

    public static void main(String[] args) throws IOException {
	// write your code here
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N, M, K;
        Dice dice = new Dice();
        String[] str = br.readLine().split(" ");
        N = Integer.parseInt(str[0]);
        M = Integer.parseInt(str[1]);
        dice.row = Integer.parseInt(str[2]);
        dice.col = Integer.parseInt(str[3]);
        K = Integer.parseInt(str[4]);
        int[][] board = new int[N][M];
        for(int i = 0; i < N; ++i){
            str = br.readLine().split(" ");
            for(int j = 0; j < M; ++j){
                board[i][j] = Integer.parseInt(str[j]);
            }
        }
        int[] command = new int[K];//1 east 2 west 3 north 4 south
        str = br.readLine().split(" ");
        for(int i = 0; i < K; ++i){
            command[i] = Integer.parseInt(str[i]);
        }
        for(int i = 0; i < K; ++i){
            if(dice.diceRollXY(command[i], N, M)){
                dice.diceRoll(command[i]);
                if(board[dice.row][dice.col] == 0){
                    board[dice.row][dice.col] = dice.down;
                }else{
                    dice.down = board[dice.row][dice.col];
                    board[dice.row][dice.col] = 0;
                }
                System.out.println(dice.top);
            }
        }
    }
}
