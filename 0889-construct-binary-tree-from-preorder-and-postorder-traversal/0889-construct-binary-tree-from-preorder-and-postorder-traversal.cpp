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
    TreeNode* Solve(int prestart,int poststart,int preend,vector<int>& preorder, vector<int>& postorder,unordered_map<int,int>& mp){
        if(prestart>preend) return NULL;
        TreeNode* root=new TreeNode(preorder[prestart]);
        if(prestart==preend) return root;
        int next=preorder[prestart+1]; //left wla ka root hoga
        //find on postorder
        int j=mp[next];
        int num=j-poststart+1;
        root->left=Solve(prestart+1,poststart, prestart + num,preorder,postorder,mp);
        root->right=Solve(prestart+num+1,j+1,preend,preorder,postorder,mp);     
        return root;  

    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n=preorder.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[postorder[i]]=i;
        }
        return Solve(0,0,n-1,preorder,postorder,mp);
    }
};