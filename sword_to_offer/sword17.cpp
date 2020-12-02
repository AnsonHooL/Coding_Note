//
// Created by lenovo on 2020/9/18.
//
/***  难点是大数乘法  ***/
class Solution {
public:
    vector<int> printNumbers(int n) {
        int max = 0;
        vector<int> tmp;
        max = pow(10,n)-1;
        for(int i=1;i<=max;i++)
        {
            tmp.push_back(i);
        }
        return tmp;
    }
};