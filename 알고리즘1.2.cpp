/* 2019.09.16 ��
  �˰���
  �˰��� ����    1-�˰���1.2

  ����: ����n ���� �迭S�� �ִ� ������ ���� ��� ���Ͻÿ�
  �Է�: ����n(>0), ���� �迭 S(�ε����� ������ 1����n����)
  ���: S�� �ִ� ��� ���� ��
 */

#include<iostream>

using namespace std;

int main() {
	int index;
	int* ptr = new int[100];
	int sum = 0;

	cin >> index;
	if (index <= 0)index = 1;
	for (int i = 0; i < index; i++) {  // �� ����
		ptr[i] = i;
	}
	for (int i = 0; i < index; i++) {
		sum += ptr[i];
	}
	cout << sum;

	delete[]ptr;
	return 0;

}