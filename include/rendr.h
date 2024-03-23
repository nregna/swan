#ifndef RENDR_H_INCLUDED
#define RENDR_H_INCLUDED

#include<iostream>
#include<SDL.h>
#include<SDL_image.h>

void dest(SDL_Texture*&);
void desw(SDL_Window*&);

void dest(SDL_Texture*&);
void desw(SDL_Window*&);

class Draw{
	public:
		bool texture(SDL_Texture*&, SDL_Renderer*, const char*);
		bool sprite(int, int, SDL_Texture*&, SDL_Renderer*&, SDL_Rect*, double, SDL_Point*, SDL_RendererFlip);
};

bool Draw::texture(SDL_Texture*& tex, SDL_Renderer* ren, const char* prm="44.png"){
	if(SDL_Surface* surf=IMG_Load(prm); surf){
		tex=SDL_CreateTextureFromSurface(ren, surf);
		if(tex==NULL){
			return false;
		};
		SDL_FreeSurface(surf);
	};
};

bool Draw::sprite(int xpos, int ypos, SDL_Texture*& ten, SDL_Renderer*& rei, SDL_Rect* arg=NULL, double angle=0.0, SDL_Point* center=NULL, SDL_RendererFlip flip=SDL_FLIP_NONE){
	SDL_Rect renderQuad = {xpos, ypos, 99, 78};
	if(arg!=NULL){
		renderQuad.w=arg->w;
		renderQuad.h=arg->h;
	};
	SDL_RenderCopyEx(rei, ten, arg, &renderQuad, angle, center, flip);
	printf("\n%s\n\n", SDL_GetError());
};

void dest(SDL_Texture*& tex){
	SDL_DestroyTexture(tex); tex=NULL;
};

void desw(SDL_Window*& wind){
	SDL_DestroyWindow(wind); wind=NULL;
};

#endif // RENDR_H_INCLUDED
