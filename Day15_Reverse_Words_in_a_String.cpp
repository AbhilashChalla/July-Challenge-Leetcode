/*
Problem Statement: 
-----------------------------------------------------------------------------------
Given an input string, reverse the string word by word.
A word is defined as a sequence of non-space characters.
Input string may contain leading or trailing spaces. However, your reversed string should not contain leading or trailing spaces.
You need to reduce multiple spaces between two words to a single space in the reversed string.

Example 1:

Input: "the sky is blue"
Output: "blue is sky the"
Example 2:

Input: "  hello world!  "
Output: "world! hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
Example 3:

Input: "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
-----------------------------------------------------------------------------------
*/

class Solution {
	//Approach: Use a stack to store each word. Append each word from the stack to result string. Lot of corner cases to take care of.
	//Time Complexity: O(String length)
	//Space Complexity: O(Number of words)
public:
    string reverseWords(string s) {
        string ans="",temp="";
        stack<string> st;
        for(int i=0;i<s.length();i++){
            if(temp!="" && s[i]==' '){ 
                st.push(temp); 
                temp="";
            }
            else if(s[i]!=' ')
                temp+=s[i];
        }
        if(temp!="")
            st.push(temp);
        while(st.size()>1){
            ans+=st.top();
            ans+=" ";
            st.pop();
        }
        if(!st.empty())
        	ans+=st.top();
        return ans;
    }
};
