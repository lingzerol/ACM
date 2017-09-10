// ConsoleApplication4.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
//INSERT-SORT;
/*#include <iostream>
using namespace std;
int main() {
	int A[] = { 0,1,5,6,7,84,15,48,65,125,51,56,89,14,5,26 };
	int n,j,i,key;
	n = 15;
	for (i = 2; i <= n; i++) {
		key = A[i];
		j= i - 1;
		while (key < A[j]&&j>0)
		{
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = key;
	}
	for (i = 1; i <= n; i++)
		cout << A[i] << ' ';
	system("pause");
	return 0;
}*/
//MERGE-SORT AND BINARY-SEARCH
/*void MERGE(int[], int, int, int);
void MERGE_SORT(int[],int,int);
int BINARY_SEARCH(int[],int,int);
int main() {
	int A[] = { 0,45,8,49,15,3,15,26,48,47,26,98,78,26,85,84,98,48,165,195,156,12,156,19,06,05,6,651,056,06};
	int r, p,mid;
	r = 29;
	p = 1;
	MERGE_SORT(A, p, r);
	for (p = 1; p <= r; p++) {
		cout << A[p]<<' ';
	}
	cout << endl;
	mid=BINARY_SEARCH(A,r,2);
	if(mid!=NULL)
	cout << endl << "the position of '165' is:" << mid<<endl;
	else cout << endl << "could not find this number";
	system("pause");
}
void MERGE(int A[], int p, int q, int r) {
	int n1 = q - p + 2, n2 = r - q+1,k;
	int *R, *L;
    R = new int[n1];
	L = new int[n2];
	int i, j;
	for (i = 1; i < n1; i++)
		L[i] = A[p + i-1];
	for (j = 1; j < n2; j++)
		R[j] = A[q  + j];
	i = j= 1;
	for (k = p; k <= r; k++) {
		if (i == n1)
		{
			A[k] = R[j++];
		}
		else if (j == n2)
		{
			A[k] = L[i++];
		}
		else if (R[j] <= L[i])
		{
			A[k] = R[j++];
		}
		else A[k] = L[i++];
	}
}
void MERGE_SORT(int A[], int p, int r) {
	int q=0;
	if (p < r) {
		q = (p + r) / 2;
		MERGE_SORT(A, p, q);
		MERGE_SORT(A, q+1, r);
		MERGE(A, p, q, r);
	}
}
int BINARY_SEARCH(int A[],int r,int v) {
	int high = r, low = 1,mid;
	while (low <= high) {
		mid = (low + high) / 2;
		if (A[mid] == v)
			return mid;
		else if (A[mid] > v)
			high = mid - 1;
		else if (A[mid] < v)
			low = mid + 1;
	}
	return NULL;
}*/
/*#include <iostream>
using namespace std;
int main() {
	char a[1000];
	m = 0;
	while (cin >> a) {
		int i, n, len, m;
		len = strlen(a);
		for (i = 0; i<len - 3; i++)
		{
			if (a[i] == 'D' || a[i] == 'd')
			{
				n = i + 1;
				if (a[n] == 'O' || a[n] == 'o')
				{
					n++;
					if (a[n] == 'g' || a[n] == 'G')
					{
						n++;
						if (a[n] == 'E' || a[n] == 'e')
							m++;
					}
				}
			}
		}

	}
	cout << m << endl;
}*/
/*#include <iostream>
using namespace std;
int main() {
	int a[20], right[20], left[20];
	int n, m;
	cin >> n;
	for (m = 0; m<n; m++) {
		int t, b[100001], i, j, sum, left_sum;
		bool jud = false;
		cin >> i;
		b[0] = 0;
		left[m] = t = 1;
		right[m] = 1;
		cin >> b[1];
		sum = left_sum = b[1];
		for (j = 2; j <= i; j++)
		{
			if (sum<0) {
				jud = true;
				sum = 0;
				t = j;
			}
			cin >> b[j];
			sum += b[j];
			if (sum>left_sum) {
				left_sum = sum;
				right[m] = j;
				left[m] = t;
			}
		}
		a[m] = left_sum;
	
	}	for (m = 0; m < n; m++) {
		cout << "Case " << m + 1 << ':' << endl << a[m] << ' ' << left[m] << ' ' << right[m] << endl;
		if (m != n - 1)
			cout << endl;
	}
	system("pause");
	return 0;
}
*/
/*#include<iostream>
#include<vector>
const int N = 100010;
using namespace std;

int main() {
	vector<int>vec;
	int T;
	cin >> T;
	int flag = 1;
	while (T--) {
		int n;
		int first;
		int last = 1;
		cin >> n;
		int a[N], d[N];
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		d[1] = a[1];
		cout << "Case " << flag++ << ":" << endl;
		for (int j = 2; j <= n; j++) {
			if (d[j - 1]<0) {
				d[j] = a[j];
			}
			else {
				d[j] = d[j - 1] + a[j];
			}
		}
		int max = d[1];
		for (int i = 1; i <= n; i++) {
			if (d[i]>max) {
				max = d[i];
				last = i;
			}
		}
		int f = last;
		int t = 0;
		for (int k = f; k>0; k--) {
			t = t + a[k];
			if (t == max)
				first = k;
		}
		cout << max << " " << first << " " << last;
		if (T >= 1)
			cout << endl << endl;
		else
			cout << endl;
	}
	system("pause");
	return 0;
}*/
/*#include <iostream>
using namespace std;
typedef struct Sort{
	Sort *ahead;
	int num;
	Sort *next;
}sort;
int main(){
	int n, m,a,len;
	cin >> n >> m;
	cin >> a;
	sort *sorted, *p, *q,*head, *tail,*h,*t;
	sorted = new sort();
	sorted->num = a;
	sorted->ahead = new sort();
	sorted->next = new sort();
	p = sorted->ahead;
	q = sorted->next;
	p->next = sorted;
	q->ahead = sorted;
	p->ahead = NULL;
	q->next = NULL;
	head = tail = h = t = sorted;
	len = 1;
	n--;
	while (n > 0) {
		cin >> a;
		t = tail;
		h = head;
		if (len < m) {
			if (a > tail->num&&a < head->num)
			{
				q->num = a;
				while (q->num > t->num) {
					int temp;
					temp = t->num;
					t->num = q->num;
					q->num = temp;
					q = q->ahead;
					t = t->ahead;
					if (t == p)
						break;
				}
				tail = tail->next;
				q = t = tail;
				q->next = new sort();
				q = q->next;
				q->ahead = t;
				q->next = NULL;
				len++;
			}
			else if (a <= tail->num)
			{
				q->num = a;
				q->next = new sort();
				tail = t = q;
				q = q->next;
				q->ahead = t;
				q->next = NULL;
				len++;
			}
			else
			{
				p->num = a;
				p->ahead = new sort();
				head = h = p;
				p = p->ahead;
				p->next = h;
				p->ahead = NULL;
				len++;
			}
		}
		else {
			if (a > tail->num) {
                 q->num = a;
				while ((q->num) > (t->num)) {
					int temp;
					temp = t->num;
					t->num = q->num;
					q->num = temp;
					q = q->ahead;
					t = t->ahead;
					if (t == p)
						break;
				}
				q = tail->next;
				t = tail;
			}
		}
		n--;
	}
	while (h->next != NULL)
	{
		cout << h->num;
		h = h->next;
		if (h->next != NULL)
			cout << ' ';
	}
	cout << endl;
	system("pause");
}*/
/*#include <iostream>
using namespace std;
int merge(int[], int, int, int);
int  merge_sort(int[], int, int);
int main() {
	int i, m, n;
	while (cin >> m >> n)
	{
		int *a;
		a = new int[m];
		for (i = 0; i < m; i++)
			cin >> a[i];
		merge_sort(a, 0, i - 1);
		for (i = 0; i < n; i++)
		{
			cout << a[i];
			if (i != n - 1)
				cout << ' ';
		}
		cout << endl;
		delete a;
	}
	return 0;
}
int  merge_sort(int a[], int p, int r) {
	int q;
	if (p<r) {
		q = (p + r) / 2;
		merge_sort(a, p, q);
		merge_sort(a, q + 1, r);
		merge(a, p, q, r);
	}
	return 0;
}
int merge(int a[], int p, int q, int r) {
	int n1, n2;
	int i, j;
	n1 = q - p + 1;
	n2 = r - q;
	int *L, *R;
	L = new int[n1];
	R = new int[n2];
	for (i = 0; i<n1; i++)
		L[i] = a[i + p];
	for (j = 0; j<n2; j++)
		R[j] = a[q + j + 1];
	i = 0;
	j = 0;
	int k;
	for (k = p; k <= r; k++) {
		if (i == n1)
			a[k] = R[j++];
		else if (j == n2)
			a[k] = L[i++];
		else if (R[j] >= L[i])
			a[k] = R[j++];
		else a[k] = L[i++];
	}
	delete L, R;
	return 0;
}*///该算法超时的原因可能是c语言的编译及运行速度快过c++的编译和运行速度，故c语言可以AC但c++不行
/*#include <iostream>
#include <algorithm>
bool cmp(int a,int b) {
	if (a != b)
		return a > b;
}
int main() {
	int n, m;
	while (cin >> n >> m) {
		int *a;
		a = new int[n];
		int i = 0;
		for (i = 0; i < n; i++)
			cin >> a[i];
		sort(a, a + n, cmp);
		for (i = 0; i < m; i++)
		{
			cout << a[i];
			if (i != m - 1)
				cout << ' ';
		}
		cout << endl;
	}
}*///该算法超时的原因可能是c语言的编译及运行速度快过c++的编译和运行速度，故c语言可以AC但c++不行
/*#include <iostream>
using namespace std;
int main() {
	int n, m;
	while (cin >> n >> m) {
		long a[1000001] = { 0 };
		long p, i, j, t;
		t = 500000;
		for (i = 1; i <= n; i++)
		{
			cin >> p;
			p = p + t;
			a[p] = 1;
		}
		j = 0;
		for (i = 1000000; i > 0 && j < m; i--) {
			if (a[i] == 1)
			{
				p = i - t;
				cout << p;
				j++;
				if (j != m)
					cout << ' ';
				else cout << endl;

			}
		}
	}
	return 0;
}*/
/*#include <stdio.h>
int merge(int[], int, int, int);
int  merge_sort(int[], int, int);
int main() {
	int i, m, n, *a;
	while (scanf("%d%d", &n, &m) != EOF)
	{
		a= (int *)malloc(sizeof(int)*n);
		for (i = 0; i < n; i++)
			scanf("%d", &a[i]);
		merge_sort(a, 0, i - 1);
		for (i = 0; i < m; i++)
		{
			printf("%d", a[i]);
			if (i != m- 1)
				printf(" ");
		}
		printf("\n");
		free(a);
	}
	return 0;
}
int  merge_sort(int a[], int p, int r) {
	int q;
	if (p<r) {
		q = (p + r) / 2;
		merge_sort(a, p, q);
		merge_sort(a, q + 1, r);
		merge(a, p, q, r);
	}
	return 0;
}
int merge(int a[], int p, int q, int r) {
	int n1, n2, i, j, k, *L, *R;
	n1 = q - p + 1;
	n2 = r - q;
	L = (int*)malloc(sizeof(int)*n1);
	R = (int *)malloc(sizeof(int)*n2);
	for (i = 0; i<n1; i++)
		L[i] = a[i + p];
	for (j = 0; j<n2; j++)
		R[j] = a[q + j + 1];
	i = 0;
	j = 0;
	for (k = p; k <= r; k++) {
		if (i == n1)
			a[k] = R[j++];
		else if (j == n2)
			a[k] = L[i++];
		else if (R[j] >= L[i])
			a[k] = R[j++];
		else a[k] = L[i++];
	}
	free(L);
	free(R);
	return 0;
}*/
/*#include <iostream>
using namespace std;
int main() {
	long n;
	while (cin >> n) {
		if (n % 8 == 2 || n % 8 == 6)
			cout << "yes" << endl;
		else cout << "no" << endl;
	}
	return 0;
}*/
#/*include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	double f = 3.1415926535;
	cout << f << endl;           // 3.14159
	cout << setiosflags(ios::fixed);  //只有在这项设置后，setprecision才是设置小数的位数。
	cout << setprecision(0) << f << endl;    //输出0位小数，3
	cout << setprecision(1) << f << endl;    //输出1位小数，3.1
	cout << setprecision(2) << f << endl;    //输出2位小数，3.14
	cout << setprecision(3) << f << endl;    //输出3位小数，3.142
	cout << setprecision(4) << f << endl;    //输出4位小数，3.1416
	system("pause");
	return 0;
}*///控制小数点后的位数程序
/*#include <iostream>
#include <iomanip>
using namespace std;
void merge_sort(double *,double*, int, int);
void merge(double*,double*,int,int,int);
int main() {
	double m, n;
	while (cin >> m >> n) {
		if (m < 0 || n < 0)
			break;
		double sum = 0;
		if (n != 0) {
			double *j, *f;
			int i = 0, temp = 0;
			j = new double[n];
			f = new double[n];
			for (i = 0; i < n; i++)
			{
				cin >> j[i] >> f[i];
				if (f[i] == 0)
				{
					sum += j[i];
					i--;
					n--;
				}
			}
			if(n-1>0)
			merge_sort(j, f, 0, n - 1);
			i = 0;
			while (m >0) {
				if (m >= f[i]) {
					sum += j[i];
					m = m - f[i];
					i++;
					if (i == n)
						break;
				}
				else {
					double rate;
					rate = m / f[i];
					sum += rate*j[i];
					m = -1;
					i++;
				}
			}
			delete j,f;
		}
		else sum = 0;
		cout << setiosflags(ios::fixed);
		cout << setprecision(3)<<sum << endl;
		
	}
	return 0;
}
void merge_sort(double *j,double *f, int p, int r) {
	int q = 0;
	if (p < r)
	{
		q = (p + r) / 2;
		merge_sort(j,f, p, q);
		merge_sort(j,f, q + 1, r);
		merge(j,f, p, q, r);
	}
}
void merge(double *j,double *f, int p, int q, int r) {
	int n1, n2, m,n, k;
	double *LD,*LU,*RD,*RU;
	double temp1, temp2;
	n1 = q - p + 1;
	n2 = r - q;
	LD = new double[n1];
	RD = new double[n2];
	LU = new double[n1];
	RU = new double[n2];
	for (m = 0; m < n1; m++)
	{
		LU[m] = j[p + m];
		LD[m] = f[p + m];
	}
	for (n = 0; n < n2; n++)
	{
		RU[n] = j[q + n + 1];
		RD[n] = f[q + n + 1];
	}
	m = 0;
	n = 0;
	temp1 = 0;
	temp2 = 0;
	for (k = p; k <= r; k++)
	{if(m!=n1)
		temp1 = LU[m] / LD[m];
	if(n!=n2)
		temp2 = RU[n] / RD[n];
		if (m == n1)
		{
			j[k] = RU[n];
			f[k] = RD[n++];
		}
		else if (n == n2)
		{
			j[k] = LU[m];
			f[k] = LD[m++];
		}
		else if (temp1 > temp2)
		{
			j[k] = LU[m];
			f[k] = LD[m++];
		}
		else {
			j[k] = RU[n];
			f[k] = RD[n++];
		}
		
	}
	delete RU, RD, LU, LD;
}*/
/*#include <iostream>
#include <iomanip>
using namespace std;
int main() {
	int i = 1, j;
	double temp, sum;
	cout << setiosflags(ios::fixed);
	cout << "n e" << endl << "- -----------" << endl;
	cout << "0 1"<<endl;
	cout << "1 2" << endl;
	cout << "2 2.5" << endl;
	i = 3;
	while (i<10) {
		temp = 1;
		sum = 1;
		for (j = 1; j <= i; j++)
		{
			temp = temp / j;
			sum = sum + temp;
		}
		cout << i << ' ' <<setprecision(9)<< sum<<endl;
		i++;
	}
	system("pause");
}*///acm1012

