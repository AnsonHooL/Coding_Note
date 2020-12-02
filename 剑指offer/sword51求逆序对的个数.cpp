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
            if(nums[low] <= nums[high])
            {
                swap(nums[low],nums[high]);

            }
            else
            {
                reversenum++;
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
            if(nums[lowa] > nums[lowb])
            {
                reversenum += (high - lowb + 1);
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

    int reversePairs(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        reversenum = 0;
        sortArray(nums);
        return reversenum;
    }

    int reversenum;
};

/***
 *
 * 示例 1:

输入: [7,5,6,4]
输出: 5



 思路：归并排序，然后计算合并过程每个区间的逆序对，跨区间的逆序对

 /