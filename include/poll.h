#ifndef POLL_H_INCLUDED
#define POLL_H_INCLUDED

#include<iostream>
#include<SDL.h>
#include<SDL_image.h>

#include"rendr.h"

class Ballot{
    public:
        bool menu(SDL_Event&, SDL_Texture*&, SDL_Renderer*&);
        bool handle(SDL_Event&, int*, int*, int);
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
				draw.texture(tex, ren, "44.png");
				SDL_RenderClear(ren);
				SDL_RenderCopy(ren, tex, NULL, NULL);
				SDL_RenderPresent(ren);
				return true; break;
        	};
	}; return false;
};

bool Ballot::handle(SDL_Event& arg, int* xvel, int* yvel, int haste){
    if(arg.type==SDL_KEYDOWN){
        switch(arg.key.keysym.sym){
		case SDLK_BACKSPACE:
			arg.type=SDL_QUIT;
			break;
		case SDLK_ESCAPE:
			arg.type=SDL_QUIT;
			break;
		case SDLK_UP:
			*yvel+=haste;
			break;
		case SDLK_DOWN:
			*yvel-=haste;
			break;
		case SDLK_LEFT:
			*xvel+=haste;
			break;
		case SDLK_RIGHT:
			*xvel-=haste;
			break;
        };
    };
    printf("vel: (%d) - (%d)\n", *xvel, *yvel);
};

#endif // POLL_H_INCLUDED
