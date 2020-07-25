/**
Problem Statement:
---------------------------------------------------
Given two binary trees, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical and the nodes have the same value.

Example 1:

Input:     1         1
          / \       / \
         2   3     2   3

        [1,2,3],   [1,2,3]

Output: true
Example 2:

Input:     1         1
          /           \
         2             2

        [1,2],     [1,null,2]

Output: false
---------------------------------------------------

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
	//Approach: Simple pre-order traversal with base condition checks would do.
	//Time Complexity: O(Nodes)
	//Space Complexity: O(1) Without considering stack usage for recursion
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if( (p==NULL && q!=NULL) || (p!=NULL && q==NULL) ) return false;
        if(p==NULL && q==NULL) return true;
        if(p->val!=q->val || !(isSameTree(p->left,q->left)) || !(isSameTree(p->right,q->right))) return false;
        return true;
        
    }
};
