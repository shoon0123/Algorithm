#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

struct Lecture
{
    int start;
    int end;
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    std::vector<Lecture> lectures(N);
    for (int i = 0; i < N; i++)
    {
        int idx, s, t;
        std::cin >> idx >> s >> t;
        lectures[i] = {s, t};
    }

    std::sort(lectures.begin(), lectures.end(), [](const Lecture &a, const Lecture &b)
    {
        return a.start < b.start;
    });

    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

    for (auto &lec : lectures)
    {
        if (!pq.empty() && pq.top() <= lec.start)
        {
            pq.pop();
        }
        pq.push(lec.end);
    }

    std::cout << pq.size() << "\n";
    return 0;
}