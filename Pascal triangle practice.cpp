//============================================================================
// Name        : Pascal.cpp
// Author      : Kevin N.
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>
int pascal(int n){
	int value;
	for (int rows=0;rows<=n;rows++){
		value=1;
		for (int k=0;k<=rows;k++){
		std::cout<<value<<" ";
		value=value*(rows-k)/(k+1);
		}
		std::cout<<std::endl;
	}
	return value;
}
int main (){
	int n;
	std::cout<<"enter value"<<std::endl;
	std::cin>>n;
	std::cout<<pascal(n)<<std::endl;

}
