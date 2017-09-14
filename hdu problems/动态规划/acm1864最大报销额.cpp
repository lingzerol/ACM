
#include <iostream>
#include <cstring>
double Q;
int  N,P;
double goods[3], temp;
int  dp[5000000],p[35];
int i, j, k, m;
double sum;
char c1,c2;
bool flag;

const int& max_(const int  &a, const int &b) {
	if (a < b)
		return b;
	else return a;
}

int main() {
	std::cout.setf(std::ios::fixed);
	std::cout.precision(2);
	while (std::cin >> Q >> N&&N) {
		P = 0;
		for (i = 0; i < N; ++i) {
			std::cin >> m;
			sum = 0;
			memset(goods, 0, sizeof(goods));
			flag = true;
			for (j = 0; j < m; ++j) {
				std::cin >> c1;
				std::cin >> c2;
				if ((c1 - 'A') >= 0 && (c1 - 'A') <= 2)
				{
					std::cin >> temp;
					goods[c1 - 'A'] += temp;
					sum += temp;
				}
				else {
					std::cin >> temp;
					flag = false;
				}
			}
			for (k = 0; k <= 2; k++) {
				if (goods[k] > 600)
				{
					flag = false;
					break;
				}
			}
			if (sum <= 1000&&sum<=Q&&flag) {
				p[P++] = sum*100;
			}
		}
		memset(dp, 0, sizeof(dp));
		for (i = 0; i < P; ++i) {
			for (j = (int)(Q * 100); j >= p[i]; --j) {
				dp[j] = max_(dp[j], dp[j - p[i]] + p[i]);
			}
		}
		std::cout << dp[(int)(Q * 100)]/100.0 << std::endl;
	
	}
	return 0;
}