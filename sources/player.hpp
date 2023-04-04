//
// Created by avi on 20/03/2023.
//

#ifndef CPP_EX2_PLAYER_HPP
#define CPP_EX2_PLAYER_HPP

#include <string>
#include <vector>
#include "card.hpp"
using namespace std;
namespace ariel{}
namespace ariel{}

    class Player{
    private:
        string name;
        int cards_left, won_cards;
        bool is_playing;
        vector<Card> cards;
    public:
        Player();
        Player(string name);
        int stacksize();
        int cardesTaken();
        string getName();
        void setName(string new_str);
        void setCardsLeft(int new_cards_left);
        void addWonCards( int add_won_cards);
        vector<Card> getDeckOfCards();
        void setCardInDeckOfCards(Card card);
        bool IsPlaying();
        void setIsPlaying(bool new_playing_status);
        void RemoveCardFromDeck();
    };
#endif //CPP_EX2_PLAYER_HPP
