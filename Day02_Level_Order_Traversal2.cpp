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
    //Is there a solution without reversal? 
    //The basic idea would be to use queue to maintain level-wise nodes, store each level in vector and reverse the final output.
    // Time Complexity: O(Number of nodes) 
    // Space Complexity: O(Number of nodes)
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root==NULL) return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> ans;
        while(!q.empty()){
            vector<int> level;
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode* cur=q.front();
                if(cur->left){
                    q.push(cur->left);
                }
                if(cur->right){
                    q.push(cur->right);
                }
                level.push_back(cur->val);
                q.pop();
            }
            ans.push_back(level);
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};
