/*
Problem Statement:
-----------------------------------------
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]
-----------------------------------------
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
class Solution {
public:
    //Approach: Make use of 2 stacks to alternate direction of traversal. Use stack 1 to store left to right traversal and right to left to store right to left traversal. At one time, a stack will be storing one level.
    //Time Complexity: O(Nodes)
    //Space Complexity: O(Nodes)
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL) return {};
        stack<TreeNode*> st1,st2;
        st1.push(root);
        vector<vector<int>> res;
        vector<int> row;
        while(st1.empty()==false || st2.empty()==false){
            while(st1.empty()==false){
                
                TreeNode* n=st1.top();
                st1.pop();
                row.push_back(n->val);
                if(n->left)
                {
                    st2.push(n->left);
                }
                if(n->right)
                {
                    st2.push(n->right);
                }
                if(st1.empty()==true){
                    res.push_back(row);
                    row.clear();
                }
            }
            
            while(st2.empty()==false){
                
                TreeNode* n=st2.top();
                st2.pop();
                row.push_back(n->val);
                if(n->right)
                {
                    st1.push(n->right);
                }
                if(n->left)
                {
                    st1.push(n->left);
                }
                if(st2.empty()==true){
                    res.push_back(row);
                    row.clear();
                }
            }
        }
        return res;
    }
};
