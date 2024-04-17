#include <iostream>
#include <vector>
#include <cmath>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N;
	std::cin >> N;
	std::vector<int> numbers(N);
	for (int& i : numbers)
	{
		std::cin >> i;
	}
	std::vector<int> maxFromFront(N);
	maxFromFront[0] = numbers[0];
	int result = maxFromFront[0];
	for (int i = 1; i < N; ++i)
	{
		maxFromFront[i] = std::max(numbers[i], maxFromFront[i - 1] + numbers[i]);
		result = std::max(result, maxFromFront[i]);
	}
	std::vector<int> maxFromBack(N);
	maxFromBack[N - 1] = numbers[N - 1];
	for (int i = N - 2; i >= 0; --i)
	{
		maxFromBack[i] = std::max(numbers[i], maxFromBack[i + 1] + numbers[i]);
	}
	for (int i = 1; i < N - 1; ++i)
	{
		result = std::max(result, maxFromFront[i - 1] + maxFromBack[i + 1]);
	}
	std::cout << result;
}