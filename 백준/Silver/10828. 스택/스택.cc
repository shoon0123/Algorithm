#include <iostream>
#include <stack>
#include <string>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL );

    int commandCount;
    std::cin >> commandCount;

    std::stack<int> stack;

    for (int i = 0; i < commandCount; ++i)
    {
        std::string command;
        std::cin >> command;

        if (command == "push")
        {
            int value;
            std::cin >> value;
            stack.push(value);
        }
        else if (command == "pop")
        {
            if (stack.empty())
            {
                std::cout << -1 << '\n';
            }
            else
            {
                std::cout << stack.top() << '\n';
                stack.pop();
            }
        }
        else if (command == "size")
        {
            std::cout << stack.size() << '\n';
        }
        else if (command == "empty")
        {
            std::cout << (stack.empty() ? 1 : 0) << '\n';
        }
        else if (command == "top")
        {
            if (stack.empty())
            {
                std::cout << -1 << '\n';
            }
            else
            {
                std::cout << stack.top() << '\n';
            }
        }
    }

    return 0;
}