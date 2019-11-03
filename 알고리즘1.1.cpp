/* 2019.09.07 토
  알고리즘
  알고리즘 기초    1-알고리즘1.1

  문제: 원소가 n개인 배열S에 원소x 가 있는가?
  입력: 정수 n(>0), 배열 S(인덱스 범위는 1부터n까지), 원소x
  출력: 원소x가 위치한 인덱스를 location에 저장(S안에 x가 없으면 0을 저장)
 */

#include <iostream>
#include <stdlib.h>

using namespace std;

int main(){
	int input;
	int qq;
	int* ptr = new int[100];
	int location=1;

	cin >> input;
	if (input <= 0)input =1;
	cin >> qq;
	for (int i = 0; i < input; i++) {
		ptr[i] = i;
	}
	while (location <= input && ptr[location] != qq)
		location++;
	if (location > input)
		location = 0;
	cout << location;

	delete[]ptr;
	return 0;

	}