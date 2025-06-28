#include <iostream>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int t;
    std::cin >> t;
    
    int n;

    std::vector<int> vec(1001,-1);
    std::vector<bool> visited(1001, false);

    int count;
    int curNode;
    while (t--)
    {
        std::cin >> n;
        count = 0;
        for (int i = 1; i <= n; i++)
        {
            std::cin >> vec[i];
        }

        for (int i = 1; i <= n; i++)
        {
            if (visited[i])
            {
                continue;
            }
            curNode = i;
            while (!visited[curNode])
            {
                visited[curNode] = true;
                curNode = vec[curNode];
            }
            count++;
        }
        std::cout << count << "\n";

        for (int i = 1; i <= n; i++)
        {
            visited[i] = false;
        }
    }

}