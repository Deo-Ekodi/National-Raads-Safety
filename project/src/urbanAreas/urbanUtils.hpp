#pragma once

#include "urban.hpp"

#include <initializer_list>
#include <cmath>
#include <map>
#include <stdexcept>
#include <iostream>

using namespace std;
namespace urb{

    const double _proximity(const urban& x, const urban& y);
    const map<pair<string, string>, double> proximity(initializer_list<const urban>& lst);

    // below implements deprecation qith warnings!
    // [[deprecated("avoid using \'info\', urban area information is yet to be removed from access!")]]
    const string info(const urban& ur);


    const double _proximity(const urban& x, const urban& y){
        return hypot(abs(x.getX() - y.getX()), abs(x.getY() - y.getY()));
    }
    const map<pair<string, string>, double> proximity(initializer_list<const urban>& lst){
        map<pair<string, string>, double> mp;
        try{
            for (size_t i = 0; i < lst.size(); i++){
                /**
                 * store urban names in a pair of strings
                 * compute proximity
                */
                for(auto x : lst){
                    pair<string, string> prStr;
                    prStr.first = x.getName();
                    prStr.second = (lst.begin() + i)->getName();
                    mp[prStr] = _proximity(x, *(lst.begin() + i));
                }
            }
            throw std::runtime_error("error calculating proximities");;
        }
        catch(const std::runtime_error& e)
        {
            cerr << e.what() << '\n';
        }
        return mp;
    }

    const string info(const urban& ur){
        ostringstream os;
        os << ur.getName()  << " ["<< ur.getX() << ", " << ur.getY() << "]" << flush;
        return os.str();
    }
} // namespace urb
