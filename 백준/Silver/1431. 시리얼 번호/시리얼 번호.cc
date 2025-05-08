#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int cmp(std::string aString, std::string bString)
{
    // 1.길이가 짧은 것이 먼저
    const int aSize = aString.size();
    const int bSize = bString.size();
    if (aSize != bSize)
    {
        return aSize < bSize;
    }
    // 2.숫자의 합이 작은 것이 먼저 
    int aSum = 0;
    int bSum = 0;
    for (const char& c : aString)
    {
        if (c >= '0' && c <= '9')
        {
            aSum += c - '0';
        }
    }
    for (const char& c : bString)
    {
        if (c >= '0' && c <= '9')
        {
            bSum += c - '0';
        }
    }
    if (aSum != bSum)
    {
        return aSum < bSum;
    }
    // 3.사전순
    return aString < bString;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N;
    std::cin >> N;
    std::vector<std::string> guitars(N);
    for (int i = 0; i < N; ++i)
    {
        std::cin >> guitars[i];
    }

    std::sort(guitars.begin(), guitars.end(), cmp);

    for (int i = 0; i < N; ++i)
    {
        std::cout << guitars[i] << "\n";
    }
}