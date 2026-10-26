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
vector<int>ans;
void dfs(TreeNode* root,map<int,int>&mp){
      if(!root) return;
      int val=mp[root->val];
      root->val=val;
      dfs(root->left,mp);
      dfs(root->right,mp);
}
void inorder(TreeNode* root){
       if(!root) return;
       inorder(root->left);
       ans.push_back(root->val);
       inorder(root->right);
}
    TreeNode* convertBST(TreeNode* root) {
        if(!root) return nullptr;
        map<int,int>mp;
        inorder(root);
        int n=ans.size();
        vector<int>suff(n,0);
        suff[n-1]=ans[n-1]; 
        for(int i=n-2;i>=0;i--){
              suff[i]=suff[i+1]+ans[i];
        }
        for(int i=0;i<n;i++){
              int sum=suff[i];
              mp[ans[i]]=sum;
        }
        dfs(root,mp);
        return root;
    }
};