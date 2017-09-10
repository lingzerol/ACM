#include <iostream>
#include <string>
unsigned int w[1001], v[1001],result[1001][1001];
unsigned int N, V, t;
long long max(const long long&a,const long long&b) {
	if (a < b)
		return b;
	else return a;
}
int main(){
	int i, j;
	unsigned int m;
	std::cin >> t;
	while (t--) {
		std::cin >> N >> V;
		for (i = 0; i < N; i++)
		{
			std::cin >> v[i];
		}
		for (i = 0; i < N; i++) {
			std::cin >> w[i];
		} 
		for (i = w[0]; i <= V; ++i) {
			result[0][i] = v[0];
		}
		for (i = 1; i < N; i++) {
			for (j = 0; j <= V; j++)
			{
				if (j<w[i])
					result[i][j] = result[i - 1][j];
				else
					result[i][j] = max(result[i - 1][j], result[i - 1][j - w[i]] + v[i]);
			}
		}
		m = 0;
		for (i = 0; i <= V; ++i) {
			if (result[N - 1][i] > m)
				m = result[N - 1][i];
		}
		std::cout << m << std::endl;
		memset(result, 0, sizeof(result));
	}
	return 0;
}