#include "threading.h"

#include<iostream>
#include <memory>

using namespace std;

int recurse(int num)
{
    if(num == 0)
    {
        return 0;
    }

    return num + recurse(num - 1);
}

void iterate(int i, int limit)
{
    if (i % 1000 == 0)   // print frequently
        cout << "Depth: " << i << endl;

    if (i == limit)
        return;          // base case (logic is correct)

    iterate(i + 1, limit);
}

threading::threading()
{
    cout<<"######## Hello from threading class ##########"<<endl;

    int number = 5;
    cout<<recurse(number)<<" :recurse answer"<<endl;

    for(int i=0; i<10'00'000;i++)
    {
        if(i%1'00'000 == 0)
        {
            cout<<i<<endl;
        }
    }

    iterate(0, 40000);   // try 1000, 5000, 10000, 20000... at 64000 crash happens



    cout<<"######## ########################## ##########"<<endl;

}
