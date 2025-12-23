#include <bits/stdc++.h>
using namespace std;
const int N = 120+5;
int a[N][N], qz[N][N], sum[N][N], n, ans = -0x7FFFFFFF;
int main() {
	scanf ("%d", &n);
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= n; j ++) {
			scanf ("%d", &a[i][j]);
			qz[i][j] = qz[i][j - 1] + a[i][j];
			sum[i][j] = qz[i][j] + sum[i - 1][j];
	}
	for (int x1 = 1; x1 <= n; x1 ++) 
		for (int y1 = 1; y1 <= n; y1 ++)
			for (int x2 = x1; x2 <= n; x2 ++)
				for (int y2 = y1; y2 <= n; y2 ++) {
					ans = max(ans, sum[x2][y2] + sum[x1 - 1][y1 - 1] - sum[x2][y1 - 1] - sum[x1 - 1][y2]);
				}
	printf ("%d", ans);
	return 0;
}