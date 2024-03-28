#ifndef TROUPE_H_INCLUDED
#define TROUPE_H_INCLUDED

#include<iostream>

#include"rendr.h"
#include"mekanikk.h"
#include"poll.h"

class Pierrot{
	public:
		Draw draw; Ballot ballot;
		bool update(SDL_Event&, SDL_Renderer*&), init(SDL_Renderer*&), close(), texture();
	private:
		int const HASTE = 1;
		int iXPos=0, iYPos=0, iXVel=0, iYVel=0;
	protected:
		SDL_Texture* ten=NULL;
	//        SDL_Renderer* rei=NULL;
};

bool Pierrot::update(SDL_Event& arg, SDL_Renderer*& rei){
	ballot.handle(arg, &iXVel, &iYVel, HASTE);
	shift(&iXVel, &iXPos, 391-99);
	shift(&iYVel, &iYPos, 293-78);
	draw.sprite(iXPos, iYPos, ten, rei);
	printf("pos: %d - %d\n\n",iXPos,iYPos);
};

bool Pierrot::init(SDL_Renderer*& rei){
	draw.texture(ten, rei, "swan.png");
	draw.sprite(iXPos, iYPos, ten, rei);
};

bool Pierrot::close(){
	dest(ten);
//    SDL_DestroyRenderer(rei); rei=NULL;
};

bool Pierrot::texture(){
	return ten;
};

#endif // TROUPE_H_INCLUDED
