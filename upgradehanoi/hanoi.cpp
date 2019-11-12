#include "hanoi.h"
#include <iostream>

using namespace std;

upgradehanoi::upgradehanoi(int size) {
	quenum = 1;
	hanoi_size = size;
	hanoi_page = (hanoi_size + 1) * 3;
	start = NULL;
	end = NULL;
	buf = NULL;
	ptr = NULL;
	cout << "hanoi instance create" << endl;
}

void upgradehanoi::hanoisort() {
	start = (hanoin*)calloc(1, sizeof(hanoin));
	start->stateindex = 1;
	start->hanoistate = (int*)calloc(hanoi_page, sizeof(int));
	start->ancestor = NULL;
	start->nextnode = NULL;
	end = start;    // start node define

	for (int x = 1; x <= hanoi_size; x++) {
		start->hanoistate[x] = hanoi_size - x + 1;
	}
	for (int x = 0; x < hanoi_page; x++) {
		cout << start->hanoistate[x] << " ";
	}
	cout << endl; //start node state
	cout << "sort start";
	while (1) {
		hanoiwrite(quenum);
		if (check(quenum) == true)
			break;
		quenum++;
		cout << "loop w" << quenum << endl;
	} 
	cout << "goal state -" << endl;
	answer(quenum);
}

void upgradehanoi::hanoiwrite(int quenum) {

	int element[3] = { 0 };
	buf = start;
	while (1) {  // �ش� ��ȣ�� ��带 ã����
		if (buf->stateindex == quenum) break;
		else
			buf = buf->nextnode;
	}
	for (int x = 0; x < hanoi_page; x++) {
		cout << buf->hanoistate[x] << " ";
	}
	cout <<endl; //start node state
	for (int y = 0; y < 3; y++) { //ž�� ���� ����
		int jump = (hanoi_size + 1) * y;
		int k = 1;
		while (k <= hanoi_size) {
			if (buf->hanoistate[jump + k] != 0)
				element[y]++;
			k++;
		}
	}//0
	for (int y = 0; y < 3; y++) {
		if (element[y] != 0)generate(element,y);
	}
}//0

void upgradehanoi::generate(int ele[3], int from) {
	
	int one = 0, two = 0;
	int jump = hanoi_size + 1;
	int* trans;
	bool the;

	trans = (int*)calloc(hanoi_page, sizeof(int));

	for (int x = 0; x < hanoi_page; x++) {
		trans[x] = buf->hanoistate[x];
	}

	switch (from) {  //define to
	case(0):
		one = 1;
		two = 2;
		break;
	case(1):
		one = 0;
		two = 2;
		break;
	case(2):
		one = 0;
		two = 1;
		break;
	}// 0 cout << endl << "node" << endl;
	//0
	
	if (ele[one] == 0 || trans[jump * from + ele[from]] < trans[jump * one + ele[one]]) {  // from - > one
		trans[jump * one + ele[one] + 1] = trans[jump * from + ele[from]];
		trans[jump * from + ele[from]] = 0;  
	
		the = pedigree(trans);  // ���� ��� ����
		if (the == false) {  // ������ �� ���� ��尡 ���ٸ� ptr�� ������ �Ҵ��� ������� ����
			ptr = (hanoin*)calloc(1, sizeof(hanoin));  //0
			ptr->hanoistate = (int*)calloc(hanoi_page, sizeof(int));
			//cout << ptr << " ---- " << trans <<endl;
			for (int z = 0; z < hanoi_page; z++) {
				ptr->hanoistate[z] = trans[z];
			}
			cout << "new node write ";
			for (int z = 0; z < hanoi_page; z++) {
				cout << ptr->hanoistate[z] << " ";
			}
			cout << endl;
			ptr->ancestor = buf;
			ptr->nextnode = NULL;
			ptr->stateindex = end->stateindex + 1;
			end->nextnode = ptr;
			end = ptr;
		}
	}
	for (int x = 0; x < hanoi_page; x++) {
		trans[x] = buf->hanoistate[x];
	}
	if (ele[two] == 0 || trans[jump * from + ele[from]] < trans[jump * two + ele[two]]) {  // from - >two
		trans[jump * two + ele[two] + 1] = trans[jump * from + ele[from]];
		trans[jump * from + ele[from]] = 0;
	
		the = pedigree(trans);
		if (the == false) {  // ������ �� ���� ��尡 ���ٸ� ptr�� ������ �Ҵ��� ������� ����
			ptr = (hanoin*)calloc(1, sizeof(hanoin));
			ptr->hanoistate = (int*)calloc(hanoi_page, sizeof(int));//0
			for (int z = 0; z < hanoi_page; z++) {
				ptr->hanoistate[z] = trans[z];
			}
			cout << "new node write ";
			for (int z = 0; z < hanoi_page; z++) {
				cout << ptr->hanoistate[z] << " ";
			}
			cout << endl;
			ptr->ancestor = buf;
			ptr->nextnode = NULL;
			ptr->stateindex = end->stateindex + 1;
			end->nextnode = ptr;
			end = ptr;
		}
	}
	free(trans);
}

bool upgradehanoi::pedigree(int * translate) {

	hanoin* trace=buf;  //�ӽ��ּҺ���
	//cout << trace << " ---- " << buf <<endl;  0
	int ch = 0;  //�������� ����
	while (1) {
		if (trace->ancestor == NULL)break;
		trace = trace->ancestor;
		for (int x = 0; x < hanoi_page; x++) {
			if (trace->hanoistate[x] == translate[x])ch++;
		}
		if (ch == hanoi_page) return true;  // � ���� ���� ��ġ�Ѵٸ�
	}
	return false;  //������ ���ٸ� false
}

bool upgradehanoi::check(int quenum) {  // ��ǥ ���¿� �����ߴ��� �˻��ϴ� �Լ�
	int ck = 0;
	int to;

	cout << endl << "state check" << endl;
	if (hanoi_size % 2 == 1)to = 1;
	else to = 2;
	for (int k = 0; k <= hanoi_size ; k++) {
		if (buf->hanoistate[(hanoi_size + 1) * to + k] == start->hanoistate[k])
			ck++;
	}
	if (ck != hanoi_size + 1) return false;
	return true;
}

void upgradehanoi::answer(int quenum) {  // ��ǥ�� ������ ������ ����ϰ� ��带 �������ִ� �Լ�
	char code;
	hanoin* delo;

	for (int z = 0; z < hanoi_page; z++) {
		cout << buf->hanoistate[z] << " ";
	}
	cout << endl << endl;

	for (int u = 0; u < 3; u++) {
		cout << u + 1 << "�� ž ";
		for (int i = 1; i <= hanoi_size; i++) {
			cout << buf->hanoistate[u*(hanoi_size+1)+i] << " ";
		}
		cout << endl;
	}

	cout <<"�ƹ� Ű�� �Է� �� ����, �������� - t ";
	cin >> code;
	switch (code) {
	case('t'):
		while (buf->ancestor != NULL) {
			cout<<buf->stateindex<<"��° ��� ";
			for (int z = 0; z < hanoi_page; z++) {
				cout << buf->hanoistate[z] << " ";
			}
			cout << endl << endl;
			buf = buf->ancestor;
		}
		cout << buf->stateindex << "��° ��� ";
		for (int x = 0; x < hanoi_page; x++) {
			cout << start->hanoistate[x] << " ";
		}
		break;

	default:
		cout << "����";
		ptr = start;
		while (ptr) {
			delo = ptr;
			ptr = ptr->nextnode;
			free(delo);
		}
		ptr = NULL;
	}

}