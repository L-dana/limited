/* 2019.10.11
�˰���
�˰��� ����    2-�������� 2.6, 2.7 �� ����

����: �񳻸��������� ���Ұ� n���� �迭�� ����
�Է�: ���� ����n, �迭S(�ε����� 1���� n����)
���: �񳻸��������� ���ĵ� �迭 S


����: �������Ŀ��� �� �� �ֵ��� �迭S�� ����
�Է�: �ε��� low�� high, �迭 S���� low���� high������ �κй迭
���: low���� high���� �ε����� �� S�� �κй迭�� ������ pivotpoint

������ �������� ����
*/

#include <iostream>
#include <ctime>
#include <stack>

using namespace std;

int* S;
stack <int> L;
stack <int> H;

int partition(int low, int high) {
	int i, j;
	int exchange;
	int pivotitem;
	pivotitem = S[low];
	j = low;
	for (i = low; i <= high; i++) {
		if (S[i] < pivotitem) {
			j++;
			exchange = S[i];
			S[i] = S[j];
			S[j] = exchange;
		}
	}
	exchange = S[low];
	S[low] = S[j];
	S[j] = exchange;

	return j;
}

void quicksort(int low, int high) {
	int pivotpoint = low;
	int left=low, right=high;
	L.push(left);
	H.push(right);
	while (L.empty()!=1) {

		L.pop();
		H.pop();

		pivotpoint= partition(left, right);
		cout << endl << "����:";
		for (int i = 2; i <= high ; i++) {
			cout << S[i] << "  ";
		}
		if ((pivotpoint + 1) < right) {  //������ ����
			L.push(pivotpoint + 1);
			H.push(right);
		}
		if ((pivotpoint - 1) > left) { // ���� ����
			L.push(left);
			H.push(pivotpoint - 1);
		}
		if (L.empty() == 1)break;
		left = L.top();
		right = H.top();
	}
}

int main() {
	int size;
	int low = 1, high;

	srand((unsigned)time(NULL));

	cout << "�迭�� ũ��?";
	cin >> size;
	high = size + 1;
	S = (int*)malloc(sizeof(int) * high);  // �迭 �Ҵ�
	S[0] = 0;
	for (int i = 1; i <= size; i++) {
		S[i] = rand() % size + 1;
	}
	cout << "�迭:";
	for (int i = 1; i <= size; i++) {
		cout << S[i] << "  ";
	}cout << endl;
	quicksort(low, high);
	cout << endl << endl << "����:";
	for (int i = 2; i <= high ; i++) {
		cout << S[i] << "  ";
	}
	free(S);  
	return 0;
}