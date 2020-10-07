import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;
class Shark {
    int i;
    int j;
    int speed;
    int direction;//1: 위쪽 2: 아래쪽 3: 오른쪽 4: 왼쪽
    int size;
    public Shark(int i, int j, int speed, int direction, int size){
        this.i = i;
        this.j = j;
        this.speed = speed;
        this.direction = direction;
        this.size = size;
    }
    public Shark(){
        this.i = 0;
        this.j = 0;
        this.speed = 0;
        this.direction = 0;
        this.size = 0;
    }

    public void move(){

        for(int i = 0; i < this.speed; ++i){
            if(this.direction == 1 && this.i == 0){
                this.direction = 2;
            }else if(this.direction == 2 && this.i == Main.R - 1){
                this.direction = 1;
            }else if(this.direction == 3 && this.j == Main.C - 1){
                this.direction = 4;
            }else if(this.direction == 4 && this.j == 0){
                this.direction = 3;
            }

            if(this.direction == 1){
                this.i -= 1;
            }else if(this.direction == 2){
                this.i += 1;
            }else if(this.direction == 3){
                this.j += 1;
            }else if(this.direction == 4){
                this.j -= 1;
            }


        }
    }
}
public class Main {
    public static int R, C, M;
    public static void main(String[] args) throws IOException {
	// write your code here
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        R = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        Shark[][] sharks = new Shark[R][C];
        for(int i = 0; i < R; ++i){
            for(int j = 0; j < C; ++j){
                sharks[i][j] = new Shark();
            }
        }
        for(int i = 0; i < M; ++i){
            st = new StringTokenizer(br.readLine());
            int row = Integer.parseInt(st.nextToken());
            int col = Integer.parseInt(st.nextToken());
            int speed = Integer.parseInt(st.nextToken());
            int direction = Integer.parseInt(st.nextToken());
            int size = Integer.parseInt(st.nextToken());
            sharks[row - 1][col - 1].i = row - 1;
            sharks[row - 1][col - 1].j = col - 1;
            sharks[row - 1][col - 1].speed = speed;
            sharks[row - 1][col - 1].direction = direction;
            sharks[row - 1][col - 1].size = size;
        }
        int sum = 0;
        for(int j = 0; j < C; ++j){
            for(int i = 0; i < R; ++i){
                if(sharks[i][j].size != 0){
                    sum += sharks[i][j].size;
                    sharks[i][j] = new Shark();
                    break;
                }
            }
            sharks = moveShark(sharks);
        }
        System.out.println(sum);


    }

    public static Shark[][] moveShark(Shark[][] sharks){
        Shark[][] newShark = new Shark[R][C];
        for(int i = 0; i < R; ++i){
            for(int j = 0; j < C; ++j){
                newShark[i][j] = new Shark();
            }
        }
        for(int i = 0; i < R; ++i){
            for(int j = 0; j < C; ++j){
                if(sharks[i][j].size != 0){
                    sharks[i][j].move();
                    if(newShark[sharks[i][j].i][sharks[i][j].j].size < sharks[i][j].size){
                        newShark[sharks[i][j].i][sharks[i][j].j] = sharks[i][j];
                    }
                }
            }
        }
        return newShark;
    }
}
