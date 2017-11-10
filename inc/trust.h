#pragma once

#include "player.h"

class AlwaysCooperate : public Player {
public:
    int decideMove(
        const State& state
    );
    const std::string getName();
};

class AlwaysCheat : public Player {
public:
    int decideMove(
        const State& state
    );
    const std::string getName();
};
