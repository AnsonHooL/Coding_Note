//
// Created by lenovo on 2020/12/10.
//

class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        int len = a.size();
        vector<int> b(len,1);
        int tmp = 1;
        for(int i = 0;i<len;i++)
        {
            b[i] = tmp;
            tmp *= a[i];
        }
        tmp = 1;
        for(int i = 0;i<len;i++)
        {
            b[len-i-1] *= tmp;
            tmp *= a[len-i-1];

        }
        return b;
    }
};

/****
 给定一个数组 A[0,1,…,n-1]，请构建一个数组 B[0,1,…,n-1]，其中 B 中的元素 B[i]=A[0]×A[1]×…×A[i-1]×A[i+1]×…×A[n-1]。不能使用除法。

 

示例:

输入: [1,2,3,4,5]
输出: [120,60,40,30,24]

就是 b[i] = (所有A[i]乘积) / A[i]，不能用除法

 b1 = 1 * A2 * A3
 b2 = A1 * 1 * A3
 b3 = A1 * A2 * 1

 可以做两次上下三角乘积，正着乘和逆着乘即可


 ***/