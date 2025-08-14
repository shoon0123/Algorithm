#include <iostream>
#include <unordered_set>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T, N, M;
    std::cin >> T;

    std::unordered_set<int> intSet;
    while (T--)
    {
        std::cin >> N;
        while (N--)
        {
            int n;
            std::cin >> n;
            intSet.insert(n);
        }
        std::cin >> M;
        while (M--)
        {
            int n;
            std::cin >> n;
            const int result = intSet.find(n) == intSet.end() ? 0 : 1;
            std::cout << result << "\n";
        }
        intSet.clear();
    }

    return 0;
}