class Solution {
public:
    //Approach: powerset concept can be used to obtain distinct subsets.
    //Time Complexity: O(N*2^N) where N= Size of input array
    //Space Complexity: O(1)
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        long long int powerset_size=pow(2,nums.size());
        for(long long int i=0;i<powerset_size;i++){
            vector<int> row;
            for(int j=0;j<nums.size();j++){
                if(i&(1<<j)) row.push_back(nums[j]);
            }
            ans.push_back(row);
        }
        return ans;
    }
};
