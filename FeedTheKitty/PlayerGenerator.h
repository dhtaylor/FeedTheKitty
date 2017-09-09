#pragma once

#include <time.h>

using namespace std;

class PlayerGenerator {
public:
    static int GeneratePlayers(int min, int max);

};

int PlayerGenerator::GeneratePlayers(int min, int max) {
	srand(clock());
	return rand() % (max - 1) + min;

}