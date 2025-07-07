#include <iostream>
#include <vector>
#include <string>
#include <map>

static std::map<std::string, std::string> parent;
static std::map<std::string, int> network;

std::string find(std::string a)
{
    if (a == parent[a])
    {
        return a;
    }
    else
    {
        return parent[a] = find(parent[a]);
    }
}

void unionfunc(std::string a, std::string b)
{
    a = find(a);
    b = find(b);
    parent[a] = b;
    network[b] += network[a];
    network[a] = 0;
}

bool isSameUnion(std::string a, std::string b)
{
    return find(a) == find(b);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int n, f;
    std::cin >> n;

    std::string s1, s2;
    while (n--)
    {
        parent.clear();
        network.clear();
        std::cin >> f;
        while (f--)
        {
            std::cin >> s1 >> s2;
            if (parent.find(s1) == parent.end())
            {
                parent[s1] = s1;
                network[s1] = 1;
            }
            if (parent.find(s2) == parent.end())
            {
                parent[s2] = s2;
                network[s2] = 1;
            }

            if (isSameUnion(s1, s2))
            {
                std::cout << network[find(s1)] << "\n";
            }
            else
            {
                unionfunc(s1, s2);
                std::cout << network[find(s1)] << "\n";
            }
        }
    }
}