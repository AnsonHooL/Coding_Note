//
// Created by lenovo on 2021/6/9.
//

class Solution {
public:
    string decodeString(string s) {
        string result;

        for(auto c : s){

            if(c != ']') result.push_back(c);
            else{
                int low = result.size() - 1;
                while(result[low] != '[') low--;

                string tmp = result.substr(low + 1);

                int multi = 0;

                low--;

                while(low>=0 && result[low]>= '0' && result[low]<= '9'){
                    low--;
                }

                int pos = low + 1;

                while(result[pos]>= '0' && result[pos]<= '9'){
                    multi = multi*10 + result[pos] - '0';
                    pos++;
                }

                if(multi == 0) tmp = "";
                else{
                    string cache = tmp;
                    for(int i = 1; i < multi; i++){
                        tmp += cache;
                    }
                }

                result.erase(result.begin() + low + 1, result.end());

                result += tmp;

            }

        }
        return result;
    }
};
/**
 * 给定一个经过编码的字符串，返回它解码后的字符串。

编码规则为: k[encoded_string]，表示其中方括号内部的 encoded_string 正好重复 k 次。注意 k 保证为正整数。

你可以认为输入字符串总是有效的；输入字符串中没有额外的空格，且输入的方括号总是符合格式要求的。

此外，你可以认为原始数据不包含数字，所有的数字只表示重复的次数 k ，例如不会出现像 3a 或 2[4] 的输入。

 

示例 1：

输入：s = "3[a]2[bc]"
输出："aaabcbc"
示例 2：

输入：s = "3[a2[c]]"
输出："accaccacc"
示例 3：

输入：s = "2[abc]3[cd]ef"
输出："abcabccdcdcdef"

思路：
 用字符串充当栈，很简单，可以优化一下，用栈保存数字

 *
 * */