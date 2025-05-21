#include <iostream>
#include <vector>
#include <queue>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

	int N, x;
	std::cin >> N;

	while (N--) 
	{
		std::cin >> x;
		if (x == 0) 
		{
			if (pq.empty()) 
			{
				std::cout << 0 << "\n";
			}
			else 
			{
				std::cout << pq.top() << "\n";
				pq.pop();
			}
		}
		else 
		{
			pq.push(x);
		}
	}
}