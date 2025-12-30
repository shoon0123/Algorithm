import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int n = Integer.parseInt(br.readLine());
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		ArrayDeque<Integer> stack = new ArrayDeque<Integer>();
		int target = 1;
		for(int i = 0; i < n; i++) {
			int num = Integer.parseInt(st.nextToken());
			if(num == target) {
				target++;
				while(!stack.isEmpty()) {
					int top = stack.getFirst();
					if(top == target) {
						stack.pop();
						target++;
					}else {
						break;
					}
				}
			}else {
				stack.push(num);
			}
		}
		String answer = stack.isEmpty() ? "Nice" : "Sad";
		System.out.println(answer);
	}

}
