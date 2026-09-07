#ifndef REGULARKINEMATICSH
#define REGULARKINEMATICSH
#include <iostream>
#include <cmath>
#include <string>
#include <climits>
#include <limits>

class RegKinematics
{
    private: // variables
        double x; // final positon
        double x_0; // initial positon
        double v; // final velocity
        double v_0; // initial velocity
        double a; // acceleration
        double t; // time

        double getValidInput(std::string prompt) const; // helper function

    public: // functions
        void optionfunction(); // options for the kinematic equations
        double velocitywithtime(); // v = v_0 + a * t
        double positionwithtime(); // x = x_0 + v_0 * t + 1/2 * a * t^2
        double velocitywithouttime(); // v^2 = v_0^2 + 2 * a (x - x_0)

};

#endif