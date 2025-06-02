#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n;
	std::cin >> n;
	std::vector<int> vec(n);
	for (int i = 0; i < n; ++i)
	{
		std::cin >> vec[i];
	}
	std::sort(vec.begin(), vec.end());

	int x;
	std::cin >> x;

	int left = 0;
	int right = n - 1;
	int count = 0;

	while (left < right)
	{
		const int& sum = vec[left] + vec[right];

		if (sum < x)
		{
			++left;
		}
		else if (sum > x)
		{
			--right;
		}
		else
		{
			++count;
			++left;
			--right;
		}
	}
	std::cout << count;

}