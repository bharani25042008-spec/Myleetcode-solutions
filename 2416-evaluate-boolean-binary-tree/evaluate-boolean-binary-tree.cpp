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
bool func(TreeNode* root){
       if(!root) return false;
       if(root->left==nullptr&&root->right==nullptr){
                if(root->val==0) return false;
                else return true;
       }
       bool l=func(root->left);
       bool r=func(root->right);
       bool res;
       if(root->val==2){
           res= l||r;
       }
       if(root->val==3){
           res= l&&r;
       }
       return res;
}
    bool evaluateTree(TreeNode* root) {
          return func(root);
    }
};