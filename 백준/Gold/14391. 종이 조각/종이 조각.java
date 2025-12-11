import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

// 형 근데 최적화 잘하면, 2 x 8도 되겠는데요?
//1시간 43분 고민....
//+ 30분 비트마스킹 공부
//구현 2시간...? 중간에 깜빡하고 시간 안쟀어요 ㅈㅅ..
public class Main {
	public static int n;
	public static int m;
	public static int[][] arr;
	
	//0 가로, 1 세로
	public static int getSum(int bits) {
		int sum = 0;
		
		//가로 계산
		for(int i = 0; i < n; i++) {
			int num = 0;
			for(int j = 0; j < m; j++) {
				 int shift = (n-1-i)*m + j;
				 if((bits&(1 << shift)) == 0) {
					 num = num * 10 + arr[i][j];
				 }else {
					 sum += num;
					 num = 0;
				 }
			}
			sum += num;
		}
		
		//세로 계산
		for(int j = 0; j < m; j++) {
			int num = 0;
			for(int i = 0; i < n; i++) {
				 int shift = (n-1-i)*m + j;
				 if((bits&(1 << shift)) != 0) {
					 num = num * 10 + arr[i][j];
				 }else {
					 sum += num;
					 num = 0;
				 }
			}
			sum += num;
		}
		
		return sum;
	}

	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		
		arr = new int[n][m];
		
		for(int i = 0; i < n; i++) {
			String str = br.readLine();
			for(int j = 0; j < m; j++) {
				arr[i][j] = str.charAt(j) - '0';
			}
		}
		
		int max = 0;
		for(int i = 0; i < (1<<n*m); i++) {
			max = Math.max(max, getSum(i));
		}
		
		System.out.println(max);
		
	}
	
}
