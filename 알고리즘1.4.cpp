/* 2019.09.16 월
  알고리즘
  알고리즘 기초    1-알고리즘1.4

  문제: 두 n*n 행렬의 곱을 구하시오
  입력: 정수n(>0), 수의 2차원 배열 A와 B 여기서 이 행렬의 행과 열은 모두 1부터n 까지 인덱스를 붙인다.
  출력: A와 B행렬의 곱이 표현된 2차원 배열 C 여기서 이 행렬의 행과 열은 모두 1부터 n까지 인덱스를 붙인다.
 */

#include<iostream>

using namespace std;

int main() {
	int A[2][2] = { {2,3},{4,1} };
	int B[2][2] = { {5,7},{6,8} };
	int C[2][2] = { 0 };
	int i, j, k;

	for (i = 0; i < 2; i++) {
		for (j = 0; j < 2; j++) {
			C[i][j] = 0;
			for (k = 0; k < 2; k++)
				C[i][j] = C[i][j] + A[i][k] * B[k][j];
		}
	}
	for (i = 0; i < 2; i++) {
		for (j = 0; j < 2; j++) {
			cout<<C[i][j]<<" ";
		}
		cout << endl;
	}

	return 0;

}