#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

int n, m;
int city[50][50];
std::vector<std::pair<int, int>> homes;
std::vector<std::pair<int, int>> chickens;

int getCityChickenDistance(const std::vector<int>& selected)
{
    int total = 0;

    for (const auto& home : homes)
    {
        int minDist = INT_MAX;

        for (int idx : selected)
        {
            int dist = std::abs(home.first - chickens[idx].first) + std::abs(home.second - chickens[idx].second);
            minDist = std::min(minDist, dist);
        }

        total += minDist;
    }

    return total;
}

int main()
{
    std::cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cin >> city[i][j];

            if (city[i][j] == 1)
            {
                homes.push_back({i, j});
            }
            else if (city[i][j] == 2)
            {
                chickens.push_back({i, j});
            }
        }
    }

    int chickenCount = chickens.size();
    std::vector<int> indices(chickenCount, 0);
    std::fill(indices.end() - m, indices.end(), 1);

    int answer = INT_MAX;

    do
    {
        std::vector<int> selected;

        for (int i = 0; i < chickenCount; i++)
        {
            if (indices[i])
            {
                selected.push_back(i);
            }
        }

        int cityDist = getCityChickenDistance(selected);
        answer = std::min(answer, cityDist);
    }
    while (std::next_permutation(indices.begin(), indices.end()));

    std::cout << answer << '\n';

    return 0;
}