class Solution {
public:
    //carry variable keeps track of whether there is a need to carry from addition. Based on this, we can decide to increase the size of output vector if most significant bit is 9.
    //Time Complexity: O(Number of digits)
    //Space Complexity: O(Number of digits)
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans;
        int carry=1;
        
        for(int i=digits.size()-1;i>=0;i--){
            if(digits[i]==9 && carry==1){
                digits[i]=0;
                carry=1;
            }
            else
            {
                if(carry==1){
                    digits[i]++;
                    carry=0;
                }
                
            }
        }
        if(carry==1){
            ans.resize(digits.size()+1);
            ans[0]=1;
            for(int i=0;i<digits.size();i++)
                ans[i+1]=digits[i];
            return ans;
        }
        return digits;
    }
};
