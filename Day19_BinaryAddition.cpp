/*
Problem Statement:
----------------------------------------------
Given two binary strings, return their sum (also a binary string).

The input strings are both non-empty and contains only characters 1 or 0.

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"
 

Constraints:

Each string consists only of '0' or '1' characters.
1 <= a.length, b.length <= 10^4
Each string is either "0" or doesn't contain any leading zero.
----------------------------------------------
*/

class Solution {
	//Approach: Follow basic binary digit addition and take care of carry.
	//Time Complexity: O(Max(length of 'a',length of 'b'))
	//Space Complexity: O(Max(length of 'a',length of 'b'))
public:
    string addBinary(string a, string b) {
        int maxlen=max(a.length(),b.length());
        vector<char> res(maxlen,'0');
        int carry=0,p1=a.length()-1,p2=b.length()-1;
        int resptr=res.size()-1;
        while(p1>=0 && p2>=0){
            if(a[p1]=='1' && b[p2]=='1'){
                if(carry==1)
                    res[resptr--]='1';
                else{
                    carry=1;
                    res[resptr--]='0';
                }
            }
            else if (a[p1]=='0' and b[p2]=='0')
            {
                if(carry==1)
                {
                    carry=0;
                    res[resptr--]='1';
                }
                else
                    res[resptr--]='0';
            }
            else{
                if(carry==1)
                {
                    //carry=0;
                    res[resptr--]='0';
                }
                else
                    res[resptr--]='1';
            }
            p1--;
            p2--;
        }
        if(p1<0 && p2>=0) {
            while(p2>=0){
                if(b[p2]=='1'){
                    if(carry==1)
                        res[resptr--]='0';
                    else
                        res[resptr--]='1';
                }
                else{
                    if(carry==1)
                    {
                        carry=0;
                        res[resptr--]='1';
                    }
                    else
                        res[resptr--]='0';
                }
                p2--;
            }
        }
        else if(p2<0 && p1>=0) {
            while(p1>=0){
                if(a[p1]=='1'){
                    if(carry==1)
                        res[resptr--]='0';
                    else
                        res[resptr--]='1';
                }
                else{
                    if(carry==1)
                    {
                        carry=0;
                        res[resptr--]='1';
                    }
                    else
                        res[resptr--]='0';
                }
                p1--;
            }
            
        }
        
        string ans="";
        if(carry==1) ans+='1';
        for(auto c: res){
            ans+=c;
        }
        return ans;
    }
};
