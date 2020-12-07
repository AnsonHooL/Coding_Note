#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <cstring>
#include <queue>
#include <cmath>
#include <bitset>
#include <deque>
#include <memory>
#include <thread>
#include "zconf.h"
#include <iostream>
#include <utility>
#include <thread>
#include <chrono>
#include <functional>
#include <atomic>
#include <cstring>
using namespace std;

#include <cstdio>
#include <cstdlib>


class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int row = grid.size();//hang
        int col = grid[0].size();//lie
        vector<vector<int>> value;
        value[0].push_back(grid[0][0]);
        for(int i=1;i<col;i++)
        {
            value[0].push_back(value[0][i-1] + grid[0][i]);
        }
        for(int i=1;i<row;i++)
        {
            value[i].push_back(value[i-1][0] + grid[i][0]);
        }
        for(int i =1;i<row;i++)
        {
            for(int j=1;j<col;j++)
            {
                int max1 = max(value[i-1][j], value[i][j-1]);
                value[i].push_back(max1 + grid[i][j]);
            }
        }
        return value[row-1][col-1];
    }
};



class A
{
public:
    A()
    {

    }
    ~A(){ printf("delete\n");}
};


A operator+(A lhs,A rhs)
{
    return  A();
}

A play()
{
    return A();
}


int main(){


    vector<int> vec;

    vec.push_back(324);
    vec.push_back(344);
    vec.push_back(2134);
    vec.push_back(23);
    vec.push_back(10);
    vec.push_back(101);
    vec.push_back(12);
    vec.push_back(134);
    vec.push_back(987);

    vector<int>::iterator it;
    Solution a;



    return 0;
}