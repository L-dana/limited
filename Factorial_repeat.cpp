/* 2019.09.19
알고리즘
알고리즘 기초    1-팩토리얼 계산하는 알고리즘(반복)

문제: n팩토리얼 구하기
입력: 양수n
출력: n팩토리얼
*/

#include<iostream>
using namespace std;

int main() {
	int n;
	int ans = 1;

	cin >> n;

	for (int i = 1; i <= n; i++) {
		ans = ans * i;
	}

	cout << ans;

	return 0;
}