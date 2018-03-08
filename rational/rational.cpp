#include "rational.hpp"
#include <iostream>



Rational::Rational(){
	a = 0;
	b = 1;
}

Rational::Rational(int a, int b){
	a = a;
	b = b;
}

//Operator overload functions

Rational& Rational::operator=(const Rational& rat){
	
	a = rat.a;
	b = rat.b;
	
	return *this;
}

bool Rational::operator==(const Rational& rat) const{
	bool result;
	if((this->a == rat.a) && (this->b == rat.b))
		result = true;
	else 
		result = false;
	return result;
}

bool Rational::operator!=(int x) const{
	return !(*this == num);
}

bool Rational::operator>= (const Rational& rat) const{
	bool result;
	
	if(!(*this < rat))
		result = true;
	else 
		result = false;
	return result;
}

bool Rational::operator<=(const Rational& rat) const{
	bool result;
	
	if(!(*this > rat))
		result = true;
	else 
		result = false;
	return result;
}


//Input and Output stream handlers
ostream& operator<< (ostream& os, const Rational& rat){
	
	os << rat.a << ":" << rat.b;
	return os;
}

istream& operator>> (istream& is, const Rational& rat){
	
	is >> a >> b;
	rat.a = a;
	rat.b = b;
	raturn is;
}

//Ensure that the denominator does not equal zero
void zerodenom(int a, int b){
	a++;
	if(b = 0)
		std::cout << "The denominator equals zero";
}


	
