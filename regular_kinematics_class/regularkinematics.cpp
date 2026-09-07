#include "regularkinematics.h"
#include <iostream>
#include <cmath>
#include <string>
#include <climits>
#include <limits>

// helper function of reponse input
double RegKinematics::getValidInput(std::string prompt) const
{
    double input;
    bool needsInput = true;

    while (needsInput)
    {
        std::cout << prompt;
        if (std::cin >> input)
        {
            needsInput = false;
        }
        else
        {
            std::cin.clear(); // resets error
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clears bad line
            std::cout << "Invalid Input. ";
        }
    }
    return input;
}


// option for picking what kinematic equation to use
 void RegKinematics::optionfunction()
 {
    // options for the kinematic equations
    char typeOfRegKinematics = '0';
    std::cout << '\n';
    std::cout << "1 - Velocity-Time Equation: v = v_0 + (a * t)" << '\n';
    std::cout << "2 - Position-Time Equation: x = x_0 + (v_0 * t) + 1/2 * (a * t^2)" << '\n';
    std::cout << "3 - Velocity-Without-Time Equation: v^2 = v_0^2 + 2 * [a * (x - x_0)]" << '\n';
    std::cout << "Select the following equations <1, 2, or 3>: ";      


    // filter the options of regular kinematics
    do
    {
        std::cin >> typeOfRegKinematics; // get user input for type of reg. kinematics

        switch (typeOfRegKinematics)
        {
            case '1':
                velocitywithtime();
                break;

            case '2':
                positionwithtime();
                break;

            case '3':
                std::cout << "good" << std::endl;
                break;

            default:
                std::cin.clear(); // resets error
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clears the entire bad line out of buffer to the newline
                std::cout << "Invalid Input. Select 1, 2, or 3: ";
        }
                
    } while (typeOfRegKinematics != '1' && typeOfRegKinematics != '2' && typeOfRegKinematics != '3'); 
 }


