/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root,int targetSum,vector<int> &path,vector<vector<int>>&ans){
        //base case
        if(root==NULL){
            return;
        }
        if(root->left==NULL && root->right==NULL){
            //include current node
            path.push_back(root->val);
            targetSum-=root->val;
            //check for target sum
            if(targetSum==0){
                ans.push_back(path);
            }
            //exclude
            path.pop_back();
            targetSum+=root->val;
        }
        //include current node
        path.push_back(root->val);
        solve(root->left,targetSum-root->val,path,ans);
        solve(root->right,targetSum-root->val,path,ans);

        //backtrack
        path.pop_back();
        targetSum+=root->val;

    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>path;
        solve(root,targetSum,path,ans);
        return ans;
    }
};
