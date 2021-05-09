//
// Created by lenovo on 2021/4/26.
//

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int sum = 0;
        for(auto weight: weights) {sum += weight;}
        int minship = sum / D;
        int maxship = sum;
        int midship = (minship + maxship) / 2;
        int re;
        while (minship <= maxship){ //小于等于细节很重要
            midship = (minship + maxship) / 2;
            if(check(weights, midship, D)){
                re = midship;
                maxship = midship - 1;
            } else{
                minship = midship + 1;
            }
        }
        return re;
    }

    bool check(const vector<int>& weights, int cap, int D) {
        int cnt;
        int idx = 0;
        for (int i = 0; i < D; i++) {
            cnt = 0;
            while (idx < weights.size() && cnt + weights[idx] <= cap) {
                cnt += weights[idx++];
            }
        }
        return idx == weights.size();
    }

};
/**
 * 传送带上的包裹必须在 D 天内从一个港口运送到另一个港口。

传送带上的第 i 个包裹的重量为 weights[i]。每一天，我们都会按给出重量的顺序往传送带上装载包裹。我们装载的重量不会超过船的最大运载重量。

返回能在 D 天内将传送带上的所有包裹送达的船的最低运载能力。

 

示例 1：

输入：weights = [1,2,3,4,5,6,7,8,9,10], D = 5
输出：15
解释：
船舶最低载重 15 就能够在 5 天内送达所有包裹，如下所示：
第 1 天：1, 2, 3, 4, 5
第 2 天：6, 7
第 3 天：8
第 4 天：9
第 5 天：10

请注意，货物必须按照给定的顺序装运，因此使用载重能力为 14 的船舶并将包装分成 (2, 3, 4, 5), (1, 6, 7), (8), (9), (10) 是不允许的。


 思路：二分只后就不难，但是细节很重要啊
 * */