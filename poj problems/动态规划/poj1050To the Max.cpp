
#include <iostream>

int a[110][110], m[110][110];

int main() {
	int N;
	while (std::cin >> N) {
		memset(m, 0, sizeof(m));
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= N; ++j) {
				std::cin >> a[i][j];
				m[i][j] = m[i][j - 1] + a[i][j];
			}
		}
		int max = INT_MIN;
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= N; ++j) {
				for (int p = j; p >= 1; --p) {
					int msum1 = INT_MIN, msum2 = INT_MIN, sum = 0, spa = p;
					for (int k = i; k <= N; ++k) {
						sum += m[k][j] - m[k][j - spa];
						if (sum > msum1)
							msum1 = sum;
					}
					sum = 0;
					for (int k = i; k >= 1; --k) {
						sum += m[k][j] - m[k][j - spa];
						if (sum > msum2)
							msum2 = sum;
					}
					msum1 = msum1 + msum2 - (m[i][j] - m[i][j - spa]);
					if (msum1 > max)
						max = msum1;
				}
			}
		}
		std::cout << max << std::endl;
	}
	return 0;
}