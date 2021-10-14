#include <iostream>
#include <string>
#include <limits>

using namespace std;

// this function will take an input, if the input number is within the value it
// will pass through otherwise it will fail.
int inputNumRange(int lower, int upper){

    // variables init
    int inputVariable;
    bool active = true;

    // asinging for the first input
    cin >> inputVariable;

    // loop for checking if the cin
    while (active == true)
    {
        // if the cin is not an int
        if (!cin.fail()){

            // if the input is with in the range
            if ( inputVariable >= lower && inputVariable <= upper){
                active = false;
                return inputVariable;
            }
            // otherwise input not valid
            else
            {
                cout << "not a valid input please try again" << endl;
                cin >> inputVariable;
            }
        }
        // otherwise not valid
        else
        {
            cout << "not a valid input please try again" << endl;

            // clears the input
            cin.clear();

            // ignores the "bad" inputs
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cin >> inputVariable;
        }
    }
    
    return 0;
}


// this function will take an input, if the input number is one of the specifc
// value it will pass trough otherwise it will fail.
int inputNumStatic(int allNumbers[], int ammount){

    // variables init
    int inputVariable;
    bool active = true;

    // asinging for the first input
    cin >> inputVariable;

    // loop for checking if the cin
    while (active == true)
    {
        bool correct = false;

        // if the cin is not an int
        if (!cin.fail()){

            // looping for the length of the array
            for (int i = 0; i < ammount; i++){
                if(allNumbers[i] == inputVariable){
                    correct = true;
                }

                if (correct == true){
                    return inputVariable;
                }
            }

            // if it doesn't find a valid input
            cout << "not a valid input please try again" << endl;

            // clears the input
            cin.clear();

            // ignores the "bad" inputs
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cin >> inputVariable;

        }
        // otherwise not valid
        else
        {
            cout << "not a valid input please try again" << endl;

            // clears the input
            cin.clear();

            // ignores the "bad" inputs
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cin >> inputVariable;
        }
    }
    
    return 0;
}