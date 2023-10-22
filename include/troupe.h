#ifndef TROUPE_H_INCLUDED
#define TROUPE_H_INCLUDED

#include<iostream>

#include"rendr.h"
#include"automata.h"
#include"poll.h"

class pierrot{
    public:
        Draw draw; Ballot ballot;
        int const haste = 10;
        bool update(SDL_Event&);
    private:
        int* xpos=0;
        int* ypos=0;
        int xvel=0, yvel=0;
    protected:
        SDL_Texture* ten=NULL;
        SDL_Renderer* rei=NULL;
};

bool pierrot::update(SDL_Event& arg){
    ballot.handle(arg, *xpos, *ypos, xvel, yvel, haste);
    chuyen(xvel, xpos);
    chuyen(yvel, ypos);
    draw.sprite(xpos, ypos);
};

#endif // TROUPE_H_INCLUDED
