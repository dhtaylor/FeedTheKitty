#pragma once
#include "Symbol.h"

class BowlSymbol : public Symbol {
public:
	BowlSymbol() { setSymbolValue("Bowl"); };
    void virtual action() {};
};