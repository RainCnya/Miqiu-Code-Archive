#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+5;
int a[N][N], sum[N][N], diff[N][N];
int n, m, c, ans_x, ans_y;
int main () {
	scanf ("%d%d%d", &n, &m, &c);
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= m; j ++){
			scanf ("%d", &a[i][j]);	
			diff[i][j] = diff[i][j - 1] + a[i][j];
			sum[i][j] = diff[i][j] + sum[i - 1][j];
		}
	int ans = -0x7FFFFFFF, tmp;
	for (int x = 1; x + c - 1 <= n; x ++) 
		for (int y = 1; y + c - 1 <= m; y ++) {
			tmp = sum[x + c - 1][y + c - 1] - sum[x + c - 1][y - 1] - sum[x - 1][y + c - 1] + sum[x - 1][y - 1];
			if (tmp > ans) ans_x = x, ans_y = y, ans = tmp;
		}
	printf ("%d %d", ans_x, ans_y);
	return 0;
}