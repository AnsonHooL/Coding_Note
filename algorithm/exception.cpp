//
// Created by lenovo on 2021/3/25.
//
#include <bits/stdc++.h>
using namespace std;

class Base
{
public:
    Base(const Base& arg)
    {
        printf("copy\n");
        throw bad_alloc();
    }
    Base() = default;
    int a;
    virtual void run() {printf("Base\n");}
    ~Base(){printf("destruct\n");}
};



class Devide: public Base
{
public:
    int c;
    void run() {printf("Devide\n");}
};

class Devide1: public Devide
{
public:
//     void run() {printf("Devide1\n");}
};


int main()
{
    try {
        vector<Base> vec;
        vec.push_back(Base());
    }
    catch(bad_alloc& e) {
        printf("catch\n");
        printf("%s\n",e.what());
    }


    return 0;
}