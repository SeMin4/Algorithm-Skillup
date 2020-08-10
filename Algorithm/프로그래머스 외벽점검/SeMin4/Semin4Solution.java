import java.util.ArrayList;

public class Main {
    static int result = -1;
    static int weakCnt;
    public static void main(String[] args) {
	// write your code here
        int n = 12;
//        int[] weak = {1, 5, 6, 10};
//        int[] dist = {1, 2, 3, 4};
        int[] weak = {1, 3, 4, 9, 10};
        int[] dist = {3, 5, 7};
        int result = solution(n, weak, dist);
        System.out.println(result);
    }
    public static int solution(int n, int[] weak, int[] dist) {
        int answer = 0;
        boolean[] select = new boolean[dist.length];
        int[] newWeak = new int[weak.length * 2];
        weakCnt = weak.length;
        for (int i = 0; i < weak.length; i++) {
            newWeak[i] = weak[i];
        }
        for (int i = 0; i < weak.length; i++) {
            newWeak[i + weak.length] = weak[i] + n;
        }
        for (int i = 1; i <= dist.length; i++) {
            ArrayList<Integer> list = new ArrayList<>();
            selectPerson(select, list, dist, newWeak,dist.length, i);
            if(result != -1){
                break;
            }
        }
        answer = result;
        return answer;
    }
    public static void selectPerson(boolean[] select, ArrayList<Integer> list, int[] dist, int[] weak, int n, int m){
        if(m == 0){
            for (int k = 0; k < weak.length / 2; k++) {//회전하면서 한개씩 방문하기
                int idx = 0;
                boolean[] visit = new boolean[weak.length];
                for (int i = k; i < weak.length / 2 && idx < list.size(); i++) {
                    if(!visit[i]){
                        int tmp = list.get(idx);
                        for (int j = i; j < weak.length; j++) {
                            if(weak[j] <= weak[i] + dist[tmp]){
                                visit[j] = true;
                            }
                            else break;
                        }
                        idx += 1;
                    }
                }
                int cnt = 0;
                for (int j = 0; j < visit.length; j++) {//전체 다 방문 하였으면?
                    if(visit[j])
                        cnt += 1;
                }
                if(cnt >= weakCnt){
                    result = list.size();
                    return;
                }
            }
            return ;
        }
        for(int i = 0; i < n; ++i){
            if(!select[i]){
                select[i] = true;
                list.add(i);
                selectPerson(select, list, dist, weak, n, m - 1);
                if(result != -1)//종료 조건
                    return;
                list.remove(list.size() - 1);
                select[i] = false;
            }
        }
    }

}
