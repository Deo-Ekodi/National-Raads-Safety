#include "Hospital.hpp"
#include "hospital.hpp"

int main()
{
    int hrs = 24;
    hos::Hospital hs({"ALupe", "Teso South", "333-444", "GOK"}, hrs);
    std::cout << hs.info();

    cout << alignof(hos::hospital) << endl;
}