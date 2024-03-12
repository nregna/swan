#ifndef AUTOMATA_H_INCLUDED
#define AUTOMATA_H_INCLUDED

#include<iostream>

#include"rendr.h"
#include"mekanikk.h"
#include"poll.h"

class Automata{
    public:
        Draw draw; Ballot ballot;
        bool update(SDL_Event&, SDL_Renderer*), init(SDL_Renderer*), close();
    private:
        int const haste = 12;
        int xpos=0, ypos=0, xvel=0, yvel=0;
    protected:
        SDL_Texture* ten=NULL;
};

bool Automata::update(SDL_Event& arg, SDL_Renderer* rei){
    ballot.handle(arg, &xvel, &yvel, haste);
    chuyen(&xvel, &xpos, 391);
    chuyen(&yvel, &ypos, 293);
    draw.sprite(xpos, ypos, ten, rei);
    printf("pos: %d - %d\n\n",xpos,ypos);
};

bool Automata::init(SDL_Renderer* rei){
    draw.texture(ten, rei, "swan.png");
    //draw.sprite(xpos, ypos, ten, rei);
};

bool Automata::close(){
    dest(ten);
};

#endif // AUTOMATA_H_INCLUDED
