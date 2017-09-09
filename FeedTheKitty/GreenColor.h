#pragma once
#include "Color.h"

class GreenColor : public Color {
public:
	GreenColor() { setColorValue("Green"); };
    virtual void action() {};
};