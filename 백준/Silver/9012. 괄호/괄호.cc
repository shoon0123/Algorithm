#include <iostream>
#include <string>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N;
    std::cin >> N;
    std::string s;

    int left;
    bool isVPS;
    while(N--)
    {
        left = 0;
        isVPS = true;
        std::cin >> s;
        for (const char& c : s)
        {
            if (c == '(')
            {
                ++left;
            }
            else if(left == 0)
            {
                isVPS = false;
                break;
            }
            else
            {
                --left;
            }
        }
        if (left != 0)
        {
            isVPS = false;
        }

        std::cout << (isVPS ? "YES" : "NO") << "\n";
    }

        


}