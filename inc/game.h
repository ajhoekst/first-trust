#pragma once

#include "player.h"
#include "state.h"

#include <iostream>
#include <memory>
#include <vector>

class Game {
public:
    Game();
    ~Game();
    void addPlayer(
        std::shared_ptr<Player> newPlayer
    );
    void playRound();
    void printResults();
private:
    std::vector<std::shared_ptr<Player> > players_;
    std::vector<std::unique_ptr<StatePair> > statePairs_;
    bool isUnique(
        std::shared_ptr<Player> const& player
    );
    std::shared_ptr<Player> getLeftPlayer(
        std::unique_ptr<StatePair> const& pair
    );
    std::shared_ptr<Player> getRightPlayer(
        std::unique_ptr<StatePair> const& pair
    );
    int getLeftMove(
        std::unique_ptr<StatePair> const& pair
    );
    int getRightMove(
        std::unique_ptr<StatePair> const& pair
    );
};
