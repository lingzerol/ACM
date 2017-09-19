

#include <iostream>

int a[110][110];
int dp[110][110];
int R, C;
const int direction[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
int MAX_(int a, int b) {
	if (a < b)
		return b;
	else return a;
}

int dfs(int x, int y) {
	int max = 1;
	if (dp[x][y] != 0)
		return dp[x][y];
	for (int i = 0; i < 4; ++i) {
		int xx=0, yy=0;
		xx = x+direction[i][0];
		yy = y+direction[i][1];
		if (xx < 1 || xx > R||yy< 1 || yy > C)
			continue;
		 if (a[xx][yy] > a[x][y])
		{
			max = MAX_(max, dfs(xx, yy) + 1);
		}
	}
	dp[x][y] = max;
	return max;
}
int main() {
	while (std::cin >> R >> C) {
		for (int i = 1; i <= R; ++i) {
			for (int j = 1; j <= C; ++j)
			{
				std::cin >> a[i][j];
			}
		}
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= R; ++i) {
			for (int j = 1; j <= R; ++j) {
				dfs(i, j);
			}
		}
		int max = INT_MIN;
		for (int i = 1; i <= R; ++i) {
			for (int j = 1; j <= C; ++j) {
				max = MAX_(max, dp[i][j]);
			}
		}
		std::cout << max << std::endl;
	}
	return 0;
}