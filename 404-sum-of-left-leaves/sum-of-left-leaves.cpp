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
// checking for leaf node
bool isLeaf(TreeNode *root){
    return !root->left && !root->right;
}
void preOrder(TreeNode *root, int &sum){
    if(root == NULL) return;
    // root->left should be there
    if(root->left != NULL){
        // check node is leaf or not.
        if(isLeaf(root->left) == true){
            // if node left and leaf add in sum variable
        sum+=root->left->val;
        }
        // go for further left call
        preOrder(root->left,sum);
    }
    //  go for right call;
    preOrder(root->right,sum);
}
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        preOrder(root,sum);
        return sum;
    }
};