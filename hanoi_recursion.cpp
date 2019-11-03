/* 2019.10.29
알고리즘
알고리즘 기초    하노이의 탑 알고리즘(재귀)


*/

#include <iostream>

using namespace std;

void move(char from, char to) {

	cout << from << "에서 " << to << "로 이동." << endl;

}

void hano(int n, char from, char by, char to) {
	if (n == 1)move(from, to);
	else {
		hano(n - 1, from, to, by);
		move(from, to);
		hano(n - 1, by, from, to);
	}
}

int main() {

	int flow;
	char from = 'a';
	char by = 'b';
	char to = 'c';

	cout << "탑의 층 수는? :";
	cin >> flow;
	hano(flow, from, by, to);

	return 0;
}