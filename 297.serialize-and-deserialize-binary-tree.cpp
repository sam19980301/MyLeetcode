/*
 * @lc app=leetcode id=297 lang=cpp
 *
 * [297] Serialize and Deserialize Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <bits/stdc++.h>
using namespace std;
class Codec {
private:
    enum { SEP = ',' };
    void serialize_helper(TreeNode* node, string& data)
    {
        if (!node)
            return ;
        
        data += to_string(node->val);
        data.push_back(SEP);

        serialize_helper(node->left, data);
        data.push_back(SEP);
        serialize_helper(node->right, data);
    }

    TreeNode* deserialize_helper(string& data, int& index)
    {
        if (index == data.size() || data[index] == SEP)
            return nullptr;
        
        int n = 0;
        bool is_pos = true;
        if (data[index] == '-')
        {
            is_pos = false;
            index++;
        }
        while (data[index] != SEP)
            n = n * 10 + (data[index++] - '0');
        n = is_pos ? n : -n;
        TreeNode *node = new TreeNode(n);

        index++;
        node->left = deserialize_helper(data, index);
        index++;
        node->right = deserialize_helper(data ,index);
        return node;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string data;
        serialize_helper(root, data);
        return data;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int index = 0;
        return deserialize_helper(data, index);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end

