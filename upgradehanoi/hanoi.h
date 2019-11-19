#pragma once
#ifndef __HEADER_hanoi_
#define __HEADER_hanoi_

typedef struct hanoistr { //hanoi state node

	int stateindex;  //state number
	int* hanoistate;  //state
	hanoistr* ancestor;
	hanoistr* nextnode;    // location of nextnode 

}hanoin;

class upgradehanoi {

private:
	int quenum;
	int hanoi_size;
	int hanoi_page;
	hanoin* start, * end, * buf, * ptr;

public:
	upgradehanoi(int size);  // setting

	void hanoisort();     // core algorithem

	void hanoiwrite(int quenum);  // new state write

	void generate(int ele[3], int from);  // node generate

	bool pedigree( int* trans);  // ancestor search

	bool check(int quenum);  // goal = return true

	void answer(int quenum);  // 마무리

	void glist(int quenum);   // make g-list

};
/*class upgradehanoi {
private:

	int hanoi_size;
	int hanoi_page;
	int numof;  // total hanoi_state number

public:
	upgradehanoi(int size);

	void hanoisearch(); //search goalstate

	bool hanoicheck(int quenum);  //goal state check

	void hanoi_statewrite(int quenum);  //state memory

	void hanoi_answer(int quenum);  //print

	void write(int* buf, int n, int[], int from);

	void node_f();

	~upgradehanoi() {};
};*/


#endif
