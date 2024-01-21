#include "urban.hpp"
#include "urbanUtils.hpp"
#include <iostream>

using namespace urb;

int main(){
    urban ub("nakuru");
    ub(20.0, 45.0);
    cout << info(ub) << endl;
}
