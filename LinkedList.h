//LinkedList.h
//Declaration of the class "LinkedList"
//Programmer: Malcolm Milton
//Date: 3/3/15

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"

class LinkedList
{
	private:
		Node *list; //Pointer to the first node in the list
		Node *createNode(); //Private utitlity function to create a new node
		Node *searchLocation(int); //Private utility function to search for the location of a node
	public:
		LinkedList(); //Constructor for the class
		~LinkedList(); //Destructor for the class, deletes all nodes in the list
		void insertNode(); //Inserts a new node into the correct position in the list
		void deleteNode(int); //Finds the node that the student wants to delete  and rearanges the list
		void printList(); //Prints the contents of all nodes in the list
		void searchNode(); //Prints the contents of the node the user is searching for
};

#endif
