//
// Created by lenovo on 2020/12/3.
//

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int bit[32] = {0};
        for(auto x : nums)
        {
            uint mask = 0x1L;
            for(int i = 0;i<32;i++)
            {
                if(mask & x) bit[i]++;
                mask <<= 1;
            }
        }
        int rec = 0;
        for(int i = 0; i<32; i++)
        {
            if(bit[i]%3 != 0) rec = rec | (0x1L << (i));
        }
        return rec;
    }
};

/***
 *
 * 统计每个bit出现的次数
 *
 * /