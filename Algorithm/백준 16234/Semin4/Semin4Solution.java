import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

class Country{
    int i;
    int j;
    int value;
    public Country(int i, int j, int value){
        this.i = i;
        this.j = j;
        this.value = value;
    }
}
public class Main {
    static int N, L, R;
    public static void main(String[] args) throws IOException {
	// write your code here
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] str = br.readLine().split(" ");
        N = Integer.parseInt(str[0]);
        L = Integer.parseInt(str[1]);
        R = Integer.parseInt(str[2]);
        int[][] map = new int[N][N];
        for(int i = 0; i < N; ++i){
            str = br.readLine().split(" ");
            for(int j = 0; j < N; ++j){
                map[i][j] = Integer.parseInt(str[j]);
            }
        }
        boolean[][] visit = new boolean[N][N];
        boolean flag = true;
        int cnt = 0;
        while(flag){
            flag = false;
            cnt += 1;
            for(int i = 0; i < N; ++i){
                for(int j = 0; j < N; ++j){
                    visit[i][j] = false;
                }
            }
            for(int i = 0; i < N; ++i){
                for(int j = 0; j < N; ++j){
                    if(!visit[i][j]){
                        ArrayList<Country> countriesList = new ArrayList<>();
                        Queue<Country> countries = new LinkedList<>();
                        countries.add(new Country(i, j, map[i][j]));
                        visit[i][j] = true;
                        while(!countries.isEmpty()){
                            Country country = countries.poll();
                            countriesList.add(country);
                            int row = country.i;
                            int col = country.j;
                            if(row - 1 >= 0 && Math.abs(country.value - map[row - 1][col]) >= L && Math.abs(country.value - map[row - 1][col]) <= R && !visit[row - 1][col]){
                                countries.add(new Country( row - 1, col, map[row - 1][col]));
                                visit[row - 1][col] = true;
                                flag = true;
                            }
                            if(col - 1 >= 0 && Math.abs(country.value - map[row][col - 1]) >= L && Math.abs(country.value - map[row][col - 1]) <= R && !visit[row][col - 1]){
                                countries.add(new Country(row, col - 1, map[row][col - 1]));
                                visit[row][col - 1] = true;
                                flag = true;
                            }
                            if(row + 1 < N && Math.abs(country.value - map[row + 1][col]) >= L && Math.abs(country.value - map[row + 1][col]) <= R && !visit[row + 1][col]){
                                countries.add(new Country(row + 1, col, map[row + 1][col]));
                                visit[row + 1][col] = true;
                                flag = true;
                            }
                            if(col + 1 < N && Math.abs(country.value - map[row][col + 1]) >= L && Math.abs(country.value - map[row][col + 1]) <= R && !visit[row][col + 1]){
                                countries.add(new Country(row, col + 1, map[row][col + 1]));
                                visit[row][col + 1] = true;
                                flag = true;
                            }
                        }
                        int sum = 0;
                        for(int k = 0; k < countriesList.size(); ++k){
                            sum += countriesList.get(k).value;
                        }
                        sum /= countriesList.size();
                        for(int k = 0; k < countriesList.size(); ++k){
                            Country country = countriesList.get(k);
                            map[country.i][country.j] = sum;
                        }
                    }
                }
            }
        }
        System.out.println(cnt - 1);
    }
}
