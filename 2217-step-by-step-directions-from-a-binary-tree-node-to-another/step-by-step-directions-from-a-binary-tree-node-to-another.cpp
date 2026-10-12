class Solution {
public:
    TreeNode* start = nullptr;
    void c(TreeNode* root, int s) {
        if (!root || start) return;
        if (root->val == s) {
            start = root;
            return;
        }
        c(root->left, s);
        c(root->right, s);
    }
    void func(TreeNode* root,
              unordered_map<TreeNode*, TreeNode*>& mp) {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node->left) {
                mp[node->left] = node;
                q.push(node->left);
            }
            if (node->right) {
                mp[node->right] = node;
                q.push(node->right);
            }
        }
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        unordered_map<TreeNode*, TreeNode*> mp;
        func(root, mp);
     start = nullptr;
        c(root, startValue);
        queue<TreeNode*> q;
        unordered_set<TreeNode*> vis;
        unordered_map<TreeNode*, pair<TreeNode*, char>> parent;

        q.push(start);
        vis.insert(start);
        parent[start] = {nullptr, '#'};

        TreeNode* dest = nullptr;

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node->val == destValue) {
                dest = node;
                break;
            }

            if (node->left && !vis.count(node->left)) {
                vis.insert(node->left);
                parent[node->left] = {node, 'L'};
                q.push(node->left);
            }

            if (node->right && !vis.count(node->right)) {
                vis.insert(node->right);
                parent[node->right] = {node, 'R'};
                q.push(node->right);
            }

            if (mp.count(node) && !vis.count(mp[node])) {
                TreeNode* p = mp[node];
                vis.insert(p);
                parent[p] = {node, 'U'};
                q.push(p);
            }
        }
        string ans;
        while (dest != start) {
            auto [p, dir] = parent[dest];
            ans += dir;
            dest = p;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};