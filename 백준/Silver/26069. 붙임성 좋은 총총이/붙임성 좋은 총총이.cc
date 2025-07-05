#include <iostream>
#include <string>
#include <set>


int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int n;
    std::cin >> n;

    std::string str1;
    std::string str2;
    std::set<std::string> strSet;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> str1 >> str2;
        if (str1 == "ChongChong")
        {
            strSet.insert(str2);
        }
        else if (str2 == "ChongChong")
        {
            strSet.insert(str1);
        }
        else if (strSet.find(str1)!=strSet.end())
        {
            strSet.insert(str2);
        }
        else if (strSet.find(str2) != strSet.end())
        {
            strSet.insert(str1);
        }
    }
    std::cout << strSet.size() + 1;
}