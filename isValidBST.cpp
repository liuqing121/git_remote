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
        //�ݹ�ÿ���ڵ�,�ж�ÿ���ڵ�����½��Ƿ���ȷ
        return _isVaildBST(root, LONG_MIN, LONG_MAX);
    }
    bool _isVaildBST(TreeNode* node, long int lower, long int up)
    {
        if(node == NULL)
            return true;
        if(node->val <= lower) return false;
        if(node->val >= up) return false;
        //�ұ�ʱ���޾��ǵ�ǰ�ڵ�
        if(!_isVaildBST(node->right, node->val, up)) return false;
        //�����������޾��ǵ�ǰ�ڵ�
        if(!_isVaildBST(node->left, lower, node->val)) return false;
        return true;
    }
};