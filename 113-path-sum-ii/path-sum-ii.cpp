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
vector<vector<int>>ans;
void func(TreeNode* root,vector<int>res){
         if(!root) return;
         res.push_back(root->val);
         if(root->left==nullptr&&root->right==nullptr){
              ans.push_back(res);
              return;
         }
         if(root->left){
             func(root->left,res);
         }
         if(root->right){
             func(root->right,res);
         }
}
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
          
          vector<int>res;
          func(root,res);
          for(auto it:ans){
             for(auto i:it) cout<<i<<' ';
             cout<<endl;
          }
          vector<vector<int>>f;
          for(auto it:ans){
             int sum=accumulate(it.begin(),it.end(),0);
             if(sum==targetSum){
                 f.push_back(it);
             }
          }
          return f;
    }
};