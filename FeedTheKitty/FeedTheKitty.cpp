#include <iostream>
#include <stdio.h>

#include "TimingWheel.h"
#include "PlayerGenerator.h"
#include "TableGenerator.h"
#include "Table.h"

using namespace std;

void initialize();

string outfile;
int remainingTime;
TimingWheel wheel(5);
int numTables;
Table ** tables;

int main() {

    initialize();

    for (int i = 0; i < numTables; i++) {
	   wheel.insert(tables[i]->getNumPlayers(), tables[i]);
	   tables[i]->playGame();

    }

	while (remainingTime > 0) {
	    wheel.print_status();
	    wheel.schedule(remainingTime--);
	}

    return 0;

}

void initialize() {
    
    //Get the output file name from the user and open it
    cout << "Enter Output File Name: ";
    cin >> outfile;

    // Delete output file if it already exists
    ifstream out(outfile);
    if (out.good()) {
	   out.close();
	   remove(outfile.c_str());
    }

    //Get end_of_simulation time from the user
    cout << "Enter time to run (seconds): ";
    cin >> remainingTime;

    //Create and initialize the Arcade components i.e.the GameTables, PlayerGenerator and StatisticsKeeper; also the Dice Generator(for Option A) and the Timing Wheel(for Option B).
    cout << "Enter Number of Tables: ";
    cin >> numTables;
   
    cout << endl;

    tables = TableGenerator::GenerateTables(numTables, outfile);


}