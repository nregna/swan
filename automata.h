#ifndef AUTOMATA_H_INCLUDED
#define AUTOMATA_H_INCLUDED

#include<iostream>

bool chuyen(int xvel, int* xpos){
    if(*xpos==0||*xpos==391){
        xvel=0;
    }else if(*xpos+xvel>391){
        xvel=391-*xpos;
    }else if(*xpos-xvel<0){
        xvel=0-*xpos;
    }else{
        return false;
    };
    *xpos+=xvel;
	return true;
};

#endif // AUTOMATA_H_INCLUDED
