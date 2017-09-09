#pragma once
#include <string>

using namespace std;

class Symbol {
private:
    string symbolValue;
public:
    void virtual action() = 0;
	virtual void display() { cout << symbolValue.substr(0, 1); };
	virtual void displayDetail() { cout << "Symbol: " << symbolValue << endl; };
	virtual string getSymbolValue() { return symbolValue; };
	virtual void setSymbolValue(string symbol) { symbolValue = symbol; };
};