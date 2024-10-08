#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "RandGen.h"
/*
This program reads a list of student names from an input file.
Assigns unique and random IDs to each name and creates studentID objects by using name-ID pairs.
Inserts studentID objects into a vector.
Sort the vector by ID of each studentID in ascending order using selection sort algorithm.
Then prints the whole vector.

  */
using namespace std;

struct studentID
{

	string name;
	unsigned int ID;

};


void Swap (studentID & s1, studentID & s2)
{
	studentID temp;
	temp = s1;
	s1 = s2;
	s2 = temp;
}

void SelectSort(vector<studentID> & a, int size)
{
    int j,k,min;
    
    for(j=0 ; j< size-1; j++)
    {	
		min = j;
		
        for(k=j+1; k<size; k++)
        {
            if (a[k].ID < a[min].ID) 
            {
                min = k;
			}			
        }
		
        Swap(a[min],a[j]);
    }    

}

//return true if ID is unique, return false if it already exists in the vector
bool uniqueID(vector<studentID> list, int id)
{
	for (int i=0; i<list.size(); i++)
	{
		if(list[i].ID == id)
			return false;
	}
	
	return true;

}

//creates a new studentID struct and inserts this struct to the list. 
//vector list is passed by reference because it will be modified
void insertID(vector<studentID> & list, int id, string name)
{
	studentID stu;
	stu.ID = id;
	stu.name = name;
	list.push_back(stu);
}

void printList(vector<studentID> list)
{	
	cout << endl << "ID" << "\t" << "NAME" << endl;

	for (int i=0; i<list.size(); i++)
		cout << list[i].ID << "\t" << list[i].name << endl; 
	
	cout << endl;

}

int main()
{

	ifstream inf;
	string fname, line;
	RandGen rnd;

	vector<studentID> list;

	cout << "Enter filename: ";
	cin >> fname;
	inf.open(fname.c_str());

	if (inf.fail())
	{
		cout << "cannot open " << fname << endl;
		return 0;
	}
	

	while(getline(inf, line))
	{
		int id;

		do
		{
			id = rnd.RandInt(10,99);

		}while (!uniqueID(list, id));
	
		insertID(list, id, line);
	}

	//printList(list);

	SelectSort(list, list.size());

	printList(list);

	return 0;
}
