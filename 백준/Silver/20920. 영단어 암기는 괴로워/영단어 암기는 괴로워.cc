#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

std::map<std::string, int> strMap;

int cmp(std::string aString, std::string bString)
{
    //1.자주 나오는 단어일수록 먼저
    if (strMap[aString] != strMap[bString])
    {
        return strMap[aString] > strMap[bString];
    }

    // 2.길이가 긴 것이 먼저
    const int aSize = aString.size();
    const int bSize = bString.size();
    if (aSize != bSize)
    {
        return aSize > bSize;
    }
    // 3.알파벳 사전 순
    return aString < bString;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N, M;
    std::cin >> N >> M;
    std::string str;
    for (int i = 0; i < N; ++i)
    {
        std::cin >> str;
        if (str.size() < M)
        {
            continue;
        }
        if (strMap.find(str) == strMap.end())
        {
            strMap[str] = 1;
        }
        else
        {
            strMap[str]++;
        }
    }
    std::vector<std::string> strVec;
    for (const std::pair<std::string,int>& strInt : strMap)
    {
        strVec.push_back(strInt.first);
    }

    std::sort(strVec.begin(), strVec.end(), cmp);

    for (const std::string& str : strVec)
    {
        std::cout << str << "\n";
    }
}