/*#include<stdio.h>
int main()
{
	long int a, b, n, T, s[101];
	while (cin>>a>>b>>n && (a != 0 && b != 0 && n != 0))
	{
		int i, j, T;
		s[0] = 1;
		s[1] = 1;
		for (i = 2; i<101; i++) {//第一个循环

			s[i] = (a*s[i - 1] + b*s[i - 2]) % 7;
			for (j = 1; j<i - 1; j++)//第二个循环
			{
				if (s[j - 1] == s[i - 1] && s[j] == s[i]) {
					T = i - j;
					break;
				}
			}
		}
		n = n%T;
		printf("%ld\n", s[n - 1]);
	}
	return 0;
}*/
//         A                     CCCCCC                M      M               1005
//        A A                   C                     M  M   M M              1005
//       A   A                 C                     M    M M   M             1005
//      A     A               C                     M      M     M            1005
//     A       A              C                    M              M           1005
//    A AAAAAAA A              C                  M                M          1005
//   A           A              C                M                  M         1005
//  A             A              CCCCCC         M                    M        1005
/*#include <iostream>
using namespace std;
typedef struct NODE {
	int a[20];
	NODE *next;
}Node;
Node ring(int,Node*);
int main(){
	
	int n;
	while (cin >> n) {
	Node *head, *p;
	p = new Node();
	p->next = NULL;

	}

}
Node ring(int i) {

}*/
/*
#include <iostream>
using namespace std;
bool Primer(int p, int q) {
	int l, sum = p + q;
	for (l = 2; l <= sum / 2; l++)
	{
		if (sum%l == 0)
			return false;
	}
	return true;
}
int get_ring(int *a, int *b, int i, int n) {
	if (i < n) {
		int j;
		bool jud;
		for (j = 1; j <= n; j++)
		{
			jud = false;
			if (b[j] == 0) {
				jud = Primer(a[i], j);
				if (jud == true) {
					int k;
					a[i + 1] = j;
					b[j] = 1;
					get_ring(a, b, i + 1, n);
					a[i + 1] = 0;
					b[j] = 0;
				}
			}
		}
	}
	else {
		bool jud;
		jud = false;
		jud = Primer(a[n], 1);
		if (jud == true) {
			int t;
			for (t = 1; t <n; t++) {
				cout << a[t] << ' ';
			}
			cout << a[n];
			cout << endl;
		}
	}
	return 0;
}
int main() {
	int n, g;
	g = 1;
	while (cin >> n&&(n>0)&&(n<20)) {
		int a[21] = {0}, b[21] = { 0 }, i;
		a[1] = 1;
		b[1] = 1;
		i = 1;
		cout << "Case " << g << ':' << endl;
		get_ring(a, b, i, n);
		cout << endl;
		g++;
	}
	return 0;
}*/
/*#include <iostream>
#include <iomanip>
using namespace std;
void judge(double&left, double&right) {
	double n = 3600.0*24.0;
	if (right > n&&left < n)
		right = n;
	if (left > n&&right > n)
	{
		left = n;
		right = n;
	}
	if (left < 0 && right>0)
		left = 0;
	if (right < 0 && left < 0)
		left = right = 0;
}
int main() {
	double i;
	double h = 1.0 / 240.0;
	double m = 0.1;
	double s = 6.0f;
	double ms = s - m, hm = m - h, hs = s - h;
	while (cin >> i) {
		double t,temp, sum = 0,left[3],right[3],l,r;
		int rad;
		bool jud = false;
		for (rad = 0.0; rad < 60*24;rad +=1)
		{
			left[0] = (i + rad * 6.0) / hm;
			right[0] = (360 - i + rad *6.0) / hm;
			judge(left[0], right[0]);
		
			//cout << r <<' '<< l <<endl;
		}
		sum = (sum) / (36*2400);
		cout << setiosflags(ios::fixed);
		cout << setprecision(3)<<sum<<endl;
	}
}*/
/*#include <iostream>
#include <math.h>
using namespace std;
int main() {
	int i;
	const double hs = 6.0 - 1.0 / 240.0,hm=0.1-1.0/240.0,ms=6.0-0.1;
	while (cin >> i) {
		double t,t0, t1,k, tl[3], tr[3],rad[3], sum = 0;
		t = hs/ms;
		tl[0]=( i) / hm;
		tr[0]=(360 - 2 * i) / hm;
		rad[1] = tl[0] * ms;
		rad[2] = tl[0] * hs;
		while (rad[1] >= 360.0)
			rad[1] -= 360.0;
		while (rad[2] >= 360.0)
			rad[2] -= 360.0;
		if (rad[1] >= i&&rad[1] <= (360 - 2*i))
		{
			tl[1] = rad[1] / ms;
			tl[1] = (360.0 - 2*i) / ms;
		}
		else if (rad[1] < i)
		{
		tl[1] = i / ms;
		tr[1] = (360 - 2 * i) / ms;
		}
		else {
			tl[1] = tr[1] = 0;
		}
		if (rad[2] >= 2 * i&&rad[2] <= (360 - i))
		{
			tl[2] = rad[2] / hs;
			tr[2] = (360.0 - i) / hs;
		}
		else if (rad[2] < 2 * i)
		{
			tl[2] = 2.0 * i / hs;
			tr[2] = (360.0 - i) / hs;
		}
		else {
			tl[2] = tr[2] = 0;
		}
		if (tl[1] < tl[2])
			tl[1] = tl[2];
		if (tr[1] > tr[2])
			tr[1] = tr[2];
		if(tr[1]>=tl[1])
		sum += tr[1] - tl[1];
		for (k = 1; k <= (tr[0] - tl[0]) / hs;k++)
		{
			tl[1] = (i + (int)(k * 360 * hs / ms )- rad[1]) / ms;
			tr[1] = (360.0 - 2 * i + (int)(k * 360 * hs / ms) - rad[1]) / ms;
			tl[2] = (2 * i + k*360.0 - rad[2]) / hs;
			tr[2] = (360.0 - i + k*360.0 - rad[2]) / hs;
			if (tl[1] < tl[2])
				tl[1] = tl[2];
			if (tr[1] > tr[2])
				tr[1] = tr[2];
			if (tr[1] >= tl[1])
				sum += tr[1] - tl[1];
		}
		sum = sum / (1800);
		cout << sum << endl;
	}
}*/
/*#include <iostream>
using namespace std;
int main() {
	int N, i = 1, kase; double n, m;
	
	while (cin>>N)
	{
		while (N--) {
			int num = 0;
			while (cin >> n >> m && (m + n)) {
				double a, b;
				kase = 0;
				for (b = 2.0; b <= n; b++)
					for (a = 1.0; a < b; a++)
					{
						double temp1, temp2;
						temp1 = (a*a + b*b + m) / (a*b);
						temp2 = (int)temp1;
						if (temp1 == temp2)
							kase++;
					}
				num++;
				cout << "Case " << num << ':' << kase << endl;
			}
			if (N)cout << endl;
		}
	}
}*/
/*#include <stdio.h>
int main(void)

{
	char  buffer[200], s[] = "computer", c = 'l';
	int   i = 35, j;
	float fp = 1.7320534f;
	// 格式化并打印各种数据到buffer
	j = sprintf(buffer, "   String:    %s\n", s); // C4996
	j += sprintf(buffer + j, "   Character: %c\n", c); // C4996
	j += sprintf(buffer + j, "   Integer:   %d\n", i); // C4996
	j += sprintf(buffer + j, "   Real:      %f\n", fp);// C4996
	
	printf("Output:\n%s\ncharacter count = %d\n", buffer, j);
}*/
/*#include <iostream>
#include <iomanip>
using namespace std;
int main() {
	int n,i;
	cin >> n;
		while (n>0) {
			float A, B;
			char C;
			cin >> C >> A >> B;
			switch (C) {
			case '+':A = A + B; break;
			case '-':A = A - B; break;
			case '/':A = A / B; break;
			case '*':A = A*B; break;
			}
			if (A == (int)A)
			{
				cout << (int)A;
			}
			else {
				cout << setiosflags(ios::fixed);
				cout << setprecision(2) << A;
			}
			n--;
				cout << endl;
		}
	
	return 0;
}*/
/*#include <iostream>
using namespace std;
int main() {
	char a[4];
	while (cin >> a[0] >> a[1] >> a[2]) {
		char temp;
		int i, j;
		for (j = 1; j <= 2; j++) {
			temp = a[j];
			i = j - 1;
			while (a[i] > temp&&i >= 0) {
				a[i + 1] = a[i];
				i--;
			}
			a[i + 1] = temp;
		}
		cout << a[0] << ' ' << a[1] << ' ' << a[2] << endl;
	}
	return 0;
}
*/
/*#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
int main() {
	float x1,y1,x2,y2;
	cout << setiosflags(ios::fixed);
	while (cin >> x1>>y1>>x2>>y2) {
		float result, temp;
		temp = (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
		result = sqrt(temp);
		cout << setprecision(2) << result << endl;
	}
}*///计算两点之间的距离
//计算球的体积
/*#include <iostream>
#include <iomanip>
#define PI 3.1415927
using namespace std;
int main() {
	double r;
	cout << setiosflags(ios::fixed);
	while (cin >> r) {
		double v;
		v = (4.0 / 3.0)*PI*r*r*r;
		cout << setprecision(3) << v << endl;
	}
	return 0;
}*/
/*#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
int main() {
	int i;
	const double hm =0.1- 1.0 / 240.0, sm = 6.0-0.1, hs = 6.0-1.0/240.0;
	while (cin >> i) {
		double sum = 0, hmr, msr, hsr, j;
		for (j = 1; j <= 3600*24; j++)
		{
			hmr = hm*j;
			msr = sm*j;
			hsr = hs*j;
			hmr = fmod(hmr, 360);
			msr = fmod(msr, 360.0);
			hsr = fmod(hsr, 360.0);
			if (hmr >= i&&msr >= i && (360 - hmr - msr) >= i)
			{
				sum += 1;
				//cout << hsr << ' ' << msr << ' ' << hmr << endl;
			}
			else if (msr >= i&&hsr >= i && (360 - msr - hsr) >= i)
			{
				sum += 1; //cout << hsr << ' ' << msr << ' ' << hmr << endl<<endl;
			}
		}
		sum = sum/ (36*24);
		cout << setiosflags(ios::fixed);
		cout << setprecision(3)<<sum << endl;
	}
	return 0;
}*/
/*#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
int main() {
	double n;
	cout << setiosflags(ios::fixed);
	while (cin >> n) {
		n=fabs(n);
		cout <<setprecision(2)<< n << endl;
	}
	return 0;
}*///计算绝对值
//换算成绩
/*#include <iostream>
using namespace std;
int main() {
	float n;
	char s;
	while (cin >> n) {
		if (n < 0 || n>100)
		{
			cout << "Score is error!" << endl;
			
		}
		else {
			int k;
			k = (int)n / 10;
			switch (k) {
			case 10:s = 'A'; break;
			case 9:s = 'A'; break;
			case 8:s = 'B'; break;
			case 7:s = 'C'; break;
			case 6:s = 'D'; break;
			default:s = 'E'; break;
			}
			cout << s << endl;
		}
	}
	return 0;
}*/
/*#include <iostream>
using namespace std;
int main() {
	long  a[5000],i=0,n;
	while (cin >> n)
	{
		i = 0;
		long long j,m,temp=0,temps;
		a[0] = 1;
		for (j = 1; j <= n; j++) {
			temp = 0;
			for (m = 0; m <= i; m++) {
				 temps= a[m] * j+temp;
				temp = 0;
				
				if (a[m] >= 10)
				{
					temp = a[m] / 10;
					a[m] = a[m] % 10;
				}
				if (m == i&&temp > 0)
				{
					a[m + 1] = temp;
					i++;
					break;
				}
			}
			
		}
		for (m = i; m >= 0; m--)
			cout << a[m];
		cout << endl;
	}
}*/


