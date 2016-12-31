#include "intelligentcoffeemachine.h"

/*-----------------------------------------------------------------------------
                                Manu
-------------------------------------------------------------------------------*/
void intelligentcoffeemachine::manu ()
{
    do {  cout<<"\n";
        cout<<"|---------------------------|\n";
        cout<<"|    1. Open Lid            |\n";
        cout<<"|    2. Insert Filter       |\n";
        cout<<"|    3. Insert coffe        |\n";
        cout<<"|    4. Insert water        |\n";
        cout<<"|    5. close lid           |\n";
        cout<<"|    6. start cooking       |\n";
        cout<<"|    7. Take coffee         |\n";
        cout<<"|    8. Switch off          |\n";
        cout<<"|    9. Exit                |\n";
        cout<<"|---------------------------|\n";
        cin>>manueIndex;
        while (cin.fail() || manueIndex<1 || manueIndex>9)
        {   cin.clear();
            cin.ignore(1000,'\n');
            cout<<"!!! Error manue selection. Try Again \n";
            cin>>manueIndex;        //Manu Selection
        }
        switch (manueIndex) {
        case 1:
            if (!lidState) {openLid();}   //Lid will open if lidstate(by default its sets to false) is true.

            else {
                cout<<"\nLid is already Opened. Please Insert Filter \n ";
            }
            break;
        case 2: if(lidState){intelligentcoffeemachine::insertFilter();} // if Lid is open then insert filter is possible.
            else {
                cout<<"\nPlease Open the Lid first \n ";
            }

            break;
        case 3: if (lidState && filterState) {intelligentcoffeemachine::coffeeInsertion();} //coffee insertion possible while
            //lidstate and filterstate goes true.

            else if (lidState==false && filterState==false)
            {
                cout<<"\nPlease open the lid and insert filter first\n";
            }
            else if (lidState)
            {
                cout<<"\nplease insert Filter as well \n";

            }
            else cout<<"\nPlease open the Lid\n";
            break;
        case 4:
            if (lidState){waterInsertion();}            //until lidstate turns to true from is default false state
            //water insertion will not possible.
            else cout<<"\nOpen the Lid first \n";

            break;
        case 5:

            if(lidState)
            {
                closeLid();
                lidState=false; // if user press twice then it will show that its already close.
            }
            else cout<<"\n Lid is already Closed. \n";
            break;
        case 6:

            if (minWater >=100 && minCoffee >=20)
            { if(powerLED){
                    cooking();}
                else cout<<"\n !!! Take out the cooked coffee first to cook once again. \n";
            }
            else
            {
                cout<<"\n!!! Minimum 100mL of water and 20gm of Coffee needed. \n";
                cout<<"\nCurrently there are "<<minWater<< "mL water && "<<minCoffee<<" gm of coffee.\n";
            }

            break;
        case 7:
            if(!powerLED && switchState){
                takeCoffee();}
            else if(powerLED) {cout<<"\n!!! Cook first.\n";}
            else cout<<"\nFor safety Switch off the machine. \n";
            break;
        case 8:

            switchOff();
            break;

        default:
            exit();

            break;
        }
    }
    while(  manueIndex<9 );
}

/*-----------------------------------------------------------------------------
                                Checking Lid codition
-------------------------------------------------------------------------------*/

int intelligentcoffeemachine::openLid()
{

    if(lidState==false)    //consider lid is close at begaining,Hence lidState is false.
        //so after pressing "Open lid" lid is opening and lid state is going to be true as it is opened.

    {cout<<"\nOpening the Lid...\nLid is Opened.\n";
        lidState=true;   //after open the lid lidstate will be true. hence user dont need to
        //open it again.
    }


    return 0;

}
/*-----------------------------------------------------------------------------
                                Checking Lid codition
-------------------------------------------------------------------------------*/

int intelligentcoffeemachine::insertFilter()
{   int insertOption;
    if(filterState==false)                  //considered filter was not there at begining. Hence filterState is false.
        //so after pressing "Insert filter" coffe machine will insert a filter and filter state will be turn true. and ready for next step
    {
        cout<<"\nPlease insert a filter manually.\n";
        cout<<"\nFor successful insertion press '1'  or '2' for unsuccessful : ";
        cin>>insertOption;
        while (cin.fail()|| insertOption<1 || insertOption >2)
        {
            cin.clear ();
            cin.ignore(1000,'\n');
            cout<<"\n!!! Error Input .\n";
            cin>>insertOption;
        }

        if(insertOption==1)
        {
            cout<<"\nFilter insertion successful !!!\n";
            filterState=true;
        }
        else cout<<"\n!!! Filter insertion unsuccessful\n";
    }
    else {
        cout<<"\nFilter is already inserted. Please Insert coffee. \n ";
    }


    return 0;
}
/*-----------------------------------------------------------------------------
                                Checking Lid codition
-------------------------------------------------------------------------------*/

