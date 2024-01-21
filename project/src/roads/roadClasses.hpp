#pragma once
#include <bits/stdc++.h>
#include "roads.hpp"

using namespace std;

class classA;
class classB;
class classC;
class classD;

class classA final : public road
{
private:
    string adminstration;
    string trafficRating;

public:
    explicit classA(const string &roadOrigin = "X_origin",
                    const string &roadDeStination = "Y_destin",
                    unsigned numberOfLanes = 1,
                    unsigned typeOfCarriage = 2,
                    unsigned ageOfConduit = 10,
                    bool tarmac = true,
                    const string &admin = "GOK",
                    const string &trafficRating = "HEAVY") : road(roadOrigin, roadDeStination, numberOfLanes, typeOfCarriage, ageOfConduit, tarmac)
    {
        this->trafficRating = trafficRating;
        this->adminstration = admin;
    }
    ~classA() {}

    virtual string info()
    {
        ostringstream os;
        os << this->adminstration << " " << this->trafficRating << flush;
        return os.str();
    }

    void setAdmin(const string& str)
    {
        this->adminstration = str;
    }
    void setTraffic(const string& str)
    {
        this->trafficRating = str;
    }
};