#pragma once
#include <string>
#include <iostream>
#include <iomanip>
#include "Player.hpp"

using namespace std;

class Pit {
private:
    Player *owner;
    int number;
    int seeds;
    string label;
    Pit *next;
    Pit *opposite;

public:
    Pit() : owner(nullptr), number(0), seeds(0), label(""), next(nullptr), opposite(nullptr) {}
    Pit(Player *p, int n, int s, const string &l, Pit *next, Pit *opposite) :
        owner(p), number(n), seeds(s), label(l), next(next), opposite(opposite) {}

    int getSeeds() {
        return seeds;
    }

    Pit *getOpposite() {
        return opposite;
    }

    void addSeed() {
        seeds++;
        if (opposite == nullptr) {
            owner->storeSeeds++;
        } else {
            owner->houseSeeds++;
        }
    }

    void addSeeds(int s) {
        seeds += s;
        if (opposite == nullptr) {
            owner->storeSeeds += s;
        } else {
            owner->houseSeeds += s;
        }
    }

    int removeSeeds() {
        int s = seeds;
        seeds = 0;
        owner->houseSeeds -= s;
        return s;
    }

    string getLabel() {
        return label;
    }

    friend ostream &operator<<(ostream &os, const Pit &pit) {
        os << "[" << setw(2) << pit.seeds << "]";
        return os;
    }
};
