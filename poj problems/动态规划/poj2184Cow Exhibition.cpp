
#include <iostream>
#include <cstring>
#define inf (0x3f3f3f3f) 

int N,s[110],f[110],dp[210000];
const int mid = 100000;
const int maxnum = 200000;
int MAX_(int a, int b) {
	if (a < b)
		return b;
	else return a;
}

int main() {
	while (std::cin >> N) {
		memset(s, 0, sizeof(s));
		memset(f, 0, sizeof(f));
		for (int i = 1; i <= N; ++i) {
			std::cin >> s[i]>>f[i];
		}
		//memset(dp, -inf, sizeof(dp));
		for (int i = 0; i <= maxnum; i++)
			dp[i] = -inf;
		dp[mid] = 0;
		for (int i = 1; i <= N; ++i) {
			if (s[i] < 0) {
				for (int j = s[i]; j <= maxnum+s[i]; ++j) {
					if(dp[j-s[i]]>-inf)
					dp[j] = MAX_(dp[j], dp[j - s[i]] + f[i]);
				}
			}
			else {
				for (int j = maxnum; j >= s[i]; --j) {
					if(dp[j-s[i]]>-inf)
					dp[j] = MAX_(dp[j], dp[j - s[i]] + f[i]);
				}
			}
		}
		int max = -inf;
		for (int i = mid; i <= maxnum; ++i) {
			if (dp[i] >= 0) {
				max = MAX_(max,dp[i]+i-mid);
			}
		}
		std::cout << max << std::endl;
	}
	return 0;
}