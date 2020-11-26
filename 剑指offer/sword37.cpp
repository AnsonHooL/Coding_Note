//
// Created by lenovo on 2020/9/26.
//

/***序列化和反序列化二叉树 难点在怎么优化速度内存？？？  ***/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
    TreeNode* node;
    // Encodes a tree to a single string.
//    string serialize(TreeNode* root) {
//        if(root == NULL) return string("#,");
//        string s = to_string(root->val);
//        s.push_back(',');
//        s =  s + serialize(root->left);
//        s =  s + serialize(root->right);
//        return s;
//    }

    string serialize(TreeNode* root) {
        if(root == NULL) return string("#,");
        string s;
        helpser(root,s);
        return s;
    }
    void helpser(TreeNode* root, string& s)
    {
        if(root == NULL)
        {
            s.push_back('#');
            s.push_back(',');
            return;
        }
        s += to_string(root->val);
        s.push_back(',');
        helpser(root->left,s);
        helpser(root->right,s);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        num = 0;
        return help(data);
    }
    TreeNode* help(string data)
    {
        int size = data.size();
        int flag = 0;
        if(num >= size || data[num] == '#')
        {
            num++;
            num++;
            return NULL;
        }
        int number = 0;
        if(data[num] == '-')
        {
            num++;
            flag = 1;
        }
        while(data[num] != ',' && data[num] != '#')
        {
            number = number*10 + (data[num] - '0');
            num++;
        }
        num++;
        if(flag) number = -number;
        TreeNode* root = new TreeNode(number);
        root->left  = help(data);
        root->right = help(data);
        return root;
    }
    int num;
};

Codec ss;
TreeNode* root = new TreeNode(1);
TreeNode* node2 = new TreeNode(2);
TreeNode* node3 = new TreeNode(3);
TreeNode* node4 = new TreeNode(4);
TreeNode* node5 = new TreeNode(5);
root->left  = node2;
root->right = node3;
node2->left = NULL;
node2->right = NULL;
node3->left = node4;
node3->right = node5;
node4->left = NULL;
node4->right = NULL;
node5->left = NULL;
node5->right = NULL;
string A = ss.serialize(root);
std::cout << A << std::endl;

TreeNode* node = ss.deserialize(A);
string B = ss.serialize(node);
std::cout << B << std::endl;