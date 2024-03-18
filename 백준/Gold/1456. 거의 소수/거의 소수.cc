#include<iostream>
#include<vector>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	long A, B;
	int count = 0;
	std::cin >> A >> B;

	long numbers[10000001];

	for (long i = 2; i * i <= B; ++i) {
		numbers[i] = i;
	}
	for (long i = 2; i * i <= B; ++i) {
		if (numbers[i] != 0) {
			for (long j = 2; i * j < 10000001; ++j) {
				numbers[i * j] = 0;
			}
		}
	}

	for (long i = 2; i*i <= B; ++i) {
		if (numbers[i] != 0) {
			if (i > 1000000 && i*i>= A) {
				count++;
				continue;
			}
			for (long j = i * i; j <= B; j*=i) {
				if (j >= A)
				{
					++count;
				}
			}
		}
	}
	std::cout << count;
}