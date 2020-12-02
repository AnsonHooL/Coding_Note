//
// Created by lenovo on 2020/9/18.
//

/*****实现自己的整数幂  快速幂运算 折半法***/
/****  注意int 的取值范围 负数是比正数多1的 -intMIN > intMAX,所以不能出现-n，直接转化会溢出 **/
class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) return 1;
        if(n<0)
        {
            if(n%2!=0) return (1/x)*myPow(x,n+1);
        }
        if(n%2==1 && n>0) return x*myPow(x,n-1);
        else
        {
            double tmp = myPow(x,n/2);
            return tmp*tmp;
        }
    }
};
