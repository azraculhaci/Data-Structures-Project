/*************************************
*to include the addToEnd() and 
*clearList() member f-ions
*************************************/

#include <iostream>
#include <string>
#include "linkedList.h"

int main()
{	
	linkedlist list;
	string word = "";
	cout << "Please enter a word!" << endl;
	//Ctrl-Z in order to exit from the loop
	while(cin >> word)
	{
		
		list.addToEnd(word);
		//list.addToBeginning(word);
		cout << "Please enter a word!" << endl;
	}

	list.printList();
	cout << endl;
	list.printListInverse();

	list.clearList();
	cout<<endl;
	list.printList();

	system("pause");
	return 0;
}

