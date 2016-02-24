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
    void dfs(TreeNode *root, string &path, vector<string> &res){
        if(!root) return;
        string origin = path;
        path.append(to_string(root->val)).append("->");
        if(!root->left && !root->right){
            res.push_back(path.substr(0, path.size() - 2));
        }else{
            dfs(root->left, path, res);
            dfs(root->right, path, res);
        }
        path = origin;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        string path = "";
        dfs(root, path, res);
        return res;
    }
};
