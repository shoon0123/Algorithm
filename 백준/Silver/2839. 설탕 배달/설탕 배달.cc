#include <iostream>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n;
	std::cin >> n;
	for (int i = n / 5; i >= 0; --i)
	{
		const int& m = n - 5 * i;
		if (m % 3 == 0)
		{
			std::cout << i + m / 3;
			return 0;
		}
	}
	std::cout << -1;
	return 0;

}