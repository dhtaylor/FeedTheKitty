#pragma once

#include "Table.h"

class Partition {
private:
    static int counter;
    int partitionID;
    bool empty;
	Table * table;
	Partition * nextPartition;

public:
    Partition();
    Partition(const Partition & partition);

    Partition operator= (const Partition * partition);

	Partition * getNextPartition();
	Table * getTable();
	int getPartitionID();
	void setNextPartition(Partition * partition);
	void setTable(Table * table);
	bool isEmpty();
};

int Partition::counter = 0;

Partition::Partition() {
    partitionID = ++counter;
    empty = true;
}

Partition::Partition(const Partition & p) {
    empty = p.empty;
    table = p.table;
    nextPartition = p.nextPartition;
}

Partition Partition::operator= (const Partition * p) {
    partitionID = p->partitionID;
    empty = p->empty;
    table = p->table;
    nextPartition = p->nextPartition;

    return (*this);
}

Partition * Partition::getNextPartition() {
    return nextPartition;
}

Table * Partition::getTable() {
    return table;
}

int Partition::getPartitionID() {
    return partitionID;
}

void Partition::setNextPartition(Partition * partition) {
    nextPartition = partition;
}

void Partition::setTable(Table * t) {
    table = t;
    empty = false;
}

bool Partition::isEmpty() {
    return empty;
}