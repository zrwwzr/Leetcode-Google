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
    int kthSmallest(TreeNode* root, int k) {
        vector<TreeNode*> stack;
        int cnt = 0;
        TreeNode *cur = root;
        while(cur || !stack.empty()){
            while(cur){
                stack.push_back(cur);
                cur = cur->left;
            }
            cur = stack.back(), stack.pop_back();
            if(++cnt == k) return cur->val;
            cur = cur->right;
        }
    }
};
