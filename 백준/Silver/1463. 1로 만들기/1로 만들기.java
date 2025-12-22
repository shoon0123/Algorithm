import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

	public static void main(String[] args) throws NumberFormatException, IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		
		int[] arr = new int[N+1];
		for(int i = 1; i <= N; i++) {
			arr[i] = (int)1e6;
		}
		arr[1] = 0;
		for(int i = 1; i < N; i++) {
			arr[i+1] = Math.min(arr[i+1], arr[i]+1);
			
			if(i*2 > N) continue;
			arr[i*2] = Math.min(arr[i*2], arr[i]+1);
			
			if(i*3 > N) continue;
			arr[i*3] = Math.min(arr[i*3], arr[i]+1);
		}
		
		System.out.println(arr[N]);
		
	}

}
