import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;
class Num{
    int num;
    int cnt;
    public Num(int num, int cnt){
        this.num = num;
        this.cnt = cnt;
    }
}
public class Main {
    static int N, K;
    static int MAX = 500001;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        if(N == K){
            System.out.println(0);
        }
        else{
            int[] odd_visit = new int[MAX];
            int[] even_visit = new int[MAX];
            Arrays.fill(odd_visit, Integer.MAX_VALUE);
            Arrays.fill(even_visit, Integer.MAX_VALUE);
//            odd_visit[N] = 0;//오드 는 방문 안댐....아...진짜 바보..
            even_visit[N] = 0;
            Queue<Num> queue = new LinkedList<>();
            queue.offer(new Num(N, 0));
            while (!queue.isEmpty()){
                Num num = queue.poll();
                if((num.cnt + 1) % 2 == 1){// odd 방문
                    if(num.num - 1 >= 0 && odd_visit[num.num - 1] > num.cnt + 1){//홀수 번째로 방문함.
                        queue.offer(new Num(num.num - 1, num.cnt + 1));
                        odd_visit[num.num - 1] = num.cnt + 1;
                    }
                    if(num.num + 1 < MAX && odd_visit[num.num + 1] > num.cnt + 1){
                        queue.offer(new Num(num.num + 1, num.cnt + 1));
                        odd_visit[num.num + 1] = num.cnt + 1;
                    }
                    if(num.num * 2 < MAX && odd_visit[num.num * 2] > num.cnt + 1){
                        queue.offer(new Num(num.num * 2, num.cnt + 1));
                        odd_visit[num.num * 2] = num.cnt + 1;
                    }
                }
                else{
                    if(num.num - 1 >= 0 && even_visit[num.num - 1] > num.cnt + 1){//짝수 번째로 방문함.
                        queue.offer(new Num(num.num - 1, num.cnt + 1));
                        even_visit[num.num - 1] = num.cnt + 1;
                    }
                    if(num.num + 1 < MAX && even_visit[num.num + 1] > num.cnt + 1){
                        queue.offer(new Num(num.num + 1, num.cnt + 1));
                        even_visit[num.num + 1] = num.cnt + 1;
                    }
                    if(num.num * 2 < MAX && even_visit[num.num * 2] > num.cnt + 1){
                        queue.offer(new Num(num.num * 2, num.cnt + 1));
                        even_visit[num.num * 2] = num.cnt + 1;
                    }
                }
            }
            int result = Integer.MAX_VALUE;
            for (int i = 0; i < MAX; i++) {
                int cum = ((i * (i + 1)) / 2) + K;
                if(cum >= MAX){
                    break;
                }
                else if(i % 2 == 1){//동생의 홀수 번째 위치.
                    if(odd_visit[cum] <= i){
                        result = i;
                        break;
                    }
                }
                else {
                    if (even_visit[cum] <= i) {
                        result = i;
                        break;
                    }
                }
            }
            if(result == Integer.MAX_VALUE)
                System.out.println(-1);
            else
                System.out.println(result);
        }
    }

}
