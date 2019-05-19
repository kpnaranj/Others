//============================================================================
// Name        : Practice.cpp
// Author      : Kevin N.
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <iostream>

template <typename T>

size_t binary(T array[], size_t begin, size_t end, T x_value){

	size_t left{begin-1};
	size_t right{end-1};

	while(right!=left){

		size_t midpoint{(left+right)/2.0};

		if(array[midpoint]==x_value){

			return midpoint;
		}

		if(array[midpoint]>x_value){

			right=midpoint+1;
		}
		else {

			left=midpoint-1;
		}

	}

	return (array[left]==x_value)?left:end;// if array goes out of scope


}

int main(){


}

