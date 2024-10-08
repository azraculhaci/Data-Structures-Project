#include <cctype>
#include <iostream>
using namespace std;

double Power(double a, int n)
//post: returns a^n
{
    if (n==0)
    return 1.0;
    double semi = Power(a, n/2);
    if(n % 2 == 0)
        return (semi*semi);
    return ( a* semi * semi);
}


int main()
{
    double base;
    int exponent;
    
    cout << "Enter the base: ";
    cin >> base;
    
    cout << "Enter the exponent: ";
    cin >> exponent;
    
    double result = Power(base, exponent);
    
    cout << base << " raised to the power of " << exponent << " is: " << result << endl;
    
    return 0;
}