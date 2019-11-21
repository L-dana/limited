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
	while (1) {  // 해당 번호의 노드를 찾아줌
		if (buf->stateindex == quenum) break;
		else
			buf = buf->nextnode;
	}
	for (int x = 0; x < hanoi_page; x++) {
		cout << buf->hanoistate[x] << " ";
	}
	cout <<endl; //start node state
	for (int y = 0; y < 3; y++) { //탑의 높이 세기
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
	
		the = pedigree(trans);  // 조상 노드 조사
		if (the == false) {  // 조상노드 중 같은 노드가 없다면 ptr에 공간을 할당해 다음노드 저장
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
		if (the == false) {  // 조상노드 중 같은 노드가 없다면 ptr에 공간을 할당해 다음노드 저장
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

	hanoin* trace=start;  //임시주소변수
	//cout << trace << " ---- " << buf <<endl;  0
	int ch = 0;  //같은것의 개수
	while (1) {
		if (trace->nextnode == NULL)break;
		for (int x = 0; x < hanoi_page; x++) {
			if (trace->hanoistate[x] == translate[x])ch++;
		}
		if (ch == hanoi_page) return true;  // 어떤 노드와 전부 일치한다면
		trace = trace->nextnode;
		ch=0;
	}
	return false;  //같은게 없다면 false
}

bool upgradehanoi::check(int quenum) {  // 목표 상태에 도달했는지 검사하는 함수
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

void upgradehanoi::glist(int quenum) {
	hanoin** liststack;
	int stacksize = 1;

	buf = start;
	while (1) {  //buf에 quenum에 해당하는 노드 저장.
		if (buf->stateindex == quenum) break;
		else
			buf = buf->nextnode;
	}
	liststack = (hanoin**)calloc(1, sizeof(hanoin*));

	while (1) {//조상을 거슬러 올라가면서 스택에 노드의 시작주소를 저장
		liststack = (hanoin**)realloc(liststack, sizeof(hanoin*) * stacksize);
		// 스택 확장

		liststack[stacksize - 1] = buf;
		// 스택의 끝(top)에 노드의 시작주소 저장 (0~[stacksize-1])

		if (buf->ancestor == NULL)break;  // 상위노드 존재여부 검사
		buf = buf->ancestor;  // 상위노드가 없다면 그 노드로(상위노드로) 이동
		stacksize++;  // 스택 사이즈 키우기(top이동)

	}//end while

	for (int h = (stacksize - 1); h >= 0; h--) {
		cout << liststack[h]->stateindex << "번째 노드 ";
		for (int c = 0; c < hanoi_page; c++) {
			cout << liststack[h]->hanoistate[c] << " ";
		}
		cout << endl;
	}
}

void upgradehanoi::answer(int quenum) {  // 목표에 도달한 과정을 출력하고 노드를 해제해주는 함수
	char code;
	hanoin* delo;

	for (int z = 0; z < hanoi_page; z++) {
		cout << buf->hanoistate[z] << " ";
	}
	cout << endl << endl;

	for (int u = 0; u < 3; u++) {
		cout << u + 1 << "번 탑 ";
		for (int i = 1; i <= hanoi_size; i++) {
			cout << buf->hanoistate[u*(hanoi_size+1)+i] << " ";
		}
		cout << endl;
	}

	cout <<"아무 키나 입력 시 종료, 조상추적 - t, 조상리스트 추출 - g ";
	cin >> code;
	switch (code) {
	case('t'):
		while (buf->ancestor != NULL) {
			cout<<buf->stateindex<<"번째 노드 ";
			for (int z = 0; z < hanoi_page; z++) {
				cout << buf->hanoistate[z] << " ";
			}
			cout << endl << endl;
			buf = buf->ancestor;
		}
		cout << buf->stateindex << "번째 노드 ";
		for (int x = 0; x < hanoi_page; x++) {
			cout << start->hanoistate[x] << " ";
		}
		break;

	case('g'):
		glist(quenum);  // g리스트 추출 함수

	default:
		cout << "종료";
		ptr = start;
		while (ptr) {
			delo = ptr;
			ptr = ptr->nextnode;
			free(delo);
		}
		ptr = NULL;
	}

}
