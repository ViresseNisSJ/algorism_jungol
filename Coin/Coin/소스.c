#include <stdio.h>

int coin[6] = { 500, 100, 50, 10, 5, 1 };
int num[6];
int change[6] = { 0, 0, 0, 0, 0, 0 };

int main() {
	int w;
	int count = 0;
	int sum = 0;

	scanf("%d", &w);
	for (int i = 0; i < 6; i++) {
		scanf("%d", &num[i]);
		sum += num[i] * coin[i];
	}

	sum -= w;

	for (int i = 0; i <= 5; i++) {
		int temp;
		if (num[i] < sum / coin[i]) {
			temp = num[i];
		}
		else {
			temp = sum / coin[i];
		}

		sum -= coin[i] * temp;
		change[i] = temp;
	}

	for (int i = 0; i < 6; i++) {
		change[i] = num[i] - change[i];
		count += change[i];
	}

	printf("%d\n", count);
	for (int i = 0; i < 6; i++) {
		printf("%d ", change[i]);
	}
}