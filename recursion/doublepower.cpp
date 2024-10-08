#include <iostream>
#include <string>
using namespace std;

/*
double Power(double x, int n)
// post: returns x^n
{
    if (n == 0)
    {
	     return 1.0;
    }
	double result = Power(x, n-1);
    return x * result;
}
*/
double Power(double x, int n)
// post: returns x^n
{
    if (n == 0)
    {
	     return 1.0;
    }
	double result;
	if (n % 2 == 0)
	{
		double m = Power(x, n/2);
		result =  m * m;
	}
	else
	{
		double m = Power(x, n/2);
		result =  x * m * m;
	}
    return result;
}

int main()
{
	double a,b;
	cin >> a >> b;
	double result = Power(a, b);
	cout << result << endl;

	return 0;
}

//Özellikle büyük sayıların üslerini bulmak için kullanışlıdır, çünkü recursive olarak işlem yaparak hesaplama süresini azaltır.
