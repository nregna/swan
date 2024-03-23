#ifndef MEKANIKK_H_INCLUDED
#define MEKANIKK_H_INCLUDED

#include<iostream>

bool chuyen(int* vel, int* pos, int s){
	if(*pos<=0){
		*pos=s;
	}else if(*pos>=s){
		*pos=0;
	};
	*pos-=(*vel);
	return true;
};

#endif // MEKANIKK_H_INCLUDED
