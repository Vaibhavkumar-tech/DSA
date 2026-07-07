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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        if(root==NULL) return ans;
        queue<pair<TreeNode*,int>>q;
        map<int,int>mp;
        q.push({root,0});
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int line=it.second;
            TreeNode* node=it.first;
            if(mp.find(line)==mp.end()){
                mp[line]=node->val;
            }
            if(node->right!=NULL) q.push({node->right,line+1});
            if(node->left!=NULL) q.push({node->left,line+1});
        }
        for(auto val:mp){
            ans.push_back(val.second);
        }
        return ans;
    }
};