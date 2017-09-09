#pragma once

#include "Table.h"

class TableGenerator {
public:
    static Table ** GenerateTables(int numTables, string outfile);
};

Table ** TableGenerator::GenerateTables(int numTables, string outfile) {
    Table ** out;
    out = new Table *[numTables];

    for (int i = 0; i < numTables; i++) {
	   out[i] = new Table(outfile);
	   out[i]->setMinPlayers(2);
	   out[i]->setMaxPlayers(5);
	   out[i]->setNumDice(2);
	   out[i]->setNumMice(20);
	   out[i]->setupGame();

    }

    return out;
}