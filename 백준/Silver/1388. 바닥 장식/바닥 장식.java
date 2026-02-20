import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        char[][] arr = new char[N][M];

        for(int i = 0; i < N; i++){
            String s = br.readLine();
            for(int j = 0; j < M; j++) {
                arr[i][j] = s.charAt(j);
            }
        }

        int count = 0;
        boolean flag;
        for(int i = 0; i < N; i++){
            flag = false;
            for(int j = 0; j < M; j++) {
                if(arr[i][j] == '-'){
                    if(flag)continue;
                    count++;
                    flag = true;
                }else{
                    flag = false;
                }
            }
        }

        for(int j = 0; j < M; j++){
            flag = false;
            for(int i = 0; i < N; i++) {
                if(arr[i][j] == '|'){
                    if(flag)continue;
                    count++;
                    flag = true;
                }else{
                    flag = false;
                }
            }
        }

        System.out.println(count);
    }
}
