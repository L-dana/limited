#pragma once
#ifndef __HEADER_hanoiqueue_
#define __HEADER_hanoiqueue_


class hanoi {
private:
	int hanoi_size;  
	int hanoi_page;
	int* hanoi_state;
	int numof;  // total hanoi_state number
	
public:
	hanoi(int size);  //memory initial and goal deifne

	void hanoisearch(); //search goalstate

	bool hanoicheck(int quenum);  //goal state check

	void hanoi_statewrite(int quenum);  //state memory

	void hanoi_answer(int quenum);  //print

	void write(int *buf,int n,int [],int from);

	~hanoi() {};
};

#endif
