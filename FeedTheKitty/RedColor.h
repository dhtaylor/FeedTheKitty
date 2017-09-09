#pragma once
#include "Color.h"

class RedColor : public Color {
public:
	RedColor() { setColorValue("Red"); };
    virtual void action() {};
};