class Solution {
public:
    int cnt;
    unordered_map<string, int> idx;
    unordered_map<int, int> hash;
    vector<TreeNode*> ans;
    
    // 返回当前子树的 id
    int dfs(TreeNode *root) {
        if (!root) return 0;
        int left = dfs(root->left), right = dfs(root->right);
        
        // 当前子树三元组
        string key = to_string(root->val) + "," + to_string(left) + "," + to_string(right);
        if (idx.find(key) == idx.end()) idx[key] = ++ cnt;
        
        int id = idx[key];
        if (++ hash[id] == 2) ans.push_back(root);
        return id;
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        cnt = 0;
        dfs(root);
        return ans;
    }
};