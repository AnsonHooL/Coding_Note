//
// Created by lenovo on 2020/12/9.
//
/***
 *
 * 求 1+2+...+n ，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。

 

示例 1：

输入: n = 3
输出: 6
示例 2：

输入: n = 9
输出: 45

构造逻辑短路，替代if



 ***/

class Solution {
public:
    int res = 0;
    int sumNums(int n) {
        bool x = n > 1 && sumNums(n - 1);
        res += n;
        return  res;
    }
};

class Solution {
public:
    int sumNums(int n) {
        bool arr[n][n+1];
        return sizeof(arr)>>1;
    }
};

