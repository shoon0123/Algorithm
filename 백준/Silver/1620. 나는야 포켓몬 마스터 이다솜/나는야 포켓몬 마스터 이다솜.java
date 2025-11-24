
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		
		Map<String, Integer> strInt = new HashMap<>();
		Map<Integer, String> intStr = new HashMap<>();
		
		int i = 1;
		while(n-- > 0) {
			String str = br.readLine();
			strInt.put(str, i);
			intStr.put(i, str);
			i++;
		}
		while(m-- > 0) {
			String str = br.readLine();
			//정확한 방법은 아님
			if(str.charAt(0) <='9' && str.charAt(0) >='0') {
				System.out.println(intStr.get(Integer.parseInt(str)));
			} else {
				System.out.println(strInt.get(str));
			}
		}
	}

}
