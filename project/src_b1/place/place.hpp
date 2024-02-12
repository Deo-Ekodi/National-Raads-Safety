#pragma once
#include <string>
#include <exception>
#include <thread>

namespace place{
    class Place
    {
    private:
        std::string* name;
        std::string* location;
        std::string* contact;
        std::pair<double, double>* rec_coordinates;
    public:
        Place(/* args */) = default;
        Place(std::string&, std::string&, std::string&);
        Place(std::initializer_list<std::string&>);

/* disable copy assignment & copy constructor */
        Place(Place const&) = delete;
        Place& operator = (Place const&) = delete;

        void set_name(std::string&);
        std::string& get_name()const;

        void set_location(std::string&);
        std::string& get_location()const;

        void set_contact(std::string&);
        std::string& get_contact()const;

        virtual std::string info() = 0;
        virtual std::pair<double, double> rectangle_coordinates() = 0;
        virtual ~Place() = default;
    };
    
    Place::Place(/* args */)
    {
        this->name = nullptr;
        this->location = nullptr;
        this->contact = nullptr;
        this->rec_coordinates->first = -1.0;
        this->rec_coordinates->second = -1.0;
    }
    Place::Place(std::string& strx, std::string& stry, std::string& strz)
    {
        // this->name = &strx;
        std::thread thr_x(set_name, strx);
        std::thread thr_y(set_location, stry);
        std::thread thr_z(set_contact, strz);
        this->rec_coordinates->first = -1.0;
        this->rec_coordinates->second =-1.0;
    }
    Place::Place(std::initializer_list<std::string&> lst)
    {
        try
        {
            if(lst.size() == 3)
            {
                std::thread thrx(set_name, std::string(*(lst.begin() + 0)));
                std::thread thry(set_location, std::string(*(lst.begin() + 1)));
                std::thread thrz(set_contact, std::string(*(lst.begin() + 2)));

                if(thrx.joinable())
                    thrx.join();
                if(thry.joinable())
                    thry.join();
                if(thrz.joinable())
                    thrz.join();
            }
            else if(lst.size() > 3)
            {
                std::__throw_invalid_argument("invalid parameters parsed!");
            }
            else
            {
                throw;
            }
        }
        catch(...)
        {
            __throw_exception_again;
        }

        this->rec_coordinates->first = -1.0;
        this->rec_coordinates->second = -1.0;
    }

/* setters */
    void Place::set_name(std::string& str)
    {
        this->name = &str;
    }
    void Place::set_location(std::string& str)
    {
        this->location = &str;
    }
    void Place::set_contact(std::string& str)
    {
        this->contact = &str;
    }
/* getters */
    std::string& Place::get_name()const
    {
        try
        {
            if(this->name != nullptr)
            {
                return *(this->contact);
            }
            else
            {
                throw std::logic_error("calling uninitialized space!");
            }
        }
        catch(...)
        {
            __throw_exception_again;
        }
    }
    std::string& Place::get_location()const
    {
        try
        {
            if(this->location != nullptr)
            {
                return *(this->location);
            }
            else
            {
                throw std::logic_error("calling uninitialized space!");
            }
        }
        catch(...)
        {
            __throw_exception_again;
        }
    }
    std::string& Place::get_contact()const
    {
        try
        {
            if(this->contact != nullptr)
            {
                return *(this->contact);
            }
            else
            {
                throw std::logic_error("calling uninitialized space!");
            }
        }
        catch(...)
        {
            __throw_exception_again;
        }
    }
}   /*   namespace place   */