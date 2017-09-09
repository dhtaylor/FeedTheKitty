#pragma once

#include "Partition.h"

class TimingWheel {
private:
	int max_delay;
	int current_slot;
	Partition * slot;
public:
	TimingWheel(int maxDelay);
	~TimingWheel();

	void insert(int play_time, Table * table);
	void schedule(int remainingTime);
	void clear_curr_slot();
	void print_status();
};

TimingWheel::TimingWheel(int maxDelay) {
    max_delay = maxDelay + 1;
    current_slot = 0;

    slot = new Partition[max_delay];

}

TimingWheel::~TimingWheel() {
    delete[] slot;

}

void TimingWheel::insert(int play_time, Table * t) {

    int destSlot = (current_slot + play_time) % max_delay;

    Partition * p;
    p = new Partition();
    p->setTable(t);

    if (!(slot[destSlot].isEmpty())) {
	   Partition * cur = &slot[destSlot];

	   while (!(cur->getNextPartition() == NULL)) {
		  cur = cur->getNextPartition();
	   }

	   cur->setNextPartition(p);

    }
    else {
	   slot[destSlot] = *p;
    }

}

void TimingWheel::schedule(int remainingTime) {
    if (!(slot[current_slot].isEmpty())) {
	   Partition * p = &slot[current_slot];

	   while (!(p->getNextPartition() == NULL)) {
		  p = p->getNextPartition();

		  Table * t = p->getTable();
		  t->displayResults();
		  t->clearGame();
		  t->setupGame();

		  if (t->getNumPlayers() <= remainingTime) {
			 insert(t->getNumPlayers(), t);
		  }

		  t->playGame();

	   }

	   Table * t = p->getTable();
	   t->displayResults();
	   t->clearGame();
	   t->setupGame();

	   if (t->getNumPlayers() <= remainingTime) {
		  insert(t->getNumPlayers(), t);
	   }

	   t->playGame();

	   clear_curr_slot();
    }

    current_slot = (current_slot + 1) % max_delay;

}

void TimingWheel::clear_curr_slot() {

    if (!(slot[current_slot].isEmpty())) {

	   Partition * p = &slot[current_slot];

	   while (!(p->getNextPartition() == NULL)) {
		  Partition * temp = p;
		  p = temp->getNextPartition();
		  temp = NULL;
	   }

	   p = NULL;

    }

}

void TimingWheel::print_status() {
    cout << "Wheel Status" << endl;
    cout << "-----------------" << endl;

    cout << "Current Slot: " << current_slot << endl;

    int numPartitions = 0;

    if (!(slot[current_slot].isEmpty())) {
	   Partition * p = &slot[current_slot];
	   numPartitions++;

	   while (!(p->getNextPartition() == NULL)) {
		  p = p->getNextPartition();
		  numPartitions++;
	   }

    }

    cout << "Number of Games Ending: " << numPartitions << endl;
    cout << endl;
}