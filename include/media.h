#ifndef MEDIA_H_INCLUDED
#define MEDIA_H_INCLUDED

#include<iostream>
#include<SDL.h>
#include<SDL_image.h>

#include"rendr.h"
#include"poll.h"
#include"troupe.h"

class Window{
    public:
        Draw draw; Ballot ballot; pierrot swan;
        bool init();
        bool update(SDL_Event&);
        bool close();
    private:
        SDL_Window* wind=NULL;
        SDL_Renderer* ren=NULL;
        SDL_Texture* tex=NULL;
        int act[2]={0,0};
};

bool Window::init(){
    wind=SDL_CreateWindow("Ain't so", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 391, 293, SDL_WINDOW_SHOWN);
    ren=SDL_CreateRenderer(wind, -1, SDL_RENDERER_ACCELERATED); SDL_SetRenderDrawColor(ren, 0xFF, 0xFF, 0xFF, 0xFF);
    draw.texture(tex, ren);
};

bool Window::update(SDL_Event& arg){
    switch (act[0]){
        case 0:
            if(ballot.menu(arg, tex, ren)==true){
                    act[0]=1;
                    printf("das zweite\n");
                    swan.init(wind);
            };
            break;
        case 1:
            swan.update(arg);
            printf("mhm\n");
            break;
    };
    SDL_UpdateWindowSurface(wind);
};

bool Window::close(){
    swan.close(); desw(wind); dest(tex);
    SDL_DestroyRenderer(ren); ren=NULL;
};

#endif // MEDIA_H_INCLUDED
