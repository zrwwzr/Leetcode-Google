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
    void dfs(TreeNode *root, const double &target, double &res){
        if(!root) return;
        if(abs(root->val - target) < abs(res - target))
            res = root->val;
        if(root->val > target) dfs(root->left, target, res);
        else if(root->val < target) dfs(root->right, target, res);
    }
    int closestValue(TreeNode* root, double target) {
        double res = root->val;
        dfs(root, target, res);
        return res;
    }
};
