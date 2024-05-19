/*
1325. Delete Leaves With a Given Value
Given a binary tree root and an integer target, delete all the leaf nodes with value target.

Note that once you delete a leaf node with value target, if its parent node becomes a leaf node and has the value target, it should also be deleted (you need to continue doing that until you cannot).
*/
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
class Solution{
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target){
        if(root==NULL){
            return NULL;
        }
        root->left=removeLeafNodes(root->left, target);
        root->right=removeLeafNodes(root->right, target);
        if(root->val==target and root->left==NULL and root->right==NULL){
            return NULL;
        }
        return root;
    }
};

