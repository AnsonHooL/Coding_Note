//
// Created by lenovo on 2021/3/22.
//

class Solution {
public:
    int hammingWeight(uint32_t n) {
        uint32_t mask = 0x1L;
        int re = 0;
        while(n)
        {
            if(mask & n) re++;
            n = n >> 1;
        }
        return re;
    }
};
/**
 * 比直接统计32次来的高效，如果O（1）算法则是打表
 *
 * */