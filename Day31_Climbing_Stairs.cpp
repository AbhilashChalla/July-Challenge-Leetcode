/*
Problem Statement: 
=================================================
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Example 1:

Input: 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
 

Constraints:

1 <= n <= 45
=================================================
*/

class Solution {
public:
	//Approach: Number of ways of reaching step n= (Number of ways of reaching step n-1) + (Number of ways of reaching step n-2)
	//Time Complexity: O(n)
	//Space Complexity: O(1)
    int climbStairs(int n) {
        if (n==1) return 1;
        int step_0=1,step_1=1;
        int ans=1;
        for(int i=2;i<=n;i++)
        {
            ans=step_0+step_1;
            step_0=step_1;
            step_1=ans;
        }
        return ans;
    }
};
