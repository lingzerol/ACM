
#include <iostream>
#include <cstring>
#include <algorithm>
int N, V, M,T;
int dp[125010], v[51],m[101];
int i, j, k,sum,mid;
int A, B;
int max_(const int &a,const int &b){
if(a<b)
return b;
else return a;
}
int main() {
	while (std::cin >> N&&N > 0) {
		sum = 0;
		for (i = 1; i <= N; ++i) {
			std::cin >> v[i] >> m[i];
			sum += v[i] * m[i];
		}
		memset(dp, 0, sizeof(dp));
		mid = sum % 2==1? (sum / 2 + 1) : (sum / 2);
		for (i = 1; i <= N; ++i) {
			for (j = 1; j <= m[i]; j *= 2) {
				for (k = mid; k >= j*v[i]; --k) {
					dp[k] = max_(dp[k], dp[k - j*v[i]] + j*v[i]);
				}
			}
		}
		A = (sum - dp[mid]) > dp[mid] ? (sum - dp[mid]) : dp[mid];
		B = sum - A;
		std::cout << A << ' ' << B << std::endl;
	}
	return 0;
}