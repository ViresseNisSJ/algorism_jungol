#include <stdio.h>
#include <math.h>
int M, N;
int point[2][3];
int map[101][101] = { 1, };
int dirX[4] = { 0,0,1,-1 };
int dirY[4] = { 1,-1,0,0 };
int min = 10000;

void find(int x, int y, int dir, int go, int count) {
	if (count > min) {
		return;
	}
	if (x == point[1][0] && y == point[1][1]) {
		if ( point[1][2] * dir == 2 || point[1][2] * dir == 12) {
			count += 2;
		}
		else if (point[1][2] == dir) {
			count += go / 3;
			if (go % 3 != 0)count++;
		}
		else {
			count++;
		}
		if (min > count) {
			min = count;
		}
		return;
	}

	map[x][y] = 1;

	for (int i = 0; i < 4; i++) {
		if (map[x + dirX[i]][y + dirY[i]] == 0 && 0 < x + dirX[i] && x + dirX[i] <= M && 0 < y + dirY[i] && y + dirY[i] <= N) {
			go++;
			if ((i + 1)*dir == 2 || (i + 1)*dir == 12) {
				count += 2;
				count += go / 3;
				if (go / 3 != 0)count++;
				go = 0;
			}
			else if (i + 1 == dir) {

			}
			else {
				count++;
				count += go / 3;
				if (go / 3 != 0)count++;
				go = 0;
			}
			find(x + dirX[i], y + dirY[i], i+1, go, count);
			map[x + dirX[i]][y + dirY[i]] = 0;
		}
	}
}

int main() {

	scanf("%d %d", &M, &N);
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			scanf("%d", &point[i][j]);
		}
	}

	find(point[0][0], point[0][1], point[0][2], 0, 0);//xÁÂÇ¥, yÁÂÇ¥, ¹æÇâ, go, count

	printf("%d", min);
}