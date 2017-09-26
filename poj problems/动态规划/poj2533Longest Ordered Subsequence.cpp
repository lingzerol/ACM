
#include <iostream>
#include <cstring>
#include <stdio.h>
#include <algorithm>
#define inf 0x3f3f3f3f
using namespace std;

int a[10010],dp[10010];

int main() {
	int n;
	while (scanf("%d", &n)!=EOF) {
		for (int i = 1; i <=n; ++i)
			scanf("%d", &a[i]);
		memset(dp, -inf, sizeof(dp));
		int maxn=-inf;
		for (int i = 1; i <=n; ++i) {
			dp[i] = 1;
			for (int j = 1; j <= i-1; ++j) {
				if (a[j] < a[i]) {
					dp[i] = max(dp[i], dp[j]+1);
				}
			}

			maxn = max(maxn, dp[i]);
		}
		printf("%d\n",maxn);
	}
	return 0;
}