#include <iostream>
#include <iomanip>
#include <cstdlib>


const int MAX_DEGREE = 4;

using namespace std;

class Polynomial{
	
	friend bool operator<(const Polynomial & onePoly, const Polynomial & twoPoly);
	friend bool operator>(const Polynomial & onePoly, const Polynomial & twoPoly);
	friend bool operator<=(const Polynomial & onePoly, const Polynomial & twoPoly);
	friend bool operator>=(const Polynomial & onePoly, const Polynomial & twoPoly);
	friend bool operator!=(const Polynomial & onePoly, const Polynomial & twoPoly);
	friend bool operator==(const Polynomial & onePoly, const Polynomial & twoPoly);
	
	
	public:
	
	Polynomial();
	Polynomial(int c);
	
	bool setDegree(int deg=-1);
	bool setLetter(char s='X');
	char getLetter() const;
	
	int getDegree() const;
	double evaluate(double value=0.0);
	
	double getCoefficient(int k) const;
	bool setCoefficient(int k, double newcoef=0);
	
	void clear();
	
	
	private:
	
	double coef[MAX_DEGREE+1];
	
	int degree;
	
	char vartype;
	
	
};

ostream & operator<<(ostream & out, const Polynomial & p);
istream & operator>>(istream & inp, Polynomial & p);

Polynomial operator+(const Polynomial & onePoly, const Polynomial & twoPoly);
Polynomial operator-(const Polynomial & onePoly, const Polynomial & twoPoly);
Polynomial operator*(const Polynomial & onePoly, const Polynomial & twoPoly);

Polynomial operator++(Polynomial & poly);
Polynomial operator++(Polynomial & poly, int post);
Polynomial operator--(Polynomial & poly);
Polynomial operator--(Polynomial & poly, int post);
