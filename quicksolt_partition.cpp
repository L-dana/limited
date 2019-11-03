/* 2019.09.29
알고리즘
알고리즘 기초    2-분할정복 2.6, 2.7

문제: 비내림차순으로 원소가 n개인 배열을 정렬
입력: 양의 정수n, 배열S(인덱스는 1부터 n까지)
출력: 비내림차순으로 정렬된 배열 S


문제: 빠른정렬에서 쓸 수 있도록 배열S를 분할
입력: 인덱스 low와 high, 배열 S에서 low부터 high까지의 부분배열
출력: low부터 high까지 인덱스로 된 S의 부분배열의 기준점 pivotpoint

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

	cout << "배열의 크기?";
	cin >> size;
	high = size + 1;
	S = (int*)malloc(sizeof(int) * (size+1));  // 배열 할당
	S[0] = 0;
	for (int i = 1; i <= size; i++) {
		S[i] = rand() % size + 1;
	}
	cout << "배열:";
	for (int i = 1; i <= size; i++) {
		cout << S[i] << "  ";
	}
	quicksort(low, high);
	cout << endl<<"정렬:";
	for (int i = 2; i <= size+1; i++) {
		cout << S[i] << "  ";
	}
	return 0;

	//S = (int*)realloc(S, sizeof(int) * size);
}