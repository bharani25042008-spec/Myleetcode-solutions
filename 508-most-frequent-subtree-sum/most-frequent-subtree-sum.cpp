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
map<int,int>mp;
int func(TreeNode* root){
       if(!root) return 0;
       int left=func(root->left);
       int right=func(root->right);
       int sum=root->val+left+right;
       mp[sum]++;
       return sum;
}
    vector<int> findFrequentTreeSum(TreeNode* root) {
        func(root);
        int maxi=0;
        for(auto it:mp){
             maxi=max(maxi,it.second);
        }
        for(auto it:mp) cout<<it.first<<' ';
        vector<int>ans;
        for(auto it:mp){
            if(it.second==maxi){
                 ans.push_back(it.first);
            }
        }
        return ans;
    }
};