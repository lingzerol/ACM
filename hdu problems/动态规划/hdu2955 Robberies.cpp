
#include <iostream>
#include <string>
#include <algorithm>
float P, p[110],dp[10100];
int T, N, m[110];
int i, j,sum,maxi;
float max_(const float&a, const float&b) {
	if (a < b)
		return b;
	else return a;
}
int main() {
	std::cin >> T;
	while (T--) {
		std::cin >> P >> N;
		P = 1 - P;
		sum = 0;
		for (i = 0; i < N; i++) {
			std::cin >> m[i]>>p[i];
			sum += m[i];
			p[i] = 1 - p[i];
		}
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;

		for (i = 0; i < N; ++i) {
			for (j = sum; j >= m[i]; --j) {
				dp[j] = max_(dp[j], dp[j - m[i]] * p[i]);
			}
		}
		for (i = sum; i >= 0; --i) {
			if (dp[i]>=P) {
				break;
			}
		}
		std::cout << i<< std::endl;
	}
	return 0;
}