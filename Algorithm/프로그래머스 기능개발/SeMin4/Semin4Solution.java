import java.util.ArrayList;

public class Main {

    public static void main(String[] args) {
	// write your code here
        int[] progresses = {93, 30, 55};
        int[] speeds = {1, 30, 5};
        int[] answer = solution(progresses, speeds);
        for (int i = 0; i < answer.length; i++) {
            System.out.println(answer[i]);
        }
    }

    public static int[] solution(int[] progresses, int[] speeds) {
        int[] answer;
        ArrayList<Integer> arrayList = new ArrayList<>();
        int i = 0;
        while (i < progresses.length){
            boolean flag = false;
            for (int j = i; j < progresses.length; j++) {
                progresses[j] += speeds[j];
                if(progresses[i] >= 100){
                    flag = true;
                }
            }
            if(flag){
                int cnt = 0;
                for (int j = i; j < progresses.length; j++) {
                    if(progresses[j] >= 100){
                        cnt += 1;
                    }
                    else{
                        break;
                    }
                }
                arrayList.add(cnt);
                i += cnt;
            }
        }
        answer = new int[arrayList.size()];
        for (int j = 0; j < arrayList.size(); j++) {
            answer[j] = arrayList.get(j).intValue();
        }
        return answer;
    }
}
