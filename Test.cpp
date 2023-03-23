#include "doctest.h"
#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"
#include <string.h>
#include <stdexcept>
using namespace ariel;
using namespace std;

TEST_CASE("Checking if players initialized correctly"){
    CHECK_NOTHROW(Player p1("BOB"));
}

TEST_CASE("Checking Game class constructor"){
    Player p1("player1");
    Player p2("player2");
    CHECK_NOTHROW(Game game(p1, p2));
}

TEST_CASE("Checking if game stats correct for all players"){
    Player p1("player1");
    Player p2("player2");
    Game game(p1, p2);
    int amount_of_cards = 52;
    CHECK(p1.stacksize() == (amount_of_cards/2));
    CHECK(p2.stacksize() == (amount_of_cards/2));
    CHECK(p1.stacksize() + p2.stacksize() == amount_of_cards);
    CHECK(p1.stacksize() - p2.stacksize() == 0);
    CHECK_NOTHROW(game.playTurn());
    CHECK(p1.stacksize() != (amount_of_cards/2));
    CHECK(p2.stacksize() != (amount_of_cards/2));
}

TEST_CASE("Checking Player get fucntion"){
    Player p1("player1");
    CHECK(strcmp(p1.getName(), "player1") == 0);
}

TEST_CASE("Checking if exception thrown if game not finished"){
    Player p1("player1");
    Player p2("player2");
    Game game(p1, p2);
    CHECK_NOTHROW(game.playTurn());
    CHECK_THROWS_AS(game, invalid_argument);
}

TEST_CASE("Checking if there is a winner"){
    Player p1("player1");
    Player p2("player2");
    Game game(p1, p2);
    CHECK_NOTHROW(game.playAll());
    CHECK((p1.cardesTaken > 26 || p2.cardesTaken > 26));
    CHECK(p1.stacksize() == 0);
    CHECK(p2.stacksize() == 0);
}

TEST_CASE("Checking if game function called after the game finish"){
    Player p1("player1");
    Player p2("player2");
    Game game(p1, p2);
    game.playAll();
    CHECK_THROWS(game.playTurn());
    CHECK_THROWS(game.playAll());
}

TEST_CASE("Checking if other fucntions in game working"){
    Player p1("player1");
    Player p2("player2");
    Game game(p1, p2);
    game.playAll();
    CHECK_NOTHROW(game.printLastTurn());
    CHECK_NOTHROW(game.printLog());
    CHECK_NOTHROW(game.printWiner());
    CHECK_NOTHROW(game.printStats());
}