#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <cstring>
using namespace std;
// n*m
///给一个二维char矩阵，一个单词，找矩阵是否有一条路径为word。
///dfs+回溯

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(board.size()==0||board[0].size()==0) return false;
        if(word.size()==0) return true;
        int m = board.size();
        int n = board[0].size();
        char *map = (char*)malloc(m*n);
        memset(map,0,m*n);
        int row = board.size();
        int col = board[0].size();
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j] == word[0])
                {
                    if(word.size() == 1) return true;
                    map[i*col + j] = '#';
                    if(dfs(board,map,i,j,word,2))   return true;
                    map[i*col + j] = 0;
                }
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>>& board,char* map,int i,int j,string& word,int depth)
    {
        int row = board.size();
        int col = board[0].size();
        /* left */
        if(j>0 && map[i*col + j-1] != '#')
        {
            if(board[i][j-1] == word[depth-1])
            {
                if(word.size() == depth) return true;
                else
                {
                    map[i*col + j-1] = '#';
                    if(dfs(board,map,i,j-1,word,depth+1)) return true;
                    map[i*col+j-1] = 0;
                }
            }
        }
        /* right */
        if(j<col-1 && map[i*col+j+1] != '#')
        {
            if(board[i][j+1] == word[depth-1])
            {
                if(word.size() == depth) return true;
                else
                {
                    map[i*col+j+1] = '#';
                    if(dfs(board,map,i,j+1,word,depth+1)) return true;
                    map[i*col+j+1] = 0;
                }
            }
        }
        /* up */
        if(i>0 && map[(i-1)*col+j] != '#')
        {
            if(board[i-1][j] == word[depth-1])
            {
                if(word.size() == depth) return true;
                else
                {
                    map[(i-1)*col+j] = '#';
                    if(dfs(board,map,i-1,j,word,depth+1)) return true;
                    map[(i-1)*col+j] = 0;
                }
            }
        }
        if(i<row-1 && map[(i+1)*col+j] != '#')
        {
            if(board[i+1][j] == word[depth-1])
            {
                if(word.size() == depth) return true;
                else
                {
                    map[(i+1)*col+j] = '#';
                    if(dfs(board,map,i+1,j,word,depth+1)) return true;
                    map[(i+1)*col+j] = 0;
                }
            }
        }
        map[i * col + j] = 0;
        return false;
    }

};

/***
 *请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。路径可以从矩阵中的任意一格开始，每一步可以在矩阵中向左、右、上、下移动一格。如果
 * 一条路径经过了矩阵的某一格，那么该路径不能再次进入该格子。例如，在下面的3×4的矩阵中包含一条字符串“bfce”的路径（路径中的字母用加粗标出）。

[["a","b","c","e"],
["s","f","c","s"],
["a","d","e","e"]]

但矩阵中不包含字符串“abfb”的路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入这个格子。

 *
 *
 *
 *
 * */

/**下面的代码很简洁，但是速度慢很多哎，无所谓了*/
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(dfs(board, word, i, j, 0)) return true;
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>>& board, string word, int i, int j, int depth)
    {
        int rows = board.size();
        int cols = board[0].size();
        if(word.size() == depth) return true;
        if(i<0 || i==rows || j<0 || j==cols || word[depth] != board[i][j] || board[i][j] == '#') return false;
        board[i][j] = '#';
        bool flag = dfs(board,word,i-1,j,depth+1) || dfs(board,word,i+1,j,depth+1)
                    ||dfs(board,word,i,j-1,depth+1) || dfs(board,word,i,j+1,depth+1);
        board[i][j] = word[depth];
        return flag;
    }

};


