/*
Problem Statement: 
------------------------------------------------
Given a non-empty array of integers, return the k most frequent elements.

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]
Note:

You may assume k is always valid, 1 = k = number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
It's guaranteed that the answer is unique, in other words the set of the top k frequent elements is unique.
You can return the answer in any order.
------------------------------------------------
*/
class Solution {
public:
	//Aproach: Create a hashmap with frequencies of each element. Traverse through map and create a min-heap of size K.
	//Time Complexity: O(NlogK) where N=Number of unique elements in nums vector
	//Space Complexity: O(N) (Hashmap: O(N) Heap:O(K) and N will be >= K)
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        int insert=0;
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            
                pq.push(make_pair(it->second,it->first));
                if(pq.size()>k)
                    pq.pop();
            
        }
        vector<int> ans;
        for(int i=0;i<k;i++)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
