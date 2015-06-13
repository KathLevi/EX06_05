////////////////////////
//Name: Kathleen Levi
//
//Project: EX06_05 (14.7)
//
//Date: 12 June, 2015
////////////////////////

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cmath>
using namespace std;

class Complex{
private:
    double a;
    double b;
public:
    Complex(){
        a = 0;
        b = 0;
    }
    Complex(double a){
        this->a = a;
        b = 0;
    }
    Complex(double a, double b){
        this->a = a;
        this->b = b;
    }
    Complex add(Complex& secondComplex) const {
        double first = a + secondComplex.getRealPart();
        double second = b + secondComplex.getImaginaryPart();
        return Complex(first, second);
    }
    Complex subtract(Complex& secondComplex) const{
        double first = a - secondComplex.getRealPart();
        double second = b - secondComplex.getImaginaryPart();
        return Complex(first, second);
    }
    Complex multiply(Complex& secondComplex) const{
        double first = a * secondComplex.getRealPart() - b * secondComplex.getImaginaryPart();
        double second = b * secondComplex.getRealPart() + a * secondComplex.getImaginaryPart();
        return Complex(first, second);
    }
    Complex divide(Complex& secondComplex) const{
        double first = (a * secondComplex.getRealPart() + b * secondComplex.getImaginaryPart()) / (secondComplex.getRealPart() * secondComplex.getRealPart() + secondComplex.getImaginaryPart() *secondComplex.getImaginaryPart());
        double second = (b * secondComplex.getRealPart() - a * secondComplex.getImaginaryPart()) / (secondComplex.getRealPart() * secondComplex.getRealPart() + secondComplex.getImaginaryPart() *secondComplex.getImaginaryPart());
        return Complex(first, second);
    }
    double abs() const{
        double inside = a * a + b * b;
        double abs = sqrt(inside);
        return abs;
    }
    Complex operator+(Complex& secondComplex) const{
        return add(secondComplex);
    }
    Complex operator-(Complex& secondComplex) const{
        return subtract(secondComplex);
    }
    Complex operator*(Complex& secondComplex) const{
        return multiply(secondComplex);
    }
    Complex operator/(Complex& secondComplex) const{
        return divide(secondComplex);
    }
    string toString(){
        stringstream ss;
        ss << a << " + " << b <<"i";
        return ss.str();
    }
    double getRealPart(){
        return a;
    }
    double getImaginaryPart(){
        return b;
    }
    double operator[](int index){
        if (index == 0)
            return a;
        else
            return b;
    }
    Complex& operator+=(Complex& secondComplex){
        *this = add(secondComplex);
        return *this;
    }
    Complex& operator-=(Complex& secondComplex){
        *this = subtract(secondComplex);
        return *this;
    }
    Complex& operator*=(Complex& secondComplex){
        *this = multiply(secondComplex);
        return *this;
    }
    Complex& operator/=(Complex& secondComplex){
        *this = divide(secondComplex);
        return *this;
    }
    Complex& operator++(){
        a+=b;
        return *this;
    }
    Complex& operator--(){
        a-=b;
        return *this;
    }
    Complex operator++(int dummy){
        Complex temp(a,b);
        a += b;
        return temp;
    }
    Complex operator--(int dummy){
        Complex temp(a,b);
        a-=b;
        return temp;
    }
    Complex operator+(){
        return *this;
    }
    Complex operator-(){
        return Complex(-a,b);
    }
    friend ostream& operator<<(ostream& out, Complex& complex){
        out << "(" << complex.a << " + " << complex.b << "i)";
        return out;
        
    }
    friend istream& operator>>(istream& in, Complex& complex) {
        cout << "Enter a ";
        in >> complex.a;
        cout << "Enter b ";
        in >> complex.b;
        return in;
    }
    
};

int main(){
    double a, b, c, d;
    
    cout << "Enter the first complex number: ";
    cin >> a;
    cin >> b;
    cout << "Enter the second complex number: ";
    cin >> c;
    cin >> d;
    Complex c1(a,b);
    Complex c2(c,d);
    
    
    cout << c1 << "+" << c2 << "=" << (c1 + c2).toString() << endl;
    cout << c1 << "-" << c2 << "=" << (c1 - c2).toString() << endl;
    cout << c1 << "*" << c2 << "=" << (c1 * c2).toString() << endl;
    cout << c1 << "/" << c2 << "=" << (c1 / c2).toString() << endl;
    cout << "|" << c1[0] << "+" << c1[1] << "i|" << "=" << c1.abs() << endl;
 
    
    
    
    
}