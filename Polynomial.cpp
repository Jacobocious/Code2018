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

char Polynomial::getLetter(){
	
	return vartype;
}

double Polynomial::getCoefficient(int k) const{
	
   if (k <= degree)
      return coef[k];
   else
      return 0.0;
}

bool Polynomial::setCoefficient(int k, double newcoef){
	
	if (k >= 0 && k <= MAX_DEGREE){
		coef[k] = newcoef;
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
int Polynomial::getDegree(){
	
	return degree;
}


ostream & operator<<(ostream & out, Polynomial & p){
	
   if ( p.getDegree() == -1 ){
      cout << 0;
      return out;
   }      
   
   if (p.getCoefficient(p.getDegree()) != 0)
   out << p.getCoefficient(p.getDegree()) << p.getLetter() << "^"
   << p.getDegree();
   
   for (int i = p.getDegree()-1; i >= 0; i--){
	   
      if (p.getCoefficient(i) < 0.0)
         out << " - " << abs(p.getCoefficient(i));
      else if (p.getCoefficient(i) > 0.0)
         out << " + " << p.getCoefficient(i); 
	 
	  if (i > 0 && p.getCoefficient(i) != 0)
		 out << p.getLetter() << "^" << i;
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
			
			int newcoef;
			
			if (i < p.getDegree()+1)
				inp >> newcoef >> comma;
			else if (i == p.getDegree()+1)
				inp >> newcoef;
			
			p.setCoefficient(i, newcoef);
			
		}
	}
	else
		p.setDegree();
	
	return inp;
}

