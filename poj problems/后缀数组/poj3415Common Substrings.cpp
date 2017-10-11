#include <iostream>
#include <cstring>
#include <cstdlib>
#include <stdio.h>
#include <algorithm>


#define MAXN 200100
#define inf 0x3f3f3f3f
#define ll long long

using namespace std;

char ch[MAXN];
ll SA[MAXN], rank1[MAXN], Height[MAXN], tax[MAXN], tp[MAXN], a[MAXN], n, m;
char str[MAXN];
//rank[i] 第i个后缀的排名; SA[i] 排名为i的后缀位置; Height[i] 排名为i的后缀与排名为(i-1)的后缀的LCP
//tax[i] 计数排序辅助数组; tp[i] rank的辅助数组(计数排序中的第二关键字),与SA意义一样。
//a为原串
void RSort(ll *rank1, ll *tp) {
	//rank第一关键字,tp第二关键字。
	for (int i = 0; i <= m; i++) tax[i] = 0;
	for (int i = 1; i <= n; i++) tax[rank1[tp[i]]] ++;
	for (int i = 1; i <= m; i++) tax[i] += tax[i - 1];
	for (int i = n; i >= 1; i--) SA[tax[rank1[tp[i]]] --] = tp[i]; //确保满足第一关键字的同时，再满足第二关键字的要求
} //计数排序,把新的二元组排序。

ll cmp(ll *f, ll x, ll y, int w) { return f[x] == f[y] && f[x + w] == f[y + w]; }
//通过二元组两个下标的比较，确定两个子串是否相同

void Suffix(ll *rank1, ll *tp) {
	//SA
	for (int i = 1; i <= n; i++) rank1[i] = a[i], tp[i] = i;
	m = 130, RSort(rank1, tp); //一开始是以单个字符为单位，所以(m = 127)

	for (int w = 1, p = 1, i; p < n; w += w, m = p) { //把子串长度翻倍,更新rank

													  //w 当前一个子串的长度; m 当前离散后的排名种类数
													  //当前的tp(第二关键字)可直接由上一次的SA的得到
		for (p = 0, i = n - w + 1; i <= n; i++) tp[++p] = i; //长度越界,第二关键字为0
		for (i = 1; i <= n; i++) if (SA[i] > w) tp[++p] = SA[i] - w;

		//更新SA值,并用tp暂时存下上一轮的rank(用于cmp比较)
		RSort(rank1, tp), swap(rank1, tp), rank1[SA[1]] = p = 1;

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

void Init() {
	n = strlen(str);
	for (int i = 0; i < n; i++) a[i + 1] = str[i];
}


ll K;
ll s[MAXN][2];
int main() {
	while (scanf("%ld", &K)!=EOF && K) {
		long long len1, len2, num = 0;
		scanf("%s", str);
		len1 = strlen(str);
		str[len1] = '@';
		scanf("%s", str + len1 + 1);
		len2 = strlen(str) - len1;
		Init();
		Suffix(rank1, tp);
		long long tot , top = 0;
		tot = top = 0;
		num = 0;
		for (int i =2; i <= n; ++i) {
			if (Height[i] < K) { tot = top = 0; }
			else {
				ll cnt = 0;
				if (SA[i-1] > len1 + 1) {
					cnt++;
					tot += Height[i] - K + 1;
				}
				while (top > 0 && Height[i] <= s[top-1][0]) {
					top--;
					tot -= s[top][1] * (s[top][0] - Height[i]);
					cnt += s[top][1];
				}
				s[top][0] = Height[i];
				s[top++][1] = cnt;
				if (SA[i] <= len1)num += tot;
			}
		}
		tot = top = 0;
		for (int i = 2; i <= n; ++i) {
			if (Height[i] < K) { tot = top = 0; }
			else {
				ll cnt = 0;
				if (SA[i-1]<= len1) {
					cnt++;
					tot += Height[i] - K + 1;
				}
				while (top > 0 && Height[i] <= s[top - 1][0]) {
					top--;
					tot -= s[top][1] * (s[top][0] - Height[i]);
					cnt += s[top][1];
				}
				s[top][0] = Height[i];
				s[top++][1] = cnt;
				if (SA[i] > len1+1)num += tot;
			}
		}
		printf("%I64d\n", num);
	}
	return 0;
}