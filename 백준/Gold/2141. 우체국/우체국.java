import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Map.Entry;
import java.util.StringTokenizer;
import java.util.TreeMap;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		int n = Integer.parseInt(br.readLine());
		long sum = 0;
		TreeMap<Integer, Integer> map = new TreeMap<>();
		for(int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
		
			int x = Integer.parseInt(st.nextToken());
			int a = Integer.parseInt(st.nextToken());
			
			map.merge(x, a, (v1,v2)->v1+v2);
			sum += a;			
		}
		if(sum%2==1)sum++;
		sum /= 2;
		for(Entry<Integer,Integer> entry : map.entrySet()) {
			sum -= entry.getValue();
			if(sum <= 0) {
				System.out.println(entry.getKey());
				break;
			}
		}
	}
}
