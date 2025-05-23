#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int N;
	std::cin >> N;
	std::vector<int> budget(N);

	for (int i = 0; i < N; i++)
	{
		std::cin >> budget[i];
	}
    int M;
    std::cin >> M;

	std::sort(budget.begin(), budget.end());

    int start = 0;
    int end = budget[N - 1];
    int maxValue, sum;
    while (start <= end) 
    {
        sum = 0;
        int mid = (start + end) / 2;
        for (int i = 0; i < N; i++)
        {
            sum += std::min(budget[i], mid);
        }
        if (M < sum) 
        {
            end = mid - 1;
        }
        else 
        {
            maxValue = mid;
            start = mid + 1;
        }
    }

    std::cout << maxValue;
}