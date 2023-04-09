#include"iostream"
#include"SDL.h"
#include"SDL_image.h"
#include"vector.h"
#include"string.h"
using std::vector;
using std::string;

int main(int argc, char* argv[]){
	
	if(SDL_Init(SDL_INIT_VIDEO)==-1&&!IMG_Init(IMG_INIT_PNG)){
		
		printf("%s\n", SDL_GetError()); return 0;
	
	};
	
};
