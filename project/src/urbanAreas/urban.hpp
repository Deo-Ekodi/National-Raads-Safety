#pragma once

#include <string>
#include <list>
#include <sstream>

using namespace std;

// describes towns and other urban centers
namespace urb{
    class urban
    {
    private:
        string urbanName;
        pair<double, double> coordinates;

        friend const double& proximity(urban&, urban&);
    public:
        explicit urban(const string& str = "unnamed");
        ~urban() = default;

        void setName(const string& str);
        const string& getName()const noexcept;
        const pair<double, double> getCoordinates(string&);
        const double& getX()const noexcept;
        const double& getY()const noexcept;

        void setX(const double&);
        void setY(const double&);

        void  operator()(double x, double y){
            setX(x);
            setY(y);
        }
    };
    
    urban::urban(const string& str){urbanName = str;}
    void urban::setName(const string& str){urbanName = str;}
    const string& urban::getName()const noexcept{return urbanName;}

    const pair<double, double> urban::getCoordinates(string& str){
        // write logic for processing coordinates
        pair<double, double> pr;
        {
            pr.first     = -5.0;
            pr.second    = -5.0;
            return pr;
        }
    }

    const double& urban::getX()const noexcept{return coordinates.first;}
    const double& urban::getY()const noexcept{return coordinates.second;}
    void urban::setX(const double& db){coordinates.first = db;}
    void urban::setY(const double& db){coordinates.second = db;}
}   // namespace urb
