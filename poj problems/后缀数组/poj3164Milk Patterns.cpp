

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>


#define MAXN 20010
#define inf 0x3f3f3f3f
#define Range 1000010

using namespace std;

char ch[MAXN], All[MAXN];
int SA[MAXN], rank1[MAXN], Height[MAXN], tax[Range], tp[MAXN], a[MAXN], n, m;
char str[MAXN];
//rank[i] 第i个后缀的排名; SA[i] 排名为i的后缀位置; Height[i] 排名为i的后缀与排名为(i-1)的后缀的LCP
//tax[i] 计数排序辅助数组; tp[i] rank的辅助数组(计数排序中的第二关键字),与SA意义一样。
//a为原串
void RSort(int *rank1,int *tp) {
	//rank第一关键字,tp第二关键字。
	for (int i = 0; i <= m; i++) tax[i] = 0;
	for (int i = 1; i <= n; i++) tax[rank1[tp[i]]] ++;
	for (int i = 1; i <= m; i++) tax[i] += tax[i - 1];
	for (int i = n; i >= 1; i--) SA[tax[rank1[tp[i]]] --] = tp[i]; //确保满足第一关键字的同时，再满足第二关键字的要求
} //计数排序,把新的二元组排序。

int cmp(int *f, int x, int y, int w) { return f[x] == f[y] && f[x + w] == f[y + w]; }
//通过二元组两个下标的比较，确定两个子串是否相同

void Suffix(int *rank1,int *tp) {
	//SA
	for (int i = 1; i <= n; i++) rank1[i] = a[i], tp[i] = i;
	 RSort(rank1,tp); //一开始是以单个字符为单位，所以(m = 127)

	for (int w = 1, p = 1, i; p < n; w += w, m = p) { //把子串长度翻倍,更新rank

													  //w 当前一个子串的长度; m 当前离散后的排名种类数
													  //当前的tp(第二关键字)可直接由上一次的SA的得到
		for (p = 0, i = n - w + 1; i <= n; i++) tp[++p] = i; //长度越界,第二关键字为0
		for (i = 1; i <= n; i++) if (SA[i] > w) tp[++p] = SA[i] - w;

		//更新SA值,并用tp暂时存下上一轮的rank(用于cmp比较)
		RSort(rank1,tp), swap(rank1, tp), rank1[SA[1]] = p = 1;

		//用已经完成的SA来更新与它互逆的rank,并离散rank
		for (i = 2; i <= n; i++) rank1[SA[i]] = cmp(tp, SA[i], SA[i - 1], w) ? p : ++p;
	}
	//离散：把相等的字符串的rank设为相同。
	//LCP
	int j, k = 0;
	for (int i = 1; i <= n; Height[rank1[i++]] = k)
		for (k = k ? k - 1 : k, j = SA[rank1[i] - 1]; a[i + k] == a[j + k]; ++k);
	//这个知道原理后就比较好理解程序
}

int tt[MAXN << 2];
void Push_up(int rt) {
	tt[rt] = min(tt[rt << 1], tt[rt] << 1 | 1);
}
int Build_Tree(int l, int r, int rt) {
	if (l == r) {
		tt[rt] = Height[l];
		return 0;
	}
	int mid = (l + r) >> 1;
	Build_Tree(l, mid, rt << 1);
	Build_Tree(mid + 1, r, rt << 1 | 1);
	Push_up(rt);
	return 0;
}
int Query(int L, int R, int l, int r, int rt) {
	if (L <= l&&R >=r ) {
		return tt[rt];
	}
	int mid = (l + r) >> 1;
	int ans = inf;
	if (L <= mid)ans=Query(L, R, l, mid, rt << 1);
	if (R > mid)ans=min(ans,Query(L, R, mid + 1, r, rt << 1 | 1));
	return ans;
}
int main() {
	int N, K;
	while (~scanf("%d%d", &N, &K)) {
		m = -inf;
		n = N;
		for (int i = 1; i <= N; ++i) { scanf("%d", &a[i]); m = max(m, a[i]); }
		Suffix(rank1,tp);
		int maxn = 0;
		/*Build_Tree(1, N, 1);
		for (int i = 2; i <= N - K+2; ++i) {
			maxn = max(maxn, Query(i, i + K - 2, 1, N, 1));
		}*/
		int l = 1, r = n;
		while (l <= r) {
			int cnt = 1;
			int mid = l + r >> 1;
			for (int i = 1; i <= n; i++) {
				if (Height[i] >= mid)cnt++;
				else cnt = 1;
				if (cnt >= K)break;
			}
			if (cnt >= K)l = mid + 1;
			else r = mid - 1;

		}
		printf("%d\n", r);//不能使用线段树因为出现k=1时的情况，线段树无法实现
		

	//	printf("%d\n", maxn);
	}
	return 0;
}