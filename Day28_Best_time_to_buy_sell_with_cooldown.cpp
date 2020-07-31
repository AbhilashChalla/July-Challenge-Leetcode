/*
Problem Statement: 
================================================
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times) with the following restrictions:

You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
Example:

Input: [1,2,3,0,2]
Output: 3 
Explanation: transactions = [buy, sell, cooldown, buy, sell]
================================================

*/

class Solution {
public:
	//Approach: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/discuss/75928/Share-my-DP-solution-(By-State-Machine-Thinking)
    //The activities in problem can be broken down to 3 states: 
    //state1-> stores the result from selling the previous stock and not selling
    //state2-> takes care of scenario of buying stock at on current day and not buying
    //state3-> stores the result/profit when we sell
    //Time Complexity: O(N)
    //Space Complexity: O(N)
	int maxProfit(vector<int>& prices) {
        if(prices.size()==0 || prices.size()==1) return 0;
        vector<int> state1(prices.size(),0);
        vector<int> state2(prices.size(),0);
        vector<int> state3(prices.size(),0);
        state2[0]=-prices[0];
        state1[0]=0;
        state3[0]=INT_MIN;
        for(int i=1;i<prices.size();i++){
            state1[i]=max(state1[i-1],state3[i-1]);
            state2[i]=max(state2[i-1],state1[i-1]-prices[i]);
            state3[i]=state2[i-1]+prices[i];
        }
        return max(state1[prices.size()-1],state3[prices.size()-1]);
    }
};
