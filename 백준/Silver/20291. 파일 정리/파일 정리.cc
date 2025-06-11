#include <iostream>
#include <string>
#include <map>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N;
	std::cin >> N;
	std::string str;
	std::map<std::string, int> m;
	while(N--)
	{
		std::cin >> str;
		str.erase(0, str.find('.') + 1);
		if (m.find(str) != m.end())
		{
			++m[str];
		}
		else
		{
			m[str] = 1;
		}
	}
	for (const std::pair<std::string, int>& p : m)
	{
		std::cout << p.first << ' ' << p.second << '\n';
	}
}