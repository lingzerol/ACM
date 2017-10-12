
#include<cstdio>//最长公共子串
#include<cstring>
#define Max(a, b)   a>b?a:b
const int maxn = 101001;
int wa[maxn], wb[maxn], wv[maxn], ws[maxn], rank[maxn], height[maxn], sa[maxn], s[maxn], loc[maxn];
bool vis[1001];
char str[1001], ans[1001];
int n;
int cmp(int *r, int a, int b, int l) {
	return r[a] == r[b] && r[a + l] == r[b + l];
}
int abs(int a) {
	return a<0 ? -a : a;
}
void da(int *r, int n, int m) {
	int i, j, p, *x = wa, *y = wb, *t;
	for (i = 0; i<m; i++) ws[i] = 0;
	for (i = 0; i<n; i++) ws[x[i] = r[i]] ++;
	for (i = 1; i<m; i++) ws[i] += ws[i - 1];
	for (i = n - 1; i >= 0; i--) sa[--ws[x[i]]] = i;
	for (j = 1, p = 1; p<n; j *= 2, m = p) {
		for (p = 0, i = n - j; i<n; i++) y[p++] = i;
		for (i = 0; i<n; i++) if (sa[i] >= j) y[p++] = sa[i] - j;
		for (i = 0; i<n; i++) wv[i] = x[y[i]];
		for (i = 0; i<m; i++) ws[i] = 0;
		for (i = 0; i<n; i++) ws[wv[i]] ++;
		for (i = 1; i<m; i++) ws[i] += ws[i - 1];
		for (i = n - 1; i >= 0; i--) sa[--ws[wv[i]]] = y[i];
		for (t = x, x = y, y = t, p = 1, x[sa[0]] = 0, i = 1; i<n; i++)
			x[sa[i]] = cmp(y, sa[i - 1], sa[i], j) ? p - 1 : p++;
	}
	return;
}
void calheight(int *r, int n) {
	int i, j, k = 0;
	for (i = 1; i <= n; i++) rank[sa[i]] = i;//获取rank值 O(n)
	for (i = 0; i<n; height[rank[i++]] = k)
		for (k ? k-- : 0, j = sa[rank[i] - 1]; r[i + k] == r[j + k]; k++);
	return;
}


bool check(int k, int len) {
	int flag = 0;
	int tmp = 0;
	int count = 0;
	memset(vis, 0, sizeof(vis));
	for (int i = 1; i <= len; ++i) {
		if (height[i] < k) {
			memset(vis, 0, sizeof(vis));
			count = 0;
			continue;
		}
		if (!vis[loc[sa[i - 1]]])
			vis[loc[sa[i - 1]]] = true, count++;
		if (!vis[loc[sa[i]]])
			vis[loc[sa[i]]] = true, count++;
		if (count > n/2) {
			return 1;
		}
	}
	return 0;
}

bool print(int mid, int len) {
	int flag = 0;
	int tmp = 0;
	int tag = 0;
	int count = 0;
	memset(vis, 0, sizeof(vis));
	for (int i = 1; i <= len; ++i) {
		if (height[i] < mid) {
			memset(vis, 0, sizeof(vis));
			count = 0;
			tag = 0;
			continue;
		}
		if (!vis[loc[sa[i - 1]]])
			vis[loc[sa[i - 1]]] = true, count++;
		if (!vis[loc[sa[i]]])
			vis[loc[sa[i]]] = true, count++;
		if (count > n/2 && !tag) {
			for (int j = 0; j<mid; j++)
				ans[j] = s[sa[i] + j] + 'a' - 1;
			ans[mid] = '\0';
			printf("%s\n", ans);
			tag = 1;
		}
	}
	return 0;
}

int main() {
	int i, j, m, max, t, flag, x, temp, min;
	while (~scanf("%d", &n) && n) {
		flag = 0;
		m = 0;
		min = maxn;
		temp = 30;
		for (i = 0; i<n; i++) {
			scanf("%s", str);
			if (strlen(str)<min)    min = strlen(str);
			for (j = 0; str[j]; j++) {
				s[m] = str[j] - 'a' + 1;
				loc[m++] = i;
			}
			s[m] = temp;
			loc[m++] = temp++;
		}
		s[m] = 0;
		da(s, m + 1, temp);
		calheight(s, m);
		int left = 0, right = min, mid;
		while (right >= left) {
			mid = (right + left) / 2;
			if (check(mid, m)) {
				left = mid + 1;
				flag = mid;
			}
			else
				right = mid - 1;
		}
		if (flag) {
			print(flag, m);
			printf("\n");
		}
		else
			printf("?\n\n");
	}
	return 0;
}