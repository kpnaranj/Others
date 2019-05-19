//============================================================================
// Name        : Practice.cpp
// Author      : Kevin N.
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

int factorial(int n){
	if(n==0){

		return 1;
	}

	return n*factorial(n-1);
}


int main(){
	int n=0;
	std::cin>>n;

	std::cout<<factorial(n)<<std::endl;



	unsigned int m{ 1000 };
	m <<= 3;
	std::cout <<m <<std::endl;
	m >>= 1;
	std::cout <<m <<std::endl;

	int a = 11;  //8   2   1       1  0  1 1
	int b = 12; // 8   4    0      1  1  0  0       1 0 0 0   8
	int c = a & b; //
	bool d = (a > 0 && b > 0); // double value will return true false
	std::cout <<c <<std::endl;
	std::cout <<d <<std::endl;
}

//  150  128   32          1 0 1 0 0 0 0 0
// 1101011    1+2+8+32+64= 107


