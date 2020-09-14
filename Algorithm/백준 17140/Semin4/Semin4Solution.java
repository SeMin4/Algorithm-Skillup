import javax.imageio.stream.ImageInputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int R, C, K;
    static int[][] arr = new int[101][101];
    public static void main(String[] args) throws IOException {
	// write your code here
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        R = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        for(int i = 1; i <= 3; ++i){
            st = new StringTokenizer(br.readLine());
            for(int j = 1; j <= 3; ++j){
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        int row_size = 3;
        int col_size = 3;
        int time = 0;
        while(arr[R][C] != K && time <= 100){
            if(row_size >= col_size){
                int tmp = 0;
                for(int i = 1; i <= row_size; ++i){
                    tmp = Math.max(tmp, horizontalSort(i, col_size));

                }
                col_size = tmp;
            }
            else{
                int tmp = 0;
                for(int j = 1; j <= col_size; ++j){
                    tmp = Math.max(tmp, verticalSort(j, row_size));
                }
                row_size = tmp;
            }
            time += 1;
        }
        if(time == 101)
            System.out.println(-1);
        else
            System.out.println(time);
    }

    public static int horizontalSort(int row, int col_size){
        HashMap<Integer, Integer> unOrderedMap = new HashMap<>();
        for(int i = 1; i <= col_size ; ++i){
            if(arr[row][i] == 0)
                continue;
            if(unOrderedMap.containsKey(arr[row][i])){
                unOrderedMap.put(arr[row][i], unOrderedMap.get(arr[row][i]) + 1);
            }
            else{
                unOrderedMap.put(arr[row][i], 1);
            }
        }
        List<HashMap.Entry<Integer, Integer>> list = new LinkedList<>(unOrderedMap.entrySet());
        Collections.sort(list, new Comparator<HashMap.Entry<Integer, Integer>>() {
            @Override
            public int compare(Map.Entry<Integer, Integer> o1, Map.Entry<Integer, Integer> o2) {
                if(o1.getValue() < o2.getValue()){
                    return -1;
                }else if(o1.getValue() == o2.getValue()){
                    if(o1.getKey() < o2.getKey()){
                        return -1;
                    }else{
                        return 0;
                    }
                }
                else{
                    return 1;
                }
            }
        });
        Map<Integer, Integer> sortedMap = new LinkedHashMap<>();
        for(Iterator<Map.Entry<Integer, Integer>> iter = list.iterator(); iter.hasNext();){
            Map.Entry<Integer, Integer> entry = iter.next();
            sortedMap.put(entry.getKey(), entry.getValue());
        }

        for(int i = 1; i <=100; ++i){
            arr[row][i] = 0;
        }
        int i = 1;
        for(Integer key : sortedMap.keySet()){
            arr[row][i] = key;
            arr[row][i + 1] = sortedMap.get(key);
            i += 2;
            if(i > 100)
                break;
        }
        return i - 1;
    }
    public static int verticalSort(int col, int row_size){
        Map<Integer, Integer> unOrderMap = new HashMap<>();
        for(int i = 1; i <= row_size; ++i){
            if(arr[i][col] == 0)
                continue;
            if(unOrderMap.containsKey(arr[i][col])){
                unOrderMap.put(arr[i][col], unOrderMap.get(arr[i][col]) + 1);
            }else{
                unOrderMap.put(arr[i][col], 1);
            }
        }
        List<Map.Entry<Integer, Integer>> list = new LinkedList<>(unOrderMap.entrySet());
        Collections.sort(list, new Comparator<Map.Entry<Integer, Integer>>() {
            @Override
            public int compare(Map.Entry<Integer, Integer> o1, Map.Entry<Integer, Integer> o2) {
                if(o1.getValue() < o2.getValue()){
                    return -1;
                }else if(o1.getValue().equals(o2.getValue())){
                    if(o1.getKey() < o2.getKey()){
                        return -1;
                    }else{
                        return 0;
                    }
                }else{
                    return 0;
                }
            }
        });
        Map<Integer, Integer> sortedMap = new LinkedHashMap<>();
        for(Iterator<Map.Entry<Integer, Integer>> iter = list.iterator(); iter.hasNext();){
            Map.Entry<Integer, Integer> map = iter.next();
            sortedMap.put(map.getKey(), map.getValue());
        }
        for(int i = 1; i <=100; ++i){
            arr[i][col] = 0;
        }
        int i = 1;
        for(Integer key : sortedMap.keySet()){
            arr[i][col] = key;
            arr[i + 1][col] = sortedMap.get(key);
            i += 2;
            if(i > 100)
                break;
        }
        return i - 1;
    }
}
