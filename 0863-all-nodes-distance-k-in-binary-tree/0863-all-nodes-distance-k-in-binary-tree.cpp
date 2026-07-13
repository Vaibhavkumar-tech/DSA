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
    unordered_map<TreeNode*,TreeNode*>parent;
    void Find_Parent(TreeNode* root){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* current=q.front();
            q.pop();
            if(current->left){
                parent[current->left]=current;
                q.push(current->left);
            }
            if(current->right){
                parent[current->right]=current;
                q.push(current->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        Find_Parent(root);
        queue<TreeNode*>q;
        unordered_map<TreeNode*,bool>visited;
        int dist=0;
        q.push(target);
        visited[target]=true;
        while(!q.empty()){
            int n=q.size();
            if(dist==k) break;
            for(int i=0;i<n;i++){
                TreeNode* first=q.front();
                q.pop();
                if(first->left && !visited[first->left]){
                    q.push(first->left);
                    visited[first->left]=true;
                }
                if(first->right && !visited[first->right]){
                    q.push(first->right);
                    visited[first->right]=true;
                }
                if(parent[first] && !visited[parent[first]]){
                    q.push(parent[first]);
                    visited[parent[first]]=true;
                }
            }
            dist++;
        }
        vector<int>result;
        int n=q.size();
        for(int i=0;i<n;i++){
            TreeNode* top=q.front();
            q.pop();
            result.push_back(top->val);
        }
        return result;
    }
};