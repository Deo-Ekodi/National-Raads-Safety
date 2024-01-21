#pragma once
#include <string>

using namespace std;

class road// Base
{
private:
    bool tarmac;
    unsigned int lanes;
    unsigned int carriage;
    unsigned int age;
    string origin;
    string destination;
public:
    road(/* args */) = default;
    explicit road(const string &roadOrigin = "X_origin",
                  const string &roadDeStination = "Y_destin",
                  unsigned numberOfLanes = 1,
                  unsigned typeOfCarriage = 2,
                  unsigned ageOfConduit = 10,
                  /*unsigned,*/
                  bool tarmacStatus = true) : origin{roadOrigin}, destination{roadDeStination}
    {
        setOrigin(roadOrigin);
        setDestination(roadDeStination);
        origin = roadOrigin;destination = roadDeStination;
        lanes = numberOfLanes;carriage = typeOfCarriage;
        age = ageOfConduit; tarmac = tarmacStatus;
    }
    virtual ~road() {}

    void setOrigin(const string &str)
    {
        this->origin = str;
    }
    string getOrigin() const
    {
        return this->origin;
    }
    void setDestination(const string &str)
    {
        this->destination = str;
    }
    string getDestination() const
    {
        return this->destination;
    }
    void setTarmacStatus(bool bl)
    {
        this->tarmac = bl;
    }
    bool getTarmacStatus() const
    {
        return this->tarmac;
    }
    void setLanes(unsigned &un)
    {
        this->lanes = un;
    }
    unsigned getLanes() const
    {
        return this->lanes;
    }
    void setAge(unsigned &un)
    {
        this->age = un;
    }
    unsigned getAge() const
    {
        return this->age;
    }

    virtual string info() = 0;
};

