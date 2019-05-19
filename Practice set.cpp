//============================================================================
// Name        : Practice.cpp
// Author      : Kevin N.
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

double sum_operator(double x, double y){

	return x+y;
}
double sub_operator(double x, double y){

	return x-y;
}
double mult_operator(double x, double y){

	return x*y;
}
double div_operator(double x, double y){

	return x/y;
}

void input_numbers(){

	for(int i=1; i<=4; i++){

			switch (i){

			case 1:std::cout<<i<<") sum";break;
			case 2:std::cout<<i<<") subtract";break;
			case 3:std::cout<<i<<") multiply";break;
			case 4:std::cout<<i<<") divide";break;

			}
			std::cout<<std::endl;
	}

}

int main() {

	double x{0},y{0};
	int choose{0};

	std::cout<<"choose operation"<<std::endl;

	input_numbers();

	std::cout<<std::endl;

	std::cin>>choose;

	std::cout<<"enter number 1:";std::cin>>x;

	std::cout<<"enter number 2:";std::cin>>y;

	if(choose==1){

		std::cout<<"The result is ="<<sum_operator(x,y);

	}
	else if(choose==2){
		std::cout<<"The result is ="<<sub_operator(x,y);

		}
	else if(choose==3){
		std::cout<<"The result is ="<<mult_operator(x,y);

		}
	else if(choose==4){

		if(y==0){
			std::cout<<"error";
		}

		else{
			std::cout<<"The result is ="<<div_operator(x,y);
		}


	}

	else{
		std::cout<<"invalid output"<<std::endl;
	}


}
