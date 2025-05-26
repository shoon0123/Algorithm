#include <iostream>
#include <string>
#include <set>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::string S;
    std::cin >> S;

    std::set<std::string> strSet;
    std::string str;

    for (int i = 0; i < S.size(); ++i)
    {
        str = "";
        for (int j = i; j < S.size(); ++j)
        {
            str += S[j];
            strSet.insert(str);
        }
    }

    std::cout << strSet.size();
}