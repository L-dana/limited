/* 2019.09.29
�˰���
�˰��� ����    2-�������� 2.6, 2.7

����: �񳻸��������� ���Ұ� n���� �迭�� ����
�Է�: ���� ����n, �迭S(�ε����� 1���� n����)
���: �񳻸��������� ���ĵ� �迭 S


����: �������Ŀ��� �� �� �ֵ��� �迭S�� ����
�Է�: �ε��� low�� high, �迭 S���� low���� high������ �κй迭
���: low���� high���� �ε����� �� S�� �κй迭�� ������ pivotpoint

*/

#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

int* S;

int partition(int low, int high, int pivotpoint) {
	int i, j;
	int exchange;
	int pivotitem;
	pivotitem = S[low];
	j = low;
	for (i = low ; i <= high; i++) {
		if (S[i] < pivotitem) {
			j++;
			exchange = S[i];
			S[i] = S[j];
			S[j] = exchange;
		}
	}
	pivotpoint = j;
	exchange = S[low];
	S[low]=S[pivotpoint];
	S[pivotpoint] = exchange;

	return pivotpoint;
}

void quicksort(int low,int high) {
	int pivotpoint=low;

	if (high > low) {
		pivotpoint = partition(low, high, pivotpoint);
		quicksort(low, pivotpoint - 1);
		quicksort(pivotpoint + 1, high);
	}
}

int main() {
	int size;
	int low=1, high;

	srand((unsigned)time(NULL));

	cout << "�迭�� ũ��?";
	cin >> size;
	high = size + 1;
	S = (int*)malloc(sizeof(int) * (size+1));  // �迭 �Ҵ�
	S[0] = 0;
	for (int i = 1; i <= size; i++) {
		S[i] = rand() % size + 1;
	}
	cout << "�迭:";
	for (int i = 1; i <= size; i++) {
		cout << S[i] << "  ";
	}
	quicksort(low, high);
	cout << endl<<"����:";
	for (int i = 2; i <= size+1; i++) {
		cout << S[i] << "  ";
	}
	return 0;

	//S = (int*)realloc(S, sizeof(int) * size);
}