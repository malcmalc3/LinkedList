//Lab3.cpp
//Programmer: Malcolm Milton
//Date: 3/3/15

#include <iostream>
#include "LinkedList.h"
using namespace std;

int menu(); //Function to that displays the options the user will have to choose fromi

int main()
{
        int choice = 0; //Variable for user's choice and controling while loop
	int number; //Variable that will save an ID number from the user input
	
        LinkedList list; //Constructs a new instance of the LinkedList class

        cout << endl << "Welcome to the student database" << endl << endl;

        while(choice == 0) //Loop runs through if the variable choice is zero
        {
                choice = menu(); //Calls function to display options for the user and saves the responce in the variable choice

                if(choice == 1)
                        list.insertNode(); //Calls the function to insert a new node into the list
                else if(choice == 2)
                {
                        cout << "Enter the ID number of the student's information to remove: ";
                        cin >> number; //This will be the number of the student's id to remove
                        list.deleteNode(number); //Calls the List function to delete a node from the list
                }
                else if(choice == 3)
                        list.printList(); //Function that prints the contents of the list
                else if(choice == 4)
                	list.searchNode();
                else if(choice == 5) //Executes if user chose to quit program from the menu
                        cout << "Thank you for using this program" << endl << endl;

                if(choice != 5) //Sets choice back to zero to run the while loop again if the user did not select quit
                        choice = 0;
        }
        return 0;
}  

int menu()
{   
        int choice; //Variable to get input from the user on what option to execute
    
        cout << "Choose an option:" << endl;
        cout << "1. Insert a Node" << endl;
        cout << "2. Delete a Node" << endl;
        cout << "3. Print List" << endl;
        cout << "4. Search for a Node" << endl;
        cout << "5. Quit the Program" << endl;
        cout << "Choice: ";

        cin >> choice; //This will be the number that will be used in the main function to determine what to execute

        cout << endl;

        while(choice < 1 || choice > 5) //Executes to make sure the user chooses an option between 1 and 5, if they didn't at first
        {
                cout << "Please choose a valid option: " << endl;
                cin >> choice;
                cout << endl;
        }

        return choice;
}
