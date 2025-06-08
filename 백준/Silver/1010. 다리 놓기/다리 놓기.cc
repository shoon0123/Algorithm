#include <iostream>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int T; 
	std::cin >> T;

	while (T--) {
		int N, M; 
		std::cin >> N >> M;
		long long result = 1;

		if (N > M / 2)
		{
			N = M - N;
		}
		for (int i = M; i > M - N; i--)
		{
			result *= i;
		}
		for (int i = 1; i <= N; i++)
		{
			result /= i;
		}
		std::cout << result << "\n";
	}

	return 0;

}