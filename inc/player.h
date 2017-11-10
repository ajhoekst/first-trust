#pragma once

#include "state.h"

#include <string>
#include <vector>

class State;

class Player {
public:
    virtual int decideMove(
        const State& state
    ) = 0;
    virtual const std::string getName() = 0;
};
