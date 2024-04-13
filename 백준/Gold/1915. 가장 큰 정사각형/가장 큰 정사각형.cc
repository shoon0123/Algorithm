#include <iostream>
#include <vector>
#include <cmath>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N, M;;
	std::cin >> N >> M;
	std::vector<std::vector<int>> DP(N + 1, std::vector<int>(M + 1));
	
	int maxNum = 0;

	for (int i = 1; i <= N; ++i)
	{
		std::string S;
		std::cin >> S;
		for (int j = 1; j <= M; ++j)
		{
			DP[i][j] = S[j - 1] - '0';

			if (DP[i][j] == 1)
			{
				DP[i][j] = std::min(DP[i - 1][j - 1], std::min(DP[i][j - 1], DP[i - 1][j])) + 1;
				maxNum = std::max(maxNum, DP[i][j]);
			}
			else
			{
				DP[i][j] = 0;
			}
		}
	}
	std::cout << maxNum * maxNum;
}