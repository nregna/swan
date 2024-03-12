#ifndef AUTOMATA_H_INCLUDED
#define AUTOMATA_H_INCLUDED

#include<iostream>

bool chuyen(int* vel, int* pos, int s){
    if(*pos==0||*pos==s){
        (*vel)=-2*(*vel);
    }else if(*pos+(*vel)>s){
        (*vel)=s-*pos;
    }else if(*pos-(*vel)<0){
        (*vel)=0-*pos;
    }else{
        return false;
    };
    *pos+=(*vel);
	return true;
};

#endif // AUTOMATA_H_INCLUDED
