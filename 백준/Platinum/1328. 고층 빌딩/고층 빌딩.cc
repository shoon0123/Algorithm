#include <iostream>
#include <vector>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N, L, R;
	std::cin >> N >> L >> R;
	std::vector<std::vector<std::vector<int>>> DP(N + 1);
	DP[1].resize(3, std::vector<int>(3));
	DP[1][1][1] = 1;
	for (int i = 2; i <= N; ++i)
	{
		DP[i].resize(i + 2, std::vector<int>(i + 2));
		for (int j = 1; j <= i; ++j)
		{
			for (int k = 1; k <= i + 1 - j; ++k)
			{
				DP[i][j][k] = static_cast<int>((static_cast<long>(DP[i - 1][j][k]) * (i - 2) + DP[i - 1][j - 1][k] + DP[i - 1][j][k - 1]) % 1000000007);
			}
		}
	}
	std::cout << DP[N][L][R];
}