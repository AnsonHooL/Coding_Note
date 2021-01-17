//
// Created by lenovo on 2021/1/17.
//

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if(coordinates.size() < 3) return true;
        auto t1 = coordinates[0];
        auto t2 = coordinates[1];
        int a = t2[0] - t1[0];
        int b = t2[1] - t1[1];
        for(auto coordinate : coordinates)
        {
            ///平行的判断
            if((coordinate[0] - t1[0]) * b != (coordinate[1] - t1[1]) * a) return false;
        }
        return true;
    }
};
/**
 * 在一个 XY 坐标系中有一些点，我们用数组 coordinates 来分别记录它们的坐标，其中 coordinates[i] = [x, y] 表示横坐标为 x、纵坐标为 y 的点。

请你来判断，这些点是否在该坐标系中属于同一条直线上，是则返回 true，否则请返回 false。


 思路: 判断是否为一个平行即可，用交叉乘积
 *
 * */