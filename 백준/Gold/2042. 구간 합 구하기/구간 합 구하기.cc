#include <iostream>
#include <vector>
#include <cmath>

static std::vector<long> tree;
long getSum(int s, int e);
void changeValue(int index, long val);
void setTree(int i);

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N, M, K;
	std::cin >> N >> M >> K;

	int height = 0;
	int length = N;

	while (length != 0)
	{
		length /= 2;
		++height;
	}
	int size = int(pow(2, height + 1));
	int startIndex = size / 2;
	tree.resize(size + 1);

	for (int i = 0; i < N; ++i) 
	{
		std::cin >> tree[startIndex + i];
	}
	setTree(size - 1);

	for (int i = 0; i < M + K; ++i) 
	{
		long request, s, e;
		std::cin >> request >> s >> e;
		if (request == 1)
		{
			changeValue(startIndex + s - 1, e);
		}
		else if (request == 2) 
		{
			s = startIndex + s - 1;
			e = startIndex + e - 1;
			std::cout << getSum(s, e) << "\n";
		}
		else
		{
			std::cout << "a is not 1 or 2" << "\n";
			--i;
			continue;
		}
	}
}

long getSum(int s, int e)
{
	long partSum = 0;
	while (s <= e)
	{
		if (s % 2 == 1)
		{
			partSum = partSum + tree[s];
			++s;
		}
		if (e % 2 == 0)
		{
			partSum = partSum + tree[e];
			--e;
		}
		s = s / 2;
		e = e / 2;
	}
	return partSum;
}

void changeValue(int index, long val)
{
	long diff = val - tree[index];
	while (index > 0)
	{
		tree[index] = tree[index] + diff;
		index = index / 2;
	}
}

void setTree(int i)
{
	while (i > 1)
	{
		tree[i / 2] += tree[i];
		--i;
	}
}