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
    int dfs(TreeNode *root, int len, int pre){
        if(!root) return 0;
        int cur_len = root->val == pre + 1 ? len + 1 : 1;
        return max(cur_len, max(dfs(root->left, cur_len, root->val), dfs(root->right, cur_len, root->val)));
    }
    int longestConsecutive(TreeNode* root) {
        if(!root) return 0;
        return dfs(root, 1, root->val);
    }
};
