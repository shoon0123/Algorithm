
#include<stdio.h>
#pragma warning(disable:4996)


int main() {
	int N, i, j, cnt = 0, pnum = 0; // pnum = 소수의 개수
	int arr[100];

	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d", arr + i);
	}
	for (i = 0; i < N; i++) {
		for (j = 1, cnt = 0; j < arr[i]; j++) {
			if (arr[i] % j == 0) {
				cnt++;
			}
		}
		if (cnt == 1) {
			pnum++;
		}
	}

	printf("%d", pnum); //소수 개수 출력

	return 0;
}
