/* 2019.09.19
�˰���
�˰��� ����    1-�˰���1.6

����: �Ǻ���ġ �������� n��° ���� ���Ͻÿ�
�Է�: ���n(0����)
���: fib, �Ǻ���ġ �������� n��° ��
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