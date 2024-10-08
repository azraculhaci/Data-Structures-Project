/***************************************************
Program to demonstrate the use of pointers for dynamic memory 
allocation, it will create a linked list with nodes and the 
ids of nodes will be set from 0 to 9 through a loop. Then if 
the debug mode is set; linked list will be displayed. This 
part will only be executed if the debug mode is set. Yet, irrespective 
of the solution configuration mode (debug or release mode) the ids 
of the elements of linked list will be doubled and printed in a reverse order (recursive function)

  1.Added the function PrintList() which prints the list in order.
  2.PrintList() is called before and after changing the list so to see the
    effect (e.g. at the beggining when the list was created,
    before and after adding an element after the 6th node, etc.)
  3.After calling ClearList() the dynamically allocated nodes
    are deleted, but myList pointer from main still doesn't point 
    to NULL. We solve it by using a pointer reference while calling the f-ion.
	Alternatively it can be solved by setting myList to NULL after calling 
    ClearList() in main()  
****************************************************/
#include <iostream>
using namespace std;

struct node
{
	int id;
	node * next;

	//default constructor
	node::node ()
		:id(0), next(NULL)
	{}

	//constructor
	node::node (int i,node *n)
		:id(i), next(n)
	{}	
};

//This function multiplies the each element of the list by 2 
void Double(node *head)
{
	while (head != NULL)
	{
		head->id = (head->id) * 2;
		head = head->next;
	}
}

//Print the linked list in order
void PrintList(node * nodePtr)
{
	while ( nodePtr != NULL)
	{
		cout << nodePtr->id << endl;
		nodePtr = nodePtr->next;
	}
}

//Prints the list in a reverse order
void ReversePrint(node *nodePtr)
{
	if (nodePtr != NULL)
	{
		ReversePrint(nodePtr->next);
		cout << nodePtr->id << endl;
	}
}

//Deletes all of the elements in the list
void ClearList(node * &head)
{
	node *ptr;
	while(head!=NULL)
	{
		ptr=head;
		head=head->next;
		delete ptr;
	}
}

//Searches the list for a value and returns true or false
bool SearchList(node *head, int searchValue)
{
	while (head != NULL)
	{
		if(head->id == searchValue) //If the node with the given ID is found
			return true;			
		head = head->next;
	}
	//If the code proceeds from here, it means that the whole list is traversed 
	//and a node with ID == searchValue could not be found. 
	return false;
}

/*Returns the nth node in the list. If the total number of nodes 
in the list is smaller than n, it returns null */
node * GetNthNode(node *head, int n)
{
	int counter=0;
	node *ptr = head;
	while (ptr != NULL && counter<n-1)
	{ 
		ptr = ptr->next;
		counter++;
	}
	return ptr;
}

int main ()
{
	node *myList;			//my linklist
	myList = new node;		//first node has id 0 and its next points to NULL
	int searchValue;
	bool isFound;
	node *temp;

	//complete to a linklist such that the finished list has:
	//elements: 0->1->...->9->NULL
	node *p=myList;
	for (int i=1; i < 10; i++)
	{
		//get a new node, fill it with current id and 
		//point to it from what p points to
		(*p).next=new node(i,NULL);		//(*p).next is the same as p->next
		//advance p by one node - to point to the final node
		p=(*p).next;	//(*p).next is the same as p->next
	}

	cout<<"Printing the newly created list"<<endl;
	PrintList(myList);


//If the program is running in the debug mode, this if block will be executed.
//Debug or release mode will be selected from the solution configurations above.
#ifdef _DEBUG
	//initialize p to the beginning of the list
	//Print the list before doubling its elements
	cout << "Program is running in the debug mode..." << endl;
	cout << endl;
	/*cout << "Printing the elements of the list:" << endl;
	p=myList;
	for (int i=0; i < 10; i++)
	{
		cout << p->id << " ";
		p= p->next;
		cout << endl;
	}*/
#endif
	
	/* Ask for a value from the user. After the user enters the value, 
	search for it in the list. If a node with this ID exists in the list, 
	display a message. Otherwise, add a node with the entered ID as the 
	6th node into the linked list. */
	cout << "Please enter a value to add to the list: ";
	cin >> searchValue;
	isFound=SearchList(myList,searchValue);
	if(isFound)
	{		//If a node with this ID already exists
		cout << "A node with value " << searchValue << " already exists in the list." << endl;
	}
	else
	{				//Add a new node as the 6th node in the list
		p=GetNthNode(myList,6);		//Get the current 6th node 
		//If the list has more than 6 nodes, add a new node between p and its next node
		if(p!=NULL)
		{
			p->next=new node(searchValue,p->next);
			cout<<"The list has more than 6 elements.\nAfter adding a new node at the 6th position the list is:" << endl;
			PrintList(myList);
		}
	}
	
	//Double the IDs of nodes in the linked list and display them in reversed order
	cout<<"Doubling the values of the list"<<endl;
	Double(myList);

	cout << "Printing the doubled list in order: " << endl;
	PrintList(myList);

	cout << "Printing the doubled list in a reverse order: " << endl;
	ReversePrint(myList);

	//Remove all the nodes from the linked list
	ClearList(myList);
	//myList = NULL;

	cout << "Printing the list after clearing it (empty list): " << endl;
	PrintList(myList);

	cout<<"End of the program"<<endl;
	cin.get();
	cin.ignore();

	return 0;	
}

