#pragma once

#include "Player.h"
#include "Dice.h"

class Game {
private:
	static int counter;
	int gameID;

	int numPlayers;
	int numDice;
	int numMice;
	int direction;
	int currentPlayer;
	int nextPlayer;
	int remainingPlayers;

	Player ** players;
	Dice ** dice;
	Player * bowl;
	DiceFace ** results;

	void checkColors(ostream & out);
	void checkSymbols(ostream & out);
	void generateDice();
	void generatePlayers();
	int getNextPlayer();
	int getRemainingPlayers();

public:
	Game(int players, int dice, int mice);
	~Game();

	void printGameSettings(ostream & out);
	void play(ostream & out);
	void printResults(ostream & out);

};

#include "Game.h"

int Game::counter = 0;

Game::Game(int p, int d, int m) {
    gameID = ++counter;
    numPlayers = p;
    numDice = d;
    numMice = m;

    direction = 1;

    // Get Dice
    dice = new Dice *[numDice];
    generateDice();

    // Get Players
    players = new Player *[numPlayers];
    generatePlayers();

    // Get Bowl
    bowl = new Player();
    bowl->set_Label("Bowl");

    // Get Starting Player
    currentPlayer = rand() % numPlayers;
    nextPlayer = getNextPlayer();
    remainingPlayers = numPlayers;

    // Distribute Mice
    for (int i = 0; i < numPlayers; i++) {
	   players[i]->set_MouseCount(numMice / numPlayers);
    }

    bowl->set_MouseCount(numMice % numPlayers);

}

Game::~Game() {

    delete bowl;

    for (int i = 0; i < numPlayers; i++)
	   delete players[i];

    delete[] players;

    for (int i = 0; i < numDice; i++)
	   delete dice[i];

    delete[] dice;

}

void Game::generateDice() {
    for (int i = 0; i < numDice; i++) {
	   dice[i] = new Dice("./diceConfig.txt");
    }
}

void Game::generatePlayers() {
    for (int i = 0; i < numPlayers; i++) {
	   players[i] = new Player();
    }
}

int Game::getNextPlayer() {
    int cp = currentPlayer;
    if (cp == 0 && direction == -1)
	   cp = numPlayers - 1;
    else if (cp == (numPlayers - 1) && direction == 1)
	   cp = 0;
    else
	   cp += direction;

    return cp;

}

int Game::getRemainingPlayers() {
    int rp = 0;

    for (int i = 0; i < numPlayers; i++) {
	   if (players[i]->get_MouseCount() > 0)
		  rp += 1;
    }

    return rp;

}

void Game::printGameSettings(ostream & out) {
    out << "Game Settings" << endl;
    out << "-----------------" << endl;
    out << "Game ID: " << gameID << endl;
    out << "Number of Dice: " << numDice << endl;
    out << "Number of Players: " << numPlayers << endl;
    out << "Number of Mice: " << numMice << endl;
    out << "Starting Player: " << players[currentPlayer]->get_Label() << endl;
    out << "Direction of Play: " << direction << endl;

    for (int i = 0; i < numPlayers; i++) {
	   players[i]->display(out);
    }

    bowl->display(out);

    out << endl;

}

void Game::play(ostream & out) {
    remainingPlayers = numPlayers;

    while (remainingPlayers > 1) {

	   // Find Next Player
	   nextPlayer = getNextPlayer();

	   out << "Current Player: " << players[currentPlayer]->get_Label() << endl;
	   out << "Next Player: " << players[nextPlayer]->get_Label() << endl;
	   out << endl;

	   // Take Turn
	   if (players[currentPlayer]->get_MouseCount() > 0) {
		  results = players[currentPlayer]->rollDice(dice, numDice, out);

		  out << "Play" << endl;
		  out << "-----------------" << endl;

		  checkSymbols(out);
		  checkColors(out);

		  // Current State
		  for (int i = 0; i < numPlayers; i++) {
			 players[i]->display(out);
		  }

		  bowl->display(out);

		  out << endl;

	   }

	   // Check for Game End
	   remainingPlayers = getRemainingPlayers();

	   currentPlayer = nextPlayer;

    }

}

void Game::checkColors(ostream & out) {
    int changes = 0;

    for (int i = 0; i < numDice; i++) {
	   string color = results[i]->getColor();

	   if (color == "Red") {
		  direction *= -1;
		  nextPlayer = getNextPlayer();
		  changes++;
	   }
	   // Green - Do Nothing
    }

    if (changes % 2 != 0)
	   out << "Game Changes Direction!" << endl;

}

void Game::checkSymbols(ostream & out) {
    for (int i = 0; i < numDice; i++) {
	   string symbol = results[i]->getSymbol();

	   if (symbol == "Bowl") {
		  int amount = players[currentPlayer]->subtractMouse(1);
		  bowl->addMouse(amount);
		  out << players[currentPlayer]->get_Label() << " puts mouse in bowl." << endl;
	   }
	   else if (symbol == "Arrow") {
		  int amount = players[currentPlayer]->subtractMouse(1);
		  players[nextPlayer]->addMouse(amount);
		  out << players[currentPlayer]->get_Label()
			 << " gives a mouse to "
			 << players[nextPlayer]->get_Label() << endl;
	   }
	   else if (symbol == "Mouse") {
		  int amount = bowl->subtractMouse(1);
		  players[currentPlayer]->addMouse(amount);
		  out << players[currentPlayer]->get_Label() << " takes a mouse from the bowl." << endl;
	   }
	   else {
		  // Sleeping Cat - Do Nothing
		  out << players[currentPlayer]->get_Label() << " does nothing." << endl;
	   }
    }

}

void Game::printResults(ostream & out) {
    out << "Game " << gameID << " Results" << endl;
    out << "-----------------" << endl;

    for (int i = 0; i < numPlayers; i++) {
	   players[i]->display(out);
    }

    bowl->display(out);

    out << endl;

    for (int i = 0; i < numPlayers; i++) {
	   if (players[i]->get_MouseCount() > 0) {
		  players[i]->addWin();
		  out << players[i]->get_Label() << " Wins!" << endl;
	   }
    }

    out << endl;

}