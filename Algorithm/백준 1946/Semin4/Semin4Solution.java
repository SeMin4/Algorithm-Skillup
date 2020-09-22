import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

class People implements Comparable<People>{
    int idx;
    int paperScore;
    int interviewScore;
    public People(int idx, int paperScore, int interviewScore){
        this.idx = idx;
        this.paperScore = paperScore;
        this.interviewScore = interviewScore;
    }

    @Override
    public int compareTo(People o) {
        if(this.paperScore < o.paperScore)
            return -1;
        else if(this.paperScore == o.paperScore)
            return 0;
        else
            return 1;
    }
}
public class Main {
    static int T, N;
    public static void main(String[] args) throws IOException {
	// write your code here
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        T = Integer.parseInt(br.readLine());
        for (int i = 0; i < T; i++) {
            N = Integer.parseInt(br.readLine());
            StringTokenizer st;
            People[] arr = new People[N];
            for (int j = 0; j < N; j++) {
                st = new StringTokenizer(br.readLine());
                arr[j] = new People(j, Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
            }
            Arrays.sort(arr);
            PriorityQueue<People> priorityQueue = new PriorityQueue<>(new Comparator<People>() {
                @Override
                public int compare(People o1, People o2) {
                    if(o1.interviewScore < o2.interviewScore)
                        return -1;
                    else if(o1.interviewScore == o2.interviewScore)
                        return 0;
                    else
                        return 1;
                }
            });
            priorityQueue.offer(arr[0]);
            for (int j = 1; j < N; j++) {
                People people = priorityQueue.peek();
                if(arr[j].interviewScore < people.interviewScore){
                    priorityQueue.offer(arr[j]);
                }
            }
            System.out.println(priorityQueue.size());
            priorityQueue.clear();

        }

    }
}
