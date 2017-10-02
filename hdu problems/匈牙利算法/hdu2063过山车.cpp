

#include <iostream>
#include <stdio.h>
#include <cstring>

#define inf 0x3f3f3f3f
#define MAXN 510
#define Couple 1010

using namespace std;


int link[MAXN][MAXN],girl[MAXN];
bool used[MAXN];
int N,M;

int find(int x) {
	for (int i = 1; i <=M; ++i) {
		if (link[x][i] && !used[i]) {
			used[i] = true;
			if (girl[i] == 0 || find(girl[i])) {
				girl[i] = x;
				return true;
			}
		}
	}
	return false;
}

int main() {
	int K;
	while (~scanf("%d", &K) && K != 0) {
		scanf("%d%d", &M, &N);
		int x, y;
		int all = 0;
		memset(link, 0, sizeof(link));
		memset(girl, 0, sizeof(girl));
		for (int i = 0; i < K; ++i) {
			scanf("%d%d", &y, &x);
			link[x][y]=1;
		}
		for (int i = 1; i <= N;++i) {
			memset(used, 0, sizeof(used));
			if (find(i)) all++;
		}
		printf("%d\n", all);
	}
	return 0;
}