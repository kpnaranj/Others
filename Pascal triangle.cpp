//============================================================================
// Name        : Pascal.cpp
// Author      : Kevin N.
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>


int pascal_triangle(int n){
	int value;
	for (int i=0;i<=n;i++){
		value=1;
		for (int k=0;k<=i;k++){
			std::cout<<value<<" ";
			value=value*(i-k)/(k+1);
		}
		std::cout<<std::endl;
	}

	return value;
}
int main(){
	int n;
	std::cout<<"insert number here"<<std::endl;
	std::cin>>n;
	pascal_triangle(n);

}
