#include <iostream>
#include <vector>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N;
	std::cin >> N;

	std::vector<int> vec(3);

	vec[0] = 1;
	vec[1] = 2;
	for (int i = 2; i < N; ++i)
	{
		vec[i % 3] = (vec[(i - 1) % 3] + vec[(i - 2) % 3]) % 15746;
	}

	std::cout << vec[(N - 1) % 3];

}