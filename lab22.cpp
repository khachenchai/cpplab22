#include<iostream>
#include<cmath>
using namespace std;

class ComplexNumber{				
	public:
		double real;
		double imag;
		ComplexNumber(double,double);
		ComplexNumber operator+(const ComplexNumber &);
		ComplexNumber operator-(const ComplexNumber &);
		ComplexNumber operator*(const ComplexNumber &);
		ComplexNumber operator/(const ComplexNumber &);
		bool operator==(const ComplexNumber &);
		ComplexNumber operator+(double);
		ComplexNumber operator-(double);
		ComplexNumber operator*(double);
		ComplexNumber operator/(double);
		bool operator==(double);
		double abs();
		double angle();
};

ComplexNumber::ComplexNumber(double x = 0,double y = 0){
	real = x; imag = y;
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber &c){
	return ComplexNumber(real+c.real,imag+c.imag);
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber &c){
	return ComplexNumber(real-c.real,imag-c.imag);
}

//Write your code here
ComplexNumber ComplexNumber::operator*(const ComplexNumber &c) {
	double realRes = (real*c.real) - (imag*c.imag);
	double imgRes = (real*c.imag) + (imag*c.real);
	return ComplexNumber(realRes, imgRes);
}

ComplexNumber ComplexNumber::operator/(const ComplexNumber &c){
    double x = c.real*c.real + c.imag*c.imag;

    double realRes = (real*c.real + imag*c.imag) / x;
    double imgRes  = (imag*c.real - real*c.imag) / x;

    return ComplexNumber(realRes, imgRes);
}

bool ComplexNumber::operator==(const ComplexNumber &c) {
	return real==c.real && imag==c.imag;
}

ComplexNumber ComplexNumber::operator+(double val){
    return ComplexNumber(real + val, imag);
}

ComplexNumber ComplexNumber::operator-(double val){
    return ComplexNumber(real - val, imag);
}

ComplexNumber ComplexNumber::operator*(double val){
    return ComplexNumber(real * val, imag * val);
}

ComplexNumber ComplexNumber::operator/(double val){
    return ComplexNumber(real / val, imag / val);
}

bool ComplexNumber::operator==(double val){
    return (real == val && imag == 0);
}

ComplexNumber operator+(double val, const ComplexNumber& c) {
    return ComplexNumber(val + c.real, c.imag);
}

ComplexNumber operator-(double val, const ComplexNumber& c) {
    return ComplexNumber(val - c.real, -c.imag);
}

ComplexNumber operator*(double val, const ComplexNumber& c) {
    return ComplexNumber(val * c.real, val * c.imag);
}

ComplexNumber operator/(double val, const ComplexNumber& c) {
    return ComplexNumber(val, 0) / c; 
}

bool operator==(double val, const ComplexNumber& c) {
    return (val == c.real && c.imag == 0);
}


double ComplexNumber::abs() {
	return (double)sqrt(pow(real, 2) + pow(imag, 2));
}

double ComplexNumber::angle() {
	double ang = atan2(imag, real);
	return (double)((ang * 180)/M_PI);
}


ostream & operator<<(ostream &os, const ComplexNumber &c) {
	if (c.real != 0 && c.imag != 0) os << c.real << (c.imag > 0 ? "+" : "") << c.imag << 'i';
	else if (c.real == 0 && c.imag != 0) os << c.imag << 'i';
	else if (c.real != 0 && c.imag == 0) os << c.real;
	else os << 0;

	return os;
}

int main(){
	ComplexNumber a(1.5,2),b(3.2,-2.5),c(-1,1.2);	
	cout << a << "\n";
	cout << b << "\n";
	cout << c << "\n";
	cout << a+2.5 << "\n";
	cout << 2.5+a << "\n";
	cout << a-1.5 << "\n";
	cout << 1.5-a << "\n";
	cout << b+ComplexNumber(0,2.5) << "\n";
	cout << c-c << "\n";
	cout << "-----------------------------------\n";
	
	ComplexNumber d = (a+b)/c;
	ComplexNumber e = b/(a-c);
	cout << d << "\n";
	cout << e << "\n";
	cout << c*2 << "\n";
	cout << 0.5*c << "\n";
	cout << 1/c << "\n";
	cout << "-----------------------------------\n";
	
	cout << ComplexNumber(1,1).abs() << "\n";
	cout << ComplexNumber(-1,1).abs() << "\n";
	cout << ComplexNumber(1.5,2.4).abs() << "\n";
	cout << ComplexNumber(3,4).abs() << "\n";
	cout << ComplexNumber(69,-9).abs() << "\n";		
	cout << "-----------------------------------\n";	
	
	cout << ComplexNumber(1,1).angle() << "\n";
	cout << ComplexNumber(-1,1).angle() << "\n";
	cout << ComplexNumber(-1,-1).angle() << "\n";
	cout << ComplexNumber(1,-1).angle() << "\n";
	cout << ComplexNumber(5,2).angle() << "\n";
	cout << "-----------------------------------\n";
	
	cout << (ComplexNumber(1,1) == ComplexNumber(1,2)) << "\n";
	cout << (ComplexNumber(1,1) == 1) << "\n";
	cout << (0 == ComplexNumber()) << "\n";
}