// v = v_0 + a * t
 double RegKinematics::velocitywithtime()
 {
    std::cout << "\nEquation: v = v_0 + a * t \n";
    std::cout << "[f] Final Velocity (v)\n";
    std::cout << "[i] Initial Velocity (v_0)\n";
    std::cout << "[a] Acceleration (a)\n";
    std::cout << "[t] time (t)\n";
    std::cout << "Enter your choice: ";

    double ans = 0.0;
    char response;

    // user response of what variable to find
    do
    {
        std::cin >> response;

        switch (response)
        {
            case 'f':
                std::cout << "\nEquation: v = v_0 + (a * t)" << '\n';
                
                // Call the helper function and assign it straight to class variables
                v_0 = getValidInput("Enter initial velocity, v_0 (m/s): ");
                a = getValidInput("Enter acceleration, a (m/s^2): ");
                t = getValidInput("Enter time, t (s): ");

                // Calculate and print
                ans = v_0 + (a * t);
                std::cout << "\nThe calculated Final Velocity (v) is: " << ans << " m/s\n";
                break;

            case 'i':
                std::cout << "\nEquation: v_0 = v - (a * t)" << '\n';

                // Call the helper function and assign it straight to class variables
                v = getValidInput("Enter final velocity, v (m/s): ");
                a = getValidInput("Enter acceleration, a (m/s^2): ");
                t = getValidInput("Enter time, t (s): ");

                // Calculate and print
                ans = v - (a * t);
                std::cout << "\nThe calculated Initial Velocity (v_0) is: " << ans << " m/s\n";
                break;

            case 'a':
                std::cout << "\n";
                std::cout << "Equation: a = (v - v_0) / t" << '\n';
            
                // Call the helper function and assign it straight to class variables
                v = getValidInput("Enter final velocity, v (m/s): ");
                v_0 = getValidInput("Enter initial velocity, v_0 (m/s): ");
                t = getValidInput("Enter time, t (s): ");

                // Calculate and print
                ans = (v - v_0) / t;
                std::cout << "\nThe calculated Acceleration (a) is: " << ans << " m/s^2\n";
                break;

            case 't':
                std::cout << "\nEquation: t = (v - v_0) / a" << '\n';
            
                // Call the helper function and assign it straight to class variables
                v = getValidInput("Enter final velocity, v (m/s): ");
                v_0 = getValidInput("Enter initial velocity, v_0 (m/s): ");
                a = getValidInput("Enter acceleration, a (m/s^2): ");

                // Calculate and print
                ans = (v - v_0) / a;
                std::cout << "\nThe calculated Time (t) is: " << ans << " s\n";
                break;

            default:
                std::cin.clear(); // resets error
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clears the entire bad line out of buffer to the newline
                std::cout << "Invalid Input. \n \n";
                std::cout << "Equation: v = v_0 + a * t" << '\n';
                std::cout << "[f] Final Velocity (v)\n";
                std::cout << "[i] Initial Velocity (v_0)\n";
                std::cout << "[a] Acceleration (a)\n";
                std::cout << "[t] time (t)\n";
                std::cout << "Enter your choice: ";
        }
        
    } while (response != 'f' && response != 'i' && response != 'a' && response != 't');
    

    return ans;
 }



 // x = x_0 + v_0 * t + 1/2 * a * t^2
 double RegKinematics::positionwithtime()
 {
    std::cout << "\nEquation: x = x_0 + v_0 * t + 1/2 * a * t^2 \n";
    std::cout << "[x] Final Position (x)\n";
    std::cout << "[o] Initial Position (x_0)\n";
    std::cout << "[i] Initial Velocity (v_0)\n";
    std::cout << "[a] Acceleration (a)\n";
    std::cout << "[t] time (t)\n";
    std::cout << "Enter your choice: ";

    double ans = 0.0;
    char response;

    // initialize variables for quadratic formula to solve for time
    double A;
    double B;
    double C;
    double discriminant;
    double t1;
    double t2;

    // user response of what variable to find
    do
    {
        std::cin >> response;

        switch (response)
        {
            case 'x':
                std::cout << "\nx = x_0 + v_0 * t + 1/2 * a * t^2" << '\n';

                // Call the helper function and assign it straight to class variables
                x_0 = getValidInput("Enter initial position, x_0 (m): ");
                v_0 = getValidInput("Enter initial velocity, v_0 (m/s): ");
                a = getValidInput("Enter acceleration, a (m/s^2): ");
                t = getValidInput("Enter time, t (s): ");

                // Calculate and print
                ans = x_0 + (v_0 * t) + (0.5 * a * pow(t, 2));
                std::cout << "\nThe calculated Final Position (x) is: " << ans << " m\n";
                break;

            case 'o':
                std::cout << "\nx_0 = x - v_0 * t - 1/2 * a * t^2" << '\n';

                // Call the helper function and assign it straight to class variables
                x = getValidInput("Enter final position, x (m): ");
                v_0 = getValidInput("Enter initial velocity, v_0 (m/s): ");
                a = getValidInput("Enter acceleration, a (m/s^2): ");
                t = getValidInput("Enter time, t (s): ");

                // Calculate and print
                ans = x - (v_0 * t) - (0.5 * a * pow(t, 2));
                std::cout << "\nThe calculated Initial Position (x_0) is: " << ans << " m\n";
                break;

            case 'i':
                std::cout << "\nv_0 = (x - x_0 - [1/2 * a * t^2]) / t" << '\n';

                // Call the helper function and assign it straight to class variables
                x = getValidInput("Enter final position, x (m): ");
                x_0 = getValidInput("Enter initial position, x_0 (m): ");
                a = getValidInput("Enter acceleration, a (m/s^2): ");
                t = getValidInput("Enter time, t (s): ");

                // Calculate and print
                ans = (x - x_0 - (0.5 * a * pow(t, 2))) / t;
                std::cout << "\nThe calculated Initial Velocity (v_0) is: " << ans << " m/s\n";
                break;

            case 'a':
                std::cout << "\na = (2(x - x_0 - v_0 * t))/ t^2" << '\n';

                // Call the helper function and assign it straight to class variables
                x = getValidInput("Enter final position, x (m): ");
                x_0 = getValidInput("Enter initial position, x_0 (m): ");
                v_0 = getValidInput("Enter initial velocity, v_0 (m/s): ");
                t = getValidInput("Enter time, t (s): ");

                // Calculate and print
                ans = (2 * (x - x_0 - (v_0 * t)))/ (pow(t, 2));
                std::cout << "\nThe calculated Acceleration (a) is: " << ans << " m/s^2\n";
                break;

            case 't':
                std::cout << "\nt = (-B +/- sqrt(B^2 - 4AC)) / 2A   ";
                std::cout << "Where A = 1/2 * a, B = v_0, and C = x_0 - x \n \n";

                // Call the helper function and assign it straight to class variables
                x = getValidInput("Enter final position, x (m): ");
                x_0 = getValidInput("Enter initial position, x_0 (m): ");
                v_0 = getValidInput("Enter initial velocity, v_0 (m/s): ");
                a = getValidInput("Enter acceleration, a (m/s^2): ");


                // Quadratic Formula
                A = 0.5 * a;
                B = v_0;
                C = x_0 - x;

                discriminant = (pow(B, 2)) - (4 * A * C);

                // in quadratic formula, checking if there are real or non-real solutions
                if (discriminant < 0) 
                {
                    std::cout << "\nNo real solution for time exists with these inputs.\n";
                    ans = 0.0;
                } 
                else 
                {
                    // two possible ans for time
                    t1 = (-B + sqrt(discriminant)) / (2 * A);
                    t2 = (-B - sqrt(discriminant)) / (2 * A);
                    
                    // filters if the time is negative and/or usually takes in the time where it reaches the end completely
                    ans = fmax(t1, t2);
                }

                std::cout << "\nThe calculated Time (t) is: " << ans << " s\n";
                break;

            default:
                std::cin.clear(); // resets error
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clears the entire bad line out of buffer to the newline
                std::cout << "Invalid Input. \n \n";
                std::cout << "Equation: x = x_0 + v_0 * t + 1/2 * a * t^2 \n";
                std::cout << "[x] Final Position (x)\n";
                std::cout << "[o] Initial Position (x_0)\n";
                std::cout << "[i] Initial Velocity (v_0)\n";
                std::cout << "[a] Acceleration (a)\n";
                std::cout << "[t] time (t)\n";
                std::cout << "Enter your choice: ";
        }
        
    } while (response != 'x' && response != 'o' && response != 'i' && response != 'a' && response != 't');


    return ans;
 }


