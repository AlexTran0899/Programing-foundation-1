// Include statements 
#include <iostream> 
using namespace std;

// Main function
int main()
{
// Print message

cout << "Hello, world!\n"; 
int number;
cin >> number#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

void print_quadratic(double a,double b,double c)
{
   cout << "Quadratic equation: ";
   cout << a << "x^2" << " + " << b << "x" << " + " << c << endl;
}

void print_roots(double a,double b,double c)
{
   double discriminant = b * b - 4 * a * c;
   double root1 = (- b - sqrt(discriminant)) / (2 * a);
   double root2 = (- b + sqrt(discriminant)) / (2 * a);
   if (discriminant < 0)
      cout << "There are no roots to this quadratic equation\n";
   else if (discriminant == 0)
      cout << "There is one root: " << root1 << endl;
   else
      cout << "There are two roots: " << root1 << " and " << root2 << endl;
}

void get_coefficients(double& a,double& b,double& c){
  while (a == 0)
   {
      cout << "Enter quadratic coefficients a b c:\n";
      cin >> a >> b >> c;
      if (a == 0)
         cout << "Ooops, when a=0 you have a linear equation\n";
   }
}

int main()
{
   double a = 0, b = 0, c = 0;
   // Get coefficients of quadratic equation
   get_coefficients(a,b,c);

   // Print quadratic equation
   print_quadratic(a,b,c);

   // Print roots of quadratic equation
   print_roots(a,b,c);

  print_quadratic(-a,-b,-c);
   print_roots(-a,-b,-c);

   return 0;
}
;
cout << number << endl;
return 0 ;
}

