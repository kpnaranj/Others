//============================================================================
// Name        : Practice.cpp
// Author      : Kevin N.
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

struct array_t{

	int *max;
	int *min;

};



array_t set_values(int array[],std::size_t capacity){

	array_t result{};

	result.max=&array[0];
	result.min=&array[capacity];

	for(std::size_t k{0}; k<capacity; k++){

		if(array[k]>(*result.max)){

			result.max=&array[k];

		}

		if(array[k]<(*result.min)){

			result.min=&array[k];
		}


	}


	return result;

}

int main(){

	std::size_t capacity=5;

	int array[capacity]{1,2,-1,4,8};

	array_t values=set_values(array,capacity);

	std::cout<<(*values.max)<<(*values.min);




}
