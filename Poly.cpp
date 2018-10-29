


#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <iomanip>
#include "Polynomial.h"

using namespace std;


//default constructor definition
Polynomial::Polynomial(){
	
	degree = -1;
	setLetter();
	
	for ( int i = 0; i <= MAX_DEGREE; i++ )
      coef[i] = 0.0;
	
}

//constructor for a polynomial with a specific 0th degree
Polynomial::Polynomial(int c){
	
	degree = MAX_DEGREE;
	setLetter();
	
	for ( int i = 0; i <= MAX_DEGREE; i++ ){
      coef[i] = c;
		c--;
	}
  
}

//this function sets the letter only if it's a valid char
//and returns false otherwise (if it's an int for example)
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


/*this algorithm treats the polynomial like a function
and returns the corresponding value based on the value
of the variable entered */
double Polynomial::evaluate(double value){
	
	double sum = 0;
	int exponent = degree;
	
	for (int i=degree; i >= 0; i--){
		
		sum = sum + coef[i]*(pow(value, exponent));
		exponent--;
	}
	return sum;
}
		

//returns variable type
char Polynomial::getLetter() const{
	
	return vartype;
}

//function def that returns the coefficients
//for a specific degree (if it is a valid degree)
double Polynomial::getCoefficient(int k) const{
	
   if (k <= degree)
      return coef[k];
   else
      return 0.0;
}

//sets the coefficient at a degree and changes degree
//if coefficient is set to 0
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

//function def that sets the degree if it
//is equal to or lower than MAX_DEGREE
bool Polynomial::setDegree(int deg){
	
	if (deg <= MAX_DEGREE){
		degree = deg;
		return true;
	}
	else
		return false;
}

//simply returns the degree
int Polynomial::getDegree() const{
	
	return degree;
}



//allows output of a polynomial
ostream & operator<<(ostream & out, const Polynomial & p){
	
	// if the degree is -1, don't need to continue
   if ( p.getDegree() == -1 ){                    
      cout << "Polynomial of degree -1" << endl;
      return out;
   }      
   
   //outputting the first term in the polynomial if it
   //isn't zero
   if (p.getCoefficient(p.getDegree()) != 0){
     out << p.getCoefficient(p.getDegree());
	 
	 if (p.getDegree() > 0)
     out << p.getLetter() << "^" << p.getDegree();
 
   }
   
   //a loops to output the entire polynomial
   for (int i = p.getDegree()-1; i >= 0; i--){
	  

	  //this condition is for negative values	  
      if (p.getCoefficient(i) < 0.0){
		  
		if(i != 0 || p.getDegree() != 0){
		 
			out << " - ";
			
		 out << abs(p.getCoefficient(i));
		}
	  }
	  
	  //this condition is for positive values
      else if (p.getCoefficient(i) > 0.0){
		 
		if(i != 0 || p.getDegree() != 0){
		 
			if (p.getCoefficient(i) != 0){
				
				if(p.getCoefficient(i+1) != 0 || (i+1) != p.getDegree())
					out << " + ";
			}
				
		 out << p.getCoefficient(i); 
		 
		}
	  }

		
	 //outputs the variable type and degree (part of loop)
	  if (i > 0 && p.getCoefficient(i) != 0){
		  
		 out << p.getLetter();

		if(i > 1)
			out << "^" << i;
	  }
	}

   return out;
}


