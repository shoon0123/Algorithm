#include <iostream>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N;
    std::cin >> N;
    std::vector<int> vec(N, 0);
    for (int i = 0; i < N; ++i) {
        std::cin >> vec[i];
    }
    for (int i = 1; i < N; ++i) {
        for (int j = 0; j < i; ++j) {
            if (vec[i] < vec[j]) {
                int tmp = vec[i];
                vec.erase(vec.begin() + i);
                vec.insert(vec.begin() + j, tmp);
            }
        }
    }
    int sum = 0;
    for (int i = 0; i < N; ++i) {
        sum += vec[i] * (N - i);
    }
    std::cout << sum << '\n';
}