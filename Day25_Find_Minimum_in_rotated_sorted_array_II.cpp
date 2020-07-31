/*
Problem statement: 
===============================================================
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).

Find the minimum element.

The array may contain duplicates.

Example 1:

Input: [1,3,5]
Output: 1
Example 2:

Input: [2,2,2,0,1]
Output: 0
================================================================
*/

class Solution {
public:
	//Approach: Binary Search with modifications
	//Time Complexity: O(N) In case of all duplicates, the time complexity of below algorithm is O(N)
	//Space Complexity: O(1)
    int findMin(vector<int>& nums) {
        int l=0,r=nums.size()-1,mid;
        while(l<r){
            mid=(l+r)/2;
            if(nums[mid]<nums[r])
                r=mid;
            else if (nums[mid]>nums[r])
                l=mid+1;
            else 
                r--;
        }
        return nums[l];
    }
};
