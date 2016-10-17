#include <stdio.h>
int N;
int map[512][512];

void find(int x, int y, int X, int Y, int n) {
	int check[4][2];
	check[0][0] = x + (n / 2) - 1;
	check[0][1] = y + (n / 2) - 1;
	check[1][0] = x + (n / 2) - 1;
	check[1][1] = y + (n / 2);
	check[2][0] = x + (n / 2);
	check[2][1] = y + (n / 2) - 1;
	check[3][0] = x + (n / 2);
	check[3][1] = y + (n / 2);
	if (X < x + n / 2 && Y < y + n / 2) { //타일이 1구역에 있을때
		check[0][0] = X;
		check[0][1] = Y;
		map[check[1][0]][check[1][1]] = 1;
		map[check[2][0]][check[2][1]] = 1;
		map[check[3][0]][check[3][1]] = 1;
	}
	else if (X < x + n / 2 && Y >= y + n / 2) { //타일이 2구역에 있을때
		check[1][0] = X;
		check[1][1] = Y;
		map[check[0][0]][check[0][1]] = 2;
		map[check[2][0]][check[2][1]] = 2;
		map[check[3][0]][check[3][1]] = 2;
	}
	else if (X >= x + n / 2 && Y < y + n / 2) { //타일이 3구역에 있을때
		check[2][0] = X;
		check[2][1] = Y;
		map[check[0][0]][check[0][1]] = 3;
		map[check[1][0]][check[1][1]] = 3;
		map[check[3][0]][check[3][1]] = 3;
	}
	else if (X >= x + n / 2 && Y >= y + n / 2) { //타일이 4구역에 있을때
		check[3][0] = X;
		check[3][1] = Y;
		map[check[0][0]][check[0][1]] = 4;
		map[check[1][0]][check[1][1]] = 4;
		map[check[2][0]][check[2][1]] = 4;
	}

	if (n == 2) {
		return;
	}

	find(x, y, check[0][0], check[0][1], n / 2);
	find(x, y + n / 2, check[1][0], check[1][1], n / 2);
	find(x + n / 2, y, check[2][0], check[2][1], n / 2);
	find(x + n / 2, y + n / 2, check[3][0], check[3][1], n / 2);
}

int main() {
	int X, Y;
	scanf("%d", &N);
	scanf("%d %d", &X, &Y);
	map[X][Y] = 0;

	find(0, 0, X, Y, N);//시작점, 하수구, 한변의길이

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}


}
