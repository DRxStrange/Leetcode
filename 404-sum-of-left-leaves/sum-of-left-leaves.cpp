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
bool isLeaf(TreeNode *root){
    return !root->left && !root->right;
}
void preOrder(TreeNode *root, int &sum){
    if(root == NULL) return;
    if(root->left != NULL){
        if(isLeaf(root->left) == true){
        sum+=root->left->val;
        }
        preOrder(root->left,sum);
    }
    preOrder(root->right,sum);
}
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        preOrder(root,sum);
        return sum;
    }
};