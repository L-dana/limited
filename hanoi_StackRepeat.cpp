/* 2019.10.29
�˰���
�˰��� ����    �ϳ����� ž �˰���(�ݺ�,����)


*/

#include <iostream>
#include <stack>

using namespace std;

stack<int> num;

void move(char from, char to) {

	cout <<from << "���� " << to << "�� �̵�." << endl;

}

void hano(int n, char from, char by, char to) {
	int exc;
	while (1) {
		while (n > 1) {

			num.push(to);
			num.push(by);
			num.push(from);
			num.push(n);
			n--;

			exc = to;
			to = by;
			by = exc;
		}
		move(from, to);

		if (num.empty() != 1) {
			n = num.top();
			num.pop(); //n
			from = num.top();
			num.pop(); //from
			by = num.top();
			num.pop(); //by
			to = num.top();
			num.pop(); //to
			move(from, to);

			n--;
			exc = from;
			from = by;
			by = exc;
		}
		else
			break;
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