#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int k;
char sign[10];
bool used[10];
std::string maxNum = "0", minNum = "9999999999";

bool valid(char a, char b, char op)
{
    if (op == '<') return a < b;
    if (op == '>') return a > b;
    return false;
}

void dfs(int depth, std::string num)
{
    if (depth == k + 1)
    {
        if (maxNum < num) maxNum = num;
        if (minNum > num) minNum = num;
        return;
    }

    for (int i = 0; i <= 9; i++)
    {
        if (used[i]) continue;

        if (depth == 0 || valid(num[depth - 1], i + '0', sign[depth - 1]))
        {
            used[i] = true;
            dfs(depth + 1, num + (char)(i + '0'));
            used[i] = false;
        }
    }
}

int main()
{
    std::cin >> k;
    for (int i = 0; i < k; i++)
    {
        std::cin >> sign[i];
    }

    dfs(0, "");

    std::cout << maxNum << "\n" << minNum << "\n";
}
