#include "trust.h"
#include "game.h"
#include "state.h"

#include <iostream>
#include <string>

/* Always Cooperate */
int AlwaysCooperate::decideMove(
    const State& state
)
{
    return STATE_COOPERATE;
}
const std::string AlwaysCooperate::getName()
{
    return u8"Always Cooperate";
}

/* Always Cheat */
int AlwaysCheat::decideMove(
    const State& state
)
{
    return STATE_CHEAT;
}
const std::string AlwaysCheat::getName()
{
    return u8"Always Cheat";
}

int main(
    int argc,
    char** argv
)
{
    // Create game
    Game g;

    // Create players
    g.addPlayer( std::make_unique<AlwaysCooperate>() );
    g.addPlayer( std::make_unique<AlwaysCheat>() );

    // Play round and print results
    for (
        int index = 0;
        index < 10;
        index++
    )
    {
        g.playRound();
    }
    g.printResults();

    return 0;
}
