#pragma once
#include <string>

using namespace std;

enum class Side { North, South };

struct Player {
    Side side;
    string name;
    char label;

    Player(Side s, const string& n, char l) : side(s), name(n), label(l) {}

    Side otherSide() const {
        return (side == Side::North) ? Side::South : Side::North;
    }

    // Print the player name
    friend ostream& operator<<(ostream& os, const Player& player) {
        os << player.name;
        return os;
    }
};
