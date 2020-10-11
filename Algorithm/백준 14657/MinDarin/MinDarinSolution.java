import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class Main {
	static int INF;
	static int n;
	static int far_len = -1;
	static int far = -1;
	static int far_cost = Integer.MAX_VALUE;
	static LinkedList<Integer[]>[] list;
	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader (System.in));
		String line = br.readLine();
		StringTokenizer st = new StringTokenizer(line);
		n = Integer.parseInt(st.nextToken());
		int t = Integer.parseInt(st.nextToken());
		INF = Integer.MAX_VALUE / 2;

		list = new LinkedList[n+1];
		for(int i = 0; i <= n; i++)
		{
			list[i] = new LinkedList();
		}	
		int answer = 0;
		boolean[] visited = new boolean[n+1];
		for(int i = 1 ; i <= n-1; i++)
		{
				line = br.readLine();
				st = new StringTokenizer(line);
				int  to = Integer.parseInt(st.nextToken());
				int  from = Integer.parseInt(st.nextToken());
				int  w = Integer.parseInt(st.nextToken());
				Integer[] set = {from,w};
				list[to].add(set);
				Integer[] set2 = {to,w};
				list[from].add(set2);
		}
		visited[1] = true;
		dfs(visited,1,0,0);
		visited[1] = false;
		int u = far;
		visited[u] = true;
		dfs(visited,u,0,0);
		visited[u] = false;
		int v = far;
		System.out.println((int)Math.ceil(far_cost/(double)t));
	}
	public static void dfs(boolean[] visited,int start,int len,int cost)
	{		
		int temp = -1;
		boolean islast = false;
		for(int next = 0; next < list[start].size(); next++)
		{
			int j = list[start].get(next)[0];
			int plus = list[start].get(next)[1];
			if(visited[j] == true || j == start) 
				continue;
			
			islast = true;
			visited[j] = true;
			dfs(visited,j,len+1,cost+plus);
			visited[j] = false;
		}		
	
		if(far_len < len)
		{
			far = start;
			far_len = len;
			far_cost = cost;
		}
		else if(far_len == len)
		{
			if(far_cost > cost)
			{
				far = start;
				far_cost = cost;
			}
		}
	}
}