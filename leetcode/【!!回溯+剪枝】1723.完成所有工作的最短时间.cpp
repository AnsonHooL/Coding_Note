//
// Created by lenovo on 2021/5/8.
//



class Solution1 {
public:
    int ans = INT32_MAX;
    int jobslen;
    int worker;
    vector<int> myjob;
    int minimumTimeRequired(vector<int>& jobs, int k) {
        worker = k;
        jobslen = jobs.size();
        myjob = jobs;
        vector<int> sum(jobslen);
        dfs(0,sum,0);
        return ans;
    }

    void dfs(int depth,vector<int>& sum,int maxsum){
        if(maxsum > ans)
            return;
        if(depth == jobslen){
            ans = min(maxsum, ans);
            return;
        }

        for(int i = 0; i < worker; i++)
        {
            sum[i] += myjob[depth];
            dfs(depth+1, sum, max(maxsum,sum[i]));
            sum[i] -= myjob[depth];
        }
    }
};

class Solution {
public:
    int ans = INT32_MAX;
    int jobslen;
    int worker;
    vector<int> myjob;
    int minimumTimeRequired(vector<int>& jobs, int k) {
        worker = k;
        jobslen = jobs.size();
        myjob = jobs;
        vector<int> sum(jobslen);
        dfs(0,0,sum,0);
        return ans;
    }

    void dfs(int depth,int used,vector<int>& sum,int maxsum){
        if(maxsum > ans)
            return;
        if(depth == jobslen){
            ans = min(maxsum, ans);
            return;
        }
        if(used < worker){
            sum[used] += myjob[depth];
            dfs(depth+1, used+1, sum, max(maxsum,sum[used]));
            sum[used] -= myjob[depth];
        }

        for(int i = 0; i < used; i++)
        {
            sum[i] += myjob[depth];
            dfs(depth+1, used, sum, max(maxsum,sum[i]));
            sum[i] -= myjob[depth];
        }
    }
};
/**
 * 给你一个整数数组 jobs ，其中 jobs[i] 是完成第 i 项工作要花费的时间。

请你将这些工作分配给 k 位工人。所有工作都应该分配给工人，且每项工作只能分配给一位工人。工人的 工作时间 是完成分配给他们的所有工作花费时间的总和。请你设计一套最佳的工作分配方案，使工人的 最大工作时间 得以 最小化 。

返回分配方案中尽可能 最小 的 最大工作时间 。

 

示例 1：

输入：jobs = [3,2,3], k = 3
输出：3
解释：给每位工人分配一项工作，最大工作时间是 3 。
示例 2：

输入：jobs = [1,2,4,7,8], k = 2
输出：11
解释：按下述方式分配工作：
1 号工人：1、2、8（工作时间 = 1 + 2 + 8 = 11）
2 号工人：4、7（工作时间 = 4 + 7 = 11）
最大工作时间是 11 。



 思路一：
 暴力解法，回溯，每个任务都分配一个工人去完成，然后暴力解决计算最小值，
 但是这里有一个剪枝，就是做到某一步，如果比之前的大，就没必要继续做了。
 但是这里还是有个问题，就是其实工人只用分两种，一种是已经分配工作的和没分配的。

 思路二：
 继续剪枝：
 第一种情况先分配任务给没工作的工人，提前生成较小值，使得剪枝速度更快
 再分配工作给有工作的工人


 绝了这剪枝的思路


 * */