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
    void preOrder(TreeNode *root ,int num, int &sum){
        if(root == NULL ) return;
        if(root->left == NULL &&  root->right == NULL){
            num = num*10 + root->val;
            sum += num;
            return;
        }

        num = num *10 + root->val;
        preOrder(root->left , num , sum);
        preOrder(root->right, num, sum);

    }
    int sumNumbers(TreeNode* root) {
        if(root == NULL) return 0;
        int sum = 0;
        preOrder(root,0,sum);
        return sum;
    }
};