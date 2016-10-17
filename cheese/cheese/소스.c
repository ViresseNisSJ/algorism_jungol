#include <stdio.h>
#include <stdlib.h>

int n, m;
int arr[100][100] = { 0, };
int arr2[100][100] = { 0, };
int pos1, pos2;

void findOut(int a, int b) {
	
	arr2[a][b] = 1;

	if (a == 0 && b == 0) {
		arr[pos1][pos2] = 2;
	}
	else {
		if (b + 1 < m && arr[a][b + 1] == 0 && arr2[a][b + 1] == 0) {
			arr2[a][b + 1] = 1;
			findOut(a, b + 1);
		}
		if (b - 1 >= 0 && arr[a][b - 1] == 0 && arr2[a][b - 1] == 0) {
			arr2[a][b - 1] = 1;
			findOut(a, b - 1);
		}
		if (a + 1 < n && arr[a + 1][b] == 0 && arr2[a + 1][b] == 0) {
			arr2[a + 1][b] = 1;
			findOut(a + 1, b);
		}
		if (a - 1 >= 0 && arr[a - 1][b] == 0 && arr2[a - 1][b] == 0) {
			arr2[a - 1][b] = 1;
			findOut(a - 1, b);
		}
	}
	return;
}

void find() {

	int check;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 1) {
				check = 0;
				if (arr[i - 1][j] == 0) {
					check++;
				}if (arr[i - 1][j + 1] == 0) {
					check++;
				}if (arr[i][j + 1] == 0) {
					check++;
				}if (arr[i + 1][j + 1] == 0) {
					check++;
				}if (arr[i + 1][j] == 0) {
					check++;
				}if (arr[i + 1][j - 1] == 0) {
					check++;
				}if (arr[i][j - 1] == 0) {
					check++;
				}if (arr[i - 1][j - 1] == 0) {
					check++;
				}

				if (check >= 2) {
					pos1 = i;
					pos2 = j;
					for (int k = 0; k < n; k++) {
						for (int l = 0; l < m; l++) {
							arr2[k][l] = 0;
						}
					}
					findOut(i, j);
				}
			}
		}
	}
	return;
}

int main() {

	int count = 0;
	int preCount = 0;
	int time = 0;
	int preTime = 0;

	scanf("%d %d", &n, &m);
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == 1) {
				count += +1;
			}
		}
	}
	
	while (1) {
		find();
		preCount = count;
		preTime = time;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] == 2) {
					count -= 1;
					arr[i][j] = 0;
				}
			}
		}
		time += 1;
		
		if (count == 0) {
			break;
		}
	}

	printf("%d\n", time);
	printf("%d\n", preCount);

	system("PAUSE");
}