/* 2019.10.29
�˰���
�˰��� ����    �ϳ����� ž �˰���(���)


*/

#include <iostream>

using namespace std;

void move(char from, char to) {

	cout << from << "���� " << to << "�� �̵�." << endl;

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

	cout << "ž�� �� ����? :";
	cin >> flow;
	hano(flow, from, by, to);

	return 0;
}