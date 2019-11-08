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
    bool isValidBST(TreeNode* root)
    {
        //递归每个节点,判断每个节点的上下届是否正确
        return _isVaildBST(root, LONG_MIN, LONG_MAX);
    }
    bool _isVaildBST(TreeNode* node, long int lower, long int up)
    {
        if(node == NULL)
            return true;
        if(node->val <= lower) return false;
        if(node->val >= up) return false;
        //右边时下限就是当前节点
        if(!_isVaildBST(node->right, node->val, up)) return false;
        //左子树的上限就是当前节点
        if(!_isVaildBST(node->left, lower, node->val)) return false;
        return true;
    }
};