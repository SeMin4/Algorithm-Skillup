
public class Solution {
    public static int solution(String[] lines) {
        double[][] time = new double[lines.length][2];
        int idx = 0;
        for(String l : lines)
        {
        	String[] temp = l.split(" ");
        	String[] hms = temp[1].split(":");
        	Double minus = Double.parseDouble(temp[2].substring(0, temp[2].length()-1));
        	time[idx][1] = Double.parseDouble(String.format("%.3f",(Double.parseDouble(hms[0])*3600+Double.parseDouble(hms[1])*60+Double.parseDouble(hms[2]))));
         	time[idx][0] = Double.parseDouble(String.format("%.3f", (time[idx][1] -minus+0.001d)));
      	idx++;
        }
        int answer = -1;
        for(int i = 0 ; i < idx; i++)
        {
        	double check_one_start = Double.parseDouble(String.format("%.3f",time[i][0]));
        	double check_one_end = Double.parseDouble(String.format("%.3f",(time[i][0]+0.999d)));
        	double check_two_end = Double.parseDouble(String.format("%.3f",time[i][1]));
        	double check_two_start = Double.parseDouble(String.format("%.3f",(time[i][1]+0.999d)));

        	double check_three_start = Double.parseDouble(String.format("%.3f",time[i][0]));
        	double check_three_end = Double.parseDouble(String.format("%.3f",(time[i][0]-0.999d)));
        	double check_four_end = Double.parseDouble(String.format("%.3f",time[i][1]));
        	double check_four_start = Double.parseDouble(String.format("%.3f",(time[i][1]-0.999d)));

        	
        	int count1 = 0;
        	int count2 = 0;
        	int count3 = 0;
        	int count4 = 0;
        	
        	for(int j = 0; j < idx; j++)
        	{        		
        		double start = time[j][0];
        		double end = time[j][1];
        		if(check_one_start <= end && start <= check_one_start)
        		{
        			count1++;
        		}        		
        		else if(check_one_start <=start && check_one_end >= end)
        		{
        			count1++;        			
        		}
        		else if(check_one_end >= start && check_one_end <= end)
        		{
        			count1++;
        		}
        		
        		if(check_two_start <= end && start <= check_two_start)
        		{
        			count2++;
        		}        		
        		else if(check_two_start <=start && check_two_end >= end)
        		{
        			count2++;        			
        		}
        		else if(check_two_end >= start && check_two_end <= end)
        		{
        			count2++;
        		}

           		if(check_three_start <= end && start <= check_three_start)
        		{
        			count3++;
        		}        		
        		else if(check_three_start <=start && check_three_end >= end)
        		{
        			count3++;        			
        		}
        		else if(check_three_end >= start && check_three_end <= end)
        		{
        			count3++;
        		}

        	
           		if(check_four_start <= end && start <= check_four_start)
        		{
        			count4++;
        		}        		
        		else if(check_four_start <=start && check_four_end >= end)
        		{
        			count4++;        			
        		}
        		else if(check_four_end >= start && check_four_end <= end)
        		{
        			count4++;
        		}

        	}
        	answer = Math.max(answer, count1);
        	answer = Math.max(answer, count2);
        	answer = Math.max(answer, count3);
        	answer = Math.max(answer, count4);
        }
        return answer;
    }
    public static void main(String[] args)
    {
//    String[] trafic = {
//    	"2016-09-15 20:59:57.421 0.351s",
//    	"2016-09-15 20:59:58.233 1.181s",
//    	"2016-09-15 20:59:58.299 0.8s",
//    	"2016-09-15 20:59:58.688 1.041s",
//    	"2016-09-15 20:59:59.591 1.412s",
//    	"2016-09-15 21:00:00.464 1.466s",
//    	"2016-09-15 21:00:00.741 1.581s",
//    	"2016-09-15 21:00:00.748 2.31s",
//    	"2016-09-15 21:00:00.966 0.381s",
//    	"2016-09-15 21:00:02.066 2.62s"
//    	};
    String[] trafic = {"2016-09-15 01:00:04.002 2.0s", "2016-09-15 01:00:07.000 2s"};
    	System.out.println(solution(trafic));
    }
}
