#include"iostream"
#include"SDL.h"
#include"SDL_image.h"
#include"vector.h"
#include"string.h"
using std::vector;
using std::string;

class media{
	public:
		bool surf(SDL_Surface*& surfNo1){
			surfNo1=IMG_Load("");
			if(!surfNo1){
				return 0;
			};
		};
};

int main(int argc, char* argv[]){

};
