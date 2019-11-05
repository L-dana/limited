#include"hanoiqueue.h"
#include<iostream>

using namespace std;

int main() {

	int ss;

	cout << "탑의 크기는?? ";
	cin >> ss;

	hanoi hp = hanoi(ss);
	hp.hanoisearch();

	return 0;

}