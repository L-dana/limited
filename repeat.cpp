/* 2019.09.20  
알고리즘
알고리즘 기초    1-알고리즘1.7

문제: 피보나치 수열에서 n번쨰 항을 구하시오
입력: 양수 n(0포함)
출력: fib, 피보나치 수열에서 n번째 항
*/

#include<iostream>
using namespace std;

int main() {
	int i;
	int n;
	int* f = (int*)malloc(sizeof(int) * 1);

	cout << "구할 항은?" << endl;
	cin >> n;
	if (n < 0) n = 0;
	f = (int*)realloc(f, sizeof(int) * (n + 1));
	f[0]= 0;
	if (n > 0) {
		f[1] = 1;
		for (i = 2; i <= n; i++)
			f[i] = f[i - 1] + f[i - 2];
	}
	cout <<"n번째 항은"<<f[n];
	return 0;

}