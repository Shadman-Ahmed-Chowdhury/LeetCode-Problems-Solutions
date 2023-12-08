// Problem link: https://leetcode.com/problems/construct-string-from-binary-tree/description/

// My solution: 
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
    string str = "";
    void preOrderTraversal(TreeNode* root) {
        if(root == NULL) {
            return;
        }
        str += to_string(root->val);

        if(root->left != NULL || root->right != NULL) {
            // Even if there are no left child, we have to add parenthesis.
            str += "(";
            preOrderTraversal(root->left);
            str += ")";
        }
        if(root->right != NULL) {
            str += "(";
            preOrderTraversal(root->right);
            str += ")";
        }
    }
    string tree2str(TreeNode* root) {
        preOrderTraversal(root);
        return str;  
    }
};