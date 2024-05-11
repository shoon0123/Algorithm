#include <iostream>
#include <vector>

int main()
{
	int N, K;
	std::cin >> N >> K;
	std::vector<std::vector<int>> D(N+1, std::vector<int>(N+1));

	for (int i = 0; i <= N; ++i)
	{
		D[i][0] = 1;
		D[i][1] = i;
		D[i][i] = 1;
	}

	for (int i = 2; i <= N; ++i)
	{
		for (int j = 1; j < i; ++j)
		{
			D[i][j] = (D[i - 1][j] + D[i - 1][j - 1]) % 10007;
		}
	}
	std::cout << D[N][K];
}