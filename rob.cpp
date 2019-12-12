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
    int rob(TreeNode* root) 
    {
        //数组下标1表示偷，0表示不偷
        vector<int> ans;
        ans = dprob(root);
        return max(ans[0],ans[1]);
    }
    vector<int> dprob(TreeNode* root)
    {
        if(root == NULL)
            return {0,0};
        
        vector<int> left = dprob(root->left);
        vector<int>right = dprob(root->right);
        vector<int> tmp(2,0);
        tmp[0] = max(max(left[1] + right[1], left[0] + right[0]), max(left[1] + right[0], left[0]+ right[1]));//当前节点不偷，子节点都偷和子节点都不偷和子节点一个偷一个不偷的最大值
        tmp[1] = root->val + left[0] + right[0];      //当前节点偷，那当前节点的最大值是左右都不偷
        return tmp;
    }
};