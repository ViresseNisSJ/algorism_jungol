#include <stdio.h>

int bingo = 0;
int num[25][2];
int col[5] = { 0, };//행
int row[5] = { 0, };//렬
int line1 = 0;//왼쪽대각선
int line2 = 0;//오른쪽대각선

int check(int a) {
	col[num[a][0]]++;
	row[num[a][1]]++;
	if (num[a][0] == num[a][1])line1++;
	if (num[a][0] + num[a][1] == 4)line2++;

	if (col[num[a][0]] == 5) {
		bingo++;
		col[num[a][0]] = 0;
	}
	if (row[num[a][1]] == 5) {
		bingo++;
		row[num[a][1]] = 0;
	}
	if (line1 == 5) {
		bingo++;
		line1 = 0;
	}
	if (line2 == 5) {
		bingo++;
		line2 = 0;
	}

	if (bingo >= 3) {
		return 1;
	}
	return 0;
}

int main() {
	int a[25];
	int x, k;
	int temp;
	int count = 0;
	int out = 0;

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			scanf("%d", &temp);
			num[temp][0] = i;
			num[temp][1] = j;
		}
	}
	k = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			scanf("%d", &a[k]);
			k++;
		}
	}

	for (int i = 0; i < 25; i++) {
		x = check(a[i]);
		if (x == 1) {
			x = i + 1;
			break;
		}
	}

	printf("%d", x);
	
}