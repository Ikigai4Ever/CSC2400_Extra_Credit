/************************************
   Team Member One: Ty Ahrens
   Team Member Two: Blake Hudson
           Program: main.cpp 
              Date: 4/29/25
       Description: 
*************************************/

#include <iostream> 
#include <iomanip>
#include <sstream>
#include <string>
using namespace std;

/************* FUNCTION PROTOTYPES *************/
int menu();
int* defineArray(int&);
int recusiveMaxFind(int*, int);

int main(){
    int* myArray;   //dynamically allocate array that is defined by user
    int menuChoice; //Save the value that is given from the menu 
    int elements;   //Number of elements wanted in the array for the example
    int maxValue;   //Max value that has been found in the array of values that user specified

    cout << "Welcome! Please select a menu choice:";


    do {
        menuChoice = menu();    //display menu to the user

        switch (menuChoice){
            case 1: 
                    cout << "\n\n";
                    myArray = defineArray(elements);
                    maxValue = recusiveMaxFind(myArray, elements);
                    break;
            case 2: 
                    cout << "\n\n"
                         << "Here is a full description of the program and its steps:"
                         << "PUT STUFF HERE";
                    break;
            case 3: 
                    cout << "\n\n Have a great rest of your day!\n\n";
                    break;
        } 
    }while (menuChoice != 3);

    
    delete [] myArray;    //free dynamically allocated array
    return 0;
}

/***************** FUNCTIONS *****************/

/*
	FUNCTION: menu()
	 PURPOSE: Display a menu of choices to the user
*/
int menu(){
    int choice;

    cout << "------------------------------------------\n"
         << "   (1)    Begin Start Program\n" 
         << "   (2)    Read Description of Program\n"
         << "   (3)    Exit Program\n"
         << "      Please enter 1, 2, or 3.\n"
         << "------------------------------------------\n"
         << " CHOICE : ";
    cin >> choice; 

    while (choice < 1 || choice > 3){
        cout << "------------------------------------------\n"
             << "    Please enter a valid number\n"
             << "    Please enter 1, 2, or 3.\n"
             << "------------------------------------------\n"
             << " CHOICE : ";
        cin >> choice;
    }

    return choice;
}

/*
	FUNCTION: defineArray
	 PURPOSE: Read comma-separated values from the user, store in a dynamic array
*/
int* defineArray(int& elements){
    string input;
    cout << "Enter numbers separated by commas (e.g., 3,5,2,9): ";
    getline(cin >> ws, input);  //read whole line including leading whitespace

    elements = 0;
    for (char c : input) {
        if (c == ',') 
            elements++;     //increment the number of elements to create the array
    }
    elements++;  //count is one more than number of commas
    
    int* array = new int [elements];    //Dynamically allocate memory 
    
    // Parse input into the array
    stringstream ss(input);
    string token;
    int index = 0;

    while (getline(ss, token, ',') && index < elements) {
        array[index++] = stoi(token);
    }
    
    cout << "\nArray has been dynamically allocated successfully";
    return array;
}

/*
	FUNCTION: recursiveMaxFind()
	 PURPOSE: Read comma-separated values from the user, store in a dynamic array
*/
int recusiveMaxFind(int* array, int elements){    
    if (elements == 1)
        return array[0];

    int maxValue = recusiveMaxFind(array, elements - 1);

    if (maxValue > array[elements - 1])
        return maxValue;
    else 
        return array[elements - 1];
}