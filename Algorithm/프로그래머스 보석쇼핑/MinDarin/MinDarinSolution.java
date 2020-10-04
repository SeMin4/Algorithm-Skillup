import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

public class Solution {
	public static void main(String[] args) throws IOException
	{
//		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
//		int N = Integer.parseInt(br.readLine());
//		String[] g = {"DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA"};
//		String[] g = {"ZZZ", "YYY", "NNNN", "YYY", "BBB"};
//		String[] g = {"XYZ", "XYZ", "XYZ"};
		String[] g = {"DIA", "EM", "EM", "RUB", "DIA"};
		int[] ar = solution(g);
		System.out.println(ar[0]+","+ar[1]);
//		for (int i = 0; i < ar.length; i++) {
//			bw.write("65");
//			bw.flush();
//		}
//		bw.close();
	}
    public static int[] solution(String[] gems) 
    {
        int[] answer = new int[2];
//        HashSet<String> type = new HashSet();
        HashMap<String,Integer> s = new HashMap<>();
        int value = 0;
        for(int i = 0 ; i < gems.length; i++)
        {
        	if(s.get(gems[i]) == null)
        		s.put(gems[i], value++);
//        	type.add(gems[i]);
        }
//        int n = type.size();
        int n = s.size();
        int[] cntArr = new int[n];
        int r = 0;
        int l = 0;
        
//        int value = 0;
//        for(String gemStr : type) {
//        	s.put(gemStr, value);
//        	value += 1;
//        }
//        for(; r< n; r++)
//        {
//    		if(s.containsKey(gems[r]))
//    		{
//    			int v = s.get(gems[r]);
//    			s.put(gems[r],v+1);
//    		}
//    		else
//    		{
//    			s.put(gems[r],1);
//    		}
//        }
        int typeCnt = 0;
        int size = Integer.MAX_VALUE;
        int left = 0;
        int right = 0;
        int answer_right = 0;
        int answer_left = 0;
        while(left <= right && right < gems.length) {
        	if(typeCnt < n) {
        		cntArr[s.get(gems[right])] += 1;
        		typeCnt = cntArr[s.get(gems[right])] == 1 ? typeCnt += 1 : typeCnt;
    			right += 1;
        	}
        	else {
        		cntArr[s.get(gems[left])] -= 1;        		
        		typeCnt = cntArr[s.get(gems[left])] == 0 ? typeCnt -= 1 : typeCnt;
        		left += 1;
        	}
        	if(typeCnt == n)
        	{
        		if(size > right-left)
        		{
        		
        			answer_right = right-1;
        			if(left == 0)
        			{	
        				answer_left = left;
        				size = right;
        			}
        			else
        			{
        				answer_left = left;
        				size = (right-1) - (left-1)+1;				
        			}
        		}
			}
		}

        while(left < gems.length) {
        	if(typeCnt < n) {
        		break;
        	}
        	else {
        		cntArr[s.get(gems[left])] -= 1;        		
        		typeCnt = cntArr[s.get(gems[left])] == 0 ? typeCnt -= 1 : typeCnt;
        		left += 1;
        	}
        	if(typeCnt == n) {
        		if(size > (right-1)-left+1)
        		{
        			size = (right-1)-(left-1)+1;				
        			answer_right = (right-1);
        			answer_left = left;
        		}
			}
        }
//        while(r-l >= n)
//        {
//        	while(s.size() < n)
//        	{
//        		if(s.containsKey(gems[r]))
//        		{
//        			int v = s.get(gems[r]);
//        			s.put(gems[r],v+1);
//        		}
//        		else
//        		{
//        			s.put(gems[r],1);
//        		}
//        		r++;
//        	}
//        	while(s.size() == n)
//        	{
//        		if(answer_r - answer_l > r-l)
//        		{
//        			answer_r = r-1;
//        			answer_l = l;
//        		}
//        		int v = s.get(gems[l]);
//        		if(v == 1)
//        			s.remove(gems[l]);
//        		else
//        		{
//        			s.put(gems[r], v-1);
//        		}
//        		l++;
//        	}
//        }
        answer[0] = answer_left+1;
        answer[1] = answer_right+1;
        return answer;
    }
}	
