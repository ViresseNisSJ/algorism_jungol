//
////크루스칼 코드
//#include <cstdio>
//const int LM = 110;
//int N, dist[LM], input[LM][LM], visit[LM], ans;
//int main()
//{
//	int i, j;
//	//freopen("input.txt", "r", stdin);
//	scanf("%d", &N);
//	for (i = 1; i <= N; ++i)
//	{
//		for (j = 1; j <= N; ++j)
//		{
//			scanf("%d", input[i] + j);
//		}
//	}
//	for (i = 2; i <= N; i++)   dist[i] = 1e9;
//
//	for (i = 1; i <= N; ++i)
//	{
//		//extract minval
//		int minval = 1e9, node = i;
//		for (j = 1; j <= N; ++j) if (!visit[j] && dist[j]<minval)
//		{
//			minval = dist[j];
//			node = j;
//		}
//
//		//check
//		ans += minval;
//		visit[node] = 1;
//
//		//update
//		for (j = 1; j <= N; ++j) if (!visit[j] && j != node && dist[j]>input[node][j])
//		{
//			dist[j] = input[node][j];
//		}
//	}
//	printf("%d", ans);
//	return 0;
//}


//프림코드

#include <stdio.h>
#define size 105
int ch[size], ans, arr[size][size], n, dist[size];
void Prim() {
	int i, j, mv, mn;
	for (i = 1; i < size; i++) dist[i] = 1e9;
	for (i = 1; i <= n; i++) {
		//extract min
		mv = 1e9, mn = i;
		for (j = 1; j <= n; j++) {
			if (!ch[j] && dist[j] < mv) {
				mv = dist[j];
				mn = j;
			}
		}
		//check
		ch[mn] = 1;
		if (mv != 1e9)
			ans += mv;
		//relaxation
		for (j = 1; j <= n; j++) {
			if (!ch[j] && dist[j] > arr[mn][j]) {
				dist[j] = arr[mn][j];
			}
		}
	}
}
int main()
{
	int i, j;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	Prim();
	printf("%d", ans);
	return 0;
}
