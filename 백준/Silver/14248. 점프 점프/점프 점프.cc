#include <iostream>
#include <vector>
#include <queue>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    std::vector<int> arr(N + 1);
    for (int i = 1; i <= N; i++)
    {
        std::cin >> arr[i];
    }

    int S;
    std::cin >> S;

    std::vector<bool> visited(N + 1, false);
    std::queue<int> q;
    q.push(S);
    visited[S] = true;

    int count = 0;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        count++;

        int left = cur - arr[cur];
        int right = cur + arr[cur];

        if (left >= 1 && !visited[left])
        {
            visited[left] = true;
            q.push(left);
        }
        if (right <= N && !visited[right])
        {
            visited[right] = true;
            q.push(right);
        }
    }

    std::cout << count << "\n";
    return 0;
}