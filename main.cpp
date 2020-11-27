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


bool cmp(int a, int b){   //升序排列，小的数字放在前面 10,100  10100 10010 判断的是从高位到低位

//    string atmp = to_string(a) + to_string(b);
//    string btmp = to_string(b) + to_string(a);
    return to_string(a) + to_string(b) < to_string(b) + to_string(a);//按降序排序
}

class Solution {
public:
    string minNumber(vector<int>& nums) {

        auto cmp1 = [](int a, int b) ->bool {return to_string(a) + to_string(b) < to_string(b) + to_string(a);};
        //按降序排序
        sort(nums.begin(),nums.end(),cmp1);

        string rec;
        char t[40];
        for(auto x : nums)
        {
            sprintf(t,"%d",x);
            rec += string(t);
            cout << t << endl;
        }
        return rec;
    }
};


//bool cmp(int a, int b){   //升序排列，小的数字放在前面   100 < 9 判断的是从高位到低位
//    if(a == 0) return true;
//    if(b == 0) return false;
//    if(a == b) return true;
//    char achar[40];
//    char bchar[40];
//    sprintf(achar,"%d",a);
//    sprintf(bchar,"%d",b);
////    itoa(a,achar,10);
////    itoa(b,bchar,10);
//    int i = 0;
//    while (achar[i] && bchar[i])
//    {
//        if(achar[i] < bchar[i])
//            return true;
//        else if(achar[i] > bchar[i])
//            return false;
//        else if(achar[i] == bchar[i])
//            i++;
//    }
//    if(bchar[i])
//        return bchar[0] < bchar[i];
//    if(achar[i])
//        return achar[i] < achar[0];
//    return a < b;//按降序排序
//}

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

    sort(vec.begin(),vec.end(),cmp);

    vector<int>::iterator it;
//    for(it = vec.begin();it != vec.end();it++)
//        cout<<*it<<" ";
//    cout<<endl;

    vector<int> veca;
    veca.push_back(10);
    veca.push_back(2);
    Solution s;
    s.minNumber(veca);

    return 0;
}