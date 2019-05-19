//============================================================================
// Name        : Practice.cpp
// Author      : Kevin N.
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>
// root finding algorithm f(x)=0
float f(float x);
float rootFind(float left, float right, float precision);


int main(){

	float x,y,z;

	std::cin>>x>>y>>z;


	std::cout<<rootFind(x,y,z);




}



float f(float x){
return (x*x*x - 2.75*x + 1.2);
}

bool check_function(float a, float b){

	if((a>=0&&b<0)||(b>=0&&b<0)){

		return true;
	}

	return false;
}

float rootFind(float left, float right, float precision){


	if(!check_function(f(left),f(right))){

		std::cerr<<"range of function has no roots";
		return 0;

	}

	float midpoint=(right+left)/2;

	while(std::abs(right)>=precision){

		if(check_function(f(left),f(midpoint))){
			right=midpoint;
		}
		else{
			left=midpoint;

		}

		midpoint=(right+left)/2;

	}

	return right;
}
