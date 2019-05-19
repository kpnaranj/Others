//============================================================================
// Name        : Determine.cpp
// Author      : Kevin N.
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Polynomial.h"
#include <iostream>
#include <cmath>
#ifndef MARMOSET_TESTING
int main();
#endif


poly_t my_poly{nullptr,0};

poly_t my_second_poly{nullptr,0};

#ifndef MARMOSET_TESTING
int main() {

	poly_t values_x1{nullptr, 0};
	poly_t values_x2{nullptr, 0};

	double x=0;



	std::cout<<"The degree of the polynomial:  ";

	std::cin>>values_x1.degree;
	values_x1.a_coeffs=new double [values_x1.degree+1];



	for(unsigned int i=0; i<values_x1.degree+1; i++){

		std::cout<<"Please introduce value "<<i+1<<" ";
		std::cin>>values_x1.a_coeffs[i];
	}


	init_poly(my_poly,values_x1.a_coeffs,values_x1.degree);
					std::cout<<std::endl;

	std::cout<<"Value of degree --> "<<poly_degree(my_poly);
					std::cout<<std::endl;

	std::cout<<"Enter value to evaluate polynomial -->";
	std::cin>>x;
	std::cout<<std::endl;
	std::cout<<"Polynomial to "<<x<<" equals "<<poly_val(my_poly,x);
						std::cout<<std::endl;


	std::cout<<"Poly divide ";
	double a=0;

	std::cin>>a;

	std::cout<<poly_divide( my_poly, a);

	/*std::cout<<poly_approx_int(my_poly, a, b, n);*/


	for (unsigned int i=0; i<my_poly.degree+1; i++){


		std::cout<<my_poly.a_coeffs[i]<<" ";

	}


	std::cout<<"Enter second value q:  ";

	std::cin>>values_x2.degree;
	values_x2.a_coeffs=new double [values_x2.degree+1];

	for(unsigned int i=0; i<values_x2.degree+1; i++){

			std::cout<<"Please introduce value "<<i+1<<" ";
			std::cin>>values_x2.a_coeffs[i];

	}

	init_poly(my_second_poly, values_x2.a_coeffs, values_x2.degree);
				std::cout<<std::endl;

	poly_add(my_poly, my_second_poly);

	destroy_poly(my_second_poly);

	std::cout<<" Values are ";

	for (unsigned int i=0; i<my_poly.degree; i++){

		std::cout<< my_poly.a_coeffs[i]<<"x^"<<i<<" ";


	}







}
#endif
///////////////////////////////////



void init_poly(poly_t &p, double const init_coeffs[],
unsigned int const init_degree){

	if (p.a_coeffs!=nullptr){

		destroy_poly(p);

	}
	p.degree=init_degree;

	p.a_coeffs=new double [p.degree+1];

	for (unsigned int i=0; i<p.degree+1; i++ ){

		p.a_coeffs[i]=init_coeffs[i];


		}

	for (unsigned int i=0; i<p.degree+1; i++ ){

		if (i==0){

			std::cout<<"The polynomial is--> ";
			std::cout<<p.a_coeffs[i];

			}

		else if (i>0&&i<p.degree-1){

			std::cout<<"+"<<p.a_coeffs[i]<<"x^"<<i<<"+";
			}

		else {

			std::cout<<p.a_coeffs[i]<<"+"<<"x^"<<i;

			}

		}

	}


void destroy_poly(poly_t &p){

	delete[] p.a_coeffs;

	p.a_coeffs=nullptr;

	p.degree=0;

}

unsigned int poly_degree(poly_t const &p){

	unsigned value=0;

	if (p.a_coeffs==nullptr){

		value=0;

		throw 0;
	}
	else {

		value=p.degree;

	}

	return value;
}
double poly_coeff( poly_t const &p, unsigned int n ){

	double result= p.a_coeffs[n];

	return result;

}

