
#include <iostream>

int L, N, C, T, VR, VT1, VT2;
int a[110],m[110];
float dp[110];

float MIN_(float a, float b) {
	if (a > b)
		return b;
	else return a;
}


int main() {
	while (std::cin >> L) {
		std::cin >> N >> C >> T;
		std::cin >> VR >> VT1 >> VT2;
		float tr;
		memset(m, 0, sizeof(m));
		for (int i = 1; i <= N; i++) {
			std::cin >> a[i];
			m[i] = a[i];
			dp[i] = INT_MAX;
		}
		m[N + 1] = L;
		dp[0] = 0;
		dp[N + 1] = INT_MAX;
			for (int i = 0; i <= N; ++i) {
			for (int j = N+1; j >= i+1; --j) {
				float t1, t2,away;
				away = m[j] - m[i];
				t1 = (i==0?0:T) + ((C > away) ? away/VT1:((float)C/VT1+(float)(away-C)/VT2));
				t2 = away / VT2;
				t1 = MIN_(t1, t2);
				dp[j] = MIN_(dp[j], dp[i]+t1);
			}
		}
			tr = (float)L / VR;
			if (tr < dp[N + 1])
				std::cout << "Good job,rabbit!" << std::endl;
			else std::cout << "What a pity rabbit!" << std::endl;
	}
	return 0;
}