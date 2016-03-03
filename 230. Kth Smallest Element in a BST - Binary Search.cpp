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
        int N = getNumOfNodes(root->left);
        if(k <= N) return kthSmallest(root->left, k);
        else if(k > N + 1) return kthSmallest(root->right, k - N - 1);
        return root->val;
    }
    int getNumOfNodes(TreeNode *root){
        return !root ?  0 : 1 + getNumOfNodes(root->left) + getNumOfNodes(root->right);
    }
};
