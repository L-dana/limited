/* 2019.09.07 ��
  �˰���
  �˰��� ����    1-�˰���1.1

  ����: ���Ұ� n���� �迭S�� ����x �� �ִ°�?
  �Է�: ���� n(>0), �迭 S(�ε��� ������ 1����n����), ����x
  ���: ����x�� ��ġ�� �ε����� location�� ����(S�ȿ� x�� ������ 0�� ����)
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