//
// Created by lenovo on 2021/3/12.
//

class Solution {
public:
    bool isValidSerialization(string preorder) {
        preorder.push_back(',');
        stack<char> mystack;
        int number = 0;
        for(int i = 0; i < preorder.size(); i++)
        {
            if(preorder[i] != ',') continue;
            else
            {
                if(isdigit(preorder[i-1]))
                {

                    mystack.push('0');

                }else if(preorder[i-1] == '#')
                {
                    if(mystack.empty() || mystack.top() != '#') mystack.push('#');
                    else
                    {
                        while(!mystack.empty()&&mystack.top() == '#') ///有两个子结点
                        {
                            mystack.pop();
                            if(!mystack.empty() && isdigit(mystack.top()))
                            {
                                mystack.pop();
                            } else
                            {
                                return false;
                            }
                        }
                        mystack.push('#');
                    }
                }
            }
        }
        return mystack.empty() || (mystack.top() == '#' && mystack.size() == 1);

    }
};

/**
 * 这里的思路：就是两个#就可以退出，然后每次跳到逗号进行处理
 * 有一种快速，而且空间O(1)的方法，就是计数法，设置如果遇到空节点则消耗一个slot，如果是非空节点则消耗一个slot，并新增两个slot
 *
 *序列化二叉树的一种方法是使用前序遍历。当我们遇到一个非空节点时，我们可以记录下这个节点的值。如果它是一个空节点，我们可以使用一个标记值记录，例如 #。

     _9_
    /   \
   3     2
  / \   / \
 4   1  #  6
/ \ / \   / \
# # # #   # #
例如，上面的二叉树可以被序列化为字符串 "9,3,4,#,#,1,#,#,2,#,6,#,#"，其中 # 代表一个空节点。

给定一串以逗号分隔的序列，验证它是否是正确的二叉树的前序序列化。编写一个在不重构树的条件下的可行算法。

每个以逗号分隔的字符或为一个整数或为一个表示 null 指针的 '#' 。

你可以认为输入格式总是有效的，例如它永远不会包含两个连续的逗号，比如 "1,,3" 。

示例 1:

输入: "9,3,4,#,#,1,#,#,2,#,6,#,#"
输出: true
示例 2:

输入: "1,#"
输出: false
示例 3:

输入: "9,#,#,1"
输出: false


 我们知道在树（甚至图）中，所有节点的入度之和等于出度之和。可以根据这个特点判断输入序列是否为有效的！

在一棵二叉树中：

每个空节点（ "#" ）会提供 0 个出度和 1 个入度。
每个非空节点会提供 2 个出度和 1 个入度。
我们只要把字符串遍历一次，每个节点都累加 diff = 出度 - 入度 。在遍历到任何一个节点的时候，要求diff >= 0，原因是还没遍历到该节点的子节点，所以此时的出度应该大于等于入度。当所有节点遍历完成之后，整棵树的 diff == 0 。

这里解释一下为什么下面的代码中 diff 的初始化为 1。因为，我们加入一个非空节点时，都会先减去一个入度，再加上两个出度。但是由于根节点没有父节点，所以其入度为 0，出度为 2。因此 diff 初始化为 1，是为了在加入根节点的时候，先减去一个入度，再加上两个出度，此时 diff 正好应该是2.


class Solution(object):
    def isValidSerialization(self, preorder):
        nodes = preorder.split(',')
        diff = 1
        for node in nodes:
            diff -= 1
            if diff < 0:
                return False
            if node != '#':
                diff += 2
        return diff == 0



 *
 *
 * */