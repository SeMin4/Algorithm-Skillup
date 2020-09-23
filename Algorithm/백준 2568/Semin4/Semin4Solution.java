import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;
class Line implements Comparable<Line>{
    int start;
    int end;
    public Line(int start, int end){
        this.start = start;
        this.end = end;
    }

    @Override
    public int compareTo(Line o) {
        if(this.start < o.start)
            return -1;
        else if(this.start == o.start)
            return 0;
        else
            return 1;
    }
}
public class Main {
    static int N;
    public static void main(String[] args) throws IOException {
	// write your code here
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        StringTokenizer st;
        Line[] lines = new Line[N + 1];
        for (int i = 1; i <= N; i++) {
            st = new StringTokenizer(br.readLine());
            lines[i] = new Line(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
        }
        Arrays.sort(lines, 1, lines.length);
        int[] dp = new int[N + 1];
        int[] lis = new int[N + 1];
        lis[0] = Integer.MIN_VALUE;
//        dp[0] = Integer.MIN_VALUE;
        int idx = 0;
        for (int i = 1; i <= N; i++) {
            if(lis[idx] < lines[i].end){
                lis[++idx] = lines[i].end;
                dp[i] = idx;
            }
            else{
                 int insertIdx = lowerBound(1, idx + 1, lines[i].end, lis);
                lis[insertIdx] = lines[i].end;
                dp[i] = insertIdx;
            }
        }
        ArrayList<Integer> list = new ArrayList<>();
        for (int i = N; i >= 1; i--) {
            if(dp[i] == idx){
                idx--;
            }
            else{
                list.add(lines[i].start);
            }
        }
        Collections.sort(list);
        System.out.println(list.size());
        for (int i = 0; i < list.size(); i++) {
            System.out.println(list.get(i));
        }
    }
    public static int lowerBound(int start ,int end, int value, int[] lis){
        while (start < end){
            int mid = (start + end) / 2;
            if(lis[mid] < value){
                start = mid + 1;
            }else{
                end = mid;
            }
        }
        return start;
    }
}
