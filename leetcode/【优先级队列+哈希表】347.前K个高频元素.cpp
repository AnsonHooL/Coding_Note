//
// Created by lenovo on 2021/6/9.
//

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> M;

        for(auto num : nums){
            if(M.find(num) == M.end()) M[num] = 1;
            else M[num]++;
        }

        struct counter{
            int num  = 0;
            int time = 0;
            counter(int n, int t) :num(n), time(t) { }
        };

        auto less = [](counter lhs, counter rhs) { return lhs.time < rhs.time;};

        priority_queue<counter, vector<counter>, decltype(less)> Q(less);

        for(auto m : M){
            Q.push({m.first, m.second});
        }

        vector<int> result;

        for(int i = 0; i < k; i++){
            auto t = Q.top();
            Q.pop();
            result.push_back(t.num);
        }

        return result;
    }
};
/**
 *
 * 给你一个整数数组 nums 和一个整数 k ，请你返回其中出现频率前 k 高的元素。你可以按 任意顺序 返回答案。

 

示例 1:

输入: nums = [1,1,1,2,2,3], k = 2
输出: [1,2]
示例 2:

输入: nums = [1], k = 1
输出: [1]


 *
 *
 *
 *
 * */