int intelligentcoffeemachine::coffeeInsertion ()
{
    cout<<"\nCurrently Coffee reservoir has : "<<minCoffee<<" gm of coffee.\n ";


    unsigned int inCoffee,temp;

    if( minCoffee<maxCoffee){
        cout<<"\nCoffee reserver can hold max 100gm coffee \n";
        cout<<"\nInsert Amount (0 to 100 gm) : ";
        cin>>inCoffee;
        temp=inCoffee;
        temp=temp+minCoffee;

        while (cin.fail()||temp>maxCoffee )
        {
            cin.clear();
            cin.ignore(100,'\n');
            cout<<"\nData Error. Insert again (0 to 100 gm).\n";
            cout<<"\nRemember your coffee reservoir can hold 100 gm of coffee.\n";
            cout<<"\nCurrently it has "<<minCoffee<<" gm of coffe: ";
            temp=0;
            cin>>inCoffee;
            temp=inCoffee;
            temp=temp+minCoffee;

        }
        cout<<"\nSuccessful !!!\n";
        minCoffee+=inCoffee;
        cout<<"\nCoffee reservoir has : "<<minCoffee<<" gm of coffee.\n ";



    }

    else cout<<"\n!!! Coffee reservoir is Full.\n";
    return 0;
}
/*-----------------------------------------------------------------------------
                                Checking Lid codition
-------------------------------------------------------------------------------*/

int intelligentcoffeemachine::waterInsertion ()
{

    cout<<"\nCurrently Water reservoir has : "<<minWater<<" mL of water \n ";


    unsigned int inWater,temp;

    if( minWater<maxWater){
        cout<<"\nWater reserver can hold max 500mL(mili Liter) Water \n";
        cout<<"\nInsert Amount (0 to 500 mL) : ";
        cin>>inWater;
        temp=inWater;
        temp=temp+minWater;


        while (cin.fail()||temp>maxWater )
        {
            cin.clear();
            cin.ignore(100,'\n');
            cout<<"\nData Error. Insert again (0 to 500 mL)\n";
            cout<<"\nRemember your Water reservoir can hold 500 mL of water\n";
            cout<<"\nCurrently it has "<<minWater<<" mL of water: ";
            temp=0;
            cin>>inWater;
            temp=inWater;
            temp=temp+minWater;

        }
        cout<<"\nSuccessful !!!\n";
        minWater+=inWater;
        cout<<"\nWater reservoir has : "<<minWater<<" mL of water. \n ";
    }

    else cout<<"\n!!! Water reservoir is Full\n";
    return 0;
}
/*-----------------------------------------------------------------------------
                                Checking Lid codition
-------------------------------------------------------------------------------*/

int intelligentcoffeemachine::closeLid()
{
    lidState=true;
    cout<<"\nLid is closing...\n";
    cout<<"\nLid is closed. !!!\n";
}
/*-----------------------------------------------------------------------------
                                Checking Lid codition
-------------------------------------------------------------------------------*/

int intelligentcoffeemachine::cooking()
{
    unsigned int desireCoffee=0;
    if(powerLED){cout<<"\nPOWER LED ON\n";}
    cout<<"\nHow much coffee(gm) do you want to add:";
    cin>>desireCoffee;
    while(cin.fail()||desireCoffee<20)
    {
        cin.clear();
        cin.ignore(1000,'\n');
        cout<<"\n!!! MiniMum amount of Coffee(20 gm) is needed. \n";
        cin>>desireCoffee;
    }
    minCoffee-=desireCoffee;
    int count=0;
    for (int i=0;i<30000;i++)
    {
        if(i==10000|| i==20000 || i==30000)
        {
            cout<<++count<<" min... \n";

        }
    }
    cout<<"\n!!! Coffee is coocked \n";
    cout<<"\nWater reservoir is Empty.\n";
    cout<<"\n"<<minCoffee<<"gm Coffee is left.\n";
    powerLED=false;         //make sure user cant cooking again until he took out the coffee.
    minWater=0;
    // Now clean up the coffe maching.
    unsigned int clearFilter;
    cout<<"\nPlease take out the filter.\n";
    cout<<"\n1. Successful Take out.\n";

    cin>>clearFilter;
    while(cin.fail()||clearFilter!=1 )
    {
        cin.clear();
        cin.ignore(1000,'\n');
        cout<<"\n!!! Error. Try again. \n";
        cout<<"\n1. Successful Take out:\n";
        cin>>clearFilter;
    }
    if(clearFilter==1)
    {
        filterState=false;
        cout<<"\nSuccessful\n";
    }

    return 0;

}
/*-----------------------------------------------------------------------------
                                Checking Lid codition
-------------------------------------------------------------------------------*/

int intelligentcoffeemachine::takeCoffee()
{
    cout<<"\nCoffee taken is Successful !!!\n";
    powerLED=true;
    return 0;

}
/*-----------------------------------------------------------------------------
                                Checking Lid codition
-------------------------------------------------------------------------------*/

int intelligentcoffeemachine::switchOff()
{
    cout<<"\n!!! Machine is switched off.\n";
    switchState=true;
    return 0;

}
/*-----------------------------------------------------------------------------
                                Checking Lid codition
-------------------------------------------------------------------------------*/

int intelligentcoffeemachine::exit()
{
    cout<<"\n!!! Machine is shuting down.\n";
    return 0;

}
