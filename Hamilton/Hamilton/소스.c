#include <stdio.h>

int N;
int map[12][12];
int visit[12];
int min = 400;

void find(int i, int n, int s) {
	if (n == N-1) {
		s += map[i][0];
		if (min > s) {
			min = s;
		}
		return;
	}

	for (int j = 0; j < N; j++) {
		if (visit[j] == 0 && map[i][j]!=0) {
			s += map[i][j];
			visit[i] = 1;
			find(j,++n, s);
			visit[i] = 0;
			n--;
		}
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	find(0,0,0);

	printf("%d", min);
}