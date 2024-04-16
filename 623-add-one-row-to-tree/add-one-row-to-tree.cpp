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
            

TreeNode* solve(TreeNode* root, int val, int depth){
if(root==NULL) return NULL;
        if(depth-1==1){
            TreeNode* left = root->left;
            TreeNode* right = root->right;
            TreeNode* newNode1 = new TreeNode(val);
            TreeNode* newNode2 = new TreeNode(val);
             root->left = newNode1;
             root->right = newNode2;
             newNode1->left = left;
             newNode2->right = right;
            return root;
        }   
            TreeNode* left = solve(root->left, val,depth-1);
            TreeNode* right = solve(root->right,val,depth-1);
           
        return root;
}
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode* newroot = new TreeNode(val);
            newroot->left = root;
            return newroot;
        }
        return solve(root,val,depth);
    }
};