/*
Problem statement:
------------------------------------------------------------------
Implement pow(x, n), which calculates x raised to the power n (xn).

Example 1:

Input: 2.00000, 10
Output: 1024.00000
Example 2:

Input: 2.10000, 3
Output: 9.26100
Example 3:

Input: 2.00000, -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25
Note:

-100.0 < x < 100.0
n is a 32-bit signed integer, within the range [-231, 231 - 1]
------------------------------------------------------------------
*/
class Solution {
	//Approach: Fast exponentiation algorithm can be used to calculate x^y in O(log y) Time Complexity
	//Time Complexity: O(Log n)
	//Space Complexity: O(1)
public:
    double myPow(double x, int n) {
        long long power=n;
        if(n<0){
            x=(double)1/x;
            power*=-1;
        }
        double ans=1;
        while(power>0){
            if(power&1)
                ans*=x;
            power>>=1;
            x*=x;
        }
        return ans;
    }
};
