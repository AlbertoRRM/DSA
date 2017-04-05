#ifndef _COMPLEX_
#define _COMPLEX_

template <class T>

class Complex {
private:
	float _real;
	float _imaginary;
public:
	
	Complex();// Default Constructor
	Complex(const Complex&);// Copy constructor
	~Complex();// Destructor
	Complex operator=(const Complex&);// Copy operator

	// Destructor
	void destroy();

	// Observers
	T real() const; // Returns the real part of the complex number
	T imaginary() const; // Returns the imaginary part of the complex number
	bool operator==(const Complex&); // Compares the values of two complex numbers

	// Arithmetic operations
	// These operations DO modify the complex on which they are invoked
	void add();
	void substract();
	void multiplication();

	// These operations DO NOT modify the complex on which they are invoked
	Complex operator+(const Complex&) const;
	Complex operator-(Const Complex&) const;
	Complex operator*(Const Complex&) const;
};
#endif;