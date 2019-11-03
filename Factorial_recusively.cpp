/* 2019.09.19
알고리즘
알고리즘 기초    1-팩토리얼 계산하는 알고리즘(재귀)

문제: n팩토리얼 구하기
입력: 양수n
출력: n팩토리얼
*/

#include<iostream>
using namespace std;
int Factorial(int n) {

	if (n <= 1)return 1;
	else return n * Factorial(n - 1);

}

int main() {
	int input;

	cin >> input;
	if (input < 0)input = 1;
	cout<< endl<<Factorial(input);

}