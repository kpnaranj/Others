//============================================================================
// Name        : PascalsTriangle.cpp
// Author      : Kevin N.
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================



#include <iostream>
#include <cmath>
int pascal_triangle(int n);
int body_structure(int n,int k );
int pascal_triangle_recursive(int n);

#ifndef MARMOSET_TESTING
int main();
#endif

//Part A
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
//end part A

//Part B
int	body_structure(int n, int k){

	if (n==k||k==0){
		return 1;}

	else{
		return body_structure(n-1,k-1)+body_structure(n-1,k);
	}
}

int pascal_triangle_recursive(int n){
	int counter=0;
	for (int i=0;i<=n;i++){

		for (int j=0;j<=i;j++){
			counter++;
			std::cout<<body_structure(i,j)<<" ";

		}

		std::cout<<std::endl;
	}

	return counter;
}
// End part b

#ifndef MARMOSET_TESTING
int main(){
	int n;
	std::cin>>n;
	pascal_triangle(n);
	pascal_triangle_recursive(n);

	return 0;
}
#endif
