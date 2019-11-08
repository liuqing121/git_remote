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
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        //利用队列先进先出的特性,pop之前把队列的左右放进队列
        std::vector<vector<int>> res;
        if(root == NULL)
            return res;
        std::queue<TreeNode*> que;
        que.push(root);
        while(!que.empty())
        {
            std::vector<int> tmp;
            int size = que.size();
            for(int i = 0; i < size; ++i)
            {
                TreeNode* node = que.front();
                tmp.push_back(node->val);
                if(node->left)
                    que.push(node->left);
                if(node->right)
                    que.push(node->right);
                que.pop();
            }
            res.push_back(tmp);
        }
        return res;
    }
};