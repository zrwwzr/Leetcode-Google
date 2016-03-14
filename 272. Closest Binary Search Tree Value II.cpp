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
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        TreeNode* cur = root;
        vector<TreeNode*> stack;
        queue<int> q;
        while(cur || !stack.empty()){
            while(cur) stack.push_back(cur), cur = cur->left;
            cur = stack.back(), stack.pop_back();
            if(q.size() < k) q.push(cur->val);
            else{
                double diff1 = fabs(q.front() - target), diff2 = fabs(cur->val - target);
                if(diff1 > diff2) q.pop(), q.push(cur->val);
                else break;
            }
            cur = cur->right;
        }
        vector<int> res;
        while(!q.empty()) res.push_back(q.front()), q.pop();
        return res;
    }
};
