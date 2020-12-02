//
// Created by lenovo on 2020/12/2.
//

class Solution {
public:
    void mergesort(vector<int>& nums,uint low, uint high)
    {
        if(low >= high) return;
        if(low == high - 1)
        {
            if(nums[low] > nums[high])
            {
                swap(nums[low],nums[high]);
            }
            return;
        }
        uint mid = (low+high) >> 1;
        mergesort(nums,low,mid);
        mergesort(nums,mid+1,high);
        vector<int> sortvec;


        int lowa = low;
        int lowb = mid+1;
        while (lowa<= mid && lowb<=high)
        {
            if(nums[lowa] <= nums[lowb])
            {
                sortvec.push_back(nums[lowa]);
                lowa++;
            } else
            {
                sortvec.push_back(nums[lowb]);
                lowb++;
            }
        }
        while(lowa <= mid)
        {
            sortvec.push_back(nums[lowa]);
            lowa++;
        }
        while(lowb <= high)
        {
            sortvec.push_back(nums[lowb]);
            lowb++;
        }
        int i = low;
        for(auto& x : sortvec)
        {
            nums[i++] = x;
        }

    }

    vector<int> sortArray(vector<int>& nums)
    {
        mergesort(nums,0,nums.size()-1);
        return nums;
    }
};

/***
 * 看看代码咋优化
 *
 * /