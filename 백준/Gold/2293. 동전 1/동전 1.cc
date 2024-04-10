#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n, k;
	std::cin >> n >> k;
	std::vector<int> coins(n);
	for (int& coin : coins)
	{
		std::cin >> coin;
	}
	std::sort(coins.begin(), coins.end());
	std::vector<int> answer(k + 1,0);

	for (int j = 1; j <= k; ++j)
	{
		if (j % coins[0] == 0)
		{
			answer[j] += 1;
		}
	}

	for (int i = 1; i < n; ++i)
	{
		for (int j = k; j >= 1; --j)
		{	
			int mogs = j / coins[i];
			if (j % coins[i] == 0)
			{
				answer[j] += 1;
			}
			for (int l = 1; l <= mogs; ++l)
			{
				answer[j] += answer[j - coins[i] * l];
			}
		}
		
	}
	std::cout << answer[k];
}