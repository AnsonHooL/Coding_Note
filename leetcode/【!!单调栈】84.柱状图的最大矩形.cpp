//
// Created by lenovo on 2020/12/26.
//

/***
 *
 * 给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。

求在该柱状图中，能够勾勒出来的矩形的最大面积。
 */

///思路一暴力法，遍历以每个矩形为高度的矩形大小，向左看向右看是否大于等于自己，然后选出最大值
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxsize = 0;

        for(int i = 0; i < heights.size(); i++)
        {
            if(i > 0 && heights[i] == heights[i-1]) continue;//相邻的相等高度直接跳过

            int height = heights[i];

            int low = i;
            int high = i;
            while(low > 0 && heights[low-1] >= height) low--;
            while(high < heights.size()-1 && heights[high+1] >= height) high++;
            maxsize = max(maxsize, (high - low + 1) * height);
        }
        return maxsize;
    }
};


///  1 3 5 9 4 2
/// 维护一个单调栈，保存柱子的索引，那么如果后来的柱子 比 先入的柱子高，则以这个柱子为高的矩形则不能确定
/// 1 3 5 9  《--- 4进来，把9弹出，那么9的柱子确定了被 5   4 夹着，宽度为1
/// 1 3 5 《--- 4进来，把5弹出，那么5的柱子确定了被 3  4 夹着，宽度为2

///这里还可以用哨兵简化头尾的边界条件，很棒
/// 0 1 3 5 9 4 2 0

class Solution {
public:
    int largestRectangleArea(vector<int> &heights) {
        if (heights.size() == 0) return 0;

        vector<int> myhight;
        myhight.push_back(0);  ///哨兵
        myhight.insert(myhight.end(), heights.begin(), heights.end());
        myhight.push_back(0);

        int maxsize = 0;

        stack<int> mystack;
        mystack.push(0); ///push 柱子的索引
        for (int i = 1; i < myhight.size(); i++) {
            int index = mystack.top();
            int colsize = myhight[index]; ///柱子高度
            if (colsize < myhight[i]) {
                mystack.push(i);
                continue;
            } else if (colsize == myhight[i]) ///  1,1,1,9 相同的柱子保留一个就行，保留最右的，这样 9柱子 才能算对
            {
                mystack.pop();
                mystack.push(i);
            }

            while (colsize > myhight[i]) {
                mystack.pop();
                index = mystack.top();
                maxsize = max(maxsize, colsize * (i - index - 1));
                colsize = myhight[index];
            }
            mystack.push(i);
        }
        return maxsize;
    }
}
