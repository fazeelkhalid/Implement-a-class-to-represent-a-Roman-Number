#include<iostream>
#include"Q2.h"
#include<string.h>
using namespace std;

int main() {
	roman r1;
	roman r2;
	cout << "\n Enter in r1\n\n ";
	cin >> r1;
	cout << "\n Enter in r2\n\n ";
	cin >> r2;
	roman r3;
	cout << "\nr1 value before post increment : "<<r1;
	r3 = r1++;
	cout << "\n r3 valuse after post increment in r1 : "<<r3;
	cout << "\n r1 value after post increment  : " << r1;
	cout<<"\n_____________________________________________";
	
	cout << "\nr1 value before pre increment : "<< r1;
	r3 = ++r1;
	cout << "\n r3 valuse after pre increment in r1 : " << r3;
	cout << "\n r1 value after pre increment  : " << r1;
	cout << "\n_____________________________________________";

	cout << "\nr1 value before pre decrement : "<< r1;
	r3 = --r1;
	cout << "\n r3 valuse after pre decrement in r1 : " << r3;
	cout << "\n r1 value after pre decrement : " << r1;
	cout << "\n_____________________________________________";

	cout << "\nr1 value before post decrement : " << r1;
	r3 = r1--;
	cout << "\n r3 valuse after post decrement in r1 : " << r3;
	cout << "\n r1 value after post decrement : " << r1;
	cout << "\n_____________________________________________";

	cout<<"\nsum of two number : "<< (r1 + r2);
	cout << "\nSubtraction of two number : " << (r1 - r2);
	cout << "\nMultiplication of two number : " << (r1 * r2);
	cout << "\nDivision of two number : " << (r1 / r2);
	
	if (r1 == r2) {
		cout << "\nr1 == r2";
	}
	
	if (r1 != r2) {
		cout << "\nr1 != r2";
	}

	if (r1 < r2) {
		cout << "\n r1 < r2";
	}

	if (r1 > r2) {
		cout << "\nr1 > r2";
	}
	
	return 0;
}