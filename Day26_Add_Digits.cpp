/*
Problem Statement: 
==================================================
Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.

Example:

Input: 38
Output: 2 
Explanation: The process is like: 3 + 8 = 11, 1 + 1 = 2. 
             Since 2 has only one digit, return it.
==================================================
*/
class Solution {
public:
	//Approach/Observation: Any number%9 would give the required sum which is sum of repeatedly adding all digits except when number is divisible by 9
	//Time Complexity: O(1)
	//Space Complexity: O(1)
    int addDigits(int num) {
        if(num==0) return 0;
        if(num%9==0) return 9;
        return num%9;
    }
};
