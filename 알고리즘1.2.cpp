/* 2019.09.16 월
  알고리즘
  알고리즘 기초    1-알고리즘1.2

  문제: 수가n 개인 배열S에 있는 원소의 수를 모두 더하시오
  입력: 정수n(>0), 수의 배열 S(인덱스의 범위는 1부터n까지)
  출력: S에 있는 모든 수의 합
 */

#include<iostream>

using namespace std;

int main() {
	int index;
	int* ptr = new int[100];
	int sum = 0;

	cin >> index;
	if (index <= 0)index = 1;
	for (int i = 0; i < index; i++) {  // 수 생성
		ptr[i] = i;
	}
	for (int i = 0; i < index; i++) {
		sum += ptr[i];
	}
	cout << sum;

	delete[]ptr;
	return 0;

}