/* 2019.10.29
알고리즘
알고리즘 기초    하노이의 탑 알고리즘(반복,스택)


*/

#include <iostream>
#include <stack>

using namespace std;

stack<int> num;

void move(char from, char to) {

	cout <<from << "에서 " << to << "로 이동." << endl;

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

	cout << "탑의 층 수는? :";
	cin >> flow;
	hano(flow, from, by, to);

	return 0;
}