/*
Problem Statement:
---------------------------------------------------
Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.

Example:

Input:  [1,2,1,3,2,5]
Output: [3,5]
Note:

The order of the result is not important. So in the above example, [5, 3] is also correct.
Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?
---------------------------------------------------
*/
class Solution {
    //Approach: Taking XOR of all elements will leave XOR of two elements which apepar only once. Let this value be X. The bits set in X indicate that bits at those positions are differnet in 2 numbers. Based on this observation we can separate all the numbers into two groups using any set bit in X. 
    //Time Complexity: O(Input vector size)
    //Space Complexity: O(1)
public:
    vector<int> singleNumber(vector<int>& nums) {
        int x=0,y=0,xorr=0;
        for(auto v: nums){
            xorr^=v;
        }
        int lastsetbit=(xorr&-xorr);
        //cout<<lastsetbit<<endl;
        for(auto v: nums){
            if( (v&lastsetbit)!=0)
                x^=v;
            else
                y^=v;
        }
        return {x,y};
    }
};
