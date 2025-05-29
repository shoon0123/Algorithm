#include <iostream>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int X, count = 0;
	std::cin >> X;
	while (X > 0)
	{
		if (X % 2 == 1)
		{
			count++;
		}
		X /= 2;
	}
	std::cout << count;

}