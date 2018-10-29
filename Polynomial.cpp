#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <iomanip>
#include "Polynomial.h"

using namespace std;


Polynomial::Polynomial(){
	
	degree = -1;
	setLetter();
	
	for ( int i = 0; i <= MAX_DEGREE; i++ )
      coef[i] = 0.0;
	
}

Polynomial::Polynomial(int c){
	
	degree = MAX_DEGREE;
	setLetter();
	
	for ( int i = 0; i <= MAX_DEGREE; i++ ){
      coef[i] = c;
		c--;
	}
  
}

bool Polynomial::setLetter(char s){
	
	char j = tolower(s);
	
	if (j == 'a' || j == 'b' || j == 'c' || j == 'd' || j == 'e' || j == 'f' ||
	j == 'g' || j == 'h' || j == 'i' || j == 'j' || j == 'k' || j == 'l' || 
	j == 'm' || j == 'n' || j == 'o' || j == 'p' || j == 'q' || j == 'r' || 
	j == 's' || j == 't' || j == 'u' || j == 'v' || j == 'w' || j == 'x' || 
	j == 'y' || j == 'z'){
		vartype = j;
		return true;
	}
	else
		return false;
}

double Polynomial::evaluate(double value){
	
	double sum = 0;
	int exponent = degree;
	
	for (int i=degree; i >= 0; i--){
		
		sum = sum + coef[i]*(pow(value, exponent));
		exponent--;
	}
	return sum;
}
		

char Polynomial::getLetter() const{
	
	return vartype;
}

double Polynomial::getCoefficient(int k) const{
	
   if (k <= degree)
      return coef[k];
   else
      return 0.0;
}

bool Polynomial::setCoefficient(int k, double newcoef){
	int i = degree;
	
	if (k >= 0 && k <= MAX_DEGREE){
		coef[k] = newcoef;
		
	  while( i >= 0 && coef[i] == 0.0  ){
		
         degree--;
	  
         i--;
      }
	
		return true;
	}
		
}	

bool Polynomial::setDegree(int deg){
	
	if (deg <= MAX_DEGREE){
		degree = deg;
		return true;
	}
	else
		return false;
}

int Polynomial::getDegree() const{
	
	return degree;
}


ostream & operator<<(ostream & out, const Polynomial & p){
	
   if ( p.getDegree() == -1 ){
      cout << "Polynomial of degree -1" << endl;
      return out;
   }      
   
   if (p.getCoefficient(p.getDegree()) != 0){
     out << p.getCoefficient(p.getDegree());
	 
	 if (p.getDegree() > 0)
     out << p.getLetter() << "^" << p.getDegree();
 
   }
   
   for (int i = p.getDegree()-1; i >= 0; i--){
	   
      if (p.getCoefficient(i) < 0.0){
		  
		 if( i != 0 || p.getDegree() != 0 && p.getCoefficient(i) != 0)
         out << " - ";
		 
		 out << abs(p.getCoefficient(i));
	  }
	  
      else if (p.getCoefficient(i) > 0.0){
		 
		 if(i != 0 || p.getDegree() != 0 && p.getCoefficient(i) != 0)
         out << " + ";
	 
		 out << p.getCoefficient(i); 
	  }
	 
	  if (i > 0 && p.getCoefficient(i) != 0){
		  
		 out << p.getLetter();

		if(i > 1)
			out << "^" << i;
	  }
   }

   return out;
   
}

istream & operator>>(istream & inp, Polynomial & p){
	
	char tempvar;
	char comma = ',';
	char semicolon = ';';
	
	inp >> tempvar >> semicolon;
	
	if (p.setLetter(tempvar) == true){
		
		for (int i = 0; i <= p.getDegree()+1; i++){
			
			double newcoef;
			
			if (i < p.getDegree()+1)
				inp >> newcoef >> comma;
			else if (i == p.getDegree()+1)
				inp >> newcoef;
			
			p.setCoefficient(i, newcoef);
			
		}
	}
	else
		p.setDegree(-1);
	
	return inp;
}

Polynomial operator+(const Polynomial & onePoly, const Polynomial & twoPoly){
	
	Polynomial sumPoly;
	
	int oneDegree, twoDegree, maxDegree;
	double sum;
	
	oneDegree = onePoly.getDegree();
	twoDegree = twoPoly.getDegree();
	
	if(oneDegree < twoDegree)
		maxDegree = twoDegree;
	else
		maxDegree = oneDegree;
	
	for (int i = maxDegree; i >= 0; i--){
		
		sum = onePoly.getCoefficient(i) + twoPoly.getCoefficient(i);
		sumPoly.setCoefficient(i, sum);
	}
	
	sumPoly.setDegree(maxDegree);
	sumPoly.setLetter(onePoly.getLetter());
	
	return sumPoly;
}

Polynomial operator++(Polynomial & poly){

	poly.setCoefficient(0, poly.getCoefficient(0)+1);
	return poly;
}

Polynomial operator++(Polynomial & poly, int post){
	
	Polynomial postcrement;
	
	postcrement.setDegree(poly.getDegree());
	
	for(int i = poly.getDegree(); i >= 0; i--){
		
	postcrement.setCoefficient(i, poly.getCoefficient(i));
	}
	
	
	poly.setCoefficient(0, poly.getCoefficient(0)+1);
	
	postcrement.setDegree(poly.getDegree());
	
	return postcrement;
}