// v^2 = v_0^2 + 2 * a (x - x_0)
 double RegKinematics::velocitywithouttime()
 {
    
    std::cout << "\nEquation: v^2 = v_0^2 + 2 * a * d \n";
    std::cout << "where d = x - x_0 [displacement - change in position] \n \n";
    std::cout << "[v] Final Velocity (v)\n";
    std::cout << "[i] Initial Velocity (v_0)\n";
    std::cout << "[a] Acceleration (a)\n";
    std::cout << "[d] Displacement (d or delta x)\n";
    std::cout << "Enter your choice: ";

    double ans = 0.0;
    char response;
    double d = 0.0;
    double insideSqrt = 0.0;

    double v1 = 0.0;
    double v2 = 0.0;
    double v_01 = 0.0;
    double v_02 = 0.0;

    do
    {
        switch (response)
        {
        case 'v':
            std::cout << "\nv = +/- sqrt(v_0^2 + 2 * a * d) \n where d = x - x_0";

            v_0 = getValidInput("Enter initial velocity, v_0 (m/s): ");
            a = getValidInput("Enter acceleration, a (m/s^2): ");

            x = getValidInput("Enter final position, x (m): ");
            x_0 = getValidInput("Enter initial position, x_0 (m): ");
            d = x - x_0;

            insideSqrt = (pow(v_0, 2)) + (2 * a * d);

            if (insideSqrt < 0) 
                {
                    std::cout << "\nNo real solution for final velocity exists with these inputs.\n";
                    ans = 0.0;
                } 
                else 
                {
                    // two possible ans for velocity
                    v1 = sqrt(insideSqrt);
                    v2 = -sqrt(insideSqrt);
                    
                    // filters if the final velocity is negative and/or usually takes in the velocity where it reaches the end completely
                    ans = fmax(v1, v2);
                }

            
            std::cout << "\nThe calculated Final Velocity (v) is: " << ans << " m/s\n";
            break;

        case 'i':
            /* code */
            break;

        case 'a':
            std::cout << "\na = (v^2 - v_0^2) / (2 * d)\n";
            v = getValidInput("Enter final velocity, v (m/s): ");
            v_0 = getValidInput("Enter initial velocity, v_0 (m/s): ");
            
            x = getValidInput("Enter final position, x (m): ");
            x_0 = getValidInput("Enter initial position, x_0 (m): ");
            d = x - x_0;

            ans = (pow(v, 2) - pow(v_0, 2)) / (2 * d);
            std::cout << "\nThe calculated Acceleration (a) is: " << ans << " m/s^2\n";
            break;

        case 'd':
            std::cout << "\nd = (v^2 - v_0^2) / (2 * a)\n";
            v = getValidInput("Enter final velocity, v (m/s): ");
            v_0 = getValidInput("Enter initial velocity, v_0 (m/s): ");
            a = getValidInput("Enter acceleration, a (m/s^2): ");

            ans = (pow(v, 2) - pow(v_0, 2)) / (2 * a);
            std::cout << "\nThe calculated Displacement (d) is: " << ans << " m\n";
            break;
        
        default:
            std::cin.clear(); // resets error
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clears the entire bad line out of buffer to the newline
            std::cout << "Invalid Input. \n \n";
            std::cout << "\nEquation: v^2 = v_0^2 + 2 * a * d \n";
            std::cout << "where d = x - x_0 [displacement - change in position] \n \n";
            std::cout << "[v] Final Velocity (v)\n";
            std::cout << "[i] Initial Velocity (v_0)\n";
            std::cout << "[a] Acceleration (a)\n";
            std::cout << "[d] Displacement (d or delta x)\n";
            std::cout << "Enter your choice: ";
            break;
        }
    } while (response != 'v' && response != 'i' && response != 'a' && response != 'd');
    

    return ans;
 }

 
 
 