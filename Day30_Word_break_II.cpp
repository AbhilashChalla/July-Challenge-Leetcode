/*
Problem Statement:
=======================================================
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences.

Note:

The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.
Example 1:

Input:
s = "catsanddog"
wordDict = ["cat", "cats", "and", "sand", "dog"]
Output:
[
  "cats and dog",
  "cat sand dog"
]
Example 2:

Input:
s = "pineapplepenapple"
wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
Output:
[
  "pine apple pen apple",
  "pineapple pen apple",
  "pine applepen apple"
]
Explanation: Note that you are allowed to reuse a dictionary word.
Example 3:

Input:
s = "catsandog"
wordDict = ["cats", "dog", "sand", "and", "cat"]
Output:
[]
=======================================================
*/
class Solution {
public:
	//Approach: DP + Backtracking. To avoid Time Limit errors we store result of every possible combination in cache and backtrack to other possiblities
	//Time Complexity: O(String size of 's' * Numner of words in dict * max word length in dict) 
	//Space Complexity: O(Number of words in dict)
    unordered_map<string,vector<string>> cache;
    vector<string> join(vector<string> first, string add){
        for(int i=0;i<first.size();i++){
            first[i]=first[i]+" "+add;
        }
        return first;
    }
    vector<string> helper(string s,unordered_set<string>& dict){
        if(cache.find(s)!=cache.end()) return cache[s];
        vector<string> sentence;
        if(dict.count(s)) sentence.push_back(s);
        for(int i=0;i<s.length();i++){
            string cur=s.substr(i);
            if(dict.count(cur))
            {
                string remaining=s.substr(0,i);
                vector<string> back=join(helper(remaining,dict),cur);
                sentence.insert(sentence.end(),back.begin(),back.end());
            }
        }
        cache[s]=sentence;
        return sentence;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        for(auto w: wordDict)
            dict.insert(w);
        vector<string> res;
        res=helper(s,dict);
        return res;
    }
};
