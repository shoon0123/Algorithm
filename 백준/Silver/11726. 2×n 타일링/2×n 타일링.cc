#include <iostream>
#include <vector>
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N;
	std::cin >> N;
	std::vector<int> D(N + 2);
	D[1] = 1;
	D[2] = 2;
	for (int i = 3; i <= N; ++i)
	{
		D[i] = D[i - 1] + D[i - 2];
		D[i] %= 10007;
	}
	std::cout << D[N];
}