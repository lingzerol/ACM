#include <iostream>
#include <algorithm>
#include <cstring>
#include <stdio.h>
using namespace std;
#define inf 0x3f3f3f3f
struct Cookie {
	int bounce;
	int fun;
	int d;
	int group;
}a[2050];

int N, D, G;
int temp;
int g[10][2050], dp[2000],tmp[2000],group[10][2000];

int ZeroOnePack(int d, int fun,int *dp) {
	for (int j = D; j >= d; --j) {
			dp[j] = std::max(dp[j], dp[j - d] + fun);

	}
	return 0;
}
int CompletePack(int d, int fun,int *dp) {
	for (int j = d; j <= D; ++j) {
			dp[j] = std::max(dp[j], dp[j - d] + fun);
	}
	return 0;
}
int MultiplePack(int d, int fun,int bounce,int *dp) {


	if (d*bounce >=D) {
		CompletePack( d, fun,dp);
		return 0;
	}
	
		int k = 1, amount =bounce;
		while (k<amount) {
			ZeroOnePack(d*k, fun*k,dp);
			amount -= k;
			k <<= 1;
		}
		ZeroOnePack(d*amount, fun*amount,dp);
		return 0;
}
bool get(int gid) {

	int x = 0;
	char ch;
	while (ch = getchar()) {
		if (ch == ' ' || ch == '\n') {
			a[x].group = gid;
			//printf( " %d" , x );  
			return ch != '\n';
		}
		x = x * 10 + (ch - '0');
	}
}
int main() {

	while (scanf("%d%d", &N, &D) != EOF&&N>=1&&D>=0&&N<=1024&&D<=1024) {
		memset(a, 0, sizeof(a));
		for (int i = 1; i <= N; ++i) {
			scanf("%d%d%d", &a[i].bounce, &a[i].fun, &a[i].d);
		}
		memset(g, 0, sizeof(g));
		scanf("%d", &G); getchar();
		for (int i = 1; i <= G; ++i) {
			while(get(i));
		}
		memset(dp, -inf, sizeof(dp));
		memset(tmp, -inf, sizeof(tmp));
		for (int i = 1; i <= G; ++i) {
			memset(group[i], -inf, sizeof(group[i]));
			group[i][0] = 0;
		}
	    temp = dp[1];
		dp[0] = 0;
		/*for (int i = 1; i <= G; ++i) {
			for (int v = D; v >= 0; --v) {
				for (int j = 1; j < g[i][0]; ++j) {
					if (v%a[g[i][j]].d == 0) {
						int w;
						w = v / a[g[i][j]].d;
						if (a[g[i][j]].bounce > 0 && w <= a[g[i][j]].bounce) {
							dp[v] = std::max(dp[v], dp[v - a[g[i][j]].d*w] + a[g[i][j]].fun*w);
						}
						else if (a[g[i][j]].bounce == 0) {
							dp[v] = std::max(dp[v], dp[v - a[g[i][j]].d*w] + a[g[i][j]].fun*w);
						}
					}
					}
				}
			}*/
		for (int i = 1; i <= N; ++i) {
			if (a[i].group) {
				memset(tmp, -inf, sizeof(tmp));
				tmp[0] = 0;
			}
			if (a[i].bounce)
				MultiplePack(a[i].d,a[i].fun,a[i].bounce,(a[i].group?tmp:dp));
			else
				CompletePack(a[i].d,a[i].fun, (a[i].group ? tmp : dp));
			if (a[i].group) {
				for (int j = 1; j <= D; ++j)
					group[a[i].group][j] = max(group[a[i].group][j], tmp[j]);
			}
			}
		for (int gid = 1; gid <= G; ++gid) {
			for (int i = D; i >= 0; --i) {
				for (int j = 1; j <= i; ++j) {
					dp[i] = max(dp[i], dp[i - j] + group[gid][j]);
				}
			}
		}
		if (dp[D] >= 0) printf("%d\n", dp[D]);
		else puts("i'm sorry...");
	}
	return 0;
}