    //
    // Created by avi on 20/03/2023.
    //
    //using namespace std;
    #include "player.hpp"
    #include <string>
    using namespace ariel;

    Player::Player(){

    }

    Player::Player(string name){
        this->name = name;
        this->cards_left = 0;
    }

    int Player::stacksize(){
        return this->cards_left;
    }

    int Player::cardesTaken(){
        return this->won_cards;
    }
    string Player::getName(){
        return this->name;
    }

    void Player::setName(string new_name){
        this->name = new_name;
    }

    int Player::getCardsLeft(){
        return this->cards_left;
    }

    void Player::setCardsLeft(int new_cards_left){
        this->cards_left = new_cards_left;
    }

    int Player::getWonCards(){
        return this->won_cards;
    }

    void Player::addWonCards( int add_won_cards){
        this->won_cards+=add_won_cards;
    }

    vector<Card> Player::getDeckOfCards(){
        return this->cards;
    }

    void Player::setDeckOfCards(int num_of_cards){
        for (int i = 0; i < num_of_cards; i++)
        {
            Card *card = new Card(); // create card object
            this->cards.push_back(*card);
        }
    }

    bool Player::IsPlaying(){
        return this->is_playing;
    }

    void Player::setIsPlaying(bool new_playing_status){
        this->is_playing = new_playing_status;
    }