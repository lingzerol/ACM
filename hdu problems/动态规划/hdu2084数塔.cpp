#include <iostream>
#include <cstring>
int temple[100][100], result[100][100];
int main() {

	int t,i,j,h,max;
	std::cin >> t;
	while (t--) {
		std::cin >> h;
		for (i = 0; i < h; i++) {
			for (j = 0; j <= i; j++) {
				std::cin >> temple[i][j];
			}
		}
		memset(result, 0, sizeof(result));
		for (j = 0; j < h; j++) {
			result[h - 1][j] = temple[h - 1][j];
		}
		for (i = h - 2; i >= 0; --i) {
			for (j = 0; j <= i; ++j) {
				if (result[i + 1][j] < result[i + 1][j + 1]) {
					max = result[i + 1][j + 1];
				}
				else max = result[i + 1][j];
				result[i][j] = max+temple[i][j];
			}
		}
		std::cout << result[0][0] << endl;
	}
	return 0;
}