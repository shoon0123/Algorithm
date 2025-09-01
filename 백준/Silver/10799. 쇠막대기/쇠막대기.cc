#include <iostream>
#include <stack>
#include <string>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s;
    std::cin >> s;

    std::stack<char> st;
    int result = 0;

    for (size_t i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            st.push('(');
        }
        else
        {
            if (s[i - 1] == '(') // 레이저
            {
                st.pop();
                result += st.size();
            }
            else // 막대 끝
            {
                st.pop();
                result += 1;
            }
        }
    }

    std::cout << result << "\n";
    return 0;
}