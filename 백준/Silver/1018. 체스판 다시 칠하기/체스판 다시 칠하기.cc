#include <iostream>
#include <limits.h>

char arr[50][50];

int checkWhite(int y, int x)
{
	int count = 0;
	for (int i = y; i < y + 8; ++i)
	{
		for (int j = x; j < x + 8; ++j)
		{
			if ((i + j) % 2 == 0 && arr[i][j] == 'B')
			{
				++count;
			}
			else if ((i + j) % 2 == 1 && arr[i][j] == 'W')
			{
				++count;
			}
		}
	}
	return count;
}

int checkBlack(int y, int x)
{
	int count = 0;
	for (int i = y; i < y + 8; ++i)
	{
		for (int j = x; j < x + 8; ++j)
		{
			if ((i + j) % 2 == 0 && arr[i][j] == 'W')
			{
				++count;
			}
			else if ((i + j) % 2 == 1 && arr[i][j] == 'B')
			{
				++count;
			}
		}
	}
	return count;
}

int main()
{

	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N, M;
	std::cin >> N >> M;
	int minValue = INT_MAX;

	for (int i = 0; i < N; ++i)
	{ 
		for (int j = 0; j < M; ++j)
		{
			std::cin >> arr[i][j];
		}
	}

	for (int i = 0; i <= N-8; ++i)
	{
		for (int j = 0; j <= M-8; ++j)
		{
			minValue = std::min(minValue, checkBlack(i, j));
			minValue = std::min(minValue, checkWhite(i, j));
		}
	}
	
	std::cout << minValue;

}