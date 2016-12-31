#ifndef INTELLIGENTCOFFEEMACHINE_H
#define INTELLIGENTCOFFEEMACHINE_H
#include <iostream>

using namespace std;

class intelligentcoffeemachine
{
public:
 /* --------------------------------------------------------------------------------------------
                                      so far total function is used
    --------------------------------------------------------------------------------------------*/
    int manueIndex;
    void manu();
    int openLid();
    int insertFilter();
    int coffeeInsertion ();
    int waterInsertion ();
    int closeLid();
    int cooking();
    int takeCoffee();
    int switchOff();
    int exit();

private:
    bool lidState=false;
    bool filterState=false;
    unsigned static int minWater;
    unsigned static int minCoffee;

    const int maxWater=500, maxCoffee=100; //water reservoir can hold max 500mL water, coffee reservoir can 100gm
    bool powerLED=true;
    int switchState=false;

};

#endif // INTELLIGENTCOFFEEMACHINE_H
