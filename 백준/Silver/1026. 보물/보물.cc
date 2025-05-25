#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N;
    std::cin >> N;
    std::vector<int> A(N);
    std::vector<int> B(N);

    int x, y;
    for (int i = 0; i < N; ++i)
    {
        std::cin >> A[i];
    }
    for (int i = 0; i < N; ++i)
    {
        std::cin >> B[i];
    }
    std::sort(A.begin(), A.end());
    std::sort(B.begin(), B.end(), std::greater<>());

    int sum = 0;
    for (int i = 0; i < N; ++i)
    {
        sum += A[i] * B[i];
    }

    std::cout << sum;
}