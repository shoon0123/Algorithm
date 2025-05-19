#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N;
	std::cin >> N;
	std::vector<int> vec(N);

	for (int i = 0; i < N; i++) {
		std::cin >> vec[i];
	}
	std::sort(vec.begin(), vec.end());
	std::cout << vec[0] * vec[N - 1];
}