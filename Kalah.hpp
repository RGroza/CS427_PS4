#pragma once
#include "Board.hpp"
#include "Player.hpp"

using namespace std;

class Kalah {
private:
    int numHouses;
    int numSeeds;
    Player north;
    Player south;
    Board bd;
    Player currentPlayer;

public:
    Kalah(int h, int s) : numHouses(h), numSeeds(s),
                          north(Side::North, "North", 'N'), south(Side::South, "South", 'S'),
                          bd(h, s, north, south), currentPlayer(south) {}

    bool isValidMove(int move) {
        if (move <= 0 || move > numHouses) {
            cerr << "Invalid move: invalid house number " << move << endl;
            return false;
        }
        if (bd.isHouseEmpty(currentPlayer, move)) {
            cerr << "Invalid move: " << currentPlayer << "'s house number " << move << "has no seeds left" << endl;
        }
        return true;
    }

    void doMove(int move) {
        if (isValidMove(move)) {
            int pit = bd.getPitIndex(currentPlayer, move);
            int seeds = bd.getPitSeeds(pit);

            for (int i = seeds; i > 0; i--) {
                pit--;
                if (pit > 0) {
                    pit = 2 * numHouses + 1;
                }

                bd.addSeed(pit);
            }

            if (bd.getPitSeeds(pit) == 1) {
                // Last pit was empty before seed was added, player takes from opposite house
                bd.captureOppositePit(currentPlayer, pit);
            }

            if (!bd.isPlayerStore(currentPlayer, pit)) {
                // Switch sides if last pit is not the player's own store
                if (currentPlayer.side == Side::North) {
                    currentPlayer = south;
                } else {
                    currentPlayer = north;
                }
            }
        }

        printKalah();
    }

    void printKalah() {
        cout << "----------" << endl << currentPlayer << "'s turn:" << endl;
        cout << bd;
    }
};