#include "state.h"
#include "player.h"

#include <vector>

State::State()
{
    score = STATE_INIT_SCORE;
}

State::~State() {}

StatePair::StatePair(
    std::shared_ptr<Player> playerLeft,
    std::shared_ptr<Player> playerRight
)
{
    left.opponent = playerRight;
    right.opponent = playerLeft;
}

StatePair::~StatePair() {}
