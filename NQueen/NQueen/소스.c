#include <stdio.h>
#include <math.h>

int cur[13];
int count = 0;
int N;//배열의 한변 크기이자, Queen의 개수

int check(int n) {
	for (int i = 0; i < n; i++) {
		if (cur[i] == cur[n] || n - i == abs(cur[n] - cur[i])) {
			return 0;
		}
	}
	return 1;
}

void addQueen(int n) {

	if (n == N-1) {
		count++;
		return;
	}

	for (int i = 0; i < N; i++) {
		cur[n+1] = i;

		if (check(n+1)==1) {
			addQueen(n+1);
		}
	}
}

int main() {
	scanf("%d", &N);

	addQueen(-1);
	
	printf("%d", count);
	
}