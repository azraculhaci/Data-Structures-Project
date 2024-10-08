#include <iostream>
using namespace std;

int RecFactorial(int num)
// precondition: 0 <= num
// postcondition: returns num! (num factorial)
//recursive
{
    if (0 == num)
    {   
        return 1;
    }
    else
    {   
        return num * RecFactorial(num-1);
    }
}

int Factorial(int num)
// precondition: 0 <= num
// postcondition: returns num! (num factorial)    
//iterative 
{
    int product = 1;
    int count;
    for(count=1; count <= num; count++)
    {   
        product *= count;
    }
    return product;
}