#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
// n*m
//要做越界检查，二维递增数组转化成，二叉搜索树
bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
    if(matrix.size() == 0 || matrix[0].size() == 0 ) return false;
    int n = matrix.size();
    int m = matrix[0].size();
    int row = 0;
    int col = m - 1;
    while( row <= n-1 && col >= 0 )
    {
        if(matrix[row][col] < target) row++;
        else if(matrix[row][col] > target) col--;
        else return true;
    }
    return false;
}
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}