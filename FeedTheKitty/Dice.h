#pragma once

#include <string>
#include <fstream>
#include <cassert>
#include <map>
#include <time.h>

#include "DiceFace.h"

using namespace std;

class Dice {
private:
	static int counter;
	int diceID;
	int numSides;
	int numColors;
	int numSymbols;
	DiceFace ** sides;
	map<int, string> colors;
	map<int, string> symbols;

	void getValues(ifstream & in, int lines, map<int, string> & values);
	string getRandomValue(map<int, string> & values);

public:
    Dice(string infile);
    Dice(const Dice & dice);

    ~Dice();

    Dice operator=(const Dice & dice);

    DiceFace * roll(ostream & out);
    void display();
	void displayDetail();

};

int Dice::counter = 0;

Dice::Dice(string infile) {
    diceID = ++counter;

    numSides = 0;
    numColors = 0;
    numSymbols = 0;

    ifstream in;
    in.open(infile);

    in >> numSides >> numColors >> numSymbols;
    in.ignore(100, '\n');

    getValues(in, numColors, colors);
    getValues(in, numSymbols, symbols);

    in.close();

    sides = new DiceFace *[numSides];

    srand(clock());

    for (int i = 0; i < numSides; i++) {
	   // Get Color
	   string color = getRandomValue(colors);

	   // Get Symbol
	   string symbol = getRandomValue(symbols);

	   // Get DiceFace
	   sides[i] = new DiceFace(color, symbol);
    }

}

Dice::Dice(const Dice & dice) {
    sides = new DiceFace *[dice.numSides];

    for (int i = 0; i < dice.numSides; i++) {
	   sides[i] = dice.sides[i];
    }

}

Dice::~Dice() {

    for (int i = 0; i < numSides; i++) {
	   delete sides[i];
    }

    delete[] sides;

}

Dice Dice::operator=(const Dice & dice) {
    assert(dice.numSides == numSides);

    for (int i = 0; i < numSides; i++) {
	   sides[i] = dice.sides[i];
    }

    return (*this);
}

DiceFace * Dice::roll(ostream & out) {
    srand(clock());
    int side = rand() % numSides;

    out << "Dice" << diceID << ": ";
    out << sides[side]->getDiceFace();
    out << endl;

    return sides[side];
}

void Dice::display() {
    cout << "Dice" << diceID << ": ";

    for (int i = 0; i < numSides; i++) {
	   sides[i]->display();
	   cout << "\t";
    }

    cout << endl;

}

void Dice::displayDetail() {
    cout << "DiceID: " << diceID << endl;
    cout << "Number of Sides: " << numSides << endl;
    cout << "Number of Colors: " << numColors << endl;
    cout << "Number of Symbols: " << numSymbols << endl;
    cout << endl;

    for (int i = 0; i < numSides; i++) {
	   sides[i]->displayDetail();
    }

    cout << endl;

}

void Dice::getValues(ifstream & in, int lines, map<int, string> & values) {
    int total = 0;

    for (int i = 0; i < lines; i++) {
	   int k;
	   string v;

	   in >> v >> k;
	   total += k;
	   values[total] = v;

    }


}

string Dice::getRandomValue(map<int, string> & values) {
    int randnum = rand() % 100 + 1;

    for (auto v : values) {
	   if (v.first >= randnum) {
		  return v.second;
	   }
    }

    return "";

}
