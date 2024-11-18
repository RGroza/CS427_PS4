/*
 * Mancala-1
 * main.cpp
 *
 *  Created on: Oct 17, 2016; October 28, 2024
 *      Author: mike
 */
#include <unistd.h>
#include <iostream>
#include <sstream>
#include "Game.hpp"
#include "tools.hpp"

static string usage = "usage: kalah numHouses numSeeds";

//-----------------------------------------------------------------------------
int main(int argc, char* argv[]) {
    cout << "Welcome to Kalah!" << endl << endl;

    if (argc != 3)
        fatal(usage);
    int numHouses = atoi(argv[1]);
    int numSeeds = atoi(argv[2]);

    Game game = Game(numHouses, numSeeds);

    string line;
    if (isatty(fileno(stdin))) {
        game.playGame(nullptr);
    } else {
        cout << "Using file" << endl;
        while (std::getline(cin, line)) {
            istringstream iss(line);
            game.playGame(&iss);
        }
    }
}
