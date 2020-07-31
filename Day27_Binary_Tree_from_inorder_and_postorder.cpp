/*
Problem Statement:
===========================================================
Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

inorder = [9,3,15,20,7]
postorder = [9,15,7,20,3]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7
===========================================================
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
	//Approach: Keep traversing from right to left in postorder traversal vector and search for the element in inorder vector as that would help in tracing elements which would fall
	// in left subarray and right subarray
	//Time Complexity: O(Nodes)
	//Space Complexity: O(1) Not considering space taken for creating tree as tree needs to be created as per the problem
    int pos=-1;
    int search(vector<int> &in,int l,int r,int element){
        int i=-1;
        for(i=l;i<=r;i++){
            if(in[i]==element)
                break;
        }
        return i;
    }
    TreeNode* helper(vector<int> &inorder,vector<int> &postorder,int l,int r){
        if(l>r) return NULL;
        int inorder_pos=search(inorder,l,r,postorder[pos]);
        pos--;
        TreeNode* root=new TreeNode(inorder[inorder_pos]);
        root->right=helper(inorder,postorder,inorder_pos+1,r);
        root->left=helper(inorder,postorder,l,inorder_pos-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        pos=inorder.size()-1;
        int l=0,r=inorder.size()-1;
        return helper(inorder,postorder,l,r);
    }
};
