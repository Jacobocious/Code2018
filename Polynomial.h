#include <iostream>
#include <iomanip>
#include <cstdlib>


const int MAX_DEGREE = 10;

using namespace std;

class Polynomial{
	
	public:
	
	Polynomial();
	Polynomial(int c);
	
	bool setDegree(int deg=-1);
	bool setLetter(char s='X');
	char getLetter();
	
	int getDegree();
	
	double getCoefficient(int k) const;
	bool setCoefficient(int k, double newcoef=0);
	
	private:
	
	double coef[MAX_DEGREE+1];
	
	int degree;
	
	char vartype;
	
	
};

ostream & operator<<(ostream & out, Polynomial & p);
istream & operator>>(istream & inp, Polynomial & p);