#include <stdio.h>

int main() {
	int A[10];
	int B[10];
	int winA = 0, winB = 0;

	for (int i = 0; i < 10; i++) {
		scanf("%d", &A[i]);
	}
	for (int i = 0; i < 10; i++) {
		scanf("%d", &B[i]);
	}

	for (int i = 0; i < 10; i++) {
		if (A[i] > B[i])winA++;
		else if (A[i] < B[i])winB++;
	}

	if (winA > winB)printf("A");
	else if (winA = winB)printf("D");
	else printf("B");

	system("PAUSE");
}