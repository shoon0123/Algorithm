#include <iostream>
#include <vector>
#include <cmath>
#include <limits.h>

static std::vector<long> tree;
int getMinimum(int s, int e);
void setTree(int i);

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N, M;
	std::cin >> N >> M;

	int height = 1;
	int length = N;

	while (length != 0)
	{
		length /= 2;
		++height;
	}
	int size = int(pow(2, height));
	int startIndex = size / 2;
	tree.resize(size + 1, INT_MAX);

	for (int i = 0; i < N; ++i)
	{
		std::cin >> tree[startIndex + i];
	}
	setTree(size - 1);

	while (M--)
	{
		int s, e;
		std::cin >> s >> e;
		std::cout << getMinimum(startIndex + s - 1, startIndex + e - 1) << '\n';
	}
}

int getMinimum(int s, int e)
{
	int minimum = INT_MAX;
	while (s <= e)
	{
		if (s % 2 == 1)
		{
			minimum = minimum < tree[s] ? minimum : tree[s];
			++s;
		}
		if (e % 2 == 0)
		{
			minimum = minimum < tree[e] ? minimum : tree[e];
			--e;
		}
		s = s / 2;
		e = e / 2;
	}
	return minimum;
}

void setTree(int i)
{
	i /= 2;
	while (i > 0)
	{
		tree[i] = tree[i * 2] < tree[i * 2 + 1] ? tree[i * 2] : tree[i * 2 + 1];
		--i;
	}
}