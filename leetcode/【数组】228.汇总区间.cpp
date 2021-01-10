//
// Created by lenovo on 2021/1/10.
//

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> re;
        int n = nums.size();
        if(n == 0) return re;
        vector<int> mynum;
        for(int i = 0; i < n; i++)
        {
            if(mynum.empty()) mynum.push_back(nums[i]);
            else if(mynum.back() == (nums[i]-1)) mynum.push_back(nums[i]);
            else
            {
                if(mynum.size() == 1) re.push_back(to_string(mynum.front()));
                else
                {
                    string a = to_string(mynum.front());
                    a += "->";
                    a += to_string(mynum.back());
                    re.push_back(a);
                }
                vector<int> a;
                mynum.swap(a);
                mynum.push_back(nums[i]);
            }
        }
        if(mynum.size() == 1) re.push_back(to_string(mynum.front()));
        else
        {
            string a = to_string(mynum.front());
            a += "->";
            a += to_string(mynum.back());
            re.push_back(a);
        }
        return re;
    }
};

/**
 * 给定一个无重复元素的有序整数数组 nums 。

返回 恰好覆盖数组中所有数字 的 最小有序 区间范围列表。也就是说，nums 的每个元素都恰好被某个区间范围所覆盖，并且不存在属于某个范围但不属于 nums 的数字 x 。

列表中的每个区间范围 [a,b] 应该按如下格式输出：

"a->b" ，如果 a != b
"a" ，如果 a == b
 

示例 1：

输入：nums = [0,1,2,4,5,7]
输出：["0->2","4->5","7"]
解释：区间范围是：
[0,2] --> "0->2"
[4,5] --> "4->5"
[7,7] --> "7"
示例 2：

输入：nums = [0,2,3,4,6,8,9]
输出：["0","2->4","6","8->9"]
解释：区间范围是：
[0,0] --> "0"
[2,4] --> "2->4"
[6,6] --> "6"
[8,9] --> "8->9"

 *
 * */