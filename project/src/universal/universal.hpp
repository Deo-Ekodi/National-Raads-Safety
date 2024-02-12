/**
 * This header file implements universally computed functions
 * These functions include:
 * 1    locationCoordinates
*/

#pragma once
#include <string>
#include <list>
#include <stdexcept>
#include "hospital/Hospital.hpp"
#include "hospital/Hospital.hpp"
#include "roads/roadClasses.hpp"
#include "roads/roads.hpp"
#include "cops/cops.hpp"
#include "urbanAreas/urban.hpp"
#include "urbanAreas/urbanUtils.hpp"


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

    int add(hos::Hospital*);
    int add(rod::)
}    // namespace univ