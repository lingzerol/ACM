#include <iostream>
#include <algorithm>
#include <cstring>
#include <stdio.h>

#define inf 0x3f3f3f3f
#define MAXN 1000000
#define NUM 4010

using namespace std;



int SA[MAXN], rank1[MAXN], Height[MAXN], tax[MAXN], tp[MAXN], a[MAXN], n, m;
char str[MAXN];
int ans,len;
int judge[NUM],id[MAXN];
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
	m = 5000, RSort(rank1,tp); //一开始是以单个字符为单位，所以(m = 127)

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

int  check(int mid, int N, int n) {
	int cnt = 0;
	memset(judge, 0, sizeof(judge));
	for (int i = 2; i <= n; ++i) {
		if (Height[i] < mid) {
			cnt = 0;
			memset(judge, 0, sizeof(judge));
			continue;
		}
		if (!judge[id[SA[i]]]) {
			cnt++;
			judge[id[SA[i]]] = 1;
		}
		if (!judge[id[SA[i - 1]]]) {
			cnt++;
			judge[id[SA[i - 1]]] = 1;
		}
		if (cnt == N) {
			ans = SA[i];
			len = mid;
			return 1;
		}
	}
	return 0;
}
int main() {
	int N;
	while (~scanf("%d",&N)&&N) {
		
		n = 1;
		int temp;
		for (int i = 1; i <= N; ++i) {
			scanf("%s", str+n);
			temp = strlen(str+n);
			int p = n;
			for (int j = 0; j < temp; ++j) {
				a[n] = (str+p)[j];
				id[n] = i;
				n++;
			}
			a[n] =128+i;
			id[n] = 128+i;
			n++;
		}
		n--;

		//Init();
		Suffix(rank1, tp);
		int l = 1, r = n;
		int flag = 0;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (check(mid, N, n)) {
				l = mid + 1;
				flag = 1;
			}
			else r = mid - 1;
		}
		str[ans + len] = '\0';
		if(flag)
		printf("%s\n", str+ans);
		else printf("IDENTITY LOST\n");
	}
	return 0;
}