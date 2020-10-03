import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int[][] keep_map = new int[10][10];
		int[][] map = new int[10][10];
		int answer = 0;
		int min = 2 <<10;
		for(int i = 0 ; i < 10; i++)
		{
				String temp = br.readLine();
				String[] t = temp.split("");
				for(int j = 0 ; j < 10; j++)
				{									
					String st = t[j];
					if(st.equals("#"))
					{
						keep_map[i][j] = 0;
					}
					else 
						keep_map[i][j] = 1;
				}
		}
		
		int[] binary = new int[10];
		for(int c = (2 << 10) -1 ; c >= 0 ; c--)
		{
			boolean hasanswer= true;
			answer = 0;
			int moc = c;
			for(int i = 0 ; i < 10; i++)
				for(int j = 0 ; j < 10; j++)
					map[i][j] = keep_map[i][j];

			for(int t = 9; t >= 0; t--)
			{
				binary[t] = moc%2 ;
				moc/=2;
			}
			
			for(int i = 0; i< 10; i++)
			{
				if(binary[i] == 1)
				{
					change(map,0,i);
					answer++;
				}
			}
						
			for(int i = 1; i < 10; i++)
			{
				for(int j = 0 ; j < 10; j++)
				{
					if(map[i-1][j] == 1)
					{
						change(map,i,j);
						answer++;
					}
				}	
				int check = 0;
				if(i>=1)
				{
					for(int j = 0; j < 10; j++)
					{
						if(map[i-1][j] == 1)
						{
							hasanswer = false;
						}	
					}
				}
			}
			for(int j = 0; j < 10; j++)
			{
				if(map[9][j] == 1)
				{
					hasanswer = false;
				}			
			}		
			if(hasanswer && min > answer)
				min = answer;
		}
		if(min < (2<<10) )
			System.out.println(min);
		else System.out.println("-1");
	}
	public static void change(int[][] map,int i, int j)
	{
		map[i][j]^=1;
		if(i > 0)
			map[i-1][j]^=1;
		if(i < 9)
			map[i+1][j]^=1;
		if(j > 0)
			map[i][j-1]^=1;
		if(j < 9)
			map[i][j+1]^=1;
	}
}