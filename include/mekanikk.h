#ifndef MEKANIKK_H_INCLUDED
#define MEKANIKK_H_INCLUDED

#include<iostream>

bool chuyen(int* vel, int* pos, int s){
	if(*pos<0||*pos>s){
		*vel=-(*vel);
	}; 
	*pos+=(*vel); 
	return true;
};

#endif // MEKANIKK_H_INCLUDED
