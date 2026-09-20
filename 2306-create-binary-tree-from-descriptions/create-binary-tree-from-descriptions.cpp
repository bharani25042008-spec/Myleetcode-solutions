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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
          unordered_map<int,int>left;
          unordered_map<int,int>right;
          unordered_map<int,int>pr;
          for(auto it:descriptions)
          {
              int p=it[0];
              int c=it[1];
              int val=it[2];
              if(val==1){
                  left[p]=c;
              }else{
                  right[p]=c;
              }
              pr[c]=p;
          }
          int r=0;
          for(auto it:descriptions){
                if(pr.find(it[0])==pr.end()){
                     r=it[0];
                     break;
                }
                else if(pr.find(it[1])==pr.end()){
                     r=it[1];
                     break;
                }
          }
            TreeNode* root=new TreeNode(r);
            queue<TreeNode*>q;
            q.push(root);
            while(!q.empty()){
                  int s=q.size();
                  for(int i=0;i<s;i++){
                      TreeNode* node=q.front();
                      q.pop();
                      if(left.find(node->val)!=left.end()){
                           node->left=new TreeNode(left[node->val]);
                           q.push(node->left);
                      }
                      if(right.find(node->val)!=right.end()){
                         node->right=new TreeNode(right[node->val]);
                         q.push(node->right);
                      }
                  }
            }
            return root;
    }
};