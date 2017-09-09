#pragma once

#include <iostream>
#include <string>

#include "Color.h"
#include "Symbol.h"
#include "ColorFactory.h"
#include "SymbolFactory.h"

using namespace std;

class DiceFace {
private:
	static int counter;
	int diceFaceID;
    string label;
	Color * color;
	Symbol * symbol;

public:

	DiceFace(string c, string s);

    void action();
    void display();
	void displayDetail();
	string getDiceFace();
	string getColor();
	string getSymbol();
};

int DiceFace::counter = 0;

DiceFace::DiceFace(string c, string s) {
    color = ColorFactory::Create(c);
    symbol = SymbolFactory::Create(s);
    label = color->getColorValue() + symbol->getSymbolValue();
    diceFaceID = ++counter;
}

void DiceFace::action() {
    symbol->action();
    color->action();
}

void DiceFace::display() {
    color->display();
    cout << "-";
    symbol->display();
}

void DiceFace::displayDetail() {
    cout << "DiceFaceID: " << diceFaceID << endl;
    cout << "Label: " << label << endl;
    color->displayDetail();
    symbol->displayDetail();
    cout << endl;
}

string DiceFace::getDiceFace() {
    return getColor().substr(0, 1) + "-" + getSymbol().substr(0, 1);

}
string DiceFace::getColor() {
    return color->getColorValue();
}

string DiceFace::getSymbol() {
    return symbol->getSymbolValue();
}