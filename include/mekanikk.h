#ifndef MEKANIKK_H_INCLUDED
#define MEKANIKK_H_INCLUDED

#include<iostream>

bool shift(int* vel, int* pos, int s){
	if(*pos<0){
		*vel=-(*vel); *pos=0;
	}else if(*pos>s){
		*vel=-(*vel); *pos=s;
	};
	*pos+=(*vel);
	return true;
};

#endif // MEKANIKK_H_INCLUDED
