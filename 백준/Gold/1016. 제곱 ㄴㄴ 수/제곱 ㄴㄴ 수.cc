#include <iostream>
#include <vector>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	long min, max;
	std::cin >> min >> max;
	
	std::vector<bool> Check(max - min + 1);

	for (long i = 2; i * i <= max; ++i) {
		long pow = i* i;
		long startIndex = min / pow;
		if (min % pow != 0) {
			startIndex++;
		}
		for (long j = startIndex; pow * j <= max; ++j) {
			Check[(int)((j * pow) - min)] = true;
		}
	}
	int count = 0;
	for (int i = 0; i <= max - min; ++i) {
		if (!Check[i]) {
			count++;
		}
	}
	std::cout << count;
}