/*#include <iostream>
const int MAX = 5;
int main() {
	using namespace std;
	int i,j,x,a[12] = { 12,5,6,12,13 };
	i = -1;
	j = 5;
	x = 12;
	while (true) {
		do {
			j--;
		} while (a[j] > x);
		do {
			i++;
		} while (a[i] < x);
		if (i < j) {
			int temp;
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
		else break;

	}
	for (int n = 0; n < 5; ++n) {
		cout << a[n] << ' ';
	}
	cout << endl << j;
	cout << endl;
	system("pause");
	return 0;
}*/


/*
#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;
int main() {
	int n, m;
	while (cin >> n >> m) {
		int l[101], a[101], b[101] = {0};
		memset(a, -1, sizeof(int) * 101);
		bool jud = true,jud2=false,jud3=true;
		for (int i = 1; i <= m; i++) {
			cin >> l[i];
		}
			for (int i = 1; i < m; i++)
			{
				int t;
				if (l[i + 1] < l[i])
					t = l[i + 1] + n;
				else t = l[i + 1];
				a[l[i]] = t - l[i];
				if (a[l[i]] == 0)
					a[l[i]] = n;
				b[l[i]]++;
			}
			for(int i=0;i<=n;i++)
				if (b[i] == 0) {
					jud = false;
				}
			if (!jud)
				cout << "-1" << endl;
			else {
				for (int i = 1; i <= n; i++)
					cout << a[i] << ' ';
				cout << endl;
			}
	}
	return 0;
}*/



