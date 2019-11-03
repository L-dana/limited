#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

int* s;

int location(int low, int high,int node) {
	int mid;

	if (low > high)return 0;
	else {
		mid = (low+high) / 2;
		if (node == s[mid])return mid;
		else if (node < s[mid])return location(low, mid-1, node);  //left
		else return location(mid+1, high, node);                  //right
	}
}

int main() {

	int node,size;
	int low, high;
	int answer_location;

	s = (int*)malloc(sizeof(int) * 1);

	cout << "크기와 찾을 원소 입력";
	cin >> size;
	cin >> node;
	
	s = (int*)realloc(s,sizeof(int)*(size + 1));

	s[0] = 0;
	cout << "배열 원소 입력(오름차순으로)";
	for (int i = 1; i <= size; i++) {
		cin >> s[i];
	}
	cout << "원소 입력 종료";
	low = 1;
	high =size;
	cout << endl<<"원소의 위치는"<< location(low,high,node);

	return 0;
}