double poly_val(poly_t const &p, double const x){

	double evaluation=p.a_coeffs[0];

	if (p.a_coeffs==nullptr){

	throw 0;

	}

	for (unsigned int i=p.degree; i>0; i--){


		evaluation+=(p.a_coeffs[i])*std::pow(x,i);

	}

	return evaluation;


}

void poly_add (poly_t &p, poly_t const &q){

	poly_t sum;

	if (p.a_coeffs==nullptr||q.a_coeffs==nullptr){

		throw 0;
	}

	sum.degree=std::max(p.degree,q.degree);

	sum.a_coeffs=new double [sum.degree+1];

	for (unsigned int i=0; i<std::min(p.degree,q.degree)+1; i++){

		sum.a_coeffs[i]=p.a_coeffs[i]+q.a_coeffs[i];

		}



	if (sum.degree==p.degree){

		for (unsigned int j=std::min(p.degree,q.degree)+1; j<p.degree+1; j++){

				sum.a_coeffs[j]=p.a_coeffs[j];

			}

		}

	else {

		for (unsigned int k=std::min(p.degree,q.degree)+1; k<q.degree+1; k++){

			sum.a_coeffs[k]=q.a_coeffs[k];

		}

	}

	destroy_poly(p);

	p.degree=sum.degree;

	p.a_coeffs=new double [p.degree+1];

	for (unsigned int t=0; t<p.degree+1; t++){

		p.a_coeffs[t]=sum.a_coeffs[t];

	}

	destroy_poly(sum);

}

void poly_subtract( poly_t &p, poly_t const &q ){

	poly_t subs;

		if (p.a_coeffs==nullptr||q.a_coeffs==nullptr){

			throw 0;
		}

		subs.degree=std::max(p.degree,q.degree);

		subs.a_coeffs=new double [subs.degree+1];

		if (p.degree==q.degree){

			for (unsigned int i=0; i<p.degree+1; i++){

				subs.a_coeffs[i]=p.a_coeffs[i]-q.a_coeffs[i];

			}

		}

		if (q.degree<p.degree){

			for (unsigned int i=q.degree+1; i<p.degree+1; i++){

				subs.a_coeffs[i]=p.a_coeffs[i];
			}

			for (unsigned int j=0; j<q.degree+1; j++){

				subs.a_coeffs[j]=p.a_coeffs[j]-q.a_coeffs[j];

			}
		}

		if (p.degree<q.degree){

			for (unsigned int i=0; i<p.degree+1; i++){

				subs.a_coeffs[i]=p.a_coeffs[i]-q.a_coeffs[i];

			}

			for (unsigned int j=p.degree+1; j<q.degree+1; j++){

				subs.a_coeffs[j]=-q.a_coeffs[j];
			}

		}

		destroy_poly(p);

		p.degree=subs.degree;

		p.a_coeffs=new double [p.degree+1];

		for (unsigned int t=0; t<p.degree+1; t++){

			p.a_coeffs[t]=subs.a_coeffs[t];

		}

		destroy_poly(subs);



}

void poly_multiply( poly_t &p, poly_t const &q ){

				poly_t mult{nullptr, 0};

			if (p.a_coeffs==nullptr||q.a_coeffs==nullptr){

				throw 0;
			}


			mult.degree=p.degree+q.degree;

			mult.a_coeffs=new double [mult.degree+1]{};

			for (unsigned int i=0; i<p.degree+1; i++){

				for (unsigned int j=0; j<q.degree+1; j++){

					mult.a_coeffs[i+j]+=p.a_coeffs[i]*q.a_coeffs[j];

				}

			}

			destroy_poly(p);

			p.degree=mult.degree;

			p.a_coeffs=new double [p.degree+1];

			for (unsigned int j=0; j<p.degree+1; j++){

				p.a_coeffs[j]=mult.a_coeffs[j];

			}

			destroy_poly(mult);

}

