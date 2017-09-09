#pragma once
#include <string>
#include <iostream>

using namespace std;

class Color {
private:
    string colorValue;
public:
    virtual void action() = 0;
	virtual void display() { cout << colorValue.substr(0,1); };
	virtual void displayDetail() { cout << "Color: " << colorValue << endl; };
	virtual string getColorValue() { return colorValue; };
	virtual void setColorValue(string color) { colorValue = color; };
};