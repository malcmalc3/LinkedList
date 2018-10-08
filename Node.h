//Node.h
//Declaration of Node class
//Programmer: Malcolm Milton
//Date: 3/3/15

#ifndef NODE_H
#define NODE_H

class Node
{
	private:
		char firstName[20]; //Student's last name
		char lastName[20]; //Student's first name
		int idNumber; //Student's ID number
		Node *next; //Pointer to the next node in the list
	public:
		Node(); //Constructor
		void printNode(); //Function to print contents of node
		friend class LinkedList; //Declares the class LinkedList as a friend class, so it can use the member fuctions of this class
};

#endif
