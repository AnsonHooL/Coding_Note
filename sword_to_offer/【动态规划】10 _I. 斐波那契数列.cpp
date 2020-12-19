//
// Created by lenovo on 2020/12/19.
//

class Solution {
public:
    int fib(int n) {
        if(n== 0) return 0;
        if(n==1) return 1;
        unsigned long a = 0;
        unsigned long b = 1;
        for(int i= 2;i<=n;i++)
        {
            unsigned long tmp =b + a;
            a = b;
            b = tmp%1000000007;
        }
        return b % 1000000007;
    }
};