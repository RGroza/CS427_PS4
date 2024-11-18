#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include "Kalah.hpp"

using namespace std;

class Game {
private:
    Kalah kalah;
public:
    Game(int numHouses, int numSeeds) : kalah(numHouses, numSeeds) {}

    void doMove(int move) {
        kalah.doMove(move);
    }

    void playGame(istringstream *iss) {
        if (iss == nullptr) {
        } else {
            string word;
            while (*iss >> word) {
                if (word == "q") {
                    cout << "Quitting game at user's request\nGame over -- goodbye!" << endl;
                    return;
                }

                try {
                    int number = stoi(word);
                    doMove(number);
                } catch (const invalid_argument&) {
                    cerr << "Invalid input: " << word << endl;
                }
            }
        }
    }
};