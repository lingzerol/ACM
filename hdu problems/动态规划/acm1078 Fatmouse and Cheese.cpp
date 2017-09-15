#include <iostream>

int n, k;
int dp[101][101],food[101][101];
int i, j;
const int direction[4][2]{ {1,0},{-1,0},{0,1},{0,-1} };
int dfs(int, int);
int MAX_(int a, int b) {
    if (a < b)
        return b;
    else return a;
}
int main() {

    while (std::cin >> n >> k&&n>=1&&n<=100&&k<=100&&k>=1) {
        for (i = 0; i < n; ++i) {
            for (j = 0; j < n; ++j) {
                std::cin >> food[i][j];

            }
        }
        memset(dp, 0, sizeof(dp));
        std::cout<<dfs(0, 0)<<std::endl;
    }
    return 0;
}
int dfs(const int x,const int y) {
    int temp=0,i,j;
    if (dp[x][y]>0)
        return dp[x][y];
    for (i = 1; i <= k; ++i) {
        for (j = 0; j < 4; ++j) {
            int xx, yy;
            xx = x + direction[j][0] * i;
            yy = y + direction[j][1] * i;
            if (xx < 0 || yy < 0 || xx >=n || yy >= n) {
                continue;
            }
            if (food[xx][yy] > food[x][y])
                temp = MAX_(temp, dfs(xx,yy));
        }
    }
    dp[x][y] = temp + food[x][y];
    return dp[x][y];
}