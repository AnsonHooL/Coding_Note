//
// Created by lenovo on 2021/4/10.
//

class Solution {
public:
    bool isUgly(int n) {
        if(n <= 0) return false;
        while (n % 5 == 0) n = n / 5;
        while (n % 3 == 0) n = n / 3;
        while (n % 2 == 0) n = n / 2;
//        if (n == 1) return true;
//        else return false;
        return n == 1;
        /**  代码写的复杂了 */
    }
};

/***
 * 判断一个数是否为丑数
 *
 * /