#include <iostream>
using namespace std;
int a[6000];
int main() {
	int n;
	int se=1, th=1, fi=1, sev=1;
	a[1] = 1;
	for (int i = 2; i < 5843; i++) {
		if (a[se] * 2 <= a[th] * 3 && a[se] * 2 <= 5 * a[fi]&&a[se] * 2 <= a[sev] * 7) {
			a[i] = a[se] * 2;
			se++;
		}
		else if (a[th] * 3 <= a[se] * 2 && a[th] * 3 <= a[fi] * 5 && a[th] * 3 <= a[sev] * 7) {
			a[i] = a[th] * 3;
			th++;
		}
		else if (a[fi] * 5 <= a[se] * 2 && a[fi] * 5 <= a[th] * 3 && a[fi] * 5 <= a[sev] * 7) {
			a[i] = a[fi] * 5;
			fi++;
		}
		else if (a[sev] * 7 <= a[se] * 2 && a[sev]*7 <= a[th] * 3 && a[sev] * 7 <= a[fi] * 5) {
			a[i] = a[sev] * 7;
			sev++;
		}
		while (a[i] == a[i - 1])
			i--;
	}
	while (cin >> n,n) {
		cout << "The " << n;
		if (n % 10 == 1 && n % 100 != 11)
			cout << "st";
		else if (n % 10 == 2 && n % 100 != 12)
			cout << "nd";
		else if (n % 10 == 3 && n % 100 != 13)
			cout << "rd";
		else
			cout << "th";
		cout << " humble number is " << a[n] << "." << endl;
	}
}//unchange