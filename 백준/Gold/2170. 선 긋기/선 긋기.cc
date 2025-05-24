#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N;
    std::cin >> N;
    std::vector<std::pair<int, int>> lines(N);

    int x, y;
    for (int i = 0; i < N; ++i)
    {
        std::cin >> x >> y;
        lines[i] = std::make_pair(x, y);
    }
    std::sort(lines.begin(), lines.end());

    int left= -1000000000;
    int right = -1000000000;
    int length = 0;
    for (int i = 0; i < N; ++i)
    {
        if (lines[i].first > right)
        {
            length += right - left;
            left = lines[i].first;
            right = lines[i].second;
        }
        else
        {
            right = std::max(right, lines[i].second);
        }
    }
    length += right - left;

    std::cout << length;
}