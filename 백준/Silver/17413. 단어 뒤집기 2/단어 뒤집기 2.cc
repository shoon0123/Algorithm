#include <iostream>
#include <string>
#include <stack>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

   
    std::string str;
    std::stack<char> stack;

    getline(std::cin, str);

    bool bBracket = false;
    for (const char& c : str)
    {
        if (c == '<')
        {
            while (!stack.empty())
            {
                std::cout << stack.top();
                stack.pop();
            }
            std::cout << c;
            bBracket = true;
        }
        else if (c == '>')
        {
            std::cout << c;
            bBracket = false;
        }
        else if (bBracket)
        {
            std::cout << c;
            continue;
        }
        else if (c == ' ')
        {
            while (!stack.empty())
            {
                std::cout << stack.top();
                stack.pop();
            }
            std::cout << " ";
        }
        else
        {
            stack.push(c);
        }
    }
    while (!stack.empty())
    {
        std::cout << stack.top();
        stack.pop();
    }
    std::cout << " ";

    return 0;
}