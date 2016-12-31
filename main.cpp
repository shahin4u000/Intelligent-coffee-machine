#include <iostream>
using namespace std;
#include "intelligentcoffeemachine.h"


unsigned int intelligentcoffeemachine::minWater=0; // as static variable inside of the class need to define outside of the class.
unsigned int intelligentcoffeemachine::minCoffee=0;


int main ()

{
    intelligentcoffeemachine myclass;
    myclass.manu();

     return 0;
}
