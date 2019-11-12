#include<iostream>
#include "hanoi.h"

using namespace std;

int main() {
	int s;

	cout << " 탑의 높이는?";
	cin >> s;

	upgradehanoi sol = upgradehanoi(s);
	sol.hanoisort();

	return 0;
}