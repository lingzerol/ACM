
#include <iostream>

char a[1010][1010];
int u[1010][1010],l[1010][1010],r[1010][1010];
int N, M,K;

int main() {
	std::cin >> K;
	while (K--) {
		std::cin >> M >> N;
		char c;
		memset(a, 0, sizeof(a));
		memset(u, 0,sizeof(u));
		for (int i = 1; i <=M; ++i) {
			for (int j = 1; j <=N; ++j) {
				std::cin >> a[i][j];
				if (a[i][j] == ' ')
					j--;
				else {
					if(a[i][j]=='F')
					u[i][j] = u[i - 1][j] + 1;
					l[i][j] = r[i][j]=j;
				}
			}
		}//因为矩形是四四方方的所以我们计算水平最长距离和垂直最长距离并无差别，同时因为矩形是四四方方的所以我们那计算以u[i][j]为最短边计算最大举行面积时，我们不需要找出u[i][j]所在的最长边位置再求最大矩形，就是因为底边不一定时对齐的，所以我们只需要以u[i][j]所在的行尾底边然后 求出最大矩形即可
		for (int i = 1; i <=M; ++i) {
			for (int j = 1; j <= N; ++j) {
				while (u[i][j]!=0&&l[i][j]>1&&u[i][l[i][j] - 1] >= u[i][j])
					l[i][j] = l[i][l[i][j] - 1];
				while (u[i][j]!=0&&r[i][j] < N&&u[i][r[i][j] + 1] >= u[i][j])
					r[i][j] = r[i][r[i][j] + 1];
			}
		}//与hdu1506使用的方法差不多
		int max = 0;
		for (int i = 1; i <= M; ++i) {
			for (int j = 1; j <= N; ++j) {
				if (u[i][j]) {
					int sum;
					sum = (r[i][j] - l[i][j] + 1)*u[i][j];
					if (max < sum)
						max = sum;
				}
			}
		}
		std::cout << max*3 << std::endl;
	}
	return 0;
}