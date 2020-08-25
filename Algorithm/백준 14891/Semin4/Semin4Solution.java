import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int K;
    static int TWELVE = 128;
    static int DIRTY = 256;
    static int ONE = 1;
    static int THREE = 32;
    static int NINE = 2;
    static int result = 0;
    public static void main(String[] args) throws IOException {
	// write your code here
        DIRTY = ~DIRTY;
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[] machine = new int[4];
        for (int i = 0; i < 4; i++) {
            String tmp = br.readLine();
            machine[i] = Integer.parseInt(tmp, 2);
        }
        K = Integer.parseInt(br.readLine());
        for (int i = 0; i < K; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int what = Integer.parseInt(st.nextToken()) - 1;
            int direction = Integer.parseInt(st.nextToken());
            rotate(machine,what,direction, 0);
        }
        for (int i = 0, score = 1; i < 4; i++, score *= 2) {
            int value = machine[i] & TWELVE;
            if(value != 0){
                result += score;
            }
        }
        System.out.println(result);
    }
    public static void rotate(int[] machine, int what, int direction, int type){

        switch (type){
            case 0:
                if(outOfRange(what - 1)){
                    int value = (machine[what - 1] & THREE) > 0 ? 1 : 0;
                    int value2 = (machine[what] & NINE) > 0 ? 1 : 0;
                    if(value != value2){

                        rotate(machine, what - 1, direction * -1, 1);
                    }
                }
                if(outOfRange(what + 1)){
                    int value = (machine[what + 1] & NINE) > 0 ? 1 : 0;
                    int value2 = (machine[what] & THREE) > 0 ? 1 : 0;
                    if(value != value2){
                        rotate(machine, what + 1, direction * -1, 2);
                    }
                }
                break;
            case 1:
                if(outOfRange(what - 1)){
                    int value = (machine[what - 1] & THREE) > 0 ? 1 : 0;
                    int value2 = (machine[what] & NINE) > 0 ? 1 : 0;
                    if(value != value2){
                        rotate(machine, what - 1, direction * -1, 1);
                    }
                }
                break;
            case 2:
                if(outOfRange(what + 1)){
                    int value = (machine[what + 1] & NINE) > 0 ? 1 : 0;
                    int value2 = (machine[what] & THREE) > 0 ? 1 : 0;
                    if(value != value2){
                        rotate(machine, what + 1, direction * -1, 2);
                    }
                }
                break;
        }
        rotateEach(machine, what, direction);
    }
    public static boolean outOfRange(int tmp){
        return (tmp >= 0 && tmp < 4);
    }
    public static void rotateEach(int[] machine, int what, int direction){
        if(direction == -1){// 반시계
            int tmp = machine[what] & TWELVE;
            machine[what] <<= 1;
            machine[what] &= DIRTY;
            if(tmp != 0)
                machine[what] |= 1;
        }
        else{//시계
            int tmp = machine[what] & ONE;
            machine[what] >>= 1;
            tmp <<= 7;
            machine[what] |= tmp;
        }
    }
}
