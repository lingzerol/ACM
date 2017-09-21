
#include <iostream>
#include <cstring>
#include <stdio.h>
#define inf (0x3f3f3f3f) 
struct Item {
	int c[5];
	int val;
	int code;
	int num;
}a[1100];

int dp[6][6][6][6][6];

int B;


int MIN_(int a, int b) {
	if (a > b)
		return b;
	else return a;
}
int MAX_(int a, int b) {
	if (a < b)
		return b;
	else return a;
}

int main(){
	while (scanf("%d", &B)!=EOF) {
		int p = 5,sum[5],sub=0;
		memset(a, 0, sizeof(a));
		for (int i = 0; i < B; ++i) {
			scanf("%d%d%d", &a[i].code, &a[i].num, &a[i].val);
			a[i].c[i] = 1;
			a[i].val = a[i].val;
			sub += a[i].num;
		}
		int s;
		scanf("%d", &s);
		for (int i = 0; i < s; ++i) {
			int num;
			scanf("%d", &num);
			for (int j = 0; j < num; ++j) {
					int code, count,position=0;
					scanf("%d%d", &code, &count);
					while (a[position].code != code) {
						position++;
					}
					
					a[p].c[position] = count;
				}
				int val;
				scanf("%d", &val);
				a[p].num++;
				//sub++;
				a[p++].val =val;
		}
		memset(dp, inf, sizeof(dp));
		dp[0][0][0][0][0] = 0;
		for (int i = 0; i < p; ++i) {
			if (B >= 1) {
					for (int j = a[i].c[0]; j <= a[0].num; ++j) {
						if (B >= 2) {
							for (int k = a[i].c[1]; k <= a[1].num; ++k) {
								if (B >= 3) {
									for (int z = a[i].c[2]; z <= a[2].num; ++z) {
										if (B >= 4) {
											for (int g = a[i].c[3]; g <= a[3].num; ++g) {
												if (B >= 5) {
													for (int u = a[i].c[4]; u <= a[4].num; ++u) {
														//if (dp[u - a[i].c[4]][g - a[i].c[3]][z - a[i].c[2]][k - a[i].c[1]][j - a[i].c[0]] != inf) {
															//dp[u][g][z][k][j] = dp[u][g][z][k][j] == inf ? 0 : dp[u][g][z][k][j];
															dp[u][g][z][k][j] = MIN_(dp[u][g][z][k][j], dp[u - a[i].c[4]][g - a[i].c[3]][z - a[i].c[2]][k - a[i].c[1]][j - a[i].c[0]] + a[i].val);
														//}
													}
												}
												else {
													//if (dp[0][g - a[i].c[3]][z - a[i].c[2]][k - a[i].c[1]][j - a[i].c[0]] != inf) {
														//dp[0][g][z][k][j] = dp[0][g][z][k][j] == inf ? 0 : dp[0][g][z][k][j];
														dp[0][g][z][k][j] = MIN_(dp[0][g][z][k][j], dp[0][g - a[i].c[3]][z - a[i].c[2]][k - a[i].c[1]][j - a[i].c[0]] + a[i].val);
													//}
												}
											}
										}
										else {
											//if (dp[0][0][z - a[i].c[2]][k - a[i].c[1]][j - a[i].c[0]] != inf) {
												//dp[0][0][z][k][j] = dp[0][0][z][k][j] == inf ? 0 : dp[0][0][z][k][j];
												dp[0][0][z][k][j] = MIN_(dp[0][0][z][k][j], dp[0][0][z - a[i].c[2]][k - a[i].c[1]][j - a[i].c[0]] + a[i].val);
											//}
										}
									}
								}
								else {
									//if (dp[0][0][0][k - a[i].c[1]][j - a[i].c[0]] != inf) {
										//dp[0][0][0][k][j] = dp[0][0][0][k][j] == inf ? 0 : dp[0][0][0][k][j];
										dp[0][0][0][k][j] = MIN_(dp[0][0][0][k][j], dp[0][0][0][k - a[i].c[1]][j - a[i].c[0]] + a[i].val);
									//}
								}
							}
						}
						else {
							//if (dp[0][0][0][0][j - a[i].c[0]] != inf) {
								//dp[0][0][0][0][j] = dp[0][0][0][0][j] == inf ? 0 : dp[0][0][0][0][j];
								dp[0][0][0][0][j] = MIN_(dp[0][0][0][0][j], dp[0][0][0][0][j - a[i].c[0]] + a[i].val);
							//}
						}
					}
				}
		
		}
			printf("%d\n", dp[a[4].num][a[3].num][a[2].num][a[1].num][a[0].num]);
	}
}
