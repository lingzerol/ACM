#include <iostream>
#include <cstring>
const char sign[12][50] = { "rat","ox", "tiger", "rabbit", "dragon", "snake", "horse", "sheep", "monkey", "rooster", "dog","pig" };

int min(const char *c1, const char *c2) {
	if (strlen(c1) < strlen(c2))
		return strlen(c1);
	else return strlen(c2);
}
int judge(char*c) {
	bool flag;
	for (int i = 0; i < 12; ++i)
	{
		flag = true;
		for (int j = 0; j < min(c, sign[i]); ++j) {
			if (c[j] != sign[i][j])
			{
				flag = false;
				break;
			}
		}
		if (flag)
			return i;
	}
}

int main() {
	int T;
	std::cin >> T;
	while(T--){
		char c1[50], c2[50];
		int a1, a2,result;

		std::cin >> c1 >> c2;

		a1 = judge(c1);
		a2 = judge(c2);
		if (a2 > a1)
			result = a2 - a1;
		else if (a1 > a2)
			result = 12 - (a1 - a2);
		else result = 12;
		std::cout << result << std::endl;
	}
	return 0;
}