//
// Created by lenovo on 2020/9/29.
//

/*****求数组中出现超过一半的数字*****/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int re = nums[0];
        int count = 1;
        for(int i=1;i<nums.size();i++)
        {
            if(count == 0)
            {
                re=nums[i];
                count++;
                continue;
            }
            if(re == nums[i])
            {
                count++;
                continue;
            }
            if(re != nums[i])
            {
                count--;
            }
        }
        return re;
    }
};