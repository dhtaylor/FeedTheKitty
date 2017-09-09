#pragma once

#include <string>

#include "Symbol.h"
#include "ArrowSymbol.h"
#include "BowlSymbol.h"
#include "CatSymbol.h"
#include "MouseSymbol.h"

using namespace std;

class SymbolFactory {
public:
	static Symbol * Create(string symbol) {
		if (symbol == "Arrow")
			return new ArrowSymbol();
		else if (symbol == "Bowl")
			return new BowlSymbol();
		else if (symbol == "SleepingCat")
			return new CatSymbol();
		else if (symbol == "Mouse")
			return new MouseSymbol();
		else
			return NULL;
	};

};