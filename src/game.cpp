#include "game.h"
#include "state.h"

#include <memory>
#include <vector>

Game::Game() {}

Game::~Game() {}

void Game::addPlayer(
    std::shared_ptr<Player> newPlayer
)
{
    if ( players_.size() == 0 )
    {
        // Add new player to the list
        players_.push_back( newPlayer );
    }
    else if ( isUnique( newPlayer ) )
    {        
        // Add state between every existing player and the new player
        for ( auto const& p : players_ )
        {
            statePairs_.push_back(
                std::make_unique<StatePair>(
                    newPlayer,
                    p
                )
            );
        }
        // Add new player to the list
        players_.push_back( newPlayer );
    }
    else
    {
        // Do nothing
    }
}

void Game::playRound()
{
    for ( auto& pair : statePairs_ )
    {
        int leftMove = getLeftMove( pair );
        int rightMove = getRightMove( pair );

        pair->left.moves.push_back( leftMove );
        pair->right.moves.push_back( rightMove );

        if ( leftMove == STATE_COOPERATE && rightMove == STATE_COOPERATE )
        {
            pair->left.score += 2;
            pair->right.score += 2;
        }
        else if ( leftMove == STATE_COOPERATE && rightMove == STATE_CHEAT )
        {
            pair->left.score += -1;
            pair->right.score += 3;
        }
        else if ( leftMove == STATE_CHEAT && rightMove == STATE_COOPERATE )
        {
            pair->left.score += 3;
            pair->right.score += -1;
        }
        else if ( leftMove == STATE_CHEAT && rightMove == STATE_CHEAT )
        {
            pair->left.score += 0;
            pair->right.score += 0;
        }
        else
        {
            // Do nothing...this should never be reached
        }
    }
}

void Game::printResults()
{
    for ( auto const& pair : statePairs_ )
    {
        std::shared_ptr<Player> left = getLeftPlayer( pair );
        std::shared_ptr<Player> right = getRightPlayer( pair );
        std::cout <<
            left->getName() <<
            " (" << pair->left.score << ") : " <<
            right->getName() <<
            " (" << pair->right.score << ")" << std::endl;
    }
}

bool Game::isUnique(
    std::shared_ptr<Player> const& player
)
{
    for ( auto const& p : players_ )
    {
        if ( player == p )
        {
            return false;
        }
        else
        {
            // Do nothing
        }
    }
    return true;
}

std::shared_ptr<Player> Game::getLeftPlayer(
    std::unique_ptr<StatePair> const& pair
)
{
    return pair->right.opponent;
}

std::shared_ptr<Player> Game::getRightPlayer(
    std::unique_ptr<StatePair> const& pair
)
{
    return pair->left.opponent;
}

int Game::getLeftMove(
    std::unique_ptr<StatePair> const& pair
)
{
    return getLeftPlayer( pair )->decideMove( pair->left );
}

int Game::getRightMove(
    std::unique_ptr<StatePair> const& pair
)
{
    return getRightPlayer( pair )->decideMove( pair->right );
}

