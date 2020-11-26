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