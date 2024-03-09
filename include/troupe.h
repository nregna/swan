#ifndef TROUPE_H_INCLUDED
#define TROUPE_H_INCLUDED

#include<iostream>

#include"rendr.h"
#include"mekanikk.h"
#include"poll.h"

class pierrot{
    public:
        Draw draw; Ballot ballot;
        int const haste = 10;
        bool update(SDL_Event&);
        bool init(SDL_Window*);
        bool close();
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
    chuyen(xvel, xpos, 391);
    chuyen(yvel, ypos, 293);
    draw.sprite(xpos, ypos, ten, rei);
};

bool pierrot::init(SDL_Window* wind){
    rei=SDL_CreateRenderer(wind, -1, SDL_RENDERER_ACCELERATED); SDL_SetRenderDrawColor(rei, 0xFF, 0xFF, 0xFF, 0xFF);
    draw.texture(ten, rei, "swan.png");
};

bool pierrot::close(){
    dest(ten);
    SDL_DestroyRenderer(rei); rei=NULL;
};

#endif // TROUPE_H_INCLUDED
