
#include <iostream>
#include <cstdlib>
using namespace std;
struct Dpnode {
	int cost;
	int reduce;
	int pre;
}dp[1<<16];
struct Work {
	char homework[110];
	int cost;
	int deadline;
}work[16];
bool done[1 << 16];
void output(int status) {
	int curjob = dp[status].pre^status;
	int curid = 0;
	curjob >>= 1;
	while (curjob) {
		curid++;
		curjob >>= 1;
	}
	if (dp[status].pre != 0) {
		output(dp[status].pre);
	}
	cout << work[curid].homework << endl;
}
int main()
{
	int t, n;
	cin >> n;
	while (n--) {
		cin >> t;
		for (int i = 0; i < t; i++) {
			cin >> work[i].homework >> work[i].deadline >> work[i].cost;
		}
		memset(done, false, sizeof(done));
		dp[0].cost = 0;
		dp[0].pre = -1;
		dp[0].reduce = 0;
		done[0] = true;
		int upper = (1 << t) - 1;
		for (int i = 0; i < upper; i++) {
			for (int j = 0; j < t; j++) {
				int temp = 1 << j;
				if ((temp&i) == 0) {
					int next = temp | i;
					int cost = dp[i].cost + work[j].cost;
					int reduce = cost - work[j].deadline;
					dp[next].cost = cost;
					if (reduce < 0)reduce = 0;
					reduce = dp[i].reduce + reduce;
					if (done[next]) {
						if (reduce < dp[next].reduce) {
							dp[next].reduce = reduce;
							dp[next].pre = i;
						}
						/*else if (reduce == dp[next].reduce) {
							if (dp[next].pre > i) {
								dp[next].pre = i;
							}
						}
					}*///这部分可以省略因为j是从小到大搜索的，默认已经是字典序了，所以不需要再处理
					}
					else {
							done[next] = true;
							dp[next].reduce = reduce;
							dp[next].pre = i;
						}
					}
				}
			}
		cout << dp[upper].reduce << endl;
		output(upper);
	}
	return 0;
}
