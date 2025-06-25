#include <iostream>

void isStar(int i, int j, int n)
{
    if ((i / n) % 3 == 1 && (j / n) % 3 == 1) 
    {
        std::cout << ' ';
    }
    else
    {
        if (n / 3 == 0)
        {
            std::cout << '*';
        }
        else
        {
            isStar(i, j, n / 3);
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int n;
    std::cin >> n;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            isStar(i, j, n);
        }
        std::cout << "\n";
    }

}