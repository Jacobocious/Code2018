//
// driver for testing


#include "Polynomial.h"

int main(){

    Polynomial p1(3);
    Polynomial p2(6);
	Polynomial p3(4);

	p1.setCoefficient(5, 0.0);
    cout << "p1 is: " << p1 << endl;
    cout << "p2 is: " << p2 << endl;
	cout << "p3 is: " << p3 << endl;
	cout << p3.getDegree() << endl << p3.getCoefficient(4) << endl;
	

    p1.setLetter('a');

    cout << p1 << endl;
	
	p1.setCoefficient(2,2.3);

    cout << p1 << " at 0 evaluates to: "  << p1.evaluate() << endl;

    p1.setCoefficient(5, ((p1.getCoefficient(5))*(-1)));

    cout << p1 << " at 2 evaluates to: "  << p1.evaluate(2) << endl;
	
	cout << "Testing addition and subtraction" << endl;
    cout << "p1 is: " << p1 << endl;
    cout << "p2 is: " << p2 << endl;
	cout << "p2 * p1: " << p2 * p1 << endl;
    cout << "p1 * p2: " << p1 * p2 << endl;
	cout << (p1 * p2).getDegree() << endl << (p1 * p2).getCoefficient(1) << endl;
	
	p1.clear();
	p1.setDegree(2);
	p1.setCoefficient(0, 5.9);

    cout << p1 << " at 200 evaluates to: "  << p1.evaluate(200) << endl;
	cout << endl << p1.getDegree() << endl;
	
	cout << "Testing addition and subtraction" << endl;
    cout << "p2 + p1: " << (p2 + p1) << endl;
	cout << p3 << endl;
	cout << --p3 << endl << ++p3 << endl << p3-- << endl << ++p3 << endl << --p3 << endl;
	
	if(p1 != p2)
		cout << endl << "It worked!";
	
	if(p2 == p2)
		cout << endl << "It worked!";
	
	if(p2 == p1)
		cout << endl << "It didn't work! :(";
	
	return 0;
	
}