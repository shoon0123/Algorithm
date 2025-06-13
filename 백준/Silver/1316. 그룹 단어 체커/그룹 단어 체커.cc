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

	std::set<char> set;
	int count = 0;

	std::string s;
	bool flag;
	while (n--)
	{
		flag = true;
		std::cin >> s;
		char tmp = s[0];
		set.insert(s[0]);
		for (int i = 1; i < s.size(); ++i)
		{
			if (s[i] != tmp)
			{
				tmp = s[i];
				if (set.find(s[i]) != set.end())
				{
					flag = false;
					break;
				}
				set.insert(s[i]);
			}
		}

		if (flag)
		{
			++count;
		}
		set.clear();
	}
	std::cout << count;



}