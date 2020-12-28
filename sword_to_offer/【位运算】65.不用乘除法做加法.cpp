//
// Created by lenovo on 2020/12/9.
//

class Solution {
public:
    int add(int a, int b) {
        //加法 = 加 和 进位
        // +  异或
        //进位 与 再左移 1 位
        while(b)
        {
            int c = unsigned(a & b)  << 1;
            a = a ^ b;
            b = c;
        }
        return a;

    }
};

/***
 * 001 + 001
 * 010
 * 加是异或，进位是与才能进
 *
 * /