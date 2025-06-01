#include <iostream>
#include <vector>
#include <limits.h>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N, K;
	std::cin >> N >> K;

	int maxValue = INT_MIN;
	
	std::vector <int> vec(N + 1);

	int num;
	for (int i = 1; i <= N; i++)
	{
		std::cin >> num;
		vec[i] = vec[i - 1] + num;
	}
	for (int i = 0; i <= N - K; i++) 
	{
		maxValue = std::max(maxValue, vec[i + K] - vec[i]);
	}
	std::cout << maxValue;

}