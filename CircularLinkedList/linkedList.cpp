/*************************************
*to include the addToEnd() and 
*clearList() member f-ions
*************************************/

#include <iostream>
#include "linkedList.h"

using namespace std;

linkedlist::linkedlist()
{
	head=NULL;
}

void linkedlist::printList()
{
    if (head != NULL)
    {
        cout << head->data << endl;
        node * ptr = head->next;
        while(ptr != head)
        {
            cout << ptr->data << endl;
            ptr = ptr->next;
        }
    }
    else
    {
        cout << "List is empty" << endl;
    }
}

void linkedlist::addToBeginning(string n)
{
	if(head == NULL)
	{
		node *ptr = new node(n, head);
		head = ptr;
		head->next = head;
	}
	else
	{
		node *oldhead = head;
		node *ptr = new node(n, head);
		head = ptr;
		node* itr= oldhead;
		while(itr->next != oldhead)
		{
			itr = itr->next;
		}
		itr->next = head;
	}
}

void linkedlist::addToEnd(string n)
{
	if(head == NULL)
	{
		node *ptr = new node(n, head);
		head = ptr;
		head->next = head;
	}
	else
	{
		node * ptr = new node(n, head);
		node* tmpHead = head;
		while(tmpHead->next != head)
		{
			tmpHead = tmpHead->next;
		}
		tmpHead->next = ptr;
	}
}

/*****************
Delete Function could be implemented here.
******************/
void  linkedlist::clearList()
{
	if(head == NULL)
		return;
	if(head->next == head)
	{
		delete head;
		return;
	}
	else
	{
		node * oldHead = head;
		head = head->next;
		node * ptr = head;		
		while (head!=oldHead)
		{
			head = head->next;
			//cout<<"Deleting "<<ptr->data<<endl;
			delete ptr;
			ptr = head;
		}
		//cout<<"Deleting the head which is: "<<head->data<<endl;
		delete head;
		head = NULL;
	}	
}

void linkedlist::printListInverse()
{
    if (head != NULL)
        printListInverse(head);
    else
        cout << "List is empty" << endl;
}


void linkedlist::printListInverse(node *n)
{
	if(n->next != head)
	{
		printListInverse(n->next);
	}
	cout << n->data << endl;
}