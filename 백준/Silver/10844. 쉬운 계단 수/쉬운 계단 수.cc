#include <iostream>
#include <vector>

int sum(std::vector<int> vec)
{
	int sum = 0;
	for (const int& i : vec)
	{
		sum += i;
		sum %= 1000000000;
	}
	return sum;
}
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N;
	std::cin >> N;
	std::vector<std::vector<int>> D(N + 1, std::vector<int>(10));
	D[1] = { 0,1,1,1,1,1,1,1,1,1 };
	for (int i = 2; i <= N; ++i)
	{
		D[i][0] = D[i - 1][1];
		D[i][0] %= 1000000000;
		for (int j = 1; j <= 8; ++j)
		{
			D[i][j] = D[i - 1][j - 1] + D[i - 1][j + 1];
			D[i][j] %= 1000000000;
		}
		D[i][9] = D[i - 1][8];
		D[i][9] %= 1000000000;
	}
	std::cout << sum(D[N]);
}