/*
Problem Statement: 
--------------------------------------
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.
 

Constraints:

board and word consists only of lowercase and uppercase English letters.
1 <= board.length <= 200
1 <= board[i].length <= 200
1 <= word.length <= 10^3
---------------------------------------
*/
class Solution {
    //Approach: Take each character as starting point from the board. Traverse the whole board to search for the given string. If string is not matching with current character in board, then backtrack to other character.
    //Time Complexity: O(Number of rows* columns in board * (word length))
    //Space Complexity: O(Number of rows* columns in board)
public:
    bool func(string word,vector<vector<char>> &board,int i,int j,int l,vector<vector<bool>> &vis){
        if(l==word.length()) return true;
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || vis[i][j]==true ) return false;
        if(board[i][j]!=word[l]) return false;
        vis[i][j]=true;
        bool found= ( func(word,board,i+1,j,l+1,vis) || func(word,board,i-1,j,l+1,vis) || func(word,board,i,j+1,l+1,vis) || func(word,board,i,j-1,l+1,vis) );
        if(found==true)
            return true;
        else
            vis[i][j]=false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int r=board.size(),c=board[0].size();
        int i,j,l=0;
        vector<vector<bool>> vis(r,vector<bool>(c,false));
        for(i=0;i<r;i++){
            for(j=0;j<c;j++){
                bool check=func(word,board,i,j,0,vis);
                if(check==true)
                    return true;
            }
            
        }
        return false;
    }
};
