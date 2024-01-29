/**
 * This header file implements universally computed functions
 * These functions include:
 * 1    locationCoordinates
*/

#pragma once
#include <string>
#include <list>
#include <stdexcept>


namespace univ{
    std::pair<double, double>* recCoordinates(std::string*)
    {
        /**
         * implement logic for computing locations
        */
       std::pair<double, double>* temp;
       temp->first = -1.0;
       temp->second = -1.0;
       return temp;
    }
}    // namespace univ