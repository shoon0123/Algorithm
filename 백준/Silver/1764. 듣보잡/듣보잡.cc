#include <iostream>
#include <set>
#include <string>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N, M;
    std::cin >> N >> M;

    std::set<std::string> strSet;
    std::string str;
    while (N--)
    {
        std::cin >> str;
        strSet.insert(str);
    }
    std::set<std::string> answerSet;
    while (M--)
    {
        std::cin >> str;
        if (strSet.find(str) != strSet.end())
        {
            answerSet.insert(str);
        }
    }

    std::cout << answerSet.size() << "\n";
    for (const std::string& str : answerSet)
    {
        std::cout << str << "\n";
    }
}