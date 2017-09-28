
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define inf 0x3f3f3f3f
#define Clean(a,b) memset(a,b,sizeof(a))


using namespace std;


struct Cookies{
	int bounce;
	int fun;
	int d;
	int group;
}a[2000];

int group[10][2000], dp[2000], tmp[2000];
int N, D, G;


int ZeroOnePack(int d, int fun, int *f) {
	for (int i = D; i >= d; --i) {
		f[i] = max(f[i], f[i - d] + fun);
	}
	return 0;
}
int CompletePack(int d, int fun, int *f) {
	for (int i = d; i <= D; ++i) {
		f[i] = max(f[i], f[i - d] + fun);
	}
	return 0;
}
int MultiplePack(int d, int fun, int bounce, int *f) {
	if (d*bounce >= D) {
		CompletePack(d, fun, f);
		return 0;
	}


	int k = 1;
	while (k < bounce) {
		ZeroOnePack(d*k, fun*k, f);
		bounce -= k;
		k <<= 1;
	}
	ZeroOnePack(d*bounce, fun*bounce, f);
	return 0;
}

int main() {
	while (~scanf("%d%d", &N, &D)) {
		Clean(a, 0);
		for (int i = 1; i <=N; ++i) {
			scanf("%d%d%d", &a[i].bounce, &a[i].fun, &a[i].d);
		}
		scanf("%d", &G);getchar();
		for (int i = 1; i <= G; ++i) {
			int temp;
			char c;
			Clean(group[i], -inf);
			group[i][0] = 0;
			do {
				scanf("%d%c", &temp, &c);
				a[temp].group = i;
			} while (c != '\n');
		}
		Clean(dp, -inf);
		dp[0] = 0;
		for (int i = 1; i <= N; ++i) {
			if (a[i].group) {
				Clean(tmp, -inf);
				tmp[0] = 0;
			}
			if (a[i].bounce) {
				MultiplePack(a[i].d, a[i].fun, a[i].bounce, a[i].group ? tmp : dp);
			}
			else CompletePack(a[i].d, a[i].fun, a[i].group ? tmp : dp);
			if (a[i].group) {
				for (int j = 1; j <= D; ++j) {
					group[a[i].group][j] = max(group[a[i].group][j], tmp[j]);
				}
			}
		}
		for (int i = 1; i <= G; ++i) {
			for (int k = D; k >=0 ; --k) {
				for (int j = 1; j <= k; ++j) {
					dp[k] = max(dp[k], dp[k - j] + group[i][j]);
				}
			}
		}
		if (dp[D] >= 0)
			printf("%d\n", dp[D]);
		else printf("i'm sorry...\n");
	}
	return 0;
}