/*
#include<stdio.h>  
#include <iostream>
#include<algorithm>  
using namespace std;

int f[10001];
int p[10001];

struct Mouse {
	int w;
	int s;
	int n;
}Mic[10001];

bool compare(const Mouse &a, const Mouse &b) {
	if (a.w == b.w)
		return a.s > b.s;
	else
		return a.w < b.w;
}

void printLIS(int max_l) {
	if (p[max_l] == max_l) {
		printf("%d\n", Mic[max_l].n);
		return;
	}
	printLIS(p[max_l]);
	printf("%d\n", Mic[max_l].n);
}

int main() {
	int i = 1, max = 0, max_l = 0;
	while (cin>>Mic[i].w>>Mic[i].s) {
		f[i] = 1;
		p[i] = i;
		Mic[i].n = i;
		i++;
	}
	sort(Mic + 1, Mic + i, compare);

	for (int k = 1; k<i + 1; k++) {
		for (int j = 1; j<k; j++) {
			if (Mic[j].s>Mic[k].s&&Mic[j].w<Mic[k].w) {
				if ((f[j] + 1)>f[k]) {
					f[k] = f[j] + 1;
					p[k] = j;
					if (f[k]>max) {
						max = f[k];
						max_l = k;
					}
				}
			}
		}
	}
	printf("%d\n", max);
	printLIS(max_l);
	system("pause");
	return 0;
}*///ACM1160



