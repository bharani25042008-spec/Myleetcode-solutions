/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
void mark(map<TreeNode*,int>&dist,TreeNode* root){
        queue<TreeNode*>q;
        q.push(root);
        dist[root]=INT_MAX;
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            if(node->left){
                 q.push(node->left);
                 dist[node->left]=INT_MAX;
            }
            if(node->right){
                 q.push(node->right);
                 dist[node->right]=INT_MAX;
            }
        }
}
void func(map<TreeNode*,TreeNode*>&mp,TreeNode* root){
      if(!root) return;
      queue<TreeNode*>q;
      q.push(root);
      while(!q.empty()){
          TreeNode* node=q.front();
          q.pop();
          if(node->left){
               mp[node->left]=node;
               q.push(node->left);
          }
          if(node->right){
               mp[node->right]=node;
               q.push(node->right);
          }
      }
}
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*,int>dist;
        queue<pair<int,TreeNode*>>q;
        dist[target]=0;
        map<TreeNode*,TreeNode*>p;
        func(p,root);
        mark(dist,root);
        dist[target]=0;
        q.push({0,target});
        while(!q.empty()){
              auto[d,node]=q.front();
              q.pop();
              if(node->left){
                 int nd=d+1;
                 if(nd<dist[node->left]){
                      dist[node->left]=nd;
                      q.push({dist[node->left],node->left});
                 }
              }
              if(node->right){
                  int nd=d+1;
                  if(nd<dist[node->right]){
                     dist[node->right]=nd;
                     q.push({dist[node->right],node->right});
                  }
              }
              if(p.find(node)!=p.end()){
                  int nd=d+1;
                  if(nd<dist[p[node]]){
                     dist[p[node]]=nd;
                     q.push({dist[p[node]],p[node]});
                  }
              }
        }
        vector<int>ans;
        for(auto it:dist){
              if(it.second==k){
                   ans.push_back(it.first->val);
              }
        }
    return ans;
    }
};