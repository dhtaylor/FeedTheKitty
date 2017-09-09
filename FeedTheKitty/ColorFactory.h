#pragma once

#include <string>

#include "Color.h"
#include "GreenColor.h"
#include "RedColor.h"

using namespace std;

class ColorFactory {
public:
	static Color * Create(string color) {
		if (color == "Green")
			return new GreenColor;
		else if (color == "Red")
			return new RedColor;
		else
			return NULL;
	};

};