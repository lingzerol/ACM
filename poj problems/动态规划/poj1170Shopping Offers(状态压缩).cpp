
#include <iostream>
#include <stdio.h>
#include <cstring>
#define inf (0x3f3f3f3f)
const int SIX[10] = { 1,6,36,216,1296,7776,46656,279936 };
int HASH[1005],dp[500005];

struct Item{
	int has;
	int num;
	int val;
	int weight;
}item[205];

int MIN_(int a, int b) {
	if (a < b)
		return a;
	else return b;
}


int main() {
	int B,i,j,ans,sum,c,m,k,n,y,count;
	while (scanf("%d", &B) != EOF) {
		ans = sum = 0;
		memset(HASH, -1, sizeof(HASH));
		memset(item, 0, sizeof(item));
		for (i = 0; i < B; ++i) {
			scanf("%d%d%d", &c, &item[i].num, &item[i].val);
			HASH[c] = SIX[i];
			item[i].has = SIX[i];
			ans += item[i].num*item[i].val;
			sum += SIX[i] * item[i].num;          //把六进制总数当作背包容量
			item[i].weight = SIX[i];              //把每个物品的重量变成六进制，因为是完全背包所以不用考虑是否控制物品塞入背包的数目，但是存在一个问题背包容量不会限制了其个数，如例子2 7 1 0 8 1 2 0，最终输出是0，但是正确但应为2；
		}										  //但是加上了weight属性而不改变num属性的化，这样就解决了原来的问题了，而解法从原来的把问题看成完全背包问题改成了看成01背包和完全背包的合体
		scanf("%d", &m);
		for (i = 0; i < m; ++i) {
			scanf("%d", &k);
			while (k--) {
				scanf("%d%d", &c, &y);
				if (HASH[c] == -1)
					continue;
				item[i + B].weight += HASH[c] * y;//将套餐变成六进制
			}
			item[i + B].num ++;
			scanf("%d", &item[i+B].val);
		}
		memset(dp, inf, sizeof(dp));
		dp[0]=0;
		for (i = 0; i < B + m; ++i)
		{
			if (i < B) {
				count = item[i].num;
				while (count--)
					for (j = sum; j >= item[i].weight; --j)
						dp[j] = MIN_(dp[j], dp[j - item[i].weight] + item[i].val);//01背包问题
			}
			else for (j = item[i].weight; j <= sum; ++j)
				dp[j] = MIN_(dp[j], dp[j - item[i].weight] + item[i].val);//完全背包问题
		}
		printf("%d\n", MIN_(ans,dp[sum]));
	}
	return 0;
}
