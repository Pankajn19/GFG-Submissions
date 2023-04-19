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
    int maxi = 0;
    void rec(TreeNode* root, int dir, int len){
        if(!root) return;
        maxi = max(maxi,len);
        if(!dir){
            rec(root->left,abs(dir-1),len+1);
            rec(root->right,dir,1);
        }
        else{
            rec(root->right,abs(dir-1),len+1);
            rec(root->left,dir,1);
        }
    }
    int longestZigZag(TreeNode* root) {
        rec(root,0,0);
        rec(root,1,0);
        return maxi;
        
    }
};