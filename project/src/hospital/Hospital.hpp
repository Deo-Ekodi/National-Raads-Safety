#include "hospital.hpp"

#include <vector>
#include <algorithm>

namespace hos
{
    class Hospital : public hospital
    {
    private:
        std::pair<double, double> xyLocation;
	//;
    public:
        Hospital() = default;
        explicit Hospital(const std::initializer_list<std::string> &lst, int &sHours)
            : hospital(lst, sHours) {}
        virtual ~Hospital() = default;

        void operator=(Hospital&) = delete;
        void operator=(const Hospital&) = delete;

        std::map<double, double, std::less<double> > getLocation();
        std::string info() const override;
    };  // class Hospital

/**
 * code below should only be used i exceptions!
 * 
 *  [[noreturn]] void assertInvalidArguments(std::string& message){
        cerr << message << flush << endl;
        std::terminate();
    }
*/
    std::map<double, double, std::less<double> > Hospital::getLocation()
    {
        std::map<double, double, std::less<double> > pr;
        pr.insert(std::make_pair(2.3, 7.6));
        // 
        return pr;
    }
    std::string Hospital::info() const
    {
        std::ostringstream os;
        std::vector<std::vector<std::string>> str{{"Hospital Name: ", "Hospital Location: ", "Hospital Contact: ", "Hospital Owner: ", "Service Hours: "},
                                                    {getHospitalName(), hospital::location, getContact(), getOwner(), std::to_string(getServiceHours())}};
                                                    
        for (size_t i{0}; i < str[0].size(); i++)
        {
            os << str[0][i] << " : " << str[1][i] << std::endl;
        }
        return os.str();
    }
}   // namespace hos
