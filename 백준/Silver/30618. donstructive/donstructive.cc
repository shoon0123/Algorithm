#include <iostream>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N;
	std::cin >> N;

	int i = 0;
	while (i * 2 + 1<= N)
	{
		std::cout << i * 2 + 1 << ' ';
		++i;
	}
	if (i * 2 > N)
	{
		--i;
	}
	while (i > 0)
	{
		std::cout << i * 2 << ' ';
		--i;
	}

}