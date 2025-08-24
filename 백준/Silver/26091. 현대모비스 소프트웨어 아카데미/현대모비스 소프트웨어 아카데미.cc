#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N, M;
    std::cin >> N >> M;

    std::vector<int> skills(N);
    for (int i = 0; i < N; i++)
    {
        std::cin >> skills[i];
    }

    std::sort(skills.begin(), skills.end());

    int left = 0;
    int right = N - 1;
    int teams = 0;

    while (left < right)
    {
        if (skills[left] + skills[right] >= M)
        {
            teams++;
            left++;
            right--;
        }
        else
        {
            left++;
        }
    }

    std::cout << teams << "\n";

    return 0;
}