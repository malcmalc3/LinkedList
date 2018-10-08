//LinkedList.cpp
//Member functions of the class "LinkedList"
//Programmer: Malcolm Milton
//Date: 3/3/15

#include <iostream>
#include "LinkedList.h"
#include "Node.h"
using namespace std;

LinkedList::LinkedList() //Class constructor
{
	list = NULL; //Initializes the list to be empty
}

LinkedList::~LinkedList() //Destructor for the LinkedList class
{
	Node *tempNode1; //Pointer to a node in the list

	while(list != NULL) //Only loops if there is something in the list
	{
		tempNode1 = list; //Points to the first node in the list
		list = tempNode1->next; //Makes the second node into the first node in the list 
		delete tempNode1; //Deletes the node that used to be the first node in the list
	}
}

Node* LinkedList::createNode() //Function that creates a new Node
{
	Node *newNode = new Node(); //Creates a new instance of the Node class
	return newNode; //Returns the pointer to the new node
}

void LinkedList::insertNode() //Function to insert the new node into the list
{
	Node *newNode = createNode(); //Calls the function to create a new node, then points it
	
	if(list == NULL) //Executes if list is empty
        {
                list = newNode; //Makes the list pointer point to the new node, now the first node in the list
                cout << "Student added to list" << endl << endl;
        }
	else if(newNode->idNumber <= list->idNumber) //Executes if the new node should be added before the first node in the list
	{
		if(newNode->idNumber == list->idNumber) //Executes if the new node's ID number is already in the list
                        cout << "This ID number is already in use" << endl << endl;
                else
                {
			newNode->next = list; //Points the new node to the new second node in the list
                        list = newNode; //Makes the new node the first node
                        cout << "Student added to list" << endl << endl;
                }
	}
	else
	{
		Node *tempNode = searchLocation(newNode->idNumber); //Points to the node before the correct location to put the new node in the list
		
		if(tempNode->next == NULL)
                {
                        tempNode->next = newNode; //Makes the new node the last node in the list
                        cout << "Student added to list" << endl << endl;
                }
		else if(newNode->idNumber == tempNode->next->idNumber) //Executes if the new node's ID number is already in the list
                        cout << "This ID number is already in use" << endl << endl;
		else
		{
			newNode->next = tempNode->next; //Points the new node to the node that is supposed to be next in the list
			tempNode->next = newNode; //Points the node before to the new node
			cout << "Student added to the list" << endl << endl;
		}
	}
}

Node* LinkedList::searchLocation(int x) //Function to search for the location of a the node before the node the user is looking for
{
	Node *tempNode; //Pointer to be used to point to the node before

	if(list == NULL) //Executes if the list is empty
		cout << "The list is empty" << endl << endl;
	else
	{
		tempNode = list; //Points to the first node in the list
		while(tempNode->next != NULL && tempNode->next->idNumber < x) //Loop stops when the end of the list is next, or the node after is found after the node
			tempNode = tempNode->next; //Points to the next node in the list
	}

	return tempNode; //Returns a pointer to the node before the node the user is looking for
}

void LinkedList::deleteNode(int x) //Function to remove a node from the list
{
	if(list != NULL) //Executes if the list is not empty
	{
		if(list->idNumber == x) //Executes if the node to delete is the first node
		{
			//cout << x << endl;
			Node *tempNode1 = list;
			list = tempNode1->next; //Makes the next node the first node
			delete tempNode1; //Deletes the appropriate node
			cout << "Student removed from list" << endl << endl;
		}
		else
		{
			//cout << x+1 << endl;
			Node *tempNode1 = searchLocation(x); //Calls the function to search for the node before the node the user wants to delete and points to it
			if(tempNode1->next != NULL && tempNode1->next->idNumber == x) //Executes if the student actually exists in the list
			{
				//cout << x+2 << endl;
			 	Node *tempNode2 = tempNode1->next; //Points to the node to actually be deleted
				tempNode1->next = tempNode2->next; //Makes the node before point to the node after the node to delete
				delete tempNode2; //Deletes the appropriate node
				cout << "Student removed from list" << endl << endl;
			}
			else
				cout << "This student does not exist" << endl << endl;
		}
	}
	else
		cout << "The list is empty" << endl << endl;
}

void LinkedList::printList() //Function to print all of the nodes in the list
{	
	if(list == NULL) //Executes if the list is empty
		cout << "The list is empty" << endl << endl;
	else
	{
		Node *tempNode = list; //Points to the first node in the list

		cout << "Here is the list:" << endl;
		while(tempNode != NULL) //Loop stops when the end of the list is reached
		{
			tempNode->printNode(); //Prints the contents of the node being pointed to
			tempNode = tempNode->next; //Points to the next node
		}
		cout << endl;
	}
}

void LinkedList::searchNode() //Function to search for a node and print out its information
{
	int x; //Variable for user input of what ID number to search for

	cout << "Please enter the ID number of the student to search for: ";
	cin >> x; //Receives the user's choice
	
	if(list != NULL)
	{		
		if(list->idNumber == x) //Executes if the first student is the student the user is looking for
		{
			list->printNode(); //Prints the information of the student
			cout << endl;
		}
		else
		{
			Node *tempNode = searchLocation(x); //Seaches for the location of the node
		
			if(tempNode->next != NULL && tempNode->next->idNumber == x) //Executes if the student actually exists in the list
			{
				tempNode->next->printNode(); //Prints the information of the student
				cout << endl;
			}
			else
				cout << "This student does not exist" <<endl <<endl;
		}
	}
	else
		cout << "The list is empty" << endl << endl;
}
