#pragma once
#include <string>

using namespace std;

enum class Side { North, South };

struct Player {
    Side side;
    string name;
    char label;
    int houseSeeds;
    int storeSeeds;

    Player(Side s, const string& n, char l, int seeds) : side(s), name(n), label(l),
                                                         houseSeeds(seeds), storeSeeds(0) {}

    Side otherSide() const {
        return (side == Side::North) ? Side::South : Side::North;
    }

    // Print the player name
    friend ostream& operator<<(ostream& os, const Player& player) {
        os << player.name;
        return os;
    }
};
