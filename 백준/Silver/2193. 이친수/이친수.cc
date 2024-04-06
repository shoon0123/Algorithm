#include <iostream>
#include <vector>
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N;
	std::cin >> N;
	std::vector<std::pair<long,long>> D(N+1);
	D[1] = std::make_pair(0, 1);

	for (int i = 2; i <= N; ++i)
	{
		D[i] = std::make_pair(D[i - 1].first + D[i - 1].second, D[i - 1].first);
	}
	std::cout << D[N].first + D[N].second;
}