//
// Created by lenovo on 2021/3/27.
//

template<unsigned n>
struct Factorial
{
    enum {
        value = n * Factorial<n-1>::value
    };

};

template<>
struct Factorial<0>
{
    enum {
        value = 1
    };
};

#include "bits/stdc++.h"
using namespace std;

int main()
{
    cout<<Factorial<6>::value;
}