/*
#include <iostream>
#include <string>
using namespace std;
struct Chara {
	char c;
	int t;
	bool used;
	int len;
	Chara *LeftChild;
	Chara *RightChild;
}c[27],*t[27];
void Build_Tree();
void getLenth(Chara*, int);
int main() {
	int n;
	cin >> n;

	while (n--) {
		string s;
		int m;
		cin >> m;
		cin.get();
		cin >> s;
		c[0].c = 'a' - 1;
		c[0].t = 0;
		c[0].used = false;
		for (int i = 1; i < 27; i++) {
			c[i].c = c[i - 1].c + 1;
			c[i].t = 0;
			c[i].len = 0;
			c[i].used = false;
			c[i].LeftChild = NULL;
			c[i].RightChild = NULL;
		}
		for (int i = 0; i < s.size(); i++) {
			int temp;
			temp = s[i] - 'a' + 1;
			c[temp].t++;
		}
		int lenth=0;
		Build_Tree();//建最优二叉树
		for (int i = 0; i < s.size(); i++) {
			int temp;
			temp = s[i] - 'a' + 1;
			lenth += c[temp].len;
		}
		cout << lenth;
		if (lenth > m)
			cout << "no";
		else cout << "yes";
		cout << endl;
	}
	system("pause");
}
void Build_Tree() {
	int p=-1;
	Chara *head=NULL;
	while (true) {
		Chara *f, *s;
		f = s = NULL;
		for (int i = 1; i < 27; i++) {
			if (f == NULL&&s == NULL&&c[i].t != 0&&c[i].used==false)
				f = s = &c[i];
			if (s!=NULL&&c[i].used == false && c[i].t <= s->t&&c[i].t!=0)
			{
				f = s;
				s = &c[i];
			}
		}
		for (int i = 0; i <= p; i++) {
			if (f == NULL&&s == NULL&&t[i]->t != 0 && t[i]->used == false)
				f = s = t[i];
			if (s!=NULL&&t[i]->used == false && t[i]->t <= s->t) {
				f = s;
				s = t[i];
			}
		}//找最小左子树和右子树
		if (f == s) {
			s->used = true;
			f = NULL;
			for (int i = 1; i < 27; i++) {
				if (f == NULL&&c[i].t != 0 && c[i].used == false)
					f = &c[i];
				if (f != NULL&&c[i].used == false && c[i].t <= f->t&&c[i].t != 0)
				{
					f = s;
					s = &c[i];
				}
			}
			for (int i = 0; i <= p; i++) {
				if (f == NULL&&t[i]->t != 0 && t[i]->used == false)
					f = t[i];
				if (f != NULL&&t[i]->used == false && t[i]->t <= f->t) {
					f = t[i];
				}
			}
		}
			if (f ==NULL)break;
		head = new Chara;
		head->LeftChild = f;
		head->RightChild = s;
		head->c = '\0';
		head->used = false;
		head->t = s->t + f->t;
		f->used = true;
		s->used = true;
		p++;
		t[p] = head;
	}
	getLenth(head, 0);
	for (int i = 0; i <= p; i++)
		delete t[i];
}
void getLenth(Chara* p, int n){
	if (p->c >= 'a'&&p->c <= 'z') {
		c[(p->c - 'a' + 1)].len = n;
	}
	else {
		getLenth(p->LeftChild, n+1);
		getLenth(p->RightChild, n+1);
	}
}
*/



