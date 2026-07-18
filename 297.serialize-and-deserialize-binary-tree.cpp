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
#ifdef LEETCODE_LOCAL_DEV
#include "297.serialize-and-deserialize-binary-tree.h"
#endif
#include <bits/stdc++.h>
using namespace std;
class Codec
{
  private:
    static constexpr char kNullNode = '#';
    static constexpr char kSeperator = ',';
    void serialize_helper(TreeNode *node, ostringstream &oss)
    {
        if (!node)
        {
            oss << kNullNode;
            return;
        }
        oss << node->val;
        oss << kSeperator;
        serialize_helper(node->left, oss);
        oss << kSeperator;
        serialize_helper(node->right, oss);
    }

    TreeNode *deserialize_helper(istringstream &iss)
    {
        if (iss.peek() == kNullNode)
        {
            iss.get();
            return nullptr;
        }
        int node_value = 0;
        iss >> node_value;
        // NOLINTNEXTLINE(cppcoreguidelines-owning-memory)
        auto *node = new TreeNode(node_value);
        iss.get(); // kSeperator
        node->left = deserialize_helper(iss);
        iss.get(); // kSeperator
        node->right = deserialize_helper(iss);
        return node;
    }

    /*
    TreeNode *deserialize_helper(string::iterator &it, string::iterator ed_it)
    {
        TreeNode *node = nullptr;
        it++;           // '('
        if (*it != ')') // is number
        {
            int num = 0;
            const bool is_negative = *it == '-';
            if (is_negative)
            {
                it++;
            }
            while (isdigit(*it))
            {
                // NOLINTNEXTLINE(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
                num = (10 * num) + (*it++ - '0');
            }
            if (is_negative)
            {
                num = -num;
            }

            node = new TreeNode(num); // NOLINT(cppcoreguidelines-owning-memory)
            node->left = deserialize_helper(it, ed_it);
            node->right = deserialize_helper(it, ed_it);
        }
        it++; // ')'
        return node;
    }
    */

  public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        // preorder format: node value, left child tree, right child tree
        ostringstream oss;
        serialize_helper(root, oss);
        return oss.str();

        /*
        // preorder format: "(node value(left child tree)(right child tree))"
        string code;
        code.push_back('(');
        if (root)
        {
            code += to_string(root->val);
            code += serialize(root->left);
            code += serialize(root->right);
        }
        code.push_back(')');
        return code;
        */
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        istringstream iss(data);
        return deserialize_helper(iss);

        /*
        auto it = data.begin();
        return deserialize_helper(it, data.end());
        */
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end
