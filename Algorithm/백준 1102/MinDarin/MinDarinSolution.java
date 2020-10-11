import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class Main 
{
	static int answer = Integer.MAX_VALUE;
	static int n;
	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader (System.in));
		n =	Integer.parseInt(br.readLine()); 		
		int[][] map = new int[n][n];
		for(int i = 0; i < n; i++)
		{
			StringTokenizer st = new StringTokenizer(br.readLine());
			for(int j = 0; j < n; j++)
				map[i][j] = Integer.parseInt(st.nextToken());
		}
		String state = br.readLine();	
		
		ArrayList<Integer> Y = new ArrayList();
		ArrayList<Integer> N = new ArrayList();

		int already_on = 0;
		for(int i = 0; i < n; i++)
		{
			if(state.charAt(i) == 'Y')
			{
				already_on++;
				Y.add(i);
			}	
			else
			{
				N.add(i);
			}	
		}

		int p = Integer.parseInt(br.readLine());
		int remain = p-already_on;

		if(p != 0 &&already_on == 0)
		{
			System.out.println(-1);
			return;
		}
		if(p <= already_on)
		{
			System.out.println(0);
			return;
		}			
		int start_state = 0;
		for(int i = 0; i < Y.size(); i++)
		{
			int y_idx=Y.get(i);
			start_state |= 1 << y_idx;
		}
		
		int[] dp = new int[(int) Math.pow(2, n)];
		Arrays.fill(dp, 100000);
		
		dp[start_state] = 0;
		
		for(int i = 0; i < N.size(); i++)
		{
			int now = N.get(i);
			dfs(dp,map,start_state,remain,now,0,Y);
		}
		System.out.println(answer);

	}
	public static void dfs(int[] dp, int[][] map, int cur_state, int remain, int now_on,int plus,ArrayList<Integer> Y )
	{
		int temp_state = cur_state |( 1<< now_on);
		boolean update = false;
		for(int i = 0; i < Y.size(); i++)
		{
			int on_ = Y.get(i);
			if(	dp[temp_state]>dp[cur_state]+map[on_][now_on])
			{
				dp[temp_state]=dp[cur_state]+map[on_][now_on];
				update = true;
			}
		}
		if(update)
		{
			Y.add(now_on);	
        	for (int j = 0; j < n; j++) 
        	{
            	int bitMask = temp_state & (1 << j);
            	if(bitMask == 0)
            		dfs(dp,map,temp_state,remain,j,plus+1,Y);
        	}
            Y.remove((Integer)now_on);	
		}
		if(remain == plus+1)
		{
			answer = Math.min(answer, dp[temp_state]);
		}
	}	
}
