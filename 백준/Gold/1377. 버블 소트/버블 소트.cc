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
    std::vector<std::pair<int,int>> A(N);

    for (int i = 0; i < N; ++i) {
        std::cin >> A[i].first;
        A[i].second = i;
    }
    sort(A.begin(), A.end());
    int max = 0;
    for (int i = 0; i < N; ++i) {
        if (max < A[i].second - i) {
            max = A[i].second - i;
        }
    }
    std::cout << max+1 << '\n';
}