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
//  void solve (TreeNode* root, int val, int depth){
//     if(depth-1<0)return;
//           if(depth-1==1 && root!=NULL){
//             TreeNode* left = root->left;
//             TreeNode* right = root->right;
//             TreeNode* newNode = new TreeNode(val);
//             root->left = newNode;
//             root->right = newNode;
//             newNode->left = left;
//             newNode->right = right;
//         }
//         if(root->left){
//               solve(root->left, val, depth-1);
//         }
//     if(root->right)
//     solve(root->right, val,depth-1);
//  }
TreeNode* solve(TreeNode* root, int val, int depth,int curr){
if(root==NULL) return NULL;
        if(curr == depth-1){
            TreeNode* left = root->left;
            TreeNode* right = root->right;
            root->left =  new TreeNode(val);
            root->right = new TreeNode(val);
            root->left->left = left;
             root->right->right = right;
            return root;
        }   
            TreeNode* left = solve(root->left, val,depth-1,curr);
            TreeNode* right = solve(root->right,val,depth-1,curr);
           
        return root;
}
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode* newroot = new TreeNode(val);
            newroot->left = root;
            return newroot;
        }
        return solve(root,val,depth,1);
    }
};