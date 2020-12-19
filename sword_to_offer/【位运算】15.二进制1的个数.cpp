//
// Created by lenovo on 2020/9/18.
//

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        uint32_t mask = 1;
        while(n)
        {
            count += mask & n;
            n >>= 1;
        }
        return count;
    }
};

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while(n)
        {
            n &=  (n - 1);
            count++;
        }
        return count;
    }
};
/**
 * 二进制中一的个数，这里时间复杂度是32,可以查表减少
 * 还可以用 n &= n-1，每次必定较少1个1bit
 * */