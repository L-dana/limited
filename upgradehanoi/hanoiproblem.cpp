#include<iostream>
#include "hanoi.h"

using namespace std;

int main() {
	int s;

	cout << " ž�� ���̴�?";
	cin >> s;

	upgradehanoi sol = upgradehanoi(s);
	sol.hanoisort();

	return 0;
}