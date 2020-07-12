class Solution {
public:
    //Observations/Details: Only 1 island can be formed. Each grid is connected to other either horizontally or vertically. 
    //Approach: Traverse each cell and check for surrounding grid. Increment perimeter based on this condition.
    //Time Complexity: O(N*M) N=number of rows, M=number of columns
    //Space Complexity: O(1)
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==1){
                    if((i-1)<0 || grid[i-1][j]!=1)
                        perimeter++;
                    if((i+1)>=grid.size() || grid[i+1][j]!=1)
                        perimeter++;
                    if( (j-1)<0 || grid[i][j-1]!=1)
                        perimeter++;
                    if( (j+1)>=grid[i].size() || grid[i][j+1]!=1)
                        perimeter++;
                }
            }
        }
        return perimeter;
    }
};