double poly_divide( poly_t &p, double r ){

	// Use root terms of x
	// Divide x2+x+1=
	poly_t d{nullptr,1};//  x-2
	poly_t rem{nullptr,0};
	poly_t cocient{nullptr,0};

	if (p.a_coeffs==nullptr){

		throw 0;

	}


	d.a_coeffs=new double [d.degree+1]{0};
	d.a_coeffs[0]=-r;
	d.a_coeffs[1]=1;

	rem.degree=p.degree-d.degree;
//
	rem.a_coeffs=new double [rem.degree+1]{0};


	//2 p x3 + 2x2 +x +1  | d x+1  degree coeficient x3/x    x2 r=c degree=2+1     c*d   p-c  p x2+x+1
			//1  p x2 +2x +1 | d x+1  r->x2  x2+x  degree= 2-1   last x+0  c*d  p-c   x+1 p
			//0 p x+1| x+1  r->x  x2+x+1  degree 1-1  1  c*d  p-c   p= 0
			// rem=p  destruct p  p=r   destroy

	for (unsigned int i=rem.degree; i>0; i++){


		if (i==rem.degree){ // p =5

			cocient.degree=rem.degree;  // 4   4

			cocient.a_coeffs=new double [cocient.degree+1]{0};//

			rem.a_coeffs[i]=p.a_coeffs[i]; // rem 4 = valor

			cocient.a_coeffs[i]=rem.a_coeffs[i]; // coc 4 = valor

			poly_multiply(cocient,d);

			poly_subtract(p,cocient);

			destroy_poly(cocient);

		}

		else if (i>0){ // poli= 4 p=3 2

			rem.a_coeffs[i]=p.a_coeffs[i-1]; // rem 3=valor  2 1

			cocient.degree=rem.degree; // c=3  2 1

			cocient.a_coeffs=new double [cocient.degree+1]{0}; //

			cocient.a_coeffs[i]=rem.a_coeffs[i];//3 2 1

			poly_multiply(cocient,d);//c=43 2

			poly_subtract (p, cocient);//c=43 2

			destroy_poly(cocient);// p=32 1


		}

		if (i-1==0){ // 1

			rem.a_coeffs[i-1]=p.a_coeffs[i]; // rem 3=valor  2 1 0

			cocient.degree=poly_degree(p)-1; // c=3  2 1 0

			cocient.a_coeffs=new double [cocient.degree+1]{0}; //

			cocient.a_coeffs[i-1]=rem.a_coeffs[i-1];//3 2 1 0

			poly_multiply(cocient,d);//c=43 2 1

			poly_subtract (p, cocient);//c=43 2 1

			destroy_poly(cocient); // 0


		}

	}


	double remain=p.a_coeffs[0];

	destroy_poly(p);

	p.degree=rem.degree;
	p.a_coeffs=new double [p.degree];

	for (unsigned int i=0; i<p.degree+1; i++){

		p.a_coeffs[i]=rem.a_coeffs[i];

	}


	destroy_poly(rem);
	destroy_poly(d);

	return remain;
}

void poly_diff(poly_t &p){

	// x=cociente

	poly_t diff;

	diff.degree=p.degree-1;

	diff.a_coeffs=new double [diff.degree]{};

	if (p.a_coeffs==nullptr){

		throw 0;
	}

	for (unsigned int i=0; i<diff.degree+1; i++){

		diff.a_coeffs[i]=p.a_coeffs[i+1]*(i+1);

		std::cout<<diff.a_coeffs[i]<<" ";

	}

	destroy_poly(p);

	p.degree=diff.degree;

	p.a_coeffs=new double [p.degree+1];

	destroy_poly(diff);

}

double poly_approx_int(poly_t const &p, double a, double b, unsigned int n){

	if (p.a_coeffs==nullptr){

		throw 0;
	}

	double result=0, h=0, add_poly=0;

	double x[n+1],y[n+1];

	h=(b-a)/(2*n);

	for (unsigned int i=0; i<n+1;i++){

		x[i]=i*h+a;

		y[i]=poly_val(p, x[i]);

	}

	for (unsigned int j=0; j<n; j++){

		add_poly=add_poly+(h*y[j]);

	}

	result=h*(y[0]+y[n])+add_poly;

	return result;
}




