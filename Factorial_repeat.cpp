/* 2019.09.19
�˰���
�˰��� ����    1-���丮�� ����ϴ� �˰���(�ݺ�)

����: n���丮�� ���ϱ�
�Է�: ���n
���: n���丮��
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