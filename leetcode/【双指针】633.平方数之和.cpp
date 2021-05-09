//
// Created by lenovo on 2021/4/28.
//
class Solution {
public:
    bool judgeSquareSum(int c) {
        long c1 = c;
        long low = 0;
        long high = sqrt(c1);
        while (low <= high){
            if(low * low + high * high == c1) return true;
            else if(low * low + high * high < c1){
                low++;
            } else if(low * low + high * high > c1){
                high--;
            }
        }
        return false;
    }
};

//判断一个数是否有平方数之和
