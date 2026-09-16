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
    int findBottomLeftValue(TreeNode* root) {
           vector<vector<int>>ans;
           queue<TreeNode*>q;
           if(!root) return 0;
           q.push(root);
           while(!q.empty()){
                int s=q.size();
                vector<int>t;
                for(int i=0;i<s;i++){
                      TreeNode* node=q.front();
                      q.pop();
                       t.push_back(node->val);
                       if(node->left) q.push(node->left);
                       if(node->right) q.push(node->right);
                }
                ans.push_back(t);
           }
           vector<int>l=ans.back();
           return l.front();
    }
};