/* 2019.09.19
�˰���
�˰��� ����    1-�˰���1.5

����: ���Ұ� n���� ���ĵ� �迭 S���� ���� x�� ã���ÿ�
�Է�: �ڿ��� n,(�񳻸�����) ���ĵ� �迭S(�ε����� ������ 1����n����), ���� x
���: location, S���� x�� �ִ� ��ġ(���� x�� S�� ������ 0)
*/
#include <iostream>

using namespace std;

int main() {
	int n,x;
	int low = 1, mid, high;
	int location;
	int* S = (int*)malloc(sizeof(int) * 1);

	location = 0;

	cout << "�迭 ũ��";
	cin >> n;
	S = (int*)realloc(S, sizeof(int) * (n + 1));
	high = n;
	cout << endl << "����";
	cin >> x;
	for (int i = 0; i <= n; i++) {
		S[i] = i;
	}
	while (1 <= n&&location == 0) {
		mid = (low + high) / 2;
		if (x == S[mid])
			location = mid;
		else if (x < S[mid])
			high = mid - 1;
		else
			low = mid + 1;
	}
	cout <<"k"<< location;
	free(S);

	return 0;
}