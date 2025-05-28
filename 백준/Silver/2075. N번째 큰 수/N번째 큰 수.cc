#include <iostream>
#include <vector>
#include <queue>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

	int N;
	std::cin >> N;
	int num;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			std::cin >> num;
			pq.push(num); 
			if (pq.size() > N)
			{
				pq.pop();
			}
		}
	}
	std::cout << pq.top();

}