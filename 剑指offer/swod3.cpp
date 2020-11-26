#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
//数组中找出重复数字
int findRepeatNumber(vector<int>& nums) {
    unordered_map<int,int> map;
    for(auto a : nums)
    {
        auto iter = map.find(a);
        if(iter != map.end())
        {
            return a;
        }
        else
        {
            map[a] = 1;
        }
    }

}
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}