/* 2019.09.19
알고리즘
알고리즘 기초    1-알고리즘1.5

문제: 원소가 n개인 정렬된 배열 S에서 원소 x를 찾으시오
입력: 자연수 n,(비내림차순) 정렬된 배열S(인덱스의 범위는 1부터n까지), 원소 x
출력: location, S에서 x가 있는 위치(만약 x가 S에 없으면 0)
*/
#include <iostream>

using namespace std;

int main() {
	int n,x;
	int low = 1, mid, high;
	int location;
	int* S = (int*)malloc(sizeof(int) * 1);

	location = 0;

	cout << "배열 크기";
	cin >> n;
	S = (int*)realloc(S, sizeof(int) * (n + 1));
	high = n;
	cout << endl << "원소";
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