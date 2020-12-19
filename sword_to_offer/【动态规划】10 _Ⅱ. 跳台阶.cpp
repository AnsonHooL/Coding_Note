//
// Created by lenovo on 2020/12/19.
//

class Solution {
public:
    int numWays(int n) {
        if(n==0 || n==1) return 1;

        unsigned long b =1;
        unsigned long a =1;
        for(int i= 2;i<=n;i++)
        {
            unsigned long tmp = b ;
            b = (b + a)%1000000007;
            a = tmp;
        }
        return b%1000000007;
    }
};