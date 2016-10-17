#include <stdio.h>
#include <stdlib.h>

int map[25][25] = { 0, }, visit[25][25] = { 0, };
int num[625];
int pos = 0;

void numbering(int a, int b) {

	visit[a][b] = 1;
	if (map[a][b + 1] == 1 && visit[a][b + 1] == 0) {
		visit[a][b + 1] = 1;
		num[pos]++;
		numbering(a, b + 1);
	}if (map[a][b - 1] == 1 && visit[a][b - 1] == 0) {
		visit[a][b - 1] = 1;
		num[pos]++;
		numbering(a, b - 1);
	}if (map[a + 1][b] == 1 && visit[a + 1][b] == 0) {
		visit[a + 1][b] = 1;
		num[pos]++;
		numbering(a + 1, b);
	}if (map[a - 1][b] == 1 && visit[a - 1][b] == 0) {
		visit[a - 1][b] = 1;
		num[pos]++;
		numbering(a - 1, b);
	}
	return;
}

int main() {
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 1 && visit[i][j] == 0) {
				num[pos] = 1;
				numbering(i, j);
				pos++;
			}
		}
	}

	for (int i = 0; i < pos; i++) {
		int a;
		for (int j = i + 1; j < pos; j++) {
			if (num[i] > num[j]) {
				int a = num[i];
				num[i] = num[j];
				num[j] = a;
			}
		}
	}

	printf("%d\n", pos);
	for (int i = 0; i < pos; i++) {
		printf("%d\n", num[i]);
	}

	system("PAUSE");
}