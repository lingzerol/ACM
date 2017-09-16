#include <iostream>

_int64 h[100010], l[100010], r[100010];
int n;


int main() {
	while (std::cin >> n&&n > 0) {
		for (int i = 0; i < n; ++i) {
			std::cin >> h[i];
			l[i] = i;
			r[i] = i;
		}
		for (int i = 0; i < n; ++i) {
			while (l[i]>=1&&h[l[i] - 1] >= h[i])
				l[i] = l[l[i] - 1];
		}//如果h[l[i]-1]大于h[i]时，那么h[l[i]-1]满足的性质，h[i]也满足因为h[l[i]-1]所满足的性质是找出i右边的所有比h[i]大的矩形，所以在改变l[i]的值是 我们可以直接使用l[l[i]-1]的值
		for (int i = n - 1; i >= 0; --i) {
			while (r[i]<(n-1)&&h[r[i] + 1] >= h[i]) {
				r[i] = r[r[i]+1];
			}
		}//如果h[r[i]+1]大于h[i]时，那么h[r[i]+1]满足的性质，h[i]也满足因为h[r[i]+1]所满足的性质是找出i右边的所有比h[i]大的矩形，所以在改变r[i]的值是 我们可以直接使用l[r[i]+1]的值
		_int64 max=0;
		for (int i = 0; i < n; ++i) {
			_int64 sum;
			sum = (r[i] - l[i] + 1)*h[i];
			if (max < sum)
				max = sum;
		}
		std::cout << max << std::endl;
	}
	return 0;
}