#include <iostream>
#include <stack>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> line(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> line[i];
    }

    std::stack<int> side;
    int next = 1;
    for (int i = 0; i < n; ++i) 
    {
        const int& current = line[i];
        while (!side.empty() && side.top() == next) 
        {
            side.pop();
            next++;
        }
        if (current == next) 
        {
            next++;
        }
        else 
        {
            side.push(current);
        }
    }

    while (!side.empty() && side.top() == next) 
    {
        side.pop();
        next++;
    }

    if (side.empty()) 
    {
        std::cout << "Nice";
    }
    else 
    {
        std::cout << "Sad";
    }

    return 0;
}