//============================================================================
// Name        : Practice.cpp
// Author      : Kevin N.
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

int check_three_chars (char a, char b, char c);

//add for parameters... a char is 1 byte so the parameters are 1*3= 3 bytes
int check_three_chars (char a, char b, char c){
   //add local variables an int is 4 byes and a char is 1 so this is 5 bytes
    int x=0;
    char hold;
    //an int is 4 bytes so for local variables the total is 4+5=9 bytes
    for(int i=0; i<3; i++){
        if (i==0){
            hold=a;
        }
        else if (i==1){
            hold=b;
        }
        else{
            hold=c;
        }

        if (hold=='a'||hold=='e'||hold=='i'||hold=='o'||hold=='u'||hold=='y'){
            x=x+1;
        }
    }
    return x;
}


int main(){
	char x,y,z;
	std::cin>>x;
	std::cin>>y;
	std::cin>>z;

	std::cout<<check_three_chars(x,y,z);



}
