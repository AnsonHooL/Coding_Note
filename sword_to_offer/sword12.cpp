#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <cstring>
using namespace std;
// n*m
//给一个二维char矩阵，一个单词，找矩阵是否有一条路径为word。
//dfs+回溯
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


int main() {
    std::cout << "Hello, World!" << std::endl;
    string s("Hello, World!");

    vector<int> pre={3,9,20,15,7};
    vector<int> in = {9,3,15,20,7};

    Solution a;
    vector<vector<char>> board = {{'a','b','c','e'}, {'s','f','c','s'},{'a','d','e','e'}};
    string word("abcced");
    a.exist(board,word);
    //string c(1,s[0]);


    return 0;
}