/*
#include <iostream>
using namespace std;
int main() {
	int n;
	while (cin >> n&&n!=0) {
		int a[1000];
		long long b[1000];
		for (int i = 0; i < n; i++)
			cin >> a[i];
		b[0] = a[0];
		for (int i = 1; i < n; i++) {
			long long max=-10000;
			bool jud = false;
			for (int j = 0; j < i; j++) {
				if(a[i]>a[j]&&max<b[j])
				{
					max = b[j];
					jud = true;
				}
			}
			if (jud) {
				b[i] = a[i] + max;
			}
			else {
				b[i] = a[i];
			}
		}
		long long max=-10000;
		for (int i = 0; i < n; i++) {
			if (max < b[i])
				max = b[i];
		}
		cout << max<<endl;
	}
}*/


/*
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
int cmp(const char* a, const char* b) {
	return strlen(a) < strlen(b);
}
int main() {
	int t;
	cin >> t;
		while (t--) {
			int n,m;
			char* s[100];
			for (int i = 0; i < 100; i++)
				s[i] = new char[101];
			cin >> n;
			cin.get();
			m = n;
			while (m) {
				m--;
			cin.getline(s[m],101);
			}
			sort(s,s+n-1,cmp);
			//找出最长子串;
			int length, max = 0;
			length =strlen(s[0]) ;
			for (int i = 0; i < length; i++) {
				for (int j = length - 1; j >= i; j--) {
					char str1[101],str2[101];
					bool jud = true;
					strncpy(str1, s[0] + i, (j - i + 1));
					str1[j - i + 1] = '\0';
					strcpy(str2, str1);
					_strrev(str2);
					//cout << str1 << ' ' << str2<<endl;
					for (int a = 1; a < n; a++) {
						/*const char *p = str1, *q = str2;
						char c[10] = "no";
						char *l, *k;
						l = strstr(s[a], q);
						k = strstr(s[a], p);
						if (l == NULL)
							l = c;
						if (k == NULL)
							k = c;
						cout << l << ' ' << k << endl;*//*
						if (strstr(s[a], str1)==NULL && strstr(s[a], str2)==NULL)
						{
							jud = false;
							//break;
						}
					}
					//cout << jud <<' '<<strlen(str1)<<' '<<max<<' '<< (max<((int)strlen(str1))) << endl << endl;
					if (jud&& (max<(int)strlen(str1)))
					{
						max = j - i + 1;
						//break;
					}
				}
			}
			//cout << s[0]+2;
			cout << max<<endl;
			
		}
	}*///acm1238



