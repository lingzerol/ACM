#include <iostream>
#include <algorithm>
int n[1001], dp[1001];
int N, M, i, j, m;
int max_(const int &a, const int &b) {
	if (a < b)
		return b;
	else return a;
}
bool cmp(int a, int b) {
	return a > b;
}
int main() {
	while (std::cin >> N, N) {
		int temp;
		for (i = 0; i < N; i++) {
			std::cin >> n[i];
		}
		std::cin >> M;
		if(M<5)
		{
			std::cout << M << std::endl;
			continue;
		}
		m = 0;
		for (i = 1; i < N; i++) {
			if (n[m] < n[i])
				m = i;
		}
		temp = n[0];
		n[0] = n[m];
		n[m] = temp;
		memset(dp, 0, sizeof(dp));
		for (i = 1; i < N; ++i) {
			for (j = M - 5; j >= 1; --j) {
				if (j >= n[i])
					dp[j] = max_(dp[j], dp[j - n[i]] + n[i]);
			}
		}
		M = M - dp[M - 5] - n[0];
		std::cout << M << std::endl;
	}
	return 0;
}