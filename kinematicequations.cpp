#include <iostream>
#include <climits>
#include <limits>
#include <cmath>
#include "regular_kinematics_class/regularkinematics.h"


/* START HERE */


int main()
{
    std::cout << "Welcome to The Kinematic Equations Calculator!" << '\n' << '\n';

    // user input
    char kinematicInput = '0';
    std::cout << "Is this regular kinematics or free fall kinematics?" << '\n';
    std::cout << "1 - regular kinematics" << '\n';
    std::cout << "2 - free fall kinematics" << '\n';
    std::cout << "Select 1 or 2: ";


    // Regular Kinematics User
    RegKinematics user;


    // this code is the "filter" if the user input is wrong
    do
    {
        std::cin >> kinematicInput; // gets user input for reg. kinematics or free fall kinematics


        if (kinematicInput == '1') // if user wanted "regular" kinematics
        {
            user.optionfunction();
        }
        else if (kinematicInput == '2') // if user wanted "free fall" kinematics
        {
            std::cout << kinematicInput << std::endl;
        }
        else // clear the filter
        {
            /* if user inputs completely wrong, it'll clear up input. */
            std::cin.clear(); // resets error
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clears the entire bad line out of buffer to the newline
            std::cout << "Invalid Input. Select 1 or 2: ";
        }
    } while (kinematicInput != '1' && kinematicInput != '2');
    
   
    std::cout << "end of test";
    
    return 0; // no problems on the code
}