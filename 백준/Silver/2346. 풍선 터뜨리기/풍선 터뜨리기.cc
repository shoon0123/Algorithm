#include <iostream>
#include <deque>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    std::deque<std::pair<int,int>> dq;
    for (int i = 1; i <= N; i++)
    {
        int num;
        std::cin >> num;
        dq.push_back({i, num});
    }

    while (!dq.empty())
    {
        int idx = dq.front().first;
        int move = dq.front().second;
        dq.pop_front();

        std::cout << idx << " ";

        if (dq.empty()) break;

        if (move > 0)
        {
            for (int i = 0; i < move - 1; i++)
            {
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }
        else
        {
            for (int i = 0; i < -move; i++)
            {
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
    }
    return 0;
}