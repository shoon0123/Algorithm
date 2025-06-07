#include <iostream>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N;
	std::cin >> N;

	bool black[100][100];

	for (int i = 0; i < 100; ++i)
	{
		for (int j = 0; j < 100; ++j)
		{
			black[i][j] = false;
		}
	}

	int x, y;
	for (int i = 0; i < N; ++i)
	{
		std::cin >> x >> y;
		for (int j = x; j < x + 10; ++j)
		{
			for (int k = y; k < y + 10; ++k)
			{
				black[j][k] = true;
			}
		}
	}
	int count = 0;
	for (int i = 0; i < 100; ++i)
	{
		for (int j = 0; j < 100; ++j)
		{
			if (black[i][j])
			{
				++count;
			}
		}
	}
	std::cout << count;
}