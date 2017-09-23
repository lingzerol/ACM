#include <iostream>
#define inf 0x3f3f3f3f

int dp[110],p[110];
int m, n,t;


int MIN_(int a, int b) {
	if (a < b)
		return a;
	else return b;
}

int main() {

	while (scanf("%d%d", &n, &m) != EOF) {
		for (int i = 0; i < n; ++i) {
			scanf("%d", &p[i]);
		}
		scanf("%d", &t);
		for (int i = 0; i < t; ++i) {
			int d;
			scanf("%d", &d);
			p[d] = -1;
		}
		p[109] = 2000;
		int a=109,b=109;
		for (int i = 0; i < n; ++i) {
			if(p[i]!=-1){
			int tempmin = 109;
			int traffic = 0;
			int k = m;
			int j;
			for (j = i+1; j < (k+i)&&j<n; ++j) {
				if (p[j] != -1)
				{
					if (p[j] < p[tempmin])
						tempmin = j;
				}
				else {
					traffic++;
					k++;
				}
			}
			if ((j - m - i) == traffic)
				if (p[a] + p[b] > p[i] + p[tempmin])
				{
					a = i;
					b = tempmin;
				}
			}
		}
		printf("%d %d\n", a,b);
	}
	return 0;

}