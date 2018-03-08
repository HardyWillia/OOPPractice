class Rational 
{
public:
	//Default cnstructor
	Rational(){}
	
	//Initialize denominator as 1 to prevent division by 0
	Rational(int a, int b = 1);
	Rational(const Rational&);
	
	//Operator overloads
	Rational& operator=(const Rational&);
	bool operator+=(const Rational&) const;
	bool operator-=(const Rational&);
        bool operator*=(const Rational&);
        bool operator/=(const Rational&);
        bool operator<=(const Rational&);
        bool operator<=(const Rational&);
        
	//Support for iostream and istream
	ostream& operator<< (ostream&, const Rational&);
	istream& operator>> (istream&, const Rational&);

};
