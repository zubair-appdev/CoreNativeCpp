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

threading::threading()
{
    cout<<"######## Hello from threading class ##########"<<endl;

    int number = 5;
    cout<<recurse(number)<<" :recurse answer"<<endl;

    cout<<"######## ########################## ##########"<<endl;
}