/*
#include <iostream>
#include <algorithm>
using namespace std;
int a[21][1000] = {0};
int b[21] = {0};
bool cmp(int a, int b) {
	return a < b;
}
void unit() {
	a[0][0] = 0;
	b[0]=1;
	a[1][0] = 0;
	b[1] = 1;
	a[2][0] = 0;
	a[2][1] = 1;
	b[2] = 2;
	a[3][0] = 0;
	a[3][1] = 2;
	a[3][2] = 3;
	b[3] = 3;
	for (int m = 4; m <= 20; m++) {
		for (int r = 0; r < m; r++) {
			int temp;
			for (int i = 0; i < b[r]; i++) {
				temp = (m - r)*r + a[r][i];
				bool jud = true;
				for (int j = 0; j < b[m]; j++) {
				if(temp==a[m][j])
				{
					jud = false;
					break;
				}
				}
				if (jud)a[m][b[m]++] = temp;
			}
		}
		sort(a[m], a[m] + b[m], cmp);
	}
}
int main() {
	unit();
	int n;
	while (cin >> n) {
		for (int i = 0; i < b[n]; i++)
			cout << a[n][i] << ' ';
	}
}*/





/*
#include <iostream>
#include <string>
using namespace std;
int k[100][100] = { 0 };
int main() {
	string a, b;
	while (cin >> a >> b) {		
		int temp=0;
		for (int i = 0; i < a.size(); i++) {
			if (a[i] == b[0])
				temp = 1;
			k[i][0] = temp;
		}
		temp = 0;
		for (int i = 0; i <= b.size(); i++) {
			if (a[0] == b[i])
				temp = 1;
			k[0][i] = temp;
		}
		for (int i = 1; i <= a.size(); i++) {
			for (int j = 1; j < b.size(); j++) {
				if (a[i] == b[j])
					k[i][j] = k[i - 1][j - 1]+1;
				else {
					if (k[i-1][j] > k[i][j - 1])
						k[i][j] = k[i-1][j];
					else k[i][j] = k[i][j-1];
				}
			}
		}
		
		cout << k[a.size()-1][b.size()-1]<< endl;
	}
}
*/
//acmn1159



/*
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
struct Position {
	int x;
	int p;
	int t;
}p[100000],f[100000];
bool cmp(Position a, Position b) {
	return a.t < b.t;
}
void put_right(Position p[], int t) {
	Position key = p[t-1];
	int j = t - 2;
	while (key.p < p[j].p&&j>=0) {
		p[j + 1] = p[j];
		j--;
	}
	p[j + 1] = key;
}
int main() {
	int n, t = 0;
	while (scanf("%d", &n)!=EOF,n) {
		for (int i = 0; i < n; i++) {
			scanf("%d%d", &f[i].x, &f[i].t);
			f[i].p = 1;
		}
		sort(f, f + n, cmp);
		p[0].x = 5;
		p[0].t = 0;
		p[0].p = 0;
		t = 1;
		for (int i = 0; i < n; i++) {
			Position max;
			int j = t - 1;
			max.p = -1;
		while(max.p==-1&&j>=0) {
				if (abs(f[i].x - p[j].x) <= abs(f[i].t - p[j].t) && max.p < p[j].p) {
					max = p[j];
				}	
				j--;
			}
			if (max.p != -1) {
				max.p += f[i].p;
				max.t = f[i].t;
				max.x = f[i].x;
				//cout << t << ' ' << max.t << ' ' << max.p << ' ' << max.t << endl;;
				p[t++] = max;
			}
			put_right(p, t);
		}
		int max = 0;
		for (int i = 0; i < t; i++) {
			if (max < p[i].p)
				max = p[i].p;
		}
		cout << max << endl;
	}
}*/




/*
#include <iostream>
#include <algorithm>
using namespace std;
long long a[2001][2001] = {0};
long long b[2001];
int n, k;
long long tired;
bool cmp(long long a, long long b) {
	return a < b;
}
int main() {
	while (cin >> n >> k) {
		for (int i = 1; i <= n; i++)
		{
			cin >> b[i];
		}
		sort(b+1, b + n+1, cmp);
		for(int j=1;j<=k;j++)
		{
			for (int i = 2*j; i <= n; i++) {
				long temp = a[i - 2][j - 1] + (b[i] - b[i - 1])*(b[i] - b[i - 1]);
				if (i == 2 * j)
					a[i][j] = temp;
				else if (a[i - 1][j] < temp)
					a[i][j] = a[i - 1][j];
				else a[i][j] = temp;
			}
		}
		cout << a[n][k] << endl;
	}
}*///acm1421;


