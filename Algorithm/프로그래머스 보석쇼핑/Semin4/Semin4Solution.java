import java.util.HashMap;

public class Main {

    public static void main(String[] args) {
	// write your code here
        String[] gems = {"DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA"};
//        String[] gems = {"AA", "AB", "AC", "AA", "AC"};
        int[] answer = solution(gems);
        for (int i = 0; i <answer.length ; i++) {
            System.out.println(answer[i]);
        }

    }
    public static int[] solution(String[] gems) {
        int[] answer = {};
        HashMap<String, Integer> hashMap = new HashMap<>();
        for (int i = 0; i < gems.length; i++) {
            if(hashMap.get(gems[i]) != null){
                hashMap.put(gems[i], hashMap.get(gems[i]) + 1);
            }else{
                hashMap.put(gems[i], 1);
            }
        }
        int result_left = 0;
        int result_right = 0;
        int result_length = Integer.MAX_VALUE;
        int size = hashMap.size();
        int left = 0;
        int right = 0;
        HashMap<String, Integer> check = new HashMap<>();
        while (true){
            if(check.size() != size){//right 밀기
                if(right >= gems.length)
                    break;
                if(check.get(gems[right]) != null){
                    check.put(gems[right], check.get(gems[right]) + 1);
                }else{
                    check.put(gems[right], 1);
                }
                right += 1;
            }else{//left 당기기
                if(right-left < result_length){
                    result_length = right - left;
                    result_left = left;
                    result_right = right;
                }
                if(check.get(gems[left]) == 1){
                    check.remove(gems[left]);
                }else{
                    check.put(gems[left], check.get(gems[left]) - 1);
                }
                left += 1;
            }
        }
        answer = new int[]{result_left + 1, result_right};
        return answer;
    }
}
