/* 2019.09.19
�˰���
�˰��� ����    1-���丮�� ����ϴ� �˰���(���)

����: n���丮�� ���ϱ�
�Է�: ���n
���: n���丮��
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