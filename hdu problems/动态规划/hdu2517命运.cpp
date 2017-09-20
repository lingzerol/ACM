

#include <iostream>
#include <cstring>
#include <cstdio>
#define INF 0x3f3f3f3f

int a[21][1100], dp[21][1100],v[21][1100];
int R, C;

int MAX_(int a, int b) {
	if (a < b)
		return b;
	else return a;
}


bool judge(int x, int y) {
	if (x>=1 && x<=R && y>=1 && y<=C)
		return true;
	else return false;
}

int dfs(int x, int y) {
	if (v[x][y] != 0) {
		return dp[x][y];
	}
	int pre_max = INT_MIN;
	int xx, yy;
	if (judge(x+1, y))
		pre_max = MAX_(pre_max, dfs(x+1, y));
	if (judge(x, y+1))
		pre_max = MAX_(pre_max, dfs(x, y+1));
	for (int i = 2; y*i <= C;++i) {
		xx = x;
		yy = y*i;
		if(judge(xx,yy))
		pre_max = MAX_(pre_max, dfs(xx, yy));
	}
	if (pre_max == INT_MIN)
		pre_max = 0;
	dp[x][y] = pre_max+a[x][y];
	v[x][y] = 1;
	return dp[x][y];
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &R, &C);
		memset(a, 0, sizeof(a));
		for (int i = 1; i <= R; ++i) {
			for (int j = 1; j <= C; ++j) {
				scanf("%d", &a[i][j]);
			}
		}
		memset(dp, 0, sizeof(dp));
		memset(v, 0, sizeof(v));
		printf("%d\n", dfs(1, 1));
	}
	return 0;
}