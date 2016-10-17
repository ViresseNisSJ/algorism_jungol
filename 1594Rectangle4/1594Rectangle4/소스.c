#include <stdio.h>

int map[100][100];

int fill(int x1, int y1, int x2, int y2) {
	for (int i = y1; i < y2; i++) {
		for (int j = x1; j < x2; j++) {
			map[j][i] = 1;
		}
	}
}

int main() {
	int XY[4][4];
	int count = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			scanf("%d", &XY[i][j]);
		}
	}

	for (int i = 0; i < 4; i++) {
		fill(XY[i][0], XY[i][1], XY[i][2], XY[i][3]);
	}

	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (map[i][j] == 1) {
				count++;
			}
		}
	}
	
	printf("%d", count);

}