//overloaded insertion operator definition for polynomial
istream & operator>>(istream & inp, Polynomial & p){
	
	char tempvar;
	
	//these will do since correct user input is assumed
	char comma = ',';
	char semicolon = ';';
	
	inp >> tempvar >> semicolon;
	
	//condition so that it must be a letter and not something else
	//(an int, for example)
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

//overload definition for addition operator
Polynomial operator+(const Polynomial & onePoly, const Polynomial & twoPoly){
	
	//temporary polynomial created for storage
	Polynomial sumPoly;
	
	int oneDegree, twoDegree, maxDegree;
	double sum;
	
	oneDegree = onePoly.getDegree();
	twoDegree = twoPoly.getDegree();
	
	if(oneDegree < twoDegree)
		maxDegree = twoDegree;
	else
		maxDegree = oneDegree;
	
	//loop to add the coefficients and set the temporary polynomial
	for (int i = maxDegree; i >= 0; i--){
		
		sum = onePoly.getCoefficient(i) + twoPoly.getCoefficient(i);
		sumPoly.setCoefficient(i, sum);
	}
	
	sumPoly.setDegree(maxDegree);
	sumPoly.setLetter(onePoly.getLetter());
	
	//no change to originals
	return sumPoly;
}

//preincrement operator definition
Polynomial operator++(Polynomial & poly){

	poly.setCoefficient(0, poly.getCoefficient(0)+1);
	return poly;
}

//postincrement operator definition
Polynomial operator++(Polynomial & poly, int post){
	
	//temporary polynomial created for storage
	Polynomial postcrement;
	
	postcrement.setDegree(poly.getDegree());
	
	for(int i = poly.getDegree(); i >= 0; i--){
		
	postcrement.setCoefficient(i, poly.getCoefficient(i));
	}
	
	
	poly.setCoefficient(0, poly.getCoefficient(0)+1);
	
	postcrement.setDegree(poly.getDegree());
	
	/* NOTE: the temporary polynomial is returned and has the
	original polynomials value(s), but the original polynomial
	has been incremented */
	return postcrement;
}

//the overloaded subtraction operator (refer to addition above for NOTES)
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

//predecrement operator definition
Polynomial operator--(Polynomial & poly){

	poly.setCoefficient(0, poly.getCoefficient(0)-1);
	return poly;
}

//postdecrememnt operator definition (refer to postincrememnt NOTES)
Polynomial operator--(Polynomial & poly, int post){
	
	Polynomial postcrement;
	
	postcrement.setDegree(poly.getDegree());
	
	for(int i = poly.getDegree(); i >= 0; i--){
		
	postcrement.setCoefficient(i, poly.getCoefficient(i));
	}
	
	
	poly.setCoefficient(0, poly.getCoefficient(0)-1);
	
	return postcrement;
}


//definition of multiplication operator
Polynomial operator*(const Polynomial & onePoly, const Polynomial & twoPoly){
	
	
	Polynomial product;
	
	for(int i = MAX_DEGREE; i >= 0; i--)
		product.setCoefficient(i, 0);
	
	product.setDegree(MAX_DEGREE);
	
	//for loops to cover every term in the first poly
	for( int i = onePoly.getDegree(); i >= 0; i--){
		
		//nested loop to cover every term in the second poly
		for( int j = twoPoly.getDegree(); j >= 0; j--){
			product.setCoefficient((i + j),
		    (product.getCoefficient(i+j))+
			onePoly.getCoefficient(i)*twoPoly.getCoefficient(j));
			
			
		// this is because the "setCoefficient()" function would screw it up
			product.setDegree(MAX_DEGREE);
		}
	}
	
	//sets the variable type to whatever the first poly is
	product.setLetter(onePoly.getLetter());
	
	return product;

}

//overloaded <= definition (is a friend function)
bool operator<=(const Polynomial & onePoly, const Polynomial & twoPoly){
	
	int degree;
	
	//uses the polynomial of highest degree for the loop
	if(onePoly.getDegree() > twoPoly.getDegree())
		degree = onePoly.getDegree();
	else
		degree = twoPoly.getDegree();
	
	//reduces the degree every run and compares the coefficients of each
	//stops when the coefficients are not equal and then compares below
	while (onePoly.getCoefficient(degree) == twoPoly.getCoefficient(degree)
   		   && degree >= 0){
		
		degree--;
	}
	
	if (onePoly.getCoefficient(degree) <= twoPoly.getCoefficient(degree))
		return true;
	else if (onePoly.getCoefficient(degree) > twoPoly.getCoefficient(degree))
		return false;
	
}

//overloaded >= definition (is a friend function)
//see above for detailed explanation (NOTES)
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

//overloaded == definition (is a friend function)
//see above for detailed explanation (NOTES)
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

//overloaded == definition (is a friend function)
//see above for detailed explanation (NOTES)
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
		
	
	
//less-than comparison operator overload definition
bool operator<(const Polynomial & onePoly, const Polynomial & twoPoly){	
	
	//if degree of p1 is < than p2, no way condition isn't satisfied
	if (onePoly.getDegree() < twoPoly.getDegree())
		return true;
	else{
		
		//tests coefficients at each degree if the degrees are equal
		for(int i = onePoly.getDegree(); i >= 0; i--){
			
			if(onePoly.getCoefficient(i) < twoPoly.getCoefficient(i))
				return true;
			else if(onePoly.getCoefficient(i) > twoPoly.getCoefficient(i))
				return false;
		}
		return false;
	}
}

//greater-than comparison operator overload definition
bool operator>(const Polynomial & onePoly, const Polynomial & twoPoly){	
	
	//if degree of p1 is > than p2, no way condition isn't satisfied
	if (onePoly.getDegree() > twoPoly.getDegree())
		return true;
	else{
		
		//tests coefficients at each degree if the degrees are equal
		for(int i = twoPoly.getDegree(); i >= 0; i--){
			
			if(onePoly.getCoefficient(i) > twoPoly.getCoefficient(i))
				return true;
			else if(onePoly.getCoefficient(i) < twoPoly.getCoefficient(i))
				return false;
		}
		return false;
	}
}
	
	
//this function sets all coefficients in the polynomial to 0
//and degree to -1	
void Polynomial::clear(){
	
	for(int i = degree; i >=0; i--){
		
		coef[i] = 0.0;
	}
	
	setDegree(-1);
}


