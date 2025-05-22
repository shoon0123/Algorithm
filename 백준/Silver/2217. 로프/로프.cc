#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int N;	
	std::cin >> N;
	std::vector<int> rope(N);
	for (int i = 0; i < N; i++) 
	{
		std::cin >> rope[i];
	}
	std::sort(rope.begin(), rope.end());
	int cur, max;
	max = rope[0];
	for (int i = N - 1; i >= 0; i--) 
	{
		cur = rope[i] * (N - i);
		if (max < cur) 
		{	
			max = cur;	
		}
	}

	std::cout << max;

	return 0;
}