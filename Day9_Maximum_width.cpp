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
	//Approach: The given binary tree can be represnted in array form by denoting left child as 2i+1 and right child as 2i+2 (0-based indexing)
	//Using the similar approach of level order traversal (BFS), we maintain the starting and ending index values of nodes of each level.
	//Maximum width will be obtained from level having max. differene between starting and ending node index values.
	//Time Complexity: O(Nodes)
	//Space Complexity: O(Nodes) for queue 
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        long long int width=0;
        queue<pair<TreeNode*,int>> q;
        q.push(make_pair(root,0));
        while(!q.empty()){
            long long int start=q.front().second;
            long long int end=start;
            int s=q.size();
            for(int i=0;i<s;i++){
                TreeNode* cur=q.front().first;
                end=q.front().second;
                if(cur->left!=NULL)
                    q.push(make_pair(cur->left,(end*2)+1));
                if(cur->right!=NULL)
                    q.push(make_pair(cur->right,(end*2)+2));   
                q.pop();
            }
            if(end-start+1 > width)
                width=end-start+1;
        }
        return width;
    }
};
