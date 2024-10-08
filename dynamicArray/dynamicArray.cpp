/* 1. Besides dynamically allocated built-in arrays, it's shown how the same
   problem can be solved using dynamic vectors which are not dynamically allocated.
   For the dynamic vectors we don't need to go through the file twice (once for
   getting the number of lines and once for filling up the array), rather the
   push_back() memeber f-ion is used to do it with only one pass.
2. Counting the totalNumOfCharacters is shown in 4 different ways which are
   equivalent to each other
********Dynamic Array******/
/*This program will read a file and then create a dynamic array with the lines of the text file.
It just calculates the average number of characters in the text file.*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
int main()
{
	ifstream file;
	string filename = "dynamicArrayContent.txt";
	//If the filename is taken as a parameter c_str usage is a must.
	file.open(filename.c_str());
	string line = "";

	vector<string> myStringVec;

	int countOfLines = 0;
	//Read the file in order to obtain the number of lines
	while(getline(file,line))
	{
		countOfLines++;
		myStringVec.push_back(line);
	}
	//The size of a built-in array cannot be variable
	
	//Creating a dynamic array
	string* myList = new string[countOfLines];

	//To read the file from the beginning
	file.clear();
	file.seekg(0, ios::beg);
	
	int index = 0;
	//Read the file again in order to store the lines of the text file by using array indices
	while(getline(file,line))
	{
		 myList[index] = line;
		 index++;
	}

	//Calculate the average number of characters of the strings in the list
	double totalNumOfCharacters = 0;
	for(int i=0; i<countOfLines; i++) //for(int i=0; i<myStringVec.size(); i++) 
	{
		totalNumOfCharacters+=myStringVec[i].length();
		//totalNumOfCharacters+=(myList[i]).length();
		//totalNumOfCharacters += (*(myList + i)).length();
		//totalNumOfCharacters += (myList + i)->length();	//	alternative way of doing the same thing
	}

	double averageOfNumCharacters = totalNumOfCharacters / countOfLines;
	//double averageOfNumCharacters = totalNumOfCharacters / myStringVec.size();
	cout << "The average number of characters in the file: " << averageOfNumCharacters << endl;

	delete[] myList;
	//In order to see it on the console
	cin.get();
	cin.ignore();
	return 0;
}