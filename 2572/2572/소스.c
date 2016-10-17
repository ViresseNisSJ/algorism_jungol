#include <stdio.h>

int main() {
	int sushi[33000];
	int kind[3001] = { 0, };
	int count = 0;
	int max;
	int N, d, k, c;
	int i;

	scanf("%d %d %d %d", &N, &d, &k, &c);

	for (i = 0; i < N; i++) {
		scanf("%d", &sushi[i]);
	}
	for (i = N; i < N + k - 1; i++) {
		sushi[i] = sushi[i - N];
	}

	kind[c]++;
	count++;

	for (i = 0; i < k; i++) {
		if (kind[sushi[i]] == 0)count++;
		kind[sushi[i]]++;
	}

	max = count;

	for (i = k; i < N + k - 1; i++) {
		kind[sushi[i - k]]--;
		if (kind[sushi[i - k]] == 0)count--;
		if (kind[sushi[i]] == 0)count++;
		kind[sushi[i]]++;
		//앞빼고 뒤넣고 쿠폰종류 없으면 쿠폰써서 다양성 추가
		//if (kind[c] == 0)count++;
		if (max < count)max = count;
	}
	
	printf("%d", max);
}