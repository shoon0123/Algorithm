#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n, m;
	std::cin >> n >> m;
	std::vector<long> A(n + 1, 0);

	if (n > 0)
	{
		std::cin >> A[1];
	}
	for (int i = 2; i <= n; ++i)
	{
		std::cin >> A[i];
		A[i] += A[i - 1];
	}

	int start = 1;
	int end = m;
	long maxValue = 0;
	while (end <= n)
	{
		maxValue = std::max(maxValue, A[end] - A[start - 1]);
		++start;
		++end;
	}
	std::cout << maxValue;
}