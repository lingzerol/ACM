#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int T;
	std::cin >> T;
	while (T--) {
		unsigned long long p,max,min;
		bool flag = false;
	std::cin >> p;
	max = sqrt(p / 3.0) + 100;
	min = sqrt(p / 3.0) > 100 ? sqrt(p / 3.0) - 100 : 0;
	for (unsigned long long i = min; i <= max; ++i) {
		unsigned long long sum = i*i + i*(i - 1) + (i - 1)*(i - 1);
		if (sum == p)
		{
			flag = true;
			break;
		}
	}
	if (flag)
		cout << "YES" << endl;
	else cout << "NO" << endl;
	}
	return 0;
}