/***************************************************************************
 boatwright1.cpp
 COP 2001 Assignment #1 - 2017
 Ivan Boatwright
 ijboatwright5153@eagle.fgcu.edu
 February 9, 2017
 
   This program solves a single quadratic equation of the form:
  		a*x^2 + b*x + c = 0
   Where a, b, and c are entered by the operator when prompted. The results
   are printed to stdout and vary based on the value of the discriminant.
 ***************************************************************************/

#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

// Reads and returns a single coefficient from stdin.
void readCoeffs(double&, double&, double&);

// Solves for roots and stores the solutions in global variables.
// If real roots exists returns a 1 (true) if no real roots exist 
// 0 (false) is returned.
bool equSolver(double, double, double);

// Calculates and returns the discriminant.
double disc(double, double, double);

// Prints the results to stdout.  Output is determined by the boolean
// returned by equSolver, either real roots exist or they don't.
void outResults(double, double, double, bool);


int main(int argc, char* argv[]) {
	// local variables
	double a, b, c;	// coefficients
	bool flag; // boolean - 1 (true): real roots exist
	double root1, root2;
	int number = atoi(argv[1]);
	ofstream outStream;
	outStream.open("results.dat");
	
	for (int i=0; i < number; i++){
		
	
		// Operator enters values for the coefficients.
		readCoeffs(a, b, c);
		
		// Solve for the roots and determine if there are real roots.
		flag = equSolver(a, b, c);
		
		// Print results to stdout.
		outResults(a, b, c, flag);
	}
	return 0;
}

// Operator inputs a double for use as a coefficient.
void readCoeffs(double& a, double& b, double& c){
	while (true){
		cout << "Enter coefficient a: "; 
		cin >> a;
		if (a) break;
		else
			cout << "Invalid entry. Please enter a non-zero value for a.";
	}
	cout << "Enter coefficient b: "; 
	cin >> b;
	cout << "Enter coefficient c: "; 
	cin >> c;	
		/*http://en.cppreference.com/w/cpp/io/basic_ios/exceptions
		http://en.cppreference.com/w/cpp/string/basic_string/stol*/
	return; 
}

// Computes and returns the discriminant.
double discr(double a, double b, double c){
	return (b*b-4*a*c);
}

// Gets the discriminant and if it's greater than or equal to 0 
//	and a does not equal 0, computes the roots and returns true	  
bool equSolver(double a, double b, double c){
	double compDisc = discr(a, b, c);
	
	if (compDisc >= 0 && a){
		root1 = (-b + sqrt(compDisc))/(2*a);
		root2 = (-b - sqrt(compDisc))/(2*a);
	}
	
	return (compDisc >= 0 && a!=0)?true:false; // If roots exists true is returned, else false.
}

void outResults(double a, double b, double c,bool ind){
	string outString = "";
	
	if (ind){  // If the discriminant was greater than -1 prints the root values.
		cout << "Quadratic equation with the following coefficients:" << endl;
		cout << "a: " << a << "; b: " << b << "; c: " << c << endl;
		cout << "has the following roots" << endl;
		cout << "Root1: " << root1 << "; Root2: " << root2 << ";" << endl << endl;
	} else { // If the discriminant was -1 or less prints that no real roots exist.
		cout << "Quadratic equation with the following coefficients:" << endl;
		cout << "a: " << a << "; b: " << b << "; c: " << c << endl;
		cout << "has no roots in the real domain." << endl << endl;
	}
	return;
}
