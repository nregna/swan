#ifndef POLL_H_INCLUDED
#define POLL_H_INCLUDED

#include<iostream>
#include<SDL.h>
#include<SDL_image.h>

#include"rendr.h"

class Ballot{
    public:
        bool menu(SDL_Event&, SDL_Texture*&, SDL_Renderer*&);
        bool handle(SDL_Event&, int, int, int, int, int);
        int argfxn();
    private:
        int var=0;
};

bool Ballot::menu(SDL_Event& arg, SDL_Texture*& tex, SDL_Renderer*& ren){
	if(Draw draw; arg.type==SDL_KEYDOWN){
		switch(arg.key.keysym.sym){
			case SDLK_BACKSPACE:
				arg.type=SDL_QUIT;
				break;
			case SDLK_ESCAPE:
				arg.type=SDL_QUIT;
				break;
			case SDLK_SPACE:
                if(var!=1||2){
                    draw.texture(tex, ren, "44.png");
                    SDL_RenderClear(ren);
                    SDL_RenderCopy(ren, tex, NULL, NULL);
                    SDL_RenderPresent(ren);
                    return true;
                }else{
                    //create pierrot using texture/renderer within pierrot.
                };
                var++;
				break;
        };
	};
};

bool Ballot::handle(SDL_Event& arg, int xpos, int ypos, int xvel, int yvel, int haste){
    if(arg.type==SDL_KEYDOWN){
        switch(arg.key.keysym.sym){
            case SDLK_BACKSPACE:
				arg.type=SDL_QUIT;
				break;
			case SDLK_ESCAPE:
				arg.type=SDL_QUIT;
				break;
            case SDLK_UP:
                yvel+=haste;
                break;
            case SDLK_DOWN:
                yvel-=haste;
                break;
            case SDLK_LEFT:
                xvel+=haste;
                break;
            case SDLK_RIGHT:
                xvel-=haste;
                break;
        };
    };
};

int Ballot::argfxn(){
    return var;
};

#endif // POLL_H_INCLUDED
