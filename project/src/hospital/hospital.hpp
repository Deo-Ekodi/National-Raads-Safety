// This file implements a hospital object

#pragma once
#include <iostream>
#include <exception>
#include <string>
#include <map>
#include <initializer_list>
#include <sstream>

namespace hos{
    //
    class hospital
    {
    private:
        std::string hospitalName;
        std::string location;
        std::string contact;
        std::string owner;
        int serviceHours;

        friend class Hospital;

    public:
        explicit hospital(const std::initializer_list<std::string> &lst, int &sHours)
        {
            this->hospitalName = *(lst.begin());
            this->location = *(lst.begin() + 1);
            this->contact = *(lst.begin() + 2);
            this->owner = *(lst.begin() + 3);
            this->serviceHours = sHours;
        }
        virtual ~hospital() = default;

        void setLocation(const std::string &str) { this->location = str;}

        void setHospitalName(const std::string &str) {this->hospitalName = str; }
        const std::string &getHospitalName() const { return this->hospitalName; }

        void setContact(const std::string &str) { this->contact = str; }
        const std::string &getContact() const { return this->contact; }

        void setOwner(const std::string &str) { this->owner = str; }
        const std::string &getOwner() const { return this->owner; }

        void setServiceHours(int &sHours) { this->serviceHours = sHours; }
        const int &getServiceHours() const { return this->serviceHours; }

        virtual std::map<double, double, std::less<double>> getLocation() = 0;
        // virtual const std::string info()const = 0;

        virtual std::string info() const = 0;
    };
}   // namespace hos