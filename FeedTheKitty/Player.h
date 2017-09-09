#pragma once

#include <iostream>

#include "Dice.h"

using namespace std;

class Player {
private:
	static int counter;
	int playerID;
	string label;
	bool isSeated;
	int mouseCount;
	int wins;

	DiceFace * roll(Dice * dice, ostream & out);

public:
	Player();

	void addWin();
	bool get_IsSeated();
	string get_Label();
	int get_MouseCount();
	void set_Label(string s);
	void set_MouseCount(int count);
	void display(ostream & out);
	void displayDetail(ostream & out);
	DiceFace ** rollDice(Dice ** dice, int numDice, ostream & out);
	void addMouse(int count);
	int subtractMouse(int count);
	int getWins();
	void sitDown();
	void standUp();
};

int Player::counter = 0;

Player::Player() {
    playerID = ++counter;
    isSeated = false;
    mouseCount = 0;
    wins = 0;
    label = "Player " + to_string(playerID);
}

string Player::get_Label() {
    return label;
}

int Player::get_MouseCount() {
    return mouseCount;
}

void Player::set_Label(string s) {
    label = s;
}

void Player::set_MouseCount(int count) {
    mouseCount = count;
}

DiceFace * Player::roll(Dice * dice, ostream & out) {
    return dice->roll(out);

}

DiceFace ** Player::rollDice(Dice ** dice, int numDice, ostream & out) {
    out << "Dice Roll" << endl;
    out << "-----------------" << endl;

    DiceFace ** results;
    results = new DiceFace *[numDice];

    if (mouseCount > 0) {
	   for (int i = 0; i < numDice; i++) {
		  results[i] = roll(dice[i], out);
	   }

    }

    out << endl;

    return results;

}

void Player::addMouse(int count) {
    mouseCount += count;
}

int Player::subtractMouse(int count) {
    if (mouseCount < 1)
	   return 0;
    else if ((mouseCount - count) < 0) {
	   int result = mouseCount;
	   mouseCount = 0;
	   return result;
    }
    else {
	   mouseCount -= count;
	   return count;
    }

}

void Player::display(ostream & out) {
    out << label << ": ";
    out << mouseCount;
    out << endl;
}

void Player::displayDetail(ostream & out) {
    out << "PlayerID: " << playerID << endl;
    out << "MouseCount: " << mouseCount << endl;
    out << "Wins: " << wins << endl;
    out << endl;
}

void Player::addWin() {
    wins++;
}

int Player::getWins() {
    return wins;
}

void Player::sitDown() {
    isSeated = true;
}

void Player::standUp() {
    isSeated = false;
}

bool Player::get_IsSeated() {
    return isSeated;
}