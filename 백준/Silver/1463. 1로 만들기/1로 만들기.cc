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
	std::vector<int> vec;
	vec.resize(N + 1);
	vec[1] = 0;

	for (int i = 2; i <= N; ++i)
	{
		vec[i] = vec[i - 1] + 1;
		if (i % 2 == 0)
		{
			vec[i] = std::min(vec[i], vec[i / 2] + 1);
		}
		if (i % 3 == 0)
		{
			vec[i] = std::min(vec[i], vec[i / 3] + 1);
		}
	}
	std::cout << vec[N];
}