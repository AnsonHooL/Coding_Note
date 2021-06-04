//
// Created by lenovo on 2021/4/8.
//

class Solution {
public:
    int maxArea(vector<int>& height) {
        int low = 0;
        int high = height.size() - 1;
        int maxre = -1;
        while(low < high)
        {
            maxre = max(maxre,(high - low) * min(height[low], height[high]));
            if(height[high] < height[low]) high--;
            else low++;
        }
        return maxre;
    }
};

/// 我觉得单调队列也行啊,是不行的！！！！！！！！{1，2，1}就错了
//class Solution {
//public:
//    struct edge{
//        int pos;
//        int hight;
//    };
//
//    int maxArea(vector<int>& height) {
//        int r = 0;
//        deque<edge> q;
//        for(int i = 0; i < height.size(); i++){
//            while (!q.empty()){
//                if(q.back().hight < height[i]) q.pop_back();
//                else break;
//            }
//            q.push_back({i,height[i]});
//            int tmp = height[i] * (i - q.front().pos);
//            r = max(r, tmp);
//        }
//
//        return r;
//    }
//};
/**
 * 给你 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0) 。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

说明：你不能倾斜容器。


 思路：双指针先指向最大的两侧，然后每次贪心的移动短的那根，很容易证明移动短的那根一定是不影响最终的最大  大小的。


 *
 * */