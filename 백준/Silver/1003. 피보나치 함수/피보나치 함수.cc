#include <iostream>
#include <vector>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int T;
	std::cin >> T;

	std::vector<std::pair<int, int>> vec(41);

	vec[0] = std::make_pair(1, 0);
	vec[1] = std::make_pair(0, 1);
	for (int i = 2; i <= 40; ++i)
	{
		vec[i] = std::make_pair(vec[i - 2].first + vec[i - 1].first, vec[i - 2].second + vec[i - 1].second);
	}

	int n;
	while (T--)
	{
		std::cin >> n;
		std::cout << vec[n].first << " " << vec[n].second << "\n";
	}
}