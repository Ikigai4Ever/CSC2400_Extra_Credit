/************************************
   Team Member One: Ty Ahrens
   Team Member Two: Blake Hudson
           Program: main.cpp 
              Date: 4/29/25
       Compliation: Compiled using Programiz online complier
	   		Output: Dynamic output displayed on the console that demonstrates the different 
	  				steps of the recusive call for the decrease and conquer algorithm.
*************************************/

#include <iostream> 
#include <iomanip>
#include <sstream>
#include <string>
using namespace std;

/************* FUNCTION PROTOTYPES *************/
int menu();
int* defineArray(int&);
int recursiveMaxFind(int*, int);

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
                    cout << " ___________________________________________________________" << "\n"
                         << "|  SIZE  |  MAX VALUE  |  COMPARISION  |  VALID COMPARISON  |" << "\n";
                    maxValue = recursiveMaxFind(myArray, elements);
                    cout << "|                    FINISHED RECURSION                     |" << "\n"
                         << "|___________________________________________________________|" << "\n"
                         << "The maximum value that was found in the array was " << maxValue << "\n\n";
                    break;
            case 2: 
                    cout << "\n\n"
                         << "Here are the different parts of the program:\n"
                         << "DECREASE PHASE:\t" << "The array size is reduced in the recursiveMaxFind function on each recursive call and continues to reduce until it reaches the base case which means that there is only one element left.\n\n"
                         << "BASE CASE:\t" << "Once the size is 1, that element is returned into the recursive function as the starting \"maximum\" value, which begins the conquer phase.\n\n"
                         << "CONQUER PHASE:\t" << "This is best shown by looking at the size column, which represents the index of the array the recursive call is currently in. It then prints the comparision in the \"COMPARISON\" column to demonstrate the values it's comparing before going to the next element.\n\n"
                         << "OUTPUT:\t" << "The final output of the program shows the output of the array that was given by the user. The table demonstrates the recursive trace step-by-step to visualize how decrease-and-conquer recursion works.\n\n";

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
	FUNCTION: defineArray()
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
    
    //cout << "\nArray has been dynamically allocated successfully!\n";
    return array;
}

/*
	FUNCTION: recursiveMaxFind()
	 PURPOSE: Recurse through the array defined by the user and begin to compare 
  			  the first number in the array to the index to the right of it to find 
	   		  the maximum value in the array and send it back to the main function.
*/
int recursiveMaxFind(int* array, int elements){    
    if (elements == 1){
        cout << "\t" << elements << "\t\t\t" << array[0] << "\t\t\t" 
             << array[0] << " > N/A\t\t\tN/A\n"; 
        return array[0];
    }

    int maxValue = recursiveMaxFind(array, elements - 1);
    
    cout << "\t" << elements << "\t\t\t" << maxValue << "\t\t\t" << maxValue << " > " << array[elements - 1] << "\t\t"; 
    if (maxValue > array[elements - 1]){
        cout << "\tTRUE\n";
        return maxValue;
    }
    else{
        cout << "\tFALSE\n";
        return array[elements - 1];
    }
}
