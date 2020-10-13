import java.util.*;
import java.io.*;
public class Main {
	static LinkedList<Integer> answer_list = new LinkedList();
	static boolean finish;
	public static void main(String[] args)throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(st.nextToken());
		int[] map = new int[n+1];
		for(int i = 1; i <= n; i++)
		{
			char[] bit = br.readLine().toCharArray();
			int b = 0;
			for(int j = k-1; j >= 0; j--)
			{
				map[i] |= (bit[b++]-48) << j;
			}
		}
		st = new StringTokenizer(br.readLine());
		int start = Integer.parseInt(st.nextToken());
		int end = Integer.parseInt(st.nextToken());
		int[] visited = new int[n+1];
		LinkedList<Integer> route = new LinkedList();
		route.add(start);
		visited[start] = 1;
		dfs(map,visited,map[start],map[end],n,0,route);
		if(answer_list.size() <= 0)
		{
			System.out.println(-1);
			return;
		}
		else
		{
			BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
			Iterator ait = answer_list.iterator();
			while(ait.hasNext())
			{
				int t = (int)ait.next();
				bw.write(t+" ");
			}
			bw.close();
		}
	}
	public static void dfs(int[] map,int[] visited, int cur,int last,int n,int count,LinkedList<Integer> route)
	{
		if(cur == last)
		{
			Iterator it = route.iterator();
			while(it.hasNext())
			{
				answer_list.add((int)it.next());
				finish = true;
			}
			return;
		}
		for(int i = 1; i <= n; i++)
		{
			if(visited[i] != 0)
				continue;
			if(finish)
			{
				return;
			}
			int temp = cur ^ map[i]; 

			if(Integer.bitCount(temp) == 1)
			{
			visited[i] = 1;
			route.add(i);
			dfs(map,visited,map[i],last,n,count+1,route);
			route.remove((Integer) i);
			visited[i] = 0;
			}
		}
	}
}
