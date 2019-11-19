/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    //暴力解法,计算当前节点和左右节点分别有多少条路径符合要求
    int pathSum(TreeNode* root, int sum) 
    {
        if(root == NULL)
            return 0;
        return _pathSum(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }
    int _pathSum(TreeNode* node, int sum)
    {
        if(node == NULL)
            return 0;
        int res = 0;
        if(node->val == sum)
        {
            res+=1;
        }
        res += _pathSum(node->left, sum-node->val);
        res += _pathSum(node->right, sum-node->val);
        return res;
    }
};