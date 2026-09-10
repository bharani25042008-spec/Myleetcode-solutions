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
int c=0;
void dfs(long long sum,TreeNode* root,int tar){
      if(!root)  return;
      sum+=root->val;
      if(sum==tar){
         c++;
      }
      dfs(sum,root->left,tar);
      dfs(sum,root->right,tar);

}
    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
             int s=q.size();
             for(int i=0;i<s;i++){
                 TreeNode* node=q.front();
                 q.pop();
                 dfs(0,node,targetSum);
                 if(node->left){
                     q.push(node->left);
                 }
                 if(node->right){
                     q.push(node->right);
                 }
             }
        }
        return c;
    }
};