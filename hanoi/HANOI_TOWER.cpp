#include"hanoiqueue.h"
#include<iostream>

using namespace std;

int main() {

	int ss;

	cout << "ž�� ũ���?? ";
	cin >> ss;

	hanoi hp = hanoi(ss);
	hp.hanoisearch();

	return 0;

}