#include "roads.hpp"
#include "roadClasses.hpp"

int main()
{
    classA ca;
    ca.setTraffic("Nope");
    ca.setOrigin("Busia");
    unsigned int x= 4;
    ca.setLanes(x);
    cout << ca.info() << flush << endl;
    return 0;
}