class Solution {
	//Approach: Sort and use 2-pointer technique. Add few checks to avoid duplicate triplets as instructed in question.
	//Time Complexity: O(N^2) where N=Input vector size
	//Space Complexity: O(1)
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++){
            int start=i+1,end=n-1;
            if(i>0 && nums[i]==nums[i-1])
                continue;
            while(start<end){
                if(end<n-1 && (nums[end]==nums[end+1])){
                    end--;
                    continue;
                }
                else if (nums[i]+nums[start]+nums[end]==0){
                    ans.push_back({nums[i],nums[start],nums[end]});
                    end--;
                }
                else if(nums[i]+nums[start]+nums[end]>0)
                    end--;
                else
                    start++;
            }
        }
        return ans;
    }
};
