/* 2019.10.22
알고리즘
알고리즘 기초    2-분할정복 2.6, 2.7 을 응용

문제: 비내림차순으로 원소가 n개인 배열을 정렬
입력: 양의 정수n, 배열S(인덱스는 1부터 n까지)
출력: 비내림차순으로 정렬된 배열 S


문제: 빠른정렬에서 쓸 수 있도록 배열S를 분할
입력: 인덱스 low와 high, 배열 S에서 low부터 high까지의 부분배열
출력: low부터 high까지 인덱스로 된 S의 부분배열의 기준점 pivotpoint

분할을 큐로 응용
*/

#include <iostream>
#include <ctime>
#include <queue>

using namespace std;

int* S;
queue <int> L;
queue <int> H;

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
	int left = low, right = high;
	L.push(left);
	H.push(right);
	while (L.empty() != 1) {

		L.pop();
		H.pop();

		pivotpoint = partition(left, right);
		cout << endl << "정렬:";
		for (int i = 2; i <= high; i++) {
			cout << S[i] << "  ";
		}
		if ((pivotpoint - 1) > left) { // 왼쪽 분할
			L.push(left);
			H.push(pivotpoint - 1);
		}
		if ((pivotpoint + 1) < right) {  //오른쪽 분할
			L.push(pivotpoint + 1);
			H.push(right);
		}
		if (L.empty() == 1)break;
		left = L.front();
		right = H.front();
	}
}

int main() {
	int size;
	int low = 1, high;

	srand((unsigned)time(NULL));

	cout << "배열의 크기?";
	cin >> size;
	high = size + 1;
	S = (int*)malloc(sizeof(int) * high);  // 배열 할당
	S[0] = 0;
	for (int i = 1; i <= size; i++) {
		S[i] = rand() % size + 1;
	}
	cout << "배열:";
	for (int i = 1; i <= size; i++) {
		cout << S[i] << "  ";
	}cout << endl;
	quicksort(low, high);
	cout << endl << endl << "정렬:";
	for (int i = 2; i <= high; i++) {
		cout << S[i] << "  ";
	}
	// free(S);  버그 발생하는 줄
	return 0;
}