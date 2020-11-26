//
// Created by lenovo on 2020/9/19.
//

class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int low =0;
        int high=nums.size()-1;
        while(low <high)
        {
            while(low < high && nums[low]%2==1) low++;
            while(low<high && nums[high]%2==0) high--;
            swap(nums[low],nums[high]);
        }
        return nums;
    }
};