Polynomial operator-(const Polynomial & onePoly, const Polynomial & twoPoly){
	
	Polynomial difPoly;
	
	int oneDegree, twoDegree, maxDegree;
	double dif;
	
	oneDegree = onePoly.getDegree();
	twoDegree = twoPoly.getDegree();
	
	if(oneDegree < twoDegree)
		maxDegree = twoDegree;
	else
		maxDegree = oneDegree;
	
	for (int i = maxDegree; i >= 0; i--){
		
		dif = onePoly.getCoefficient(i) - twoPoly.getCoefficient(i);
		difPoly.setCoefficient(i, dif);
	}
	
	difPoly.setDegree(maxDegree);
	difPoly.setLetter(onePoly.getLetter());
	
	return difPoly;
}

Polynomial operator--(Polynomial & poly){

	poly.setCoefficient(0, poly.getCoefficient(0)-1);
	return poly;
}

Polynomial operator--(Polynomial & poly, int post){
	
	Polynomial postcrement;
	
	postcrement.setDegree(poly.getDegree());
	
	for(int i = poly.getDegree(); i >= 0; i--){
		
	postcrement.setCoefficient(i, poly.getCoefficient(i));
	}
	
	
	poly.setCoefficient(0, poly.getCoefficient(0)-1);
	
	return postcrement;
}

Polynomial operator*(const Polynomial & onePoly, const Polynomial & twoPoly){
	
	
	Polynomial product;
	
	for(int i = MAX_DEGREE; i >= 0; i--)
		product.setCoefficient(i, 0);
	
	product.setDegree(MAX_DEGREE);
	
	for( int i = onePoly.getDegree(); i >= 0; i--){
		
		for( int j = twoPoly.getDegree(); j >= 0; j--){
			product.setCoefficient((i + j),
		    (product.getCoefficient(i+j))+
			onePoly.getCoefficient(i)*twoPoly.getCoefficient(j));
		}
	}
	
	product.setLetter(onePoly.getLetter());
	
	return product;

}

bool operator<=(const Polynomial & onePoly, const Polynomial & twoPoly){
	
	int degree;
	
	if(onePoly.getDegree() > twoPoly.getDegree())
		degree = onePoly.getDegree();
	else
		degree = twoPoly.getDegree();
	
	while (onePoly.getCoefficient(degree) == twoPoly.getCoefficient(degree)
   		   && degree >= 0){
		
		degree--;
	}
	
	if (onePoly.getCoefficient(degree) <= twoPoly.getCoefficient(degree))
		return true;
	else if (onePoly.getCoefficient(degree) > twoPoly.getCoefficient(degree))
		return false;
	
}

bool operator>=(const Polynomial & onePoly, const Polynomial & twoPoly){
	
	int degree;
	
	if(onePoly.getDegree() > twoPoly.getDegree())
		degree = onePoly.getDegree();
	else
		degree = twoPoly.getDegree();
	
	while (onePoly.getCoefficient(degree) == twoPoly.getCoefficient(degree)
		   && degree >= 0){
		
		degree--;
	}
	
	if (onePoly.getCoefficient(degree) >= twoPoly.getCoefficient(degree))
		return true;
	else if (onePoly.getCoefficient(degree) < twoPoly.getCoefficient(degree))
		return false;
	
}

bool operator==(const Polynomial & onePoly, const Polynomial & twoPoly){
	
	int degree;
	
	if(onePoly.getDegree() > twoPoly.getDegree())
		degree = onePoly.getDegree();
	else
		degree = twoPoly.getDegree();
	
	while (onePoly.getCoefficient(degree) ==
		   twoPoly.getCoefficient(degree) && degree >= 0){
		
		degree--;
	}
	
	if (onePoly.getCoefficient(degree) == twoPoly.getCoefficient(degree))
		return true;
	else
		return false;
	
}

bool operator!=(const Polynomial & onePoly, const Polynomial & twoPoly){
	
	int degree;
	
	if(onePoly.getDegree() > twoPoly.getDegree())
		degree = onePoly.getDegree();
	else
		degree = twoPoly.getDegree();
	
	while (onePoly.getCoefficient(degree) == twoPoly.getCoefficient(degree)
		   && degree >= 0){
		
		degree--;
	}
	
	if (onePoly.getCoefficient(degree) == twoPoly.getCoefficient(degree))
		return false;
	else
		return true;
	
}
		
	
	
	
bool operator<(const Polynomial & onePoly, const Polynomial & twoPoly){	
	
	if (onePoly.getDegree() < twoPoly.getDegree())
		return true;
	else{
		
		for(int i = onePoly.getDegree(); i >= 0; i--){
			
			if(onePoly.getCoefficient(i) < twoPoly.getCoefficient(i))
				return true;
			else if(onePoly.getCoefficient(i) > twoPoly.getCoefficient(i))
				return false;
		}
		return false;
	}
}

bool operator>(const Polynomial & onePoly, const Polynomial & twoPoly){	
	
	if (onePoly.getDegree() > twoPoly.getDegree())
		return true;
	else{
		
		for(int i = twoPoly.getDegree(); i >= 0; i--){
			
			if(onePoly.getCoefficient(i) > twoPoly.getCoefficient(i))
				return true;
			else if(onePoly.getCoefficient(i) < twoPoly.getCoefficient(i))
				return false;
		}
		return false;
	}
}
	
	
void Polynomial::clear(){
	
	for(int i = degree; i >=0; i--){
		
		coef[i] = 0.0;
	}
	
	setDegree(-1);
}


