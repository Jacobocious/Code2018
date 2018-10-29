

#include <iostream>
#include <iomanip>
#include <cstdlib>

//global constant "MAX_DEGREE" 
const int MAX_DEGREE = 10;

using namespace std;

class Polynomial{
	
	//here are the overloaded comparison operator function declarations
	friend bool operator<(const Polynomial & onePoly,
	                      const Polynomial & twoPoly);
						  
	friend bool operator>(const Polynomial & onePoly, 
						  const Polynomial & twoPoly);
						  
	friend bool operator<=(const Polynomial & onePoly, 
						  const Polynomial & twoPoly);
						  
	friend bool operator>=(const Polynomial & onePoly, 
						  const Polynomial & twoPoly);
						  
	friend bool operator!=(const Polynomial & onePoly, 
						  const Polynomial & twoPoly);
						  
	friend bool operator==(const Polynomial & onePoly, 
						  const Polynomial & twoPoly);
	
	
	public:
	
	
	//constructors for objects of type polynomial
	
	Polynomial();
	Polynomial(int c);
	
	
	//below are mutator and accessor function declarations
	//NOTE: initializations through some parameters below
	bool setDegree(int deg=-1);
	bool setLetter(char s='X');
	char getLetter() const;
	
	int getDegree() const;
	double evaluate(double value=0.0);
	
	double getCoefficient(int k) const;
	bool setCoefficient(int k, double newcoef=0);
	
	void clear();
	
	
	private:
	
	//private member data
	
	double coef[MAX_DEGREE+1];
	
	int degree;
	
	char vartype;
	
	
};

//overloaded insertion and extraction operator function declarations
//NOTE: the const is important
ostream & operator<<(ostream & out, const Polynomial & p);
istream & operator>>(istream & inp, Polynomial & p);

//overloaded arithmetic overloaded operator function declaractions
//NOTE: the const is important
Polynomial operator+(const Polynomial & onePoly, const Polynomial & twoPoly);
Polynomial operator-(const Polynomial & onePoly, const Polynomial & twoPoly);
Polynomial operator*(const Polynomial & onePoly, const Polynomial & twoPoly);

//overloaded unary operator function declaractions
Polynomial operator++(Polynomial & poly);
Polynomial operator++(Polynomial & poly, int post);
Polynomial operator--(Polynomial & poly);
Polynomial operator--(Polynomial & poly, int post);
