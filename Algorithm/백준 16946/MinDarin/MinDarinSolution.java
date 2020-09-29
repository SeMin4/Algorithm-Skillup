import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

public class Main {
	public static void main(String[] args)
	{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
		int n = 0;
		int m = 0;
		try {
			String s = br.readLine();
			String[] splited_s = new String[4];
			splited_s=s.split(" ");
			n = Integer.parseInt(splited_s[0]);
			m = Integer.parseInt(splited_s[1]);
		} catch (IOException e2) {
			// TODO Auto-generated catch block
			e2.printStackTrace();
		}
		
		int[][] map = new int[n][m];
		int[][] result = new int[n][m];
		Deque<point> queue = new ArrayDeque();
		
//		for(int j = 0; j < m+2; j++)
//		{
//			map[0][j] = 1;
//			map[n+1][j] = 1;
//		}
//		for(int i = 1; i <= n; i++)
//		{
//			map[i][0] = 1;
//			map[i][m+1] = 1;
//		}
		point[] zero = new point[n*m];
		int zero_idx= 0;
	    for (int i = 0; i < n; i++) {
            String tmp = null;
			try {
				tmp = br.readLine();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
            for (int j = 0; j < m; j++) {
                int next = tmp.charAt(j) - '0';
            	map[i][j] = next;
            	
                if(next == 0)
                {
                	point p = new point(i,j);
                	zero[zero_idx++] = p;
                }
            }
        }
			
		HashMap<Integer,Integer> hmap = new HashMap();
		int key = 2;

		for(int c =0; c <zero_idx ; c++)
		{
			int i = zero[c].i;
			int j = zero[c].j;
				if(map[i][j] != 0)
					continue;
				queue.clear();
				point start = new point(i,j);
				queue.add(start);
				map[i][j] = key;

				int distance = 1;
			
				while(!queue.isEmpty())
				{
					point cur = queue.pop();
					int y = cur.i;
					int x = cur.j;

					if(y < n-1 && map[y+1][x] == 0 )
					{
						point next = new point(y+1,x);
						queue.add(next);	
						map[y+1][x] = key;
						distance ++;
					}
					if(y >= 1 && map[y-1][x] == 0)
					{
						point next = new point(y-1,x);
						queue.add(next);	
						map[y-1][x] = key;
						distance ++;
					}
					if( x < m-1 && map[y][x+1] == 0)
					{
						point next = new point(y,x+1);
						queue.add(next);	
						map[y][x+1] = key;
						distance ++;
					}
					if(x >= 1 && map[y][x-1] == 0)
					{
						point next = new point(y,x-1);
						queue.add(next);	
						map[y][x-1] = key;
						distance ++;
					}
				}
				hmap.put(key, distance);
				key++;
		}
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		for(int i = 0; i< n; i++)
		{
			for(int j = 0 ; j <m ; j++)
			{
				if(map[i][j] == 1)
				{
					int one_y = i;
					int one_x = j;
					result[one_y][one_x]++;
					HashSet<Integer> jungbok_check = new HashSet();
					jungbok_check.clear();
					if(one_y< n-1 && map[one_y+1][one_x] != 1 )
					{
						int now_key = map[one_y+1][one_x];
						jungbok_check.add(now_key);
					}
					if( one_y >= 1 && map[one_y-1][one_x] != 1)
					{
						int now_key = map[one_y-1][one_x];
						jungbok_check.add(now_key);
					}
					if( one_x < m-1 && map[one_y][one_x+1] != 1)
					{

						int now_key = map[one_y][one_x+1];
						jungbok_check.add(now_key);
					}
					if(one_x >= 1 && map[one_y][one_x-1] != 1)
					{
						int now_key = map[one_y][one_x-1];						
						jungbok_check.add(now_key);
					}
					Iterator it = jungbok_check.iterator();
					while(it.hasNext())
					{
						result[one_y][one_x] += hmap.get((int)it.next());
					}
					try {
						bw.write(Integer.toString(result[i][j]%10));
					} catch (IOException e) {
						// TODO Auto-generated catch block
						e.printStackTrace();
					}
				} else
					try {
						bw.write('0');
					} catch (IOException e) {
						// TODO Auto-generated catch block
						e.printStackTrace();
					}
			}
			try {
				bw.write('\n');
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		try {
			bw.close();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

	}
}
class point
{
	int i;
	int j;
	int d = 0;
	point (int y, int x)
	{
		i = y;
		j = x;
	}
	point (int y, int x, int d)
	{
		i =y;
		j = x;
		this.d = d;
	}
//	  public boolean equals(Object o){
//		  point po = (point)o;
//		  if(this.i == po.i && this.j == po.j)
//			  return true;
//	      return false;
//	  }  
}
