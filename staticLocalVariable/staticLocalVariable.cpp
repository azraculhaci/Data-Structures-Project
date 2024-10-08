#include <iostream>
#include <string>

using namespace std;

//This function preserves the value of staticLocalString 
void magicalFunction()
{
	static string staticLocalString= "First value assigned. ";
	cout << staticLocalString << endl;
	staticLocalString +="Updated in function. ";	
	cout << staticLocalString << endl;
}

int main()
{
	/*Call magicalFunction (at least) twice for static local variable example */
	cout << "First call." << endl;
	magicalFunction();
	cout << "Second call." << endl;
	magicalFunction();
	//cout << "Third call." << endl;
	//magicalFunction();
	system("pause");
	return 0;
}