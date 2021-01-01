//
// Created by lenovo on 2021/1/1.
//

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        vector<int> myflower;
        myflower.push_back(0);
        myflower.insert(myflower.end(), flowerbed.begin(), flowerbed.end());
        myflower.push_back(0);
        int count = 0;
        for(int i = 1; i <= flowerbed.size(); i++)
        {
            if(myflower[i] == 1) continue;
            else if(myflower[i - 1] == 0 && myflower[i + 1] == 0) ///贪心种花
            {
                myflower[i] = 1;
                count++;
            }
            if(count >= n) break;
        }
        if(count >= n) return true;
        else return false;
    }
};

/**
 *
 * 假设你有一个很长的花坛，一部分地块种植了花，另一部分却没有。可是，花卉不能种植在相邻的地块上，它们会争夺水源，两者都会死去。

给定一个花坛（表示为一个数组包含0和1，其中0表示没种植花，1表示种植了花），和一个数 n 。能否在不打破种植规则的情况下种入 n 朵花？能则返回True，不能则返回False。

示例 1:

输入: flowerbed = [1,0,0,0,1], n = 1
输出: True
示例 2:

输入: flowerbed = [1,0,0,0,1], n = 2
输出: False

 思路：现在两边设置一个空花盆，然后直接贪心种花
 * */