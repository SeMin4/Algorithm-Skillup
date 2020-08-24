import java.util.HashSet;
import java.util.Set;

public class Main {
    static Set<Integer> resultSet = new HashSet<>();
    public static void main(String[] args) {
	// write your code here
        String[] user_id = {"frodo", "fradi", "crodo", "abc123", "frodoc"};
//        String[] banned_id = {"fr*d*", "abc1**"};
//        String[] banned_id = {"*rodo", "*rodo", "******"};
        String[] banned_id = {"fr*d*", "*rodo", "******", "******"};
        int result = solution(user_id, banned_id);
        System.out.println(result);
    }
    public static int solution(String[] user_id, String[] banned_id) {
        int answer = 0;
        boolean[] visit = new boolean[user_id.length];
        combination(visit, user_id, banned_id, 0);
        answer = resultSet.size();
        return answer;
    }
    public static void combination(boolean[] visit, String[] user_id, String[] banned_id, int depth){
        if(depth == banned_id.length){
            int bitMask = 1;
            int num = 0;
            for (int i = visit.length - 1; i >= 0 ; i--) {
                if(visit[i]){
                    num = num | bitMask;
                }
                bitMask <<= 1;
            }
            if(!resultSet.contains(num)){
                resultSet.add(num);
            }
            return;
        }
        for (int i = 0; i < user_id.length; i++) {
            String user = user_id[i];
            String ban = banned_id[depth];
            if(!visit[i] && user.length() == ban.length()){
                boolean flag = true;
                for (int j = 0; j < user.length(); j++) {
                    if(user.charAt(j) != ban.charAt(j)){
                        if(ban.charAt(j) != '*'){
                            flag = false;
                            break;
                        }
                    }
                }
                if(flag){
                    visit[i] = true;
                    combination(visit, user_id, banned_id, depth + 1);
                    visit[i] = false;
                }
            }
        }
    }
}
