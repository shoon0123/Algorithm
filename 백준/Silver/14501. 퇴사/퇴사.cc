#include <iostream>
#include <vector>
#include <cmath>
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N;
	std::cin >> N;
	std::vector<std::pair<int, int>> schedule(N + 1);
	for (int i = 1; i <= N; ++i)
	{
		int days, pay;
		std::cin >> days >> pay;
		schedule[i] = std::make_pair(days, pay);
	}
	std::vector<int> D(N + 2, 0);
	
	for (int i = 1; i <= N; ++i)
	{
		D[i] = std::max(D[i], D[i - 1]);
		int dayAfterWork = i + schedule[i].first;
		if (dayAfterWork <= N + 1)
		{
			int moneyAfterWork = D[i] + schedule[i].second;
			D[dayAfterWork] = std::max(moneyAfterWork, D[dayAfterWork]);
		}
	}
	D[N + 1] = std::max(D[N], D[N + 1]);
	std::cout << D[N + 1];
}