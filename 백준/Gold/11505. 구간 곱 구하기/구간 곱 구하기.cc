#include <iostream>
#include <vector>
#include <cmath>

static std::vector<unsigned long long> tree;
static const int moduloValue = 1000000007;

void setTree(int i);
long long getMultipliedValue(int s, int e);
void changeValue(int i, int value);

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N, M, K;
	std::cin >> N >> M >> K;
	int height = 1;
	int length = N;

	while (length != 0)
	{
		length /= 2;
		++height;
	}
	int size = static_cast<int>(pow(2, height));
	tree.resize(size, 1);
	int startIndex = size / 2;
	
	for (int i = 0; i < N; ++i)
	{
		std::cin >> tree[startIndex + i];
	}
	setTree(size - 1);

	for (int i = 0; i < M + K; ++i)
	{
		int request, s, e;
		std::cin >> request >> s >> e;
		if (request == 1)
		{
			changeValue(startIndex + s - 1, e);
		}
		else if (request == 2)
		{
			std::cout << getMultipliedValue(startIndex + s - 1, startIndex + e - 1) << "\n";
		}
		else
		{
			std::cout << "Input again" << '\n';
			--i;
			continue;
		}
	}
}

void setTree(int i) 
{
	i /= 2;
	while (i > 0)
	{
		tree[i] = tree[i * 2] * tree[i * 2 + 1] % moduloValue;
		--i;
	}
}

long long getMultipliedValue(int s, int e)
{
	long long value = 1;
	while (s <= e)
	{
		if (s % 2 == 1)
		{
			value = value * tree[s] % moduloValue;
			++s;
		}
		if (e % 2 == 0)
		{
			value = value * tree[e] % moduloValue;
			--e;
		}
		s /= 2;
		e /= 2;
	}
	return value;
}

void changeValue(int i, int value)
{
	tree[i] = value;
	i /= 2;
	while (i > 0)
	{
		tree[i] = tree[i * 2] * tree[i * 2 + 1] % moduloValue;
		i /= 2;
	}
}