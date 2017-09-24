
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#define inf 0x3f3f3f3f
#define maxn 1000000+5
#define ll long long
using namespace std;

int pos[maxn * 2];

struct {
	ll cover;ll len;//cover该节点被覆盖的情况，len该区间被覆盖的长度
	ll l, r;//显示该区间的位置
}tt[maxn*4+5];

struct Sides{
	ll l, r, h;//边所在的位置及其高度
	ll f;//用于区分上下边
}ss[maxn*2];

void Build_Tree(ll l, ll r, ll rt) {
	tt[rt].l = l;
	tt[rt].r = r;
	tt[rt].cover = tt[rt].len = 0;
	if (l == r)
		return;
	ll mid = (l + r) / 2;
	Build_Tree(l, mid, rt << 1);
	Build_Tree(mid + 1, r, rt << 1 | 1);
}

void Push_Up(ll rt) {
	if (tt[rt].cover) {
		tt[rt].len = pos[tt[rt].r+1] - pos[tt[rt].l];
	}//cover不为零，则存有线段覆盖整个区间
	else if (tt[rt].r == tt[rt].l)
		tt[rt].len = 0;//该区间非线段情况
	else tt[rt].len = tt[rt << 1].len + tt[rt << 1 | 1].len;//不存在cover的情况，及该区间没有完全覆盖其的线段
}


void Update(ll l, ll r, ll f,ll rt) {
	if (tt[rt].l >= l&&tt[rt].r<=r) {
		tt[rt].cover += f;
		Push_Up(rt);
		return;
	}
	ll mid = (tt[rt].l + tt[rt].r) / 2;
	if (l <= mid)
		Update(l, r, f, rt<<1);
	if (r > mid) Update(l, r, f, rt << 1 | 1);
	Push_Up(rt);//把上层节点的信息给更新
}//更新节点信息

ll Binary_Search(ll key, ll beg, ll end) {
	ll mid;
	while (beg <= end) {
		mid = (beg + end) / 2;
		if (pos[mid] == key)
			return mid;
		if (pos[mid] < key)
			beg = mid + 1;
		else end = mid - 1;
	}
	return -1;
}//二分查找查找出ss[i].x1和ss[i].x2在pos的位置


bool cmp(Sides a, Sides b) {
	return a.h < b.h;
}

int main() {
	int N;
	while (scanf("%d", &N) != EOF&&N!=0) {
		memset(ss, 0, sizeof(ss));
		memset(tt, 0, sizeof(tt));
		memset(pos, 0, sizeof(pos));
		ll x1, x2, y1, y2;
		ll num=0, m=1;
		for (int i = 0; i < N; ++i) {
			scanf("%lld%lld%lld%lld",&x1, &y1, &x2, &y2);
			ss[num].l = x1;
			ss[num].r = x2;
			ss[num].h = y1;
			ss[num].f = 1;
			//下边的f值为1

			ss[num+1].l = x1;
			ss[num+1].r = x2;
			ss[num+1].h = y2;
			ss[num+1].f = -1;
			//上边的f值为-1
			//上述操作为保存每条边的信息

			pos[num] = x1;
			pos[num+1] = x2;
			//保存边界点的值
			num+=2;

		}



		sort(ss, ss + num, cmp);//根据纵坐边，使数据以升序排序
		sort(pos, pos + num);//使坐标值以升序排序

		m = 1;

		for (int i = 1; i < num; ++i) {
			if (pos[i] != pos[i - 1]) {
				pos[m] = pos[i];
				m++;
			}
		}

		
		Build_Tree(0, m - 1, 1);//先建树	
		ll ans =0;//ans保存矩阵的面积
		for (int i = 0; i < num; ++i) {
			ll l, r;
			l = Binary_Search(ss[i].l, 0, m - 1);
			r = Binary_Search(ss[i].r, 0, m - 1)-1;
			Update(l, r, ss[i].f, 1);
			ans += (ss[i + 1].h - ss[i].h)*tt[1].len;
		}
		printf("%lld\n", ans);
	}
	printf("*");
	return 0;
}