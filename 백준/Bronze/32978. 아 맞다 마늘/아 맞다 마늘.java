import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());

        Set<String> set = new HashSet<>();
        for(int i = 0; i < n; i++){
            set.add(st.nextToken());
        }
        st = new StringTokenizer(br.readLine());

        while(st.hasMoreTokens()){
            set.remove(st.nextToken());
        }

        for(String s : set){
            System.out.println(s);
        }
    }
}
