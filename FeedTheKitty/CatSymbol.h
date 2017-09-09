#pragma once
#include "Symbol.h"

class CatSymbol : public Symbol {
public:
	CatSymbol() { setSymbolValue("SleepingCat"); };
    void virtual action() {};
};