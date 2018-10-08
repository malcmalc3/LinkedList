//Node.cpp
//Member functions of the class "Node"
//Programmer: Malcolm Milton
//Date: 3/3/15

#include <iostream>
#include "Node.h"
using namespace std;

Node::Node() //Constructor of Node class
{
	cout << "Please enter first name: ";
	cin >> firstName; //Saves user's input into the node's firstName
	cout << "Please enter last name: ";
	cin >> lastName; //Saves user's input into the node's lastName
	cout << "Please enter student ID Number: ";
	cin >> idNumber; //Saves user's input into the node's idNumber
}

void Node::printNode() //Function to print the contents of the node
{
	cout << "Student #" << idNumber << ": " << firstName << " " << lastName << endl;
}
