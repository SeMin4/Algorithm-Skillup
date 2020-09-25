import java.util.*;

public class Main {
		public static void main(String[] args)
		{
			Scanner sc = new Scanner(System.in);
			int n = sc.nextInt();
			int[] ar = new int[n];
			for(int i = 0; i <n ; i++)
				 ar[i]  = sc.nextInt();
			System.out.print(solution(n,ar));
		}
		public static int solution(int n, int[] ar)
		{
			int answer = 0;
			Arrays.sort(ar);
			int minus = 0;
			for(int i = n-1 ; i >= 0 ;i--)
			{
				int plus = ar[i] - minus;
				if(plus <= 0)
					break;
				answer += plus;
				minus++;
			}
			return answer;
		}
}	

