import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class Main {
    static int N;
    static int max = Integer.MIN_VALUE;
    public static void main(String[] args) throws IOException {
	// write your code here
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        String input = br.readLine();
        boolean[] paren = new boolean[N];
        dfs(input, 1, paren);
        System.out.println(max);
    }
    public static void dfs(String input, int pos, boolean[] paren){
        if(pos >= N){
            int num = calculate(input, paren);
            if(num > max){
                max = num;
            }
            return;
        }
        for (int i = pos; i < N; i += 2) {
            paren[i] = true;
            dfs(input, i + 4, paren);
            paren[i] = false;
            dfs(input, i + 4, paren);
        }

    }
    public static int calculate(String input, boolean[] paren){
        ArrayList<String> calculateStr = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            char charAt = input.charAt(i);
            calculateStr.add(Character.toString(charAt));
        }
        for (int i = N - 2; i >= 1; i -= 2) {
            if(paren[i]){//괄호가 있을때
                int num = 0;
                switch (input.charAt(i)){
                    case '+':
                        num = (input.charAt(i - 1) - '0') + (input.charAt(i + 1) - '0');
                        break;
                    case '-':
                        num = (input.charAt(i - 1) - '0') - (input.charAt(i + 1) - '0');
                        break;
                    case '*':
                        num = (input.charAt(i - 1) - '0') * (input.charAt(i + 1) - '0');
                        break;
                }
                calculateStr.remove(i + 1);
                calculateStr.remove(i);
                calculateStr.remove(i - 1);
                calculateStr.add(i - 1, Integer.toString(num));

            }
        }
        while (calculateStr.size() > 1){
            String operator = calculateStr.get(1);
            int num = 0;
            switch (operator){
                case "+":
                    num = Integer.parseInt(calculateStr.get(0)) + Integer.parseInt(calculateStr.get(2));
                    break;
                case "-":
                    num = Integer.parseInt(calculateStr.get(0)) - Integer.parseInt(calculateStr.get(2));
                    break;
                case "*":
                    num = Integer.parseInt(calculateStr.get(0)) * Integer.parseInt(calculateStr.get(2));
                    break;
            }
            calculateStr.remove(2);
            calculateStr.remove(1);
            calculateStr.remove(0);
            calculateStr.add(0, Integer.toString(num));
        }
        return Integer.parseInt(calculateStr.get(0));
    }
}
