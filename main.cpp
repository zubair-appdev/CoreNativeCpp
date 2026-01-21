#include <iostream>
#include <cstring>
#include <memory>
using namespace std;

class Buffer
{
    char* data;
public:
    Buffer(const char* str)
    {
        cout<<"Buffer Constructor called"<<endl;
        data = new char[strlen(str) + 1];
        strcpy(data,str);
    }

    Buffer(const Buffer &other)
    {
        cout<<"Buffer Copy Constructor called"<<endl;
        data = new char[strlen(other.data)+1]; //Deep copy
        strcpy(data,other.data);
    }

    Buffer& operator=(const Buffer &other)
    {
        cout<<"Buffer Copy Assignment called"<<endl;
        if(this != &other)
        {
            delete[] data;
            data = new char[strlen(other.data)+1];
            strcpy(data,other.data);
        }
        return *this;
    }

    Buffer(Buffer &&other) noexcept
    {
        cout<<"Buffer Move Constructor called"<<endl;
        data = other.data;
        other.data = nullptr;
    }

    Buffer& operator=(Buffer &&other) noexcept
    {
        cout<<"Buffer Move Assignment called"<<endl;

        if(this != &other)
        {
            delete[] data;
            data = other.data;
            other.data = nullptr;
        }

        return *this;
    }

    void print()
    {
        cout<<data<<endl;
    }

    ~Buffer()
    {
        cout<<"Buffer Destructor called"<<endl;
        delete[] data;
    }
};

void changeNum(int &n)
{
    n+=10;
}

void changeNumPointer(int *n)
{
    *n+=10;
}

int main()
{
    cout << "Hello World!" << endl;
    char name2[10] = "zubair2";
    cout<<name2<<" :name2"<<endl;


    char* name = new char[20];

    strcpy(name,"zubair");

    cout<<name<<" "<<strlen(name)<<endl;

    delete[] name;
    name = nullptr;

    Buffer b1("Maytech"); // (OR) Buffer b1 = "Maytech";

    Buffer b2(b1); // (OR) Buffer b2 = b1;

    Buffer b3 = "Zubair Ahmad";

    b1 = b3;

    b1.print();

    Buffer b4 = "Company";

    Buffer b5 = move(b4);

    b5.print();
    cout<<" zzz "<<endl;

    b4 = move(b5);
    b4.print();

    int num = 10;
    int* val = &num;
    cout<<*val<<endl;

    int& ref = num;
    cout<<ref<<endl;

    changeNum(num);
    cout<<num<<endl;

    int a = 50;
    int *p = &a;
    changeNumPointer(p);

    cout<<a<<endl;

    int *arr = new int[10]{44,31,56,7,5};

    cout<<*(arr+1)<<endl;
    cout<<*(arr+5)<<endl;

    delete [] arr;
    arr = nullptr;

    if(!arr)
    {
        cout<<"Array is deleted"<<endl;
    }

    float *floarArr = new float[5]{12.4,12.8,56.8,12.6,100.67};

    auto floatArr2 = make_unique<float[]>(5);

    floatArr2[0] = 456.89;

    cout<<*(floarArr+4)<<endl;
    cout<<floarArr[4]<<endl;
    cout<<floatArr2[0]<<endl;

    delete[] floarArr;
    floarArr = nullptr;

    const int N = 3;
    int list[N] = {10,5,8};

    int max = INT_MIN, max2 = INT_MIN;

    for(int i=0; i<N; i++)
    {

        if(max < list[i])
        {

            if(max2 < max)
            {
                max2 = max;
            }
            max = list[i];

        }
        else
        {
            if(list[i] < max && max2 < list[i])
            {
                max2 = list[i];
            }
        }

    }

    if(max2 == INT_MIN)
    {
        max2 = -1;
    }

    cout<<max<<" :max"<<endl;
    cout<<max2<<" :max2"<<endl;


    return 0;
}
