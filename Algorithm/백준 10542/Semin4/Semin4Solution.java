import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    static int N;
    static int result = 0;
    public static void main(String[] args) throws IOException {
	// write your code here
//        FileReader fr = new FileReader("C:\\Users\\SeMin\\Desktop\\tmp\\mafija\\mafija.in.6");
//        BufferedReader br = new BufferedReader(fr);
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        int[] arr = new int[N + 1];
        int[] ind = new int[N + 1];//ind가 0이면 무조건 마피아임..
        for (int i = 1; i <= N; i++) {
            arr[i] = Integer.parseInt(br.readLine());//가르키고 있는것..
            ind[arr[i]] += 1;
        }
        boolean[] mafiaValid = new boolean[N + 1];
        boolean[] visit = new boolean[N + 1];
        for (int i = 1; i < N + 1; i++) {
            if(ind[i] == 0){//ind 0인 친구들은 마피아..
                dfs(visit, i, true, arr, ind, mafiaValid);
            }
        }
        for (int i = 1; i < N + 1; i++) {
            dfs(visit, i, false, arr, ind, mafiaValid);
        }
        for (int i = 1; i < N + 1; i++) {
            if(mafiaValid[i])
                result += 1;
        }
        System.out.println(result);
    }
    public static void dfs(boolean[] visit, int i, boolean isMafia, int[] arr, int[] ind, boolean[] mafiaValid) {
        if (visit[i])
            return;
        visit[i] = true;//방문기록 남기기
        if(isMafia)//마피아면 마피아임.
            mafiaValid[i] = true;//마피아다!
        ind[arr[i]] -= 1;//처리해줬으니 그친구를 그래프에서 제거.
        if(isMafia || ind[arr[i]] == 0){//현재가 마피아라면 다음 친구는 무조건 시민 또는 다음친구의 인디그리 값이 0이라면 무조건 현재와 반대 값을 가지게 됨. 지금이 시민이라면 마피아임..
            dfs(visit, arr[i], !isMafia, arr, ind, mafiaValid);
        }
    }

}
