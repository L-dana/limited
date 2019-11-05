#include "hanoiqueue.h"
#include <iostream>

hanoi::hanoi(int size){
	numof = 1;
	hanoi_size = size;
	hanoi_page = (hanoi_size + 1) * 3;
	hanoi_state = (int*)calloc(1*hanoi_page, sizeof(int));     //memory assign(hanoi tower A,B,C)
	                                                           //calloc ( page * ( tower * ( size +1 ) ) )

	for (int i = 1; i<=hanoi_size; i++) {                 //first hanoi tower state define
		hanoi_state[i] = hanoi_size-i+1;
	}
	std::cout << "하노이 탑 처음 상태" << std::endl;  //first state print
	for (int u = 0; u < 3; u++) {
		std::cout << u + 1 << "번 탑 ";
		for (int i = 1; i <= hanoi_size; i++) {
			std::cout << hanoi_state[(hanoi_size+1)*u+i] << "  ";
		}
		std::cout<<std::endl;
	}
}//0

void hanoi::hanoisearch() {  //search goal state
	int quenum=1;
	std::cout << "start" <<std::endl;  // 0
	while (1) {
		hanoi_statewrite(quenum);
		if (hanoicheck(quenum)==true)
			break;  
		quenum++;
		std::cout << "loop w" << std::endl;
	}
	hanoi_answer(quenum);
}

bool hanoi::hanoicheck(int quenum) {    //goal state = tower A >> tower C
										//if goal state = true
	int ck = 0;
	for (int k = 0; k < hanoi_size + 1; k++) {
		if (hanoi_state[hanoi_page * quenum +(hanoi_size + 1)*2+k]== hanoi_state[k])
			ck++;
	}
	if (ck != hanoi_size+1) return false;
	return true;
}

void hanoi::hanoi_statewrite(int quenum) {  //create next state and save next state

	int q[3] = { 0 };  // 타워별 원소갯수
	int* c;            //buffer [3*hanoi_size+1]

	c = (int*)calloc(sizeof(int), 3*(hanoi_size + 1)); // 
	for (int h = 0; h <= hanoi_page; h++) {
		c[h] = hanoi_state[((quenum - 1) * hanoi_page) + h];
	}
	/*
	for (int h = 0; h < hanoi_page; h++) {
		std::cout << c[h] << " ";
	}
	std::cout << std::endl; */
	for (int y = 0; y < 3; y++) { //탑의 높이 세기
		int jump = (hanoi_size + 1) * y;
		int k = 1;
		while (k <= hanoi_size) {
			if (c[jump + k] != 0)
				q[y]++;
			k++;
		}
	}
	// std::cout << 2 << std::endl;  0

	for (int y = 0; y < 3; y++) {  // 봉마다 움직이는 경우 
		int jump = (hanoi_size + 1) * y;

		if (q[y] != 0) { // 해당 봉의 원소가 0개가 아니면
			write(c, numof, q, y);  // y=from 
		}
	}
}

void hanoi::write(int *buf,int n,int qq[3], int from) {   // check and move
	int one, two;
	switch(from){  //define to
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
	}

	if (qq[one] == 0 || buf[(hanoi_size+1)*from+qq[from]] < buf[(hanoi_size + 1) * one + qq[one]]) {  // from > one
		numof++; // 총 하노이 상태 수 +1 
		hanoi_state = (int*)realloc(hanoi_state, sizeof(int) * (numof*hanoi_page)); // 메모리 확장
		for (int wr = 0; wr < hanoi_page; wr++) {
			hanoi_state[hanoi_page * (numof - 1) + wr] = buf[wr];
		}
		hanoi_state[hanoi_page * (numof - 1) + (hanoi_size + 1) * one + qq[one] + 1] = buf[(hanoi_size + 1) * from + qq[from]];
		hanoi_state[hanoi_page * (numof - 1) + (hanoi_size + 1) * from + qq[from]] = 0;
		for (int h = 0; h < hanoi_page; h++) {
			std::cout << hanoi_state[hanoi_page * (numof - 1)+h] <<" ";
		}
		std::cout << std::endl; 
	}
	if (qq[two] == 0|| buf[(hanoi_size + 1) * from + qq[from]] < buf[(hanoi_size + 1) * two + qq[two]]) {  // from > two
		numof++; // 총 하노이 상태 수 +1 
		hanoi_state = (int*)realloc(hanoi_state, sizeof(int) * (numof*hanoi_page)); // 메모리 확장
		for (int wr = 0; wr < hanoi_page; wr++) {
			hanoi_state[hanoi_page * (numof - 1) + wr] = buf[wr];
		}
		hanoi_state[hanoi_page * (numof - 1) + (hanoi_size + 1) * two + qq[two] + 1] = buf[(hanoi_size + 1) * from + qq[from]];
		hanoi_state[hanoi_page * (numof - 1) + (hanoi_size + 1) * from + qq[from]] = 0;
		for (int h = 0; h < hanoi_page; h++) {
			std::cout << hanoi_state[hanoi_page * (numof - 1)+h] <<" ";
		}
		std::cout << std::endl; 
	}
}

void hanoi::hanoi_answer(int quenum) {
	std::cout << "하노이 탑 결과" << std::endl;  //init state print
	for (int x = 0; x < hanoi_page; x++) {
		std::cout << hanoi_state[hanoi_page * quenum + x] << " ";
	}
	std::cout << std::endl;

	for (int u = 0; u < 3; u++) {
		std::cout << u + 1 << "번 탑 ";
		for (int i = 1; i <= hanoi_size; i++) {
			std::cout << hanoi_state[hanoi_page * quenum + (hanoi_size + 1) * u + i] << "  ";
		}
		std::cout << std::endl;
	}
}