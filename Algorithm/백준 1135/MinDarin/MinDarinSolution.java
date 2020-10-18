import java.util.*;
import java.io.*;

public class Main {
	static int n;
	static int[] boss;
	static boolean[] visited;
	static LinkedList<Integer>[] child_list;
	static int[] dp;
	static int time = 0;
	public static void main(String[] args)throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader (System.in));
		n = Integer.parseInt(br.readLine());
		boss = new int[n];
		visited = new boolean[n];
		StringTokenizer st = new StringTokenizer(br.readLine());
		child_list = new LinkedList[n];
		dp = new int[n];
		for(int i = 0 ; i < n; i++)
		{
			child_list[i] = new LinkedList<Integer>();
		}
		int idx = 0;
		while(st.hasMoreTokens())
		{
			int temp_boss = Integer.parseInt(st.nextToken());
			if(temp_boss != -1)
				child_list[temp_boss].add(idx);
			boss[idx++] = temp_boss;
		}
		dfs(0);
		
		System.out.println(dp[0]);
	}
	public static int dfs(int start)
	{
		if(child_list[start].size() == 0)
			return 0;
		LinkedList<Integer> temp = new LinkedList<Integer>();
		int temp_time = 0;
		for(int i = 0 ; i < child_list[start].size(); i++)
		{
			temp.add(dfs(child_list[start].get(i)));
		}
		Collections.sort(temp);
		int max = Integer.MIN_VALUE;
		int j = temp.size();
		for(int i = 0 ; i < temp.size(); i++)
		{
			if(max < temp.get(i)+j)
			{
				max = temp.get(i)+j;			
			}
			j--;
		}
		return dp[start] = max; 
	}
}
