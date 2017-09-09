#pragma once
#include "Symbol.h"

class ArrowSymbol : public Symbol {
public:
    ArrowSymbol() { setSymbolValue("Arrow"); };
    void virtual action() {};
};