/*
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
		cout << "The " << n ;
		if (n % 10 == 1 && n / 10 != 1)
		{
			cout << "st";
		}
		else if (n % 10 == 2 && n / 10 != 1) {
			cout << "nd";
		}
		else if (n % 10 == 3 && n / 10 != 1) {
			cout << "rd";
		}
		else cout << "th";
		cout << " humble number is " << a[n] << "." << endl;
	}
}*///acm1058




/*
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
				/*	}
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
}*///acm1074

/*
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
string good, bad;
string str;
int question[28], star[28];
int b, e;
bool getstar;
long n;
void judge() {
	int i = 0,j;
	bool same = true;
	getstar = false;
	do{
		if (bad[i] == '*')
		{
			b = i;
			getstar = true;
			break;
		}
		while (bad[i] == '?')
		{
			question[str[i] - 'a' + 1] = 1;
			i++;
		}
		if (bad[i] == '*')
		{
			b = i;
			getstar = true;
			break;
		}
		if (bad[i] != str[i])
		{
			same = false;
		}
		i++;
	} while (same&&i<(bad.size()<str.size()?bad.size():str.size()));
	if (!same) {
		cout << "NO" << endl;
		return;
	}
	if (getstar) {
		i = str.size()-1;
		j = bad.size() - 1;
		do {
			if (bad[j] == '*')
			{
				e = i;
				break;
			}
			while (bad[j] == '?')
			{
				question[str[i] - 'a' + 1] = 1;
				i--;
				j--;
			}
			if (bad[j] == '*')
			{
				e = i;
				break;
			}
			if (bad[j] != str[i])
			same = false;
			i--;
			j--;
		} while (same&&i>=0);
	}
	if (!same) {
		cout << "NO" << endl;
		return;
	}
	if (getstar) {
		for (i = b; i <= e; i++) {
			star[str[i] - 'a' + 1] = 1;
			
		}
	}
	for (i = 1; i <= 26; i++) {
		if (question[i] == 1) {
			char c = i + 'a' - 1;
			bool inside = false;
			for (j = 0; j < good.size(); j++) {
				if (c == good[j])
				{
					inside = true;
					break;
				}
			}
			if (!inside) {
				cout << "NO" << endl;
				return;
			}
		}
	}
	if(getstar)
	for (i = 1; i <= 26; i++) {
		if (star[i] == 1) {
			char c =i + 'a' - 1;
			bool outside = true;
			for (j = 0; j < good.size(); j++) {
				if (c == good[j])
				{
					outside = false;
					break;
				}
			}
			if (!outside) {
				cout << "NO" << endl;
				return;
			}
		}
	}
	cout << "YES" << endl;
}
int main() {
	while (cin >> good >> bad>>n) {
	
		for (int i = 0; i < n; i++) {
			memset(question, 0, sizeof(question));
			memset(star, 0, sizeof(star));
			cin >> str;
			judge();
		}
	}
}*/


/**
#include <iostream>
#include <cmath>
using namespace std;
const double x = log10(10.0) / log10(2.0);
long long k[100001];
int i = 1;
int main() {
	long long m;
	for (double j = 1; j <= 100000; j++) {
		k[(long long)j] = j/x;
	}
	while (cin >> m) {
		cout <<"Case #"<<i<<": "<<k[m] << endl;
		i++;
	}
}*/


/*
#include <iostream>
using namespace std;
long long n, k;
long long temp,t;
int i = 1;
int main() {
	while (cin >> n >> k) {
		t = (n - 1) * 2;
		temp = (k - n) % t + n - 1;
		if (temp >= n&&temp < 2 * n - 1)
			temp = temp - n;
		else if (temp >= 2 * n - 1 && temp < 3 * n - 3)
			temp = temp - (2 * n - 1);
		cout <<"Case #"<<i<<": "<<temp+1 << endl;
		i++;
	}
	return 0;
}
*/



#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <cstring>
using namespace std;
struct Node {
	int x;
	Node *next;
	Node *end;
}a[200001];
int b[200001], c[200001];//数组b为使用过的结点i，c数组为出现过的颜色ci
int n;
int sum = 0;
int t = 1;
void Find(int i) {
	Node *p;
	p = a[i].next;
	while (p != NULL) {
		if (b[p->x] != 1) {
			b[p->x] = 1;
			c[a[p->x].x]++;
			for (int k = 1; k <= n; k++) {
				if (c[k] != 0)
					sum++;
			}
			Find(p->x);
			b[p->x] = 0;
			c[a[p->x].x]--;
		}
		p = p->next;
	}
}
int main() {
	while (cin >> n) {
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i].x;
			a[i].end = &a[i];
			a[i].next = NULL;
		}
		for (int i = 1; i < n; i++) {
			int k, l;
			Node *p;
			cin >> k >> l;
			p = new Node;
			p->x = l;
			p->next = NULL;
			p->end = NULL;
			a[k].end->next = p;
			a[k].end = p;
			p = new Node;
			p->x = k;
			p->next = NULL;
			p->end = NULL;
			a[l].end->next = p;
			a[l].end = p;
		}
		/*for (int i = 1; i <= n; i++) {
		Node *p;
		p = a[i].next;
		cout << i << ' ';
		while (p != NULL) {
		cout << p->x << ' ';
		p = p->next;
		}
		cout << endl;
		}*/
		sum = 0;
		for (int i = 1; i <= n; i++) {
			memset(b, 0, sizeof(b));
			memset(c, 0, sizeof(c));
			b[i] = 1;
			c[a[i].x] = 1;
			Find(i);
			//b[i] = 0;
			c[a[i].x]--;
		}
		for (int i = 1; i <= n; i++) {
			Node *p, *q;
			p = a[i].next;
			if (p != NULL)
				q = p->next;
			else q = NULL;
			while (p != NULL) {
				delete p;
				p = q;
				if (q != NULL)
					q = q->next;
			}
		}
		cout << "Case #" << t << ": " << sum / 2 << endl;
		t++;
	}
	return 0;
}
