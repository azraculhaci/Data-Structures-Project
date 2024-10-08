#include <iostream>
#include <vector>
using namespace std;


// Illustrates "bad" recursion for computing Fibonacci numbers
// also illustrates how to fix this efficiency problem

//Recursive 
int RecFib(int n)
// precondition: 0 <= n
// postcondition: returns the n-th Fibonacci number
{
    if (0 == n || 1 == n)
    {   
        return 1; //bence burası return n; olmalı
    }
    else
    {   
        return RecFib(n-1) + RecFib(n-2);
    }
}

//Recursive but the efficiency problem due to multiple calls is now fixed
int RecFibFixed(int n)
{
	static int count = 0;
    static vector<int> storage(31,0);

	count++;

    if (0 == n || 1 == n)
    {   
        return 1; //bence burası reutrn n; olmalı
    }
    else if (storage[n] == 0)
    {   
        storage[n] = RecFibFixed(n-1) + RecFibFixed(n-2);
        return storage[n];
    }
    else
    {   
        return storage[n];
    }
}

//iterative
int Fib(int n)
{
    int first=1, second=1, temp;
    int k;
    for (k=0; k < n; k++)
    {   
        temp = first;
        first = second;
        second = temp + second;
    }
    return first;
}
