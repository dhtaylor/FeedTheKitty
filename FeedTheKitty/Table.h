#pragma once

#include "PlayerGenerator.h"
#include "Game.h"

class Table {
private:
    static int counter;
    int tableID;

	int minPlayers;
	int maxPlayers;
	int numPlayers;
	int numDice;
	int numMice;
	string sessionFile;
	ofstream session;

    Game * game;

    void openSessionFile();

public:
    Table(string sessionFile);
    Table(const Table & table);
    ~Table();

    Table operator= (const Table & table);
    void setupGame();
    void playGame();
    void displayResults();
	void clearGame();
	int getNumPlayers();
	int getTableNumber();
	void setMinPlayers(int min);
	void setMaxPlayers(int max);
	void setNumDice(int dice);
	void setNumMice(int mice);

};

int Table::counter = 0;

Table::Table(string s) {
    tableID = ++counter;
    sessionFile = s;
}

Table::~Table() {
    session.close();
}

Table::Table(const Table & t) {
    minPlayers = t.minPlayers;
    maxPlayers = t.maxPlayers;
    numPlayers = t.numPlayers;
    numDice = t.numDice;
    numMice = t.numMice;
    sessionFile = t.sessionFile;
    game = t.game;

    openSessionFile();

}

Table Table::operator= (const Table & t) {
    tableID = t.tableID;
    minPlayers = t.minPlayers;
    maxPlayers = t.maxPlayers;
    numPlayers = t.numPlayers;
    numDice = t.numDice;
    numMice = t.numMice;
    sessionFile = t.sessionFile;
    game = t.game;

    openSessionFile();

    return (*this);
}

void Table::setupGame() {

    openSessionFile();

    numPlayers = PlayerGenerator::GeneratePlayers(minPlayers, maxPlayers);
    game = new Game(numPlayers, numDice, numMice);
    game->printGameSettings(session);

}

void Table::playGame() {
    game->play(session);
}

void Table::displayResults() {
    game->printResults(cout);
}

void Table::clearGame() {
    delete game;
}

int Table::getNumPlayers() {
    return numPlayers;
}

int Table::getTableNumber() {
    return tableID;
}

void Table::setMinPlayers(int min) {
    minPlayers = min;
}

void Table::setMaxPlayers(int max) {
    maxPlayers = max;
}

void Table::setNumDice(int dice) {
    numDice = dice;
}

void Table::setNumMice(int mice) {
    numMice = mice;
}

void Table::openSessionFile() {
    if (!(session.is_open()))
	   session.open(sessionFile, ofstream::app);
}