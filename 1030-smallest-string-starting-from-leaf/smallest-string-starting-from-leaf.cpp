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

void solve(TreeNode *root, string &ans, string temp){
    if(root==NULL) return;
    
    if(!root->left && !root->right){
           temp=char(root->val+'a')+temp;
          
           if(ans=="" || ans > temp){
            ans = temp;
           }
          
          return;
    }
     temp=char(root->val+'a')+temp;
    solve(root->left,ans,temp);
    solve(root->right,ans,temp);
    
}
    string smallestFromLeaf(TreeNode* root) {
        string ans = "", temp = "";
        solve(root,ans,temp);
            return ans;
    } 
};