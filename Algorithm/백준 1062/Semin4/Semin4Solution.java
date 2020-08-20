import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
    static int N, K;
    static int result = Integer.MIN_VALUE;
    public static void main(String[] args) throws IOException {
	// write your code here
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        ArrayList<String> stringArrayList = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            String tmp = br.readLine();
            tmp = tmp.substring(4, tmp.length() - 4);
            stringArrayList.add(tmp);
        }
        boolean[] visit = new boolean[26];
        visit[0] = true;
        visit['n' - 'a'] = true;
        visit['t' - 'a'] = true;
        visit['i' - 'a'] = true;
        visit['c' - 'a'] = true;
        if(K < 5){
            System.out.println(0);
        }
        else if(K == 26){
            System.out.println(N);
        }
        else{
            K -= 5;
            dfs(stringArrayList, visit, K, 1);
            System.out.println(result);
        }


    }
    public static void dfs(ArrayList<String> stringArrayList, boolean[] visit, int depth, int start){
        if(depth == 0){
            int cnt = 0;
            for (int i = 0; i < stringArrayList.size(); i++) {
                String tmp = stringArrayList.get(i);
                for (int j = 0; j < tmp.length(); j++) {
                    if(!visit[tmp.charAt(j)-'a']){
                        cnt -= 1;
                        break;
                    }
                }
                cnt += 1;
            }
            if(cnt > result){
                result = cnt;
            }
            return;
        }
        for (int i = start; i < 26; i++) {
            if(!visit[i]){
                visit[i] = true;
                dfs(stringArrayList, visit, depth - 1, i + 1);
                visit[i] = false;
            }
        }
    }
}
