#include <stdio.h>
int dice[6] = { 0, };
int maxMoney = 0;

void getMoney() {
	int max = 0;
	int num = 0;
	int money = 0;
	for (int i = 0; i < 6; i++) {
		if (max <= dice[i]) {
			max = dice[i];
			num = i+1;
		}
	}

	if (max == 4) {
		money = 50000 + num * 5000;
	}
	else if (max == 3) {
		money = 10000 + num * 1000;
	}
	else if (max == 2) {
		int num2 = 0;
		for (int i = 0; i < num-1; i++) {
			if (dice[i] == 2) {
				num2 = i+1;
			}
		}
		if (num2 != 0) {
			money = 2000 + num * 500 + num2 * 500;
		}else{
			money = 1000 + num * 100;
		}
	}
	else {
		money = num * 100;
	}

	if (maxMoney < money) {
		maxMoney = money;
	}

	for (int i = 0; i < 6; i++) {
		dice[i] = 0;
	}

}

int main() {
	int n;
	int arr[1000][4];

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 4; j++) {
			scanf("%d", &arr[i][j]);
			dice[arr[i][j]-1]++;
		}
		getMoney();
	}
	
	printf("%d", maxMoney);
	
}