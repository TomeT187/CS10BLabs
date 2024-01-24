#include <iostream>

using namespace std;

// Rational Class declaration
class Rational {
   private:
      int numerator;
      int denominator; 
   public:
      Rational();
      explicit Rational(int numerator); 
      Rational(int numeratorIn, int denominatorIn); 
      Rational add(const Rational &fracIn) const; 
      Rational subtract(const Rational &fracIn) const; 
      Rational multiply(const Rational &fracIn) const; 
      Rational divide(const Rational &fracIn) const;
      void simplify();
      void display() const;
   private:
      int gcd(int num1, int num2) const;
};

// Implement Rational class member functions here

Rational::Rational(){
   numerator = 0;
   denominator = 1;
}
Rational::Rational(int numeratorIn){
   numerator = numeratorIn;
   denominator = 1;
}
Rational::Rational(int numeratorIn, int denominatorIn){
   numerator = numeratorIn;
   denominator = denominatorIn;
}
Rational Rational::add(const Rational &fracIn) const{
   //(a/b) + (c/d) = (ad + bc) / (b*d)
   int newNum = (numerator * fracIn.denominator) + (denominator * fracIn.numerator);
   int newDem = denominator * fracIn.denominator;
   Rational newRational(newNum, newDem);
   return newRational;
}

Rational Rational::subtract(const Rational &fracIn) const{
//(a/b) - (c/d) = (ad - bc) / (b*d)
   int newNum = (numerator * fracIn.denominator) - (denominator * fracIn.numerator);
   int newDem = denominator * fracIn.denominator;
   Rational newRational(newNum, newDem);
   return newRational;
}

Rational Rational::multiply(const Rational &fracIn) const{ 
//(a/b) * (c/d) = (ac) / (bd)
   int newNum = numerator * fracIn.numerator;
   int newDem = denominator * fracIn.denominator;
   Rational newRational(newNum, newDem);
   return newRational;
}
Rational Rational::divide(const Rational &fracIn) const{
//(a/b) / (c/d) = (ad) / (cb)
   int newNum = numerator * fracIn.denominator;
   int newDem = denominator * fracIn.numerator;
   Rational newRational(newNum, newDem);
   return newRational;
}

void Rational::simplify(){
   int GCD = gcd(numerator,denominator);
   numerator = numerator / GCD;
   denominator = denominator / GCD;
}

void Rational::display() const{
   cout << numerator << " / " << denominator;
}


int Rational::gcd(int num1, int num2) const{
   int smallest;
   int gcd = 1;
   if (num1 < num2){
      smallest = num1;
   }else{
      smallest = num2;
   }
   for (int i = 1; i <= smallest; i++){
      if (num1 % i == 0 && num2 % i == 0){
         gcd = i;
      }
   }
   return gcd;
}
// Do not change any of the code below this line!!

Rational getRational();
void displayResult(const string &, const Rational &, const Rational&, const Rational&);

int main() {
   Rational A, B, result;
   char choice;
   
   cout << "Enter Rational A:" << endl;
   A = getRational();
   cout << endl;
   
   cout << "Enter Rational B:" << endl;
   B = getRational();
   cout << endl;
   
   cout << "Enter Operation:" << endl
      << "a - Addition (A + B)" << endl
      << "s - Subtraction (A - B)" << endl
      << "m - Multiplication (A * B)" << endl
      << "d - Division (A / B)" << endl
      << "y - Simplify A" << endl;
   cin >> choice;
   cout << endl;
   
   if (choice == 'a') {
      result = A.add(B);
      displayResult("+", A, B, result);
   } else if (choice == 's') {
      result = A.subtract(B);
      displayResult("-", A, B, result);
   } else if (choice == 'm') {
      result = A.multiply(B);
      displayResult("*", A, B, result);
   } else if (choice == 'd') {
      result = A.divide(B);
      displayResult("/", A, B, result);
   } else if (choice == 'y') {
      A.simplify();
      A.display();
   } else {
      cout << "Unknown Operation";
   }
   cout << endl;
   
   return 0;
}


Rational getRational() {
   int choice;
   int numer, denom;
   
   cout << "Which Rational constructor? (Enter 2, 1, or 0)" << endl
      << "2 - 2 parameters (numerator & denominator)" << endl
      << "1 - 1 parameter (numerator)" << endl
      << "0 - 0 parameters (default)" << endl;
   cin >> choice;
   cout << endl;
   
   if (choice == 2) {
      cout << "numerator? ";
      cin >> numer;
      cout << endl;
      cout << "denominator? ";
      cin >> denom;
      cout << endl;
      return Rational(numer, denom);
   } else if (choice == 1) {
      cout << "numerator? ";
      cin >> numer;
      cout << endl;
      return Rational(numer);
   } else {
      return Rational();
   }
}

void displayResult(const string &op, const Rational &lhs, const Rational&rhs, const Rational &result) {
   cout << "(";
   lhs.display();
   cout << ") " << op << " (";
   rhs.display();
   cout << ") = (";
   result.display();
   cout << ")";
}

