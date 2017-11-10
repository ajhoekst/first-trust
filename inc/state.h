#pragma once

#include "player.h"

#include <vector>

#define STATE_COOPERATE 0
#define STATE_CHEAT     1

#define STATE_INIT_SCORE 10

class Player;

struct State {
    std::vector<int> moves;
    int score;
    std::shared_ptr<Player> opponent;
    State();
    ~State();
};

struct StatePair {
    State left;
    State right;
    StatePair(
        std::shared_ptr<Player> playerLeft,
        std::shared_ptr<Player> playerRight
    );
    ~StatePair();
};
