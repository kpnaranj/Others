//============================================================================
// Name        : Practice.cpp
// Author      : Kevin N.
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <cmath>

/*You are asked to create a program that takes in an int and prints “fizz” if the number is divisible by 3,
 * “buzz” if the number is divisible by 5, and “fizz buzz” if the number is divisible by both. Print nothing
 *  if it is not divisible by either number. Write a flow chart for this program and then code it.
 */

int main() {
	int number=0;
	std::string commands;

	std::cout<<"Enter input ";std::cin>>number;

	if(number%3==0){

		std::cout<<"fizz ";

	}

	if(number%5==0){

		std::cout<<"buzz";

	}

	int a = 150;
	int* ptr = &a;
	std::cout <<a <<std::endl;
	std::cout <<ptr <<std::endl;
	std::cout <<*ptr <<std::endl;
	std::cout <<&ptr <<std::endl;
	return 0;

}
