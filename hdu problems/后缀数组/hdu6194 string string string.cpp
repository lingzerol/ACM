
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define inf 0x3f3f3f3f
using namespace std;


const int MAXN = 300005;


int tt[2*MAXN];

int c[MAXN], wa[MAXN], wb[MAXN], sa[MAXN], Height[MAXN], ran[MAXN];
int n, m;
char str[MAXN];
void sort_sa(int m, int n) {
	int *x = wa, *y = wb, p = 0;
	for (int i = 0; i<m; i++)  c[i] = 0;
	for (int i = 0; i<n; i++)  c[x[i] = str[i]]++;
	for (int i = 1; i<m; i++)  c[i] += c[i - 1];
	for (int i = n - 1; i >= 0; i--) sa[--c[x[i]]] = i;
	for (int k = 1; p<n; k <<= 1, m = p) {
		p = 0;
		for (int i = n - k; i<n; i++) y[p++] = i;//按个位排序  
		for (int i = 0; i<n; i++)  if (sa[i] >= k) y[p++] = sa[i] - k;
		for (int i = 0; i<m; i++) c[i] = 0;
		for (int i = 0; i<n; i++) c[x[y[i]]]++;
		for (int i = 1; i<m; i++) c[i] += c[i - 1];
		for (int i = n - 1; i >= 0; i--)  sa[--c[x[y[i]]]] = y[i];
		swap(x, y); x[sa[0]] = 0, p = 1;
		for (int i = 1; i<n; i++)
			if (y[sa[i]] == y[sa[i - 1]] && y[sa[i] + k] == y[sa[i - 1] + k]) x[sa[i]] = p - 1;
			else x[sa[i]] = p++;
	}
}
void Gethight() {
	int k = 0, len = strlen(str);
	for (int i = 1; i <= len; i++) ran[sa[i]] = i;
	for (int i = 0; i<len; i++) {
		if (k) k--;
		int j = sa[ran[i] - 1];
		while (str[j + k] == str[i + k]) k++;
		Height[ran[i]] = k;
	}
}
void Init() {
	scanf("%s", str);
	n = strlen(str);
}

void Push_up(int l, int r, int rt) {
	tt[rt] = min(tt[rt << 1], tt[rt << 1 | 1]);
}
void Build_Tree(int l, int r, int rt) {
	if (l == r) {
		tt[rt] = Height[l];
		return;
	}
	int mid = (l + r) >> 1;
	Build_Tree(l, mid, rt << 1);
	Build_Tree(mid + 1, r, rt << 1 | 1);
	Push_up(l, r, rt);
}
int Query(int L, int R, int l, int r, int rt) {
	if (L <= l&&R >= r) {
		return tt[rt];
	}
	int mid = (l + r) >> 1;
	int ans = inf;
	if (L <= mid)ans = min(ans, Query(L, R, l, mid, rt << 1));
	if (R > mid)ans = min(ans, Query(L, R, mid + 1, r, rt << 1 | 1));
	return ans;
}
int main() {
	int t, len;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &len);
		Init();
		sort_sa(200, n + 1);
		Gethight();
		int ans = 0;
		Height[n+1] = inf;
		Build_Tree(1, n, 1);
		/*for (int i = 1; i <= n; ++i) {
		printf("%d ", Height[i]);
		}
		printf("\n");
		for (int i = 1; i <= n; ++i) {
			printf("%d ", SA[i]);
		}
		printf("\n");
*/		if (len > n) {
			printf("0\n");
			continue;
		}
		if (len == 1) {
			ans += n - sa[1] - Height[2];
			ans += n - sa[n] - Height[n];
			for (int i = 2; i <= n - 1; ++i) {
				ans += n - sa[i] - max(Height[i], Height[i + 1]);
			}
			printf("%d\n", ans);
			continue;
		}
		int R, L;
		R = Query(2, len, 1, n, 1);
		L = min(R, Height[len + 1]);
		ans += R - L;
		for (int i = 3; i <= n - len + 1; ++i) {
			R = Query(i, i + len - 2, 1, n, 1);
			L = max(min(R, Height[i - 1]), min(R, Height[i + len - 1]));
			ans += R - L;
		}
		R = Query(n - len + 2, n, 1, n, 1);
		L = min(R, Height[n - len + 1]);
		ans += R - L;
		printf("%d\n", ans);
	}
	return 0;
}

