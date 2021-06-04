//
// Created by lenovo on 2021/6/4.
//

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low  = 0;
        int high = nums.size() - 1;
        int cur  = 0;
        while(cur <= high){
            if(nums[cur] == 0){
                swap(nums[low], nums[cur]);
                low++;
                cur++;
            }else if(nums[cur] == 2){
                swap(nums[high], nums[cur]);
                high--;
            } else if(nums[cur] == 1){
                cur++;
            }
        }
        for(auto num : nums){
            std::cout << num << std::endl;
        }
    }
};
/**
 *
 *给定一个包含红色、白色和蓝色，一共 n 个元素的数组，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。

此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。

 

示例 1：

输入：nums = [2,0,2,1,1,0]
输出：[0,0,1,1,2,2]
示例 2：

输入：nums = [2,0,1]
输出：[0,1,2]

思路：要求一趟扫描完成

 这好像是考研时候学过啊，丢到前面，丢到后面中间的不管即可！感觉有贪心的想法在里面

 *
 *
 *
 *
 * */