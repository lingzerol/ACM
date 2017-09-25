
#include <iostream>
#include <cstring>
#include <stdio.h>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
int dp[2][310], a[310][310],sum[310],mn[310], len[310];
bool flag;

int N, M, P;


int solve() {
	int ret = -inf;
	len[0] = 0;
	memset(dp, 0, sizeof(dp));
	for (int k = 1; k <= M; ++k) {
		if (dp[0][k - 1] >= 0) {
			dp[0][k] =dp[0][k-1]+ sum[k];
			len[k]=len[k-1]+1;
		}
		else {
			dp[0][k] = sum[k];
			len[k] = 1;
		}
		if (k == 1) {
			dp[1][k] = sum[k] - mn[k] + P;
		}
		else {
			if (dp[0][k - 1] > 0) {
				dp[1][k] = dp[0][k - 1] + sum[k] - mn[k] + P;
			}
			else dp[1][k] = sum[k] - mn[k] + P;
			dp[1][k] = max(dp[1][k], dp[1][k - 1] + sum[k]);
		}
		ret = max(ret, dp[1][k]);
		if (len[k] == M&&flag)continue;
		ret = max(ret, dp[0][k]);
	}
	return ret;
}


int main() {
	while (scanf("%d%d%d", &N, &M, &P) != EOF) {
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= M; ++j) {
				scanf("%d", &a[i][j]);
			}
		}
		int ans = -inf;
		for (int i = 1; i <= N; ++i) {
			memset(sum, 0, sizeof(sum));
			memset(mn, inf, sizeof(mn));
			flag = false;
			for (int j = i; j <= N; ++j) {
				for (int k = 1; k <= M; ++k) {
					sum[k] += a[j][k];
					mn[k] = min(mn[k], a[j][k]);
				}
				if (i == 1 && j == N)flag = true;
				ans = max(ans,solve());
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}