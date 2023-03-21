//
// Created by avi on 20/03/2023.
//

#ifndef CPP_EX2_PLAYER_HPP
#define CPP_EX2_PLAYER_HPP

class player{
private:
    char* str;
public:
    player();
    player(char *str);
    void stacksize();
    void cardesTaken();
    char* getStr();
    void setStr(char*);
};

#endif //CPP_EX2_PLAYER_HPP
