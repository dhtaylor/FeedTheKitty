#pragma once
#include "Symbol.h"

class MouseSymbol : public Symbol {
public:
	MouseSymbol() { setSymbolValue("Mouse"); };
    void virtual action() {};
};