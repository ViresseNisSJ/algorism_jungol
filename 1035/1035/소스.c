#include <stdio.h>

int main() {
	int num[10] = { 0, };
	int maxIndex = 0;
	for (int i = 1; i <= 9; i++) {
		scanf("%d", &num[i]);
	}
	for (int i = 1; i <= 9; i++) {
		if (num[maxIndex] < num[i]) {
			maxIndex = i;
		}
	}

	printf("%d\n", num[maxIndex]);
	printf("%d", maxIndex);
}