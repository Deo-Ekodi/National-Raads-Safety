#pragma once

#include "universal/universal.hpp"
#include <iostream>
#include <iterator>

namespace cops{
    class Police
    {
    private:
        std::string* sName;
        std::string* sAddress;
        std::string* sContact;
        std::string* sLocation;
        std::pair<double, double>* xyLocation;

    public:
        Police();
        Police(const std::initializer_list<std::string&>&);
        ~Police() = default;

        std::string* getName()const;
        std::string* getAddress()const;
        std::string* getContact()const;
        std::string* getLocation()const;

        void setName(std::string&);
        void setAddress(std::string&);
        void setContact(std::string&);
        void setLocation(std::string&);

        bool recCoordinates(std::string*);
        void init(Police*);

        Police& operator = (Police&) = delete;
        Police& operator = (const Police&) = delete;
    };

    Police::Police()
    {
        this->sAddress = nullptr;
        this->sContact = nullptr;
        this->sName = nullptr;
        this->sLocation = nullptr;
        this->xyLocation->first = -1.0;
        this->xyLocation->second = -1.0;
    }

    Police::Police(const std::initializer_list<std::string&>& lst)
    {
        try
        {
            if(lst.size() == 4)
            {
                this->sName     = (lst.begin() + 0);
                this->sAddress  = (lst.begin() + 1);
                this->sContact  = (lst.begin() + 2);
                this->sLocation = (lst.begin() + 3);
            }
            else
            {
                throw std::invalid_argument("invalid arguments parsed, use format \"NAME, ADDRESS, CONTACT, LOCATION\"");
            }
        }
        catch(const std::invalid_argument& e)
        {
            std::cerr << e.what() << std::flush;
        }
    }
/* setters */
    void Police::setName(std::string& str){
        this->sName = &str;
    }
    void Police::setAddress(std::string& str){
        this->sAddress = &str;
    }
    void Police::setContact(std::string& str){
        this->sContact = &str;
    }
    void Police::setLocation(std::string& str){
        this->sLocation = &str;
    }
/* getters */
    std::string* Police::getName()const{
        return this->sName;
    }
    std::string* Police::getAddress()const{
        return this->sAddress;
    }
    std::string* Police::getContact()const{
        return this->sContact;
    }
    std::string* Police::getLocation()const{
        return this->sLocation;
    }
/* other functions */
    bool Police::recCoordinates(std::string* str){
        xyLocation = univ::recCoordinates(str);
        if((xyLocation->first != -1.0) || (xyLocation->second == -1.0))
            return false;
        return true;
    }
    void Police::init(Police*){
        if(this->sName != nullptr)
            return;
        std::string *s0, *s1, *s2, *s3;
        std::cout << "enter name: " << std::flush;
        std::cin >> *s0;
        std::cout << "enter address: " << std::flush;
        std::cin >> *s1;
        std::cout << "enter location: " << std::flush;
        std::cin >> *s2;
        std::cout << "enter contact: " << std::flush;
        std::cin >> *s3;

        this->setName(*s0);
        this->setAddress(*s1);
        this->setLocation(*s2);
        this->setContact(*s3);
    }
}    // namespace cops