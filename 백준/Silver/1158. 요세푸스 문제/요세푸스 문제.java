
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        LinkedList<Integer> list = new LinkedList<Integer>();
        LinkedList<Integer> answerList = new LinkedList<Integer>();
        for(int i = 1; i <= N; i++){
            list.add(i);
        }

        int idx = 0;
        while(N> 0){
            idx+=K-1;
            idx%=N;
            answerList.add(list.get(idx));
            list.remove(idx);
            N--;
        }

        StringBuilder sb = new StringBuilder();
        sb.append("<");

        for(Integer i : answerList){
            sb.append(i).append(", ");
        }

        sb.delete(sb.length()-2,sb.length());
        sb.append(">");

        System.out.print(sb);

    }
}
