/*
Problem statement: 
-------------------------------------------------------------------------------
Given a directed, acyclic graph of N nodes.  Find all possible paths from node 0 to node N-1, and return them in any order.

The graph is given as follows:  the nodes are 0, 1, ..., graph.length - 1.  graph[i] is a list of all nodes j for which the edge (i, j) exists.

Example:
Input: [[1,2], [3], [3], []] 
Output: [[0,1,3],[0,2,3]] 
Explanation: The graph looks like this:
0--->1
|    |
v    v
2--->3
There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.
Note:

The number of nodes in the graph will be in the range [2, 15].
You can print different paths in any order, but you should keep the order of nodes inside one path.
-------------------------------------------------------------------------------
*/

class Solution {
	//Approach: Use DFS with backtracking. Remove adjacent node of current node from path when its path is coevered.
	//Time Complexity: ~O(2^Number of nodes)
	//Space Complexity: O(Number of nodes) 
public:
    void dfs(vector<vector<int>> &g,vector<bool> &vis,vector<vector<int>> &paths,int s,int d,vector<int> current_path){
        if(s==d)
        {
            current_path.push_back(s);
            paths.push_back(current_path);
            return;
        }
        vis[s]=true;
        current_path.push_back(s);
        for(auto u:g[s]){
            if(!vis[u]){
                dfs(g,vis,paths,u,d,current_path);
                vis[u]=false;
            }
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<bool> vis(graph.size(),false);
        vector<vector<int>> paths;
        dfs(graph,vis,paths,0,graph.size()-1,{});
        return paths;
    }
};
