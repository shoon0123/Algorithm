#include <iostream>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;
    std::vector<long long> arr(N);

    long long sum = 0, sqSum = 0;
    for (int i = 0; i < N; i++)
    {
        std::cin >> arr[i];
        sum += arr[i];
        sqSum += arr[i] * arr[i];
    }

    long long result = (sum * sum - sqSum) / 2;
    std::cout << result << "\n";

    return 0;
}