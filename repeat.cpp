/* 2019.09.20  
�˰���
�˰��� ����    1-�˰���1.7

����: �Ǻ���ġ �������� n���� ���� ���Ͻÿ�
�Է�: ��� n(0����)
���: fib, �Ǻ���ġ �������� n��° ��
*/

#include<iostream>
using namespace std;

int main() {
	int i;
	int n;
	int* f = (int*)malloc(sizeof(int) * 1);

	cout << "���� ����?" << endl;
	cin >> n;
	if (n < 0) n = 0;
	f = (int*)realloc(f, sizeof(int) * (n + 1));
	f[0]= 0;
	if (n > 0) {
		f[1] = 1;
		for (i = 2; i <= n; i++)
			f[i] = f[i - 1] + f[i - 2];
	}
	cout <<"n��° ����"<<f[n];
	return 0;

}