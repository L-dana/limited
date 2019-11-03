/* 2019.09.19
알고리즘
알고리즘 기초    1-알고리즘1.6

문제: 피보나치 수열에서 n번째 수를 구하시오
입력: 양수n(0포함)
출력: fib, 피보나치 수열에서 n번째 항
*/

#include<iostream>
using namespace std;

int fib(int n) {
	if (n <= 1)
		return n;
	else
		return fib(n - 1) + fib(n - 2);
}
int main() {
	int input;
	int output;

	cin >> input;
	if (input < 0)input = 0;
	output = fib(input);
	cout << output;

	return 0;
}