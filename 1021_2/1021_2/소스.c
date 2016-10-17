#include <stdio.h>
int N, M;
int part[101] = { 0, };
int mid[101][101] = { 0, };

void find(int n, int c) {//n�� c�� ������
	if (mid[n][0] == 0) {
		part[n] += c;
		return;
	}
	for (int i = N; i > 0; i--) {
		if (mid[n][i] != 0) {
			find(i, mid[n][i]*c);
		}
	}
}

int main() {
	int a, b, c;
	scanf("%d", &N);//�� ��ǰ�� ����
	scanf("%d", &M);//scanf �� ��

	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &a, &b, &c);
		mid[a][b] = c;
		mid[a][0] = 1;
	}
	
	find(N, 1);

	for (int i = 1; i < N; i++) {
		if (mid[i][0] == 0) {
			printf("%d %d\n", i, part[i]);
		}
	}

}