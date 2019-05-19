//============================================================================
// Name        : Practice.cpp
// Author      : Kevin N.
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
/*
 *  Create a program to enter the year that you are born and print every year
 *  from then until 2018 inclusive. Dynamically allocate space for an array based
 *  on this. Meaning that you should be putting these values into an array, and the
 *  array should be exactly as long as it needs
 */

int main() {

	int my_year=0;
	std::size_t capacity=0;

	std::cin>>my_year;

	for(int i=my_year; i<=2018; i++){

		capacity++;

	}

	int *array_years=new int[capacity+1]; //dinamic allocation memory only works with pointers

	int j=0;
	for(int i=my_year; i<=2018; i++){

		array_years[j]=i;

		j++;

	}

	for(std::size_t k=0; k<capacity; k++){

		std::cout<<array_years[k]<<" ";

	}

	delete [] array_years;
	array_years=nullptr;


}
