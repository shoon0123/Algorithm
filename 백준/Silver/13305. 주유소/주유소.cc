#include <iostream>
#include <vector>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N;
	std::cin >> N;

	std::vector<int> edges(N-1);
	std::vector<int> prices(N);

	for (int i = 0; i < N - 1; ++i)
	{
		std::cin >> edges[i];
	}
	for (int i = 0; i < N; ++i)
	{
		std::cin >> prices[i];
	}
	int curPrice = 1000000000;
	int sum = 0;
	for (int i = 0; i < N - 1; ++i)
	{
		if (curPrice > prices[i])
		{
			curPrice = prices[i];
		}
		sum += curPrice * edges[i];
	}
	std::cout << sum;

}