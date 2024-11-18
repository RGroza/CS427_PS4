#pragma once
#include <memory>
#include "Pit.hpp"
#include "Player.hpp"

using namespace std;

class Board {
private:
    int numHouses;
    int numSeeds;
    unique_ptr<Pit[]> pitWarehouse;

public:
    Board(int h, int s, Player &north, Player &south) : numHouses(h), numSeeds(s) {
        pitWarehouse = make_unique<Pit[]>(2 * h + 2);

        // Constructing pitWarehouse array from "S<numHouses>" to "N0" (CCW direction)
        // Pits for South player houses
        for (int i = 0; i < h; i++) {
            pitWarehouse[i] = Pit(&south, h - i, s, "S" + to_string(h - i),
                                  &pitWarehouse[i + 1], &pitWarehouse[2 * h - i]);
        }
        // Pit for South player store
        pitWarehouse[h] = Pit(&south, 0, 0, "S0", &pitWarehouse[h + 1], nullptr);

        // Pits for North player houses
        for (int i = 0; i < h; i++) {
            pitWarehouse[h + 1 + i] = Pit(&north, h - i, s, "N" + to_string(h - i),
                                          &pitWarehouse[h + 2 + i], &pitWarehouse[h - 1 - i]);
        }
        // Pits for North player store
        pitWarehouse[2 * h + 1] = Pit(&north, 0, 0, "N0", &pitWarehouse[0], nullptr);
    }

    int getPitIndex(Player &player, int house) {
        if (player.side == Side::North) {
            return 2 * numHouses + 1 - house;
        } else {
            return numHouses - house;
        }
    }

    int getPitSeeds(int pit) {
        return pitWarehouse[pit].getSeeds();
    }

    int getHouseSeeds(Player &player, int house) {
        return pitWarehouse[getPitIndex(player, house)].getSeeds();
    }

    bool isPitEmpty(int pit) {
        return getPitSeeds(pit) == 0;
    }

    bool isHouseEmpty(Player &player, int house) {
        return getHouseSeeds(player, house) == 0;
    }

    int storePit(Player &player) {
        if (player.side == Side::North) {
            return 2 * numHouses + 1;
        } else {
            return numHouses;
        }
    }

    bool isPlayerStore(Player &player, int pit) {
        return pit == storePit(player);
    }

    void addSeed(int pit) {
        pitWarehouse[pit].addSeed();
    }

    void captureOppositePit(Player &player, int pit) {
        int opposite = pitWarehouse[pit].getOpposite();
        if (pitWarehouse[opposite].getSeeds() > 0) {
            int oppositeSeeds = pitWarehouse[opposite].removeSeeds();
            pitWarehouse[pit].removeSeeds();
            pitWarehouse[storePit(player)].addSeeds(oppositeSeeds + 1);
        }
    }

    friend ostream& operator<<(ostream& os, const Board& board) {
        // Print first line: North house labels
        os << "\t   ";
        for (int i = 0; i < board.numHouses; i++) {
            os << board.pitWarehouse[2 * board.numHouses - i].getLabel() << "    ";
        }
        os << endl;
        // Print second line: North house seeds
        os << "\t  ";
        for (int i = 0; i < board.numHouses; i++) {
            os << board.pitWarehouse[2 * board.numHouses - i] << "  ";
        }
        os << endl;
        // Print third line: North and South stores
        os << "  " << board.pitWarehouse[2 * board.numHouses + 1].getLabel() << " "
                   << board.pitWarehouse[2 * board.numHouses + 1];
        for (int i = 0; i < 6 * board.numHouses; i++) {
            os << " ";
        }
        os << board.pitWarehouse[board.numHouses] << " "
           << board.pitWarehouse[board.numHouses].getLabel() << endl;
        // Print fourth line: South house seeds
        os << "\t  ";
        for (int i = 0; i < board.numHouses; i++) {
            os << board.pitWarehouse[i] << "  ";
        }
        os << endl;
        // Print fifth line: South house labels
        os << "\t   ";
        for (int i = 0; i < board.numHouses; i++) {
            os << board.pitWarehouse[i].getLabel() << "    ";
        }
        os << endl;
        return os;
    }
};
