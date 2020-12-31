//
// Created by lenovo on 2020/12/31.
//

bool cmp(vector<int> lhs, vector<int> rhs)
{
    return lhs[1] < rhs[1]; ///按右区间排序
}

///[1,2] [2,3] [2,4]
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size() == 0) return 0;
        sort(intervals.begin(), intervals.end(), cmp);
        int count = 0;
        int rightedge = INT32_MIN;
        // for(auto& interval : intervals)
        // {
        //     cout<< interval[0] << " " << interval[1] <<endl;
        // }
        for(auto& interval : intervals)
        {
            if(interval[0] >= rightedge)
            {
                rightedge = interval[1];
            } else{
                count++;
                continue;
            }
        }
        return count;
    }
};

/**
 *
 * 给定一个区间的集合，找到需要移除区间的最小数量，使剩余区间互不重叠。

注意:

可以认为区间的终点总是大于它的起点。
区间 [1,2] 和 [2,3] 的边界相互“接触”，但没有相互重叠。
示例 1:

输入: [ [1,2], [2,3], [3,4], [1,3] ]

输出: 1

解释: 移除 [1,3] 后，剩下的区间没有重叠。
示例 2:

输入: [ [1,2], [1,2], [1,2] ]

输出: 2

解释: 你需要移除两个 [1,2] 来使剩下的区间没有重叠。


 贪心的思路：肯定是从左到右，先放小区间，再放大区间，按区间右端进行排序，然后逐个放进去，如果左端大于等于现在的右端就可以丢进去

 * */