#include <iostream>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N, M;
    std::cin >> N >> M;
    std::vector<long long> prefixSum(N + 1);
    std::vector<long long> count(M, 0);

    long long result = 0;
    int num;

    for (int i = 1; i <= N; i++) {
        std::cin >> num;
        prefixSum[i] = (prefixSum[i - 1] + num) % M;
        count[prefixSum[i]]++;
    }

    result += count[0];

    for (int i = 0; i < M; i++) {
        result += count[i] * (count[i] - 1) / 2;
    }

    std::cout << result << "\n";
}
