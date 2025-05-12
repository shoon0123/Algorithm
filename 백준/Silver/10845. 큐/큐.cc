#include <iostream>
#include <queue>
#include <string>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N;
    std::cin >> N;
    std::string s;
    std::queue<int> q;

    int num;

    while (N--)
    {
        std::cin >> s;
        if (s == "push")
        {
            std::cin >> num;
            q.push(num);
        }
        else if (s == "size")
        {
            std::cout << q.size() << "\n";
        }
        else if (s == "empty")
        {
            std::cout << (q.size() == 0 ? 1 : 0) << "\n";
        }
        else if (q.size() == 0)
        {
            std::cout << -1 << "\n";
        }
        else if (s == "pop")
        {
            std::cout << q.front() << "\n";
            q.pop();
        }
        else if (s == "front")
        {
            std::cout << q.front() << "\n";
        }
        else if (s == "back")
        {
            std::cout << q.back() << "\